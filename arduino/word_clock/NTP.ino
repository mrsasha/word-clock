const char* ntpServerName = "time.nist.gov";
const int NTP_PACKET_SIZE = 48;           // NTP time stamp is in the first 48 bytes of the message
const int NTP_PACKET_WAIT_TIME = 3000;    // how much to wait for the NTP reply
const unsigned long NTP_DELAY = 3600000;  // Update time using NTP once every hour
const unsigned int localPort = 2390;      // local port to listen for UDP packets

WiFiUDP udp;                              // A UDP instance to let us send and receive packets over UDP
IPAddress timeServerIP;                   // timeserver IP address holder
DateTime networkTime;

byte packetBuffer[ NTP_PACKET_SIZE];      //buffer to hold incoming and outgoing packets
unsigned long lastNTPUpdate = 0;

#define min(a,b) ((a)<(b)?(a):(b))        // recreate the min function

void setupNTP() {
  udp.begin(localPort);
}

void loopNTP() {
  if (millis() > lastNTPUpdate + NTP_DELAY) {
    updateTimeFromNTP();
  }
}

void updateTimeFromNTP() {
  WiFi.hostByName(ntpServerName, timeServerIP);                         //get a random server from the pool
  sendNTPpacket(timeServerIP);                                          // send an NTP packet to a time server
  delay(NTP_PACKET_WAIT_TIME);                                          // wait to see if a reply is available

  int cb = udp.parsePacket();           // get packet (if available)
  if (!cb) {
    Serial.println(F("... no packet yet"));
  } else {
    Serial.print(F("... NTP packet received with ")); Serial.print(cb); Serial.println(F(" bytes"));     // We've received a packet, read the data from it
    udp.read(packetBuffer, NTP_PACKET_SIZE);                            // read the packet into the buffer

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);  // timestamp starts at byte 40 of packet. It is 2 words (4 bytes) long
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);   // Extract each word and...
    unsigned long secsSince1900 = highWord << 16 | lowWord;             // ... combine into long: NTP time (seconds since Jan 1 1900):

    const unsigned long seventyYears = 2208988800UL;                    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    unsigned long epoch = secsSince1900 - seventyYears;                 // subtract seventy years to get to 1 Jan. 1900:

    int tz = -1;                                                        // adjust for EST time zone
    DateTime gt(epoch - (tz*60*60));                                    // obtain date & time based on NTP-derived epoch...
    tz = IsDST(gt.month(), gt.day(), gt.dayOfTheWeek())?-2:-1;          // if in DST correct for GMT-4 hours else GMT-5
    networkTime = DateTime(epoch - (tz*60*60));
    updateRTCs(networkTime);
    showDate("networkTime:", networkTime);
    lastNTPUpdate = millis();
  }
}

// send an NTP request to the time server at the given address
unsigned long sendNTPpacket(IPAddress& address) {
  Serial.println("sending NTP packet...");
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  udp.beginPacket(address, 123); //NTP requests are to port 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}

// getTime(): get current time from RTC (soft or hard)
//void getTime() { 
//  DateTime now = getRtcDateTime();  
//  ch = min(24,now.hour()); if(ch == 0) ch=24; // hours 1-24
//  cm = min(59,now.minute()); 
//  cs = min(59,now.second());
//  cdy= min(31,now.day()); 
//  cmo= min(now.month(),12); 
//  cyr= min(99,now.year()-2000); 
//  cdw =now.dayOfTheWeek();
//}

// IsDST(): returns true if during DST, false otherwise
boolean IsDST(int mo, int dy, int dw) {
  if (mo < 3 || mo > 11) { return false; }                // January, February, and December are out.
  if (mo > 3 && mo < 11) { return true;  }                // April to October are in
  int previousSunday = dy - dw;                               
  if (mo == 3) { return previousSunday >= 8; }            // In March, we are DST if our previous Sunday was on or after the 8th.
  return previousSunday <= 0;                             // In November we must be before the first Sunday to be DST. That means the previous Sunday must be before the 1st.
}

