/**
 * @author Ahnaf Khalique
*/

#ifndef IMU_H
#define IMU_H

// Sample rate delay of 100ms
#define BNO055_SAMPLERATE_DELAY_MS (100)

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "Sensors/Sensor.h"
#include <Wire.h>
#include <utility/imumaths.h>

class IMU {

    public:
        // sensorID – sensor ID, address – i2c address, theWire – Wire object
        IMU(int32_t id, uint8_t add);
        IMU(int32_t id);
        IMU();
        void printSensorInformation();
        void refreshSensorInformation();
        void printSensorStatus();
        void displayCalStatus();
        void printTest();
        sensors_event_t getSensorEvent();
        Adafruit_BNO055* exposeIMU();

        // DEBUGGING 
        imu::Vector<3> getVector(Adafruit_BNO055::adafruit_vector_type_t vectorType);
        imu::Vector<3> getAccel();
        imu::Vector<3> getMag();
        int8_t getTemp();
        void readAllData(boolean delay);
    private:
        sensor_t sensor;
        sensors_event_t event;
        Adafruit_BNO055 bno;
};


#endif