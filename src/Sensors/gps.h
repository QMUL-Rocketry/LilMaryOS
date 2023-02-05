// https://github.com/adafruit/Adafruit_GPS

#ifndef _GPS_
#define _GPS_

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// Pre-defined constants specific to this configuration of the teensy
// GPIO Protocol
static const int RXPin = 0, TXPin = 1;
static const uint32_t GPSBaud = 4800;

class GPS {
    public:
        GPS(void);
        GPS(int RX, int TX);
        ~GPS(void);
        void viewRead();
        void checkGPSDetected();
    private:
        TinyGPSPlus gps;
        SoftwareSerial ss = SoftwareSerial(RXPin, TXPin);
        void displayInfo();
};




#endif