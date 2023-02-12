#include <Arduino.h>
#include <globals.h>
#include "State.h"
#include "Tester/comp_check.cpp"
#include <Wire.h>
#include <SPI.h>
#include "Scheduler/Scheduler.h"
#include "Scheduler/Task.h"

enum blinks {
  PROGRAM_MODE = 1000,
  DEPLOYMENT = 500
};

// GPS UART SoftwareSerial rx 0 tx 1
// BMP280 i2c default &Wire
// BNO055 i2c? &Wire1

void blinkingLed();

blinks b = PROGRAM_MODE;

State s = State();

Scheduler sch;
Task tBlinkingLed(5000, &blinkingLed);

IMU* i = NULL;
GPS* g = NULL;
Altimeter* a = NULL;

bool isOn = true;

// Blinking LED
void blinkingLed() {
  if(isOn) {
    digitalWrite(DEFAULT_LED, HIGH);
    isOn = false;
  } else {
    digitalWrite(DEFAULT_LED, LOW);
    isOn = true;
  }
}

void tIMUWrapper();
void tGPSWrapper();
void tALTWrapper();

Task tIMU(100, &tIMUWrapper);
Task tGPS(2000, &tGPSWrapper);
Task tALT(2000, &tALTWrapper);


void setup()
{

  pinMode(DEFAULT_LED, OUTPUT);

  // Set to high for GPS
  Serial.begin(BAUD_HIGH);

  // Serial.begin(3000000);
  sch.add(&tBlinkingLed);

  // delay(5000);
  delay(1000);

  i = s.getIMU();
  g = s.getGPS();
  a = s.getAlt();

  // MUTEX SCHEDULEERRRRRRRRRRRRRRRRRRRRRRR??

  sch.add(&tIMU);
  sch.add(&tGPS);
  sch.add(&tALT);
  // sch.add(&p);

}

void loop()
{
  // blinkingLed(b);
  
  // BNO / IMU
  // i->readAllData(true);
  // delay(500);

  // GPS
  // CHANGE DELAY FOR GPS READ
  // NOTE DELAY FOR OTHER TIME SENSITIVE CODE E.G. BLINKS
  // g->viewRead();


  // BMP / Altimeter
  // a->readAllData();
  
  // scan the ports
  // i2cScanner();
  sch.execute();
  // delay(500);
}

void tIMUWrapper() {
  i->readAllData(false);
};
void tGPSWrapper() {
  g->viewRead();
};
void tALTWrapper() {
  a->readAllData();
};