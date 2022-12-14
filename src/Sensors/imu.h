/**
 * @author Ahnaf Khalique
*/

#ifndef IMU_H
#define IMU_H

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "Sensors/Sensor.h"
// #include <Wire.h>
#include <utility/imumaths.h>

class IMU: public Sensor {

    public:
        // sensorID – sensor ID, address – i2c address, theWire – Wire object
        IMU(int32_t id, uint8_t add);
        ~IMU();
        // int getPressure();
        // int getTemperature();
        sensor_t getSensorInformation();
        sensors_event_t getSensorEvent();
    private:
        Adafruit_BNO055 bno;
};





#endif IMU_H