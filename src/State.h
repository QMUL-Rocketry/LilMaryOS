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

        // Starts the state and its appropriate actions
        void start();

        // Ends the state 
        void end();

        // UNSAFE - THIS IS NOT FOR DEPLOYMENT
        IMU* getIMU();
        GPS* getGPS();
        // Altimeter* getAlt();
        // Telemetry* getTrans();
    private:
        // THESE SHOULD BE GLOBAL OR PART OF A CLASS THAT IS GLOBAL
        IMU* imu = NULL;
        GPS* gps = NULL;
        // Altimeter* alt = NULL;
        // Telemetry trans;
};








#endif