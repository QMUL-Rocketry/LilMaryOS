#ifndef _SENSORBUNDLE_
#define _SENSORBUNDLE_

#include "imu.h"
#include "gps.h"
#include "Altimeter.h"

class SensorBundle {
public:

    SensorBundle();
    ~SensorBundle();

    float* getApogeeMatrix();
private:
    IMU imu;
    GPS gps;
    Altimeter alt;
};

#endif