#include <Arduino.h>

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
  // put your main code here, to run repeatedly:
  b = DEPLOYMENT;
  digitalWrite(led, HIGH);
  delay(b);
  digitalWrite(led, LOW);
  delay(b);
}