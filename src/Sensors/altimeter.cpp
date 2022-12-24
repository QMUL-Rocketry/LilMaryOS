#include "altimeter.h"

Altimeter::Altimeter(){
    bmp = Adafruit_BMP280();
}

Altimeter::~Altimeter(){};

float Altimeter::readAltitude(){
    return bmp.readAltitude();
};

float Altimeter::readPressure(){
    return bmp.readPressure();
}

float Altimeter::readTemperature(){
    return bmp.readTemperature();
}

void Altimeter::readAllData(){
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" m");

    Serial.println();
    delay(2000);
}