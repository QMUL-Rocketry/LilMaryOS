#include "State.h"

State::State(){
    imu = IMU(55);
};

State::~State() {}

IMU* State::getIMU() {
    return &imu;
}

