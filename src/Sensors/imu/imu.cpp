#include "imu.h"

IMU::IMU(int32_t id, uint8_t add, TwoWire *wire){
    sensor_t st;
    sensors_event_t event;
    bno.getEvent(&event);
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