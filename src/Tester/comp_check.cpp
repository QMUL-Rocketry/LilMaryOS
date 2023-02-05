// Component check for sensors. See if they exist

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

void checkBMPConn() {
    Wire.beginTransmission(0x76);
    byte status = Wire.endTransmission();
    if(status != 0) {
        Serial.print("BMP Not found at this address");
        while(1);
    }
    Serial.print("FOUND BMP");
}

// THIS DOESNT WORK
// void checkBNOConn() {
//     Wire.beginTransmission(0x28);
//     byte status = Wire.endTransmission();
//     if(status != 0) {
//         Serial.print("BNO Not found at this address");
//         while(1);
//     }
//     Serial.print("FOUND BNO");
// }

// NOT IMPLEMENTED
// GPIO CONNECTION, RX 0 TX 1 PINS
void checkGPSConn() {}

// Scans all address on i2c
void i2cScanner() {
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