#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <Adafruit_NeoPixel.h>    //https://github.com/adafruit/Adafruit_NeoPixel
#include <RTClib.h>  

#define PIXELS_DATA_PIN D5
const int LEDS_COUNT = 144;
const int LEDS_SIDE = 12;
const int LED_REFRESH_RATE_IN_MS = 2000;
const int WIFI_SETUP_BUTTON_PIN = 0; 

float ambientBrightness = 0.2;         //default is 20% brightness

boolean wifiSetupRequested = false;    //TODO Wifi setup button
boolean useLightSensor = false;        //TODO how to automatically check light sensor data and enable it if correct?
boolean displayUpdated = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);         // Initialize the output led
  pinMode(WIFI_SETUP_BUTTON_PIN, INPUT);// Initialize the WIFI setup button 

  scanPorts();

  setupRTC();
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
  loopDisplayer();

  if (displayUpdated) {
    displayUpdated = false;
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }

  delay(LED_REFRESH_RATE_IN_MS);
}

