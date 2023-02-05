// https://github.com/adafruit/Adafruit_GPS

#ifndef _GPS_
#define _GPS_

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// Pre-defined constants specific to this configuration of the teensy
// Serial Protocol, &Serial1
static const int RXPin = 0, TXPin = 1;
static const uint32_t GPSBaud = 9600; // Do not use 4800

class GPS {
    public:
        GPS(void);
        GPS(int RX, int TX);
        ~GPS(void);
        void viewRead(unsigned long delay = 1000);
        void checkGPSDetected();
    private:
        TinyGPSPlus gps;
        // Default to RXPin 0 TXPin 1, that is the same as &Serial1. Need to change if this isn't the case anymore
        // Delay must be set after beginning serial e.g. ss.begin(9600), delay(5000);
        SoftwareSerial ss = SoftwareSerial(RXPin, TXPin);
        void smartDelay(unsigned long ms);
        void displayInfo();
};



#endif