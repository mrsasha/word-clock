#include "RTClib.h"

RTC_DS3231 rtcDS3231;
RTC_Millis softRTC;
boolean hasDS3231RTC = false;
boolean hasDS3231RTCInitialized = false;

void setupRTC() {
  DateTime compiled = DateTime(F(__DATE__), F(__TIME__));
  showDate("compiled:", compiled);
  
  setupSoftRTC(compiled);

  if (hasDS3231RTC) {
    setupExternalRTC_DS3231(compiled);
  }
}

void setupSoftRTC(DateTime start) {
  softRTC.begin(start);                    // initializing soft RTC
}

void setupExternalRTC_DS3231(DateTime start) {
  Serial.println("Initializing DS3231 RTC");
  hasDS3231RTCInitialized = rtcDS3231.begin();

  if (!hasDS3231RTCInitialized) {
    Serial.println("Couldn't find DS3231 RTC");
  } else {
    if (rtcDS3231.lostPower()) {
      Serial.println("DS3231 RTC lost power, let's set the time!");    
      rtcDS3231.adjust(start);               // initializing DS3231 RTC
    }

    DateTime rtcNow = rtcDS3231.now();
    showDate("DS3231 RTC now:", rtcNow);

    if (rtcNow.secondstime() - start.secondstime() < 0) {
      Serial.println("DS3231 RTC is older than start time - adjusting RTC!");
      rtcDS3231.adjust(start);
      showDate("DS3231 RTC after update:", rtcDS3231.now());
    }
  }
}

void updateRTCs(DateTime newDt) {
  softRTC.adjust(newDt);

  if (hasDS3231RTC && hasDS3231RTCInitialized) {
    rtcDS3231.adjust(newDt);    
  }
}

DateTime getRtcDateTime() {
  if (isDS3231RTCCorrect()) return rtcDS3231.now();
  else return softRTC.now();
}

boolean isDS3231RTCCorrect() {
  long softRTCDifference = rtcDS3231.now().secondstime() - softRTC.now().secondstime();
  return (hasDS3231RTC && hasDS3231RTCInitialized && abs(softRTCDifference) < 86400);
}

void showDate(const char* txt, const DateTime& dt) {
    Serial.print(txt);
    Serial.print(' ');
    Serial.print(dt.year(), DEC);
    Serial.print('/');
    Serial.print(dt.month(), DEC);
    Serial.print('/');
    Serial.print(dt.day(), DEC);
    Serial.print(' ');
    Serial.print(dt.hour(), DEC);
    Serial.print(':');
    Serial.print(dt.minute(), DEC);
    Serial.print(':');
    Serial.print(dt.second(), DEC);
    
    Serial.print(" = ");
    Serial.print(dt.unixtime());
    Serial.print("s since 1970");
    
    Serial.println();
}
