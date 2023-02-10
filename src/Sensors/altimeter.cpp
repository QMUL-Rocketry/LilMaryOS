#include "altimeter.h"

Altimeter::Altimeter(){
    bmp.begin();
}

Altimeter::~Altimeter(){};

float Altimeter::readAltitude(){
    return bmp.readAltitude();
};

float Altimeter::readPressure(){
    Serial.println("HELLO: pressure");
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
    // float temp = bmp.readTemperature();
    // float pressure = bmp.readPressure();
    // float alt = bmp.readPressure();
    // DELAYYYYY FIXXXX
    // delay(2000);
}