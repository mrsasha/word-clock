const float LIGHT_SENSOR_MAX_VALUE = 1023.0; // The light sensor returns values in the range 0 - 1023, the higher the value the darker it is. Check your sensor docs!

void loopLightSensor() {    
    float rawValue = analogRead(LIGHT_SENSOR_DATA_PIN);
    ambientBrightness = 1 - (rawValue / LIGHT_SENSOR_MAX_VALUE); //we need to normalize the value and then invert it; max brightness during day
    Serial.print("light sensor value =  "); Serial.print(rawValue); Serial.print(", normalized =  "); Serial.print(ambientBrightness);    
    Serial.println();
}

