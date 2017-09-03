#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <Adafruit_NeoPixel.h>    //https://github.com/adafruit/Adafruit_NeoPixel
#include <RTClib.h>  

const int LEDS_COUNT = 144;
const int LEDS_SIDE = 12;
const int LED_REFRESH_RATE_IN_MS = 1000;
const int WIFI_SETUP_BUTTON_PIN = 0; 

int ch,cm,cs,cdy,cmo,cyr,cdw;          // current time & date variables
int om = -1;
int nh,nm,ns,ndy,nmo,nyr,ndw;          // NTP-based time & date variables

boolean updateDisplay = false;
float ambientBrightness = 1.0;         //default is max brightness

boolean wifiSetupRequested = false;    //TODO Wifi setup button

boolean hasDS3231RTC = false;
boolean useLightSensor = false;

void setup() {
  Serial.begin(115200);
  pinMode(WIFI_SETUP_BUTTON_PIN, INPUT);// Initialize the WIFI setup button 

  scanPorts();
  
  setupLEDs();
  setupWiFi();
  setupNTP();
}

void loop() {
//  int wifiButtonState = digitalRead(WIFI_SETUP_BUTTON_PIN);
//
//  // check if the pushbutton is pressed. If it is, the buttonState is LOW:
//  if (wifiButtonState == LOW) {
//    // turn LED on:
//    digitalWrite(LED_BUILTIN, HIGH);
//    wifiSetupRequested = true;
//  } else {
//    // turn LED off:
//    digitalWrite(LED_BUILTIN, LOW);
//  }
  
  if (wifiSetupRequested) {
    Serial.println("Wifi setup requested!");
    setupWiFi();
  }
  
  if (useLightSensor) {
    loopLightSensor();
  }

  loopNTP();
  
  if (updateDisplay) {
    displayTime(ch, cm, cs);
    updateDisplay = false;
  }

  delay(LED_REFRESH_RATE_IN_MS);
}

