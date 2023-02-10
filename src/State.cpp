#include "State.h"

State::State(){};

State::~State() {}

IMU* State::getIMU() {
    return &imu;
}

GPS* State::getGPS() {
    return &gps;
}

Altimeter* State::getAlt() {
    return &alt;
}

// IMU* State::getIMU() {
//     return imu;
// }

// GPS* State::getGPS() {
//     return gps;
// }

// Altimeter* State::getAlt() {
//     return alt;
// }

// Telemetry* State::getTrans() {
//     return &trans;
// }