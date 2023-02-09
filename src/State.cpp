#include "State.h"

State::State(){
    // This isn't needed -- remove this constructor implementation?
    // imu = new IMU();
    // gps = new GPS();
    // alt = new Altimeter();
    // trans = Telemetry(868E6);
    IMU d_imu;
    GPS d_gps;
    Altimeter d_alt;
    StorageController d_storage;
    Apgoee d_apo;

    imu = &d_imu;
    gps = &d_gps;
    alt = &d_alt;
    storage = &d_storage;
    aps = &d_apo;
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