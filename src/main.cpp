#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
// #include "AudioFile.h"
#include "test.h"

enum blinks {
  PROGRAM_MODE = 100,
  DEPLOYMENT = 1000
};

int led = 13;

blinks b;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
<<<<<<< Updated upstream
  // testing branch right now just for you guys
=======
  // Controller();
>>>>>>> Stashed changes
  // put your main code here, to run repeatedly:
  b = DEPLOYMENT;
  digitalWrite(led, HIGH);
  delay(b);
  digitalWrite(led, LOW);
  delay(b);
}