#ifndef STATE
#define STATE

#include <Sensors/imu.h>
#include <Sensors/altimeter.h>

class State {
    public:
        State();
        ~State();
        IMU* getIMU();
        Altimeter* getAlt();
    private:
        IMU imu;
        Altimeter alt;
};








#endif