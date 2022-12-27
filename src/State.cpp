#include "State.h"

State::State(){
    imu = IMU(55);
    alt = Altimeter();
    trans = Telemetry(868E6);
};

State::~State() {}

IMU* State::getIMU() {
    return &imu;
}

Altimeter* State::getAlt() {
    return &alt;
}

Telemetry* State::getTrans() {
    return &trans;
}