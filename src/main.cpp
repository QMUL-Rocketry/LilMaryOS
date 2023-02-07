#include <Arduino.h>
#include <globals.h>
#include "State.h"
#include "Tester/comp_check.cpp"
#include <Wire.h>
#include <SPI.h>

enum blinks {
  PROGRAM_MODE = 1000,
  DEPLOYMENT = 500
};

// GPS UART SoftwareSerial rx 0 tx 1
// BMP280 i2c default &Wire
// BNO055 i2c? &Wire1

void blinkingLed(blinks x);

blinks b = PROGRAM_MODE;

State s = State();

IMU* i = NULL;
GPS* g = NULL;
Altimeter* a = NULL;

void setup()
{

  pinMode(DEFAULT_LED, OUTPUT);

  // Set to high for GPS
  Serial.begin(BAUD_HIGH);

  delay(5000);
  // delay(1000);

  i = s.getIMU();
  g = s.getGPS();
  a = s.getAlt();

}

void loop()
{
  // blinkingLed(b);
  
  // BNO / IMU
  i->readAllData(true);
  // delay(500);

  // GPS
  // CHANGE DELAY FOR GPS READ
  // NOTE DELAY FOR OTHER TIME SENSITIVE CODE E.G. BLINKS
  g->viewRead();


  // BMP / Altimeter
  a->readAllData();
  
  // i2cScanner();
}

// Blinking LED
void blinkingLed(blinks x) {
  digitalWrite(DEFAULT_LED, HIGH);
  delay(x);
  digitalWrite(DEFAULT_LED, LOW);
  delay(x);
}
