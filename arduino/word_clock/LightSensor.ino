#define LIGHT_SENSOR_DATA_PIN A0
const float LIGHT_SENSOR_MAX_VALUE = 1023.0; // The light sensor returns values in the range 0 - 1023. Check your sensor docs!

void loopLightSensor() {    
    float rawValue = analogRead(LIGHT_SENSOR_DATA_PIN);
    ambientBrightness = rawValue / LIGHT_SENSOR_MAX_VALUE;
    Serial.print("light sensor value =  "); Serial.print(rawValue); Serial.print(", normalized =  "); Serial.print(ambientBrightness);    
    Serial.println();
}

