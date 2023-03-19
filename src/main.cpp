#include <Arduino.h>
#include <globals.h>
#include "State.h"
// #include "Tester/comp_check.cpp"
#include <Wire.h>
#include <SPI.h>
#include "Scheduler/Scheduler.h"
#include "Scheduler/Task.h"

// class Trial : public RunMember {
// public:
//   void run() {
//     Serial.println("HEEELLLLOOO");
//     delay(1000);
//   }
// };

// Trial ok;

// Task okok(1000, &ok);

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
    Serial.println("ON");
    isOn = false;
  } else {
    digitalWrite(DEFAULT_LED, LOW);
    Serial.println("OFF");
    isOn = true;
  }
}

void tIMUWrapper();
void tGPSWrapper();
void tALTWrapper();

Task tIMU(2000, &tIMUWrapper);
Task tGPS(2000, &tGPSWrapper);
Task tALT(2000, &tALTWrapper);

void setup()
{

  pinMode(DEFAULT_LED, OUTPUT);

  // Set to high for GPS
  Serial.begin(BAUD_HIGH);

  // wait for serial port to connect
  // while (!Serial);
  sch.add(&tBlinkingLed);

  i = s.getIMU();
  g = s.getGPS();
  a = s.getAlt();

  // MUTEX SCHEDULEERRRRRRRRRRRRRRRRRRRRRRR??
  sch.add(&tIMU);
  sch.add(&tGPS);
  sch.add(&tALT);
  // sch.add(&okok);
}

// set a runtime delay?, all threads will have a guaranteed runtime of lets say 1 second?
void loop()
{
  sch.execute();
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