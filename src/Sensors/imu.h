/**
 * @author Ahnaf Khalique
*/

#ifndef IMU_H
#define IMU_H

#define BNO055_SAMPLERATE_DELAY_MS (100)

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "Sensors/Sensor.h"
#include <Wire.h>
#include <utility/imumaths.h>

class IMU: public Sensor {

    public:
        // sensorID – sensor ID, address – i2c address, theWire – Wire object
        IMU(int32_t id, uint8_t add);
        ~IMU();
        void printSensorInformation();
        void refreshSensorInformation();
        void printSensorStatus();
        sensors_event_t getSensorEvent();
    private:
        sensor_t sensor;
        Adafruit_BNO055 bno;
};





#endif IMU_H