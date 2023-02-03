#include <Arduino.h>
// #include <Wire.h>
// #include <SPI.h>
#include "State.h"

void icc_scannerA() {
    byte error, address;
    int nDevices;
    Serial.println("Scanning...");
    nDevices = 0;
    for(address = 1; address < 127; address++ ) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
        Serial.print("I2C device found at address 0x");
        if (address<16) {
            Serial.print("0");
        }
        Serial.println(address,HEX);
        nDevices++;
        }
        else if (error==4) {
        Serial.print("Unknow error at address 0x");
        if (address<16) {
            Serial.print("0");
        }
        Serial.println(address,HEX);
        }    
    }
    if (nDevices == 0) {
        Serial.println("No I2C devices found\n");
    }
    else {
        Serial.println("done\n");
    }
    delay(5000);
}

enum blinks {
  PROGRAM_MODE = 1000,
  DEPLOYMENT = 500
};

int led = 13;

blinks b;
// State s = State();
// State* s = NULL;
// IMU* i = NULL;
// Altimeter* a = NULL;
// Telemetry* t = NULL;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600); // main one
  // Serial.begin(115200); // gps one
  while ( !Serial ) delay(100);

  // s = new State();
  // delay(2000);
  // Serial.println("HE::P");

  // i = s.getIMU();

  // // a = s.getAlt();
  // t = s.getTrans();

}


void loop() {
  // edit
  // testing branch right now just for you guys
  // put your main code here, to run repeatedly:
  b = PROGRAM_MODE;
  Serial.printf("Hello");
  digitalWrite(led, HIGH);
  delay(b);
  digitalWrite(led, LOW);
  delay(b);
  // icc_scannerA();
  // Serial.println(bmp.readPressure());
  // i->readAllData(true);

  // i->printSensorInformation();
  // a->readAllData();
  // a->readPressure();
  // t->transmit(10.0);
  delay(100);
  
}
