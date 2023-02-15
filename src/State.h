#ifndef STATE
#define STATE

#include <Sensors/imu.h>
#include <Sensors/gps.h>
#include <Sensors/altimeter.h>
// #include <Storage/StorageController.h>
#include <Apogee/apogee.h>

class State {
    public:
        State();
        ~State();

        // sets up the state before turning to rin
        void setup();

        // Starts the state and its appropriate actions
        void run();

        // Ends the state 
        void end();

        // UNSAFE - THIS IS NOT FOR DEPLOYMENT
        IMU* getIMU();
        GPS* getGPS();
        Altimeter* getAlt();
        // Telemetry* getTrans();
    private:
        // POINTER VARIABLES - MUST NOT BE DYNAMICALLY ALLOCATED
        // MUST LOOK INTO NOT USING POINTERS. COPY PASS BY VALUE WILL BE FASTER
        // CHANGE AFTER EVERYTHING IS IMPLEMENTED
        IMU imu;
        GPS gps;
        Altimeter alt;
        // StorageController *storage;
        // Apgoee *aps;
};








#endif