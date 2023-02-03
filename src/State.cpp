#include "State.h"

State::State(){
    imu = new IMU(55);
    Serial.println("IMU passed here");
    // delay(5000);
    // alt = Altimeter();
    Serial.println("Alitmeter ran here");
    // trans = Telemetry(868E6);
};

State::~State() {}

IMU* State::getIMU() {
    return imu;
}

Altimeter* State::getAlt() {
    return alt;
}

// Telemetry* State::getTrans() {
//     return &trans;
// }