#include "imu.h"

IMU::IMU(int32_t id, uint8_t add){
    bno = Adafruit_BNO055(id, add, &Wire);
    sensor_t st;
    bno.getSensor(&st);
};

IMU::~IMU(){};

sensor_t IMU::getSensorInformation(){
    bno.getSensor(&sensor);
    return sensor;
};

sensors_event_t IMU::getSensorEvent() {
    bno.getEvent(&event);
    return event;
}