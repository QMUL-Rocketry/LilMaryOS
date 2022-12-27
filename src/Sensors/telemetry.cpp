#include "telemetry.h"

// 868E6 Transmission frequency at 868 MHz
Telemetry::Telemetry(double freq) {
    lr.begin(freq);
    setPinMode(A2);
}

Telemetry::~Telemetry(){}

void Telemetry::transmit(int val) {
    lr.beginPacket();
    lr.print(val);
    lr.endPacket();
    delay(50);
}

void Telemetry::setPinMode(int pot) {
    pinMode(pot, INPUT);
}

/* 
 *  Sensor Monitoring using Arduino and LoRa SX1278 Module, transmitter code
  Module SX1278 // Arduino UNO/NANO    
    Vcc         ->   3.3V
    MISO        ->   D12
    MOSI        ->   D11     
    SLCK        ->   D13
    Nss         ->   D10
    GND         ->   GND
 */
// #include <SPI.h>
// #include <LoRa.h>
// int pot = A2;  // The pin to which the sensor is connected to, im assuming only 1 pin i used

// void setup() {
//   Serial.begin(9600);
//   pinMode(pot,INPUT);
  
//   while (!Serial);  
//   Serial.println("LoRa Sender");
//   if (!LoRa.begin(868E6)) { /// transmission frequency at 868 MHz
//     Serial.println("Starting LoRa failed!");
//     while (1);
//   }
// }

// void loop() {
//   int val = map(analogRead(pot),0,1024,0,255); //mapped value of the val
//   LoRa.beginPacket();  
//   LoRa.print(val); // the send command, sending the value off the sensor
//   LoRa.endPacket();
//   delay(50);
 
// }