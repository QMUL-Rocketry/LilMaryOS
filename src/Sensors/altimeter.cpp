#include "altimeter.h"
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C Interface

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

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
