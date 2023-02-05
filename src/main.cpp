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

void blinkingLed(blinks x);

blinks b = PROGRAM_MODE;

State s = State();

IMU* i = NULL;
GPS* g = NULL;

void setup()
{

  pinMode(DEFAULT_LED, OUTPUT);

  // Set to high for GPS
  Serial.begin(BAUD_HIGH);

  i = s.getIMU();
  g = s.getGPS();

}

void loop()
{
  blinkingLed(b);
  
  i->readAllData(true);
  g->viewRead();

  delay(100);

  // i2cScanner();

}

// Blinking LED
void blinkingLed(blinks x) {
  digitalWrite(DEFAULT_LED, HIGH);
  delay(x);
  digitalWrite(DEFAULT_LED, LOW);
  delay(x);
}