#include "State.h"

State::State(){
    // This isn't needed -- remove this constructor implementation?
    imu = new IMU();
    gps = new GPS();
    alt = new Altimeter();
    // trans = Telemetry(868E6);
};

State::~State() {}

IMU* State::getIMU() {
    return imu;
}

GPS* State::getGPS() {
    return gps;
}

Altimeter* State::getAlt() {
    return alt;
}

// Telemetry* State::getTrans() {
//     return &trans;
// }