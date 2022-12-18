#ifndef STATE
#define STATE

#include <Sensors/imu.h>

class State {
    public:
        State();
        ~State();
        IMU* getIMU();
    private:
        IMU imu;
};








#endif