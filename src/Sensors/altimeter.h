#ifndef ALTIMETER
#define ALTIMETER

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

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
        Adafruit_BMP280 bmp = Adafruit_BMP280(&Wire1);
};

#endif