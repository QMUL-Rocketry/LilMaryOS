#ifndef STATE
#define STATE

#include <Sensors/imu.h>
#include <Sensors/gps.h>
// #include <Sensors/altimeter.h>
// #include <Sensors/telemetry.h>

class State {
    public:
        State();
        ~State();
        IMU* getIMU();
        GPS* getGPS();
        // Altimeter* getAlt();
        // Telemetry* getTrans();
    private:
        IMU* imu = NULL;
        GPS* gps = NULL;
        // Altimeter* alt = NULL;
        // Telemetry trans;
};








#endif