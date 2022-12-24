#include "State.h"

State::State(){
    imu = IMU(55);
    alt = Altimeter();
};

State::~State() {}

IMU* State::getIMU() {
    return &imu;
}

Altimeter* State::getAlt() {
    return &alt;
}