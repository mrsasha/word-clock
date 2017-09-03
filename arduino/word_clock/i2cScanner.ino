/* 
* i2c_port_address_scanner
* Scans ports D0 to D7 on an ESP8266 and searches for I2C device. based on the original code
* available on Arduino.cc and later improved by user Krodal and Nick Gammon (www.gammon.com.au/forum/?id=10896)
* D8 throws exceptions thus it has been left out
*
*/

#include <Wire.h>

const byte I2C_ADDRESS_DS3231_RTC = 0x68;     //Fixed address on I2C bus
const byte I2C_ADDRESS_DS3231_TEMP = 0x57;    //Fixed address on I2C bus

uint8_t portArray[] = {16, 5, 4, 0, 2, 14, 12, 13};
String portMap[] = {"GPIO16", "GPIO5", "GPIO4", "GPIO0", "GPIO2", "GPIO14", "GPIO12", "GPIO13"};

void scanPorts() { 
  Serial.println("\nI2C Scanner to scan for devices on each port pair D0 to D7");
  
  for (uint8_t i = 0; i < sizeof(portArray); i++) {
    for (uint8_t j = 0; j < sizeof(portArray); j++) {
      if (i != j){
        Wire.begin(portArray[i], portArray[j]);
        check_if_exist_I2C(portMap[i], portMap[j]);
      }
    }
  }
}

void check_if_exist_I2C(String sda, String scl) {
  byte error, address;
  int nDevices = 0;

  //looping for devices 0-127
  for (address = 0; address < 127; address++ )  {
    Wire.beginTransmission(address); // The i2c_scanner uses the return value of the Write.endTransmisstion to see if a device did acknowledge to the address.
    error = Wire.endTransmission();

    if (error == 0){
      Serial.print("Scanning (SDA : SCL) - " + sda + " : " + scl); Serial.print(" - I2C device found at address 0x"); if (address < 16) Serial.print("0"); Serial.print(address, HEX); Serial.println("!");
      nDevices++;
      if (address == I2C_ADDRESS_DS3231_RTC) hasDS3231RTC = true;
      if (address == I2C_ADDRESS_DS3231_TEMP) hasDS3231Temp = true;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x"); if (address < 16) Serial.print("0"); Serial.println(address, HEX);
    }
  }
}

