#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "test.h"

enum blinks {
  PROGRAM_MODE = 1000,
  DEPLOYMENT = 500
};

int led = 13;

blinks b;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // testing branch right now just for you guys
  // put your main code here, to run repeatedly:
  b = PROGRAM_MODE;
  digitalWrite(led, HIGH);
  delay(b);
  digitalWrite(led, LOW);
  delay(b);
}