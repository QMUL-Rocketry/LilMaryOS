#ifndef STATE
#define STATE

#include <Sensors/imu.h>
#include <Sensors/altimeter.h>
#include <Sensors/telemetry.h>

class State {
    public:
        State();
        ~State();
        IMU* getIMU();
        Altimeter* getAlt();
        Telemetry* getTrans();
    private:
        IMU imu;
        Altimeter alt;
        Telemetry trans;
};








#endif