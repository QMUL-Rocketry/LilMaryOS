#ifndef ALTIMETER
#define ALTIMETER

#include <Adafruit_BMP280.h>

class Altimeter {
    public:
        float readTemperature();
        float readPressure();
        float readAltitude();
        void readAllData();
        Altimeter();
        ~Altimeter();
    private:
        Adafruit_BMP280 bmp;
};

#endif