#include "altimeter.h"

Altimeter::Altimeter(){
    // bmp = Adafruit_BMP280(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);
    // bmp = Adafruit_BMP280(BMP_CS);
    bmp = Adafruit_BMP280();
    if(!bmp.begin()){
        Serial.println("BMP Not working");
        // while(1);
    };
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
    delay(2000);
}