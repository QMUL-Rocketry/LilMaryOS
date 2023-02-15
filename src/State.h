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

// class State {
//     public:
//         State();
//         ~State();

//         typedef void (State::*MemberFuncPtr)();

//         // sets up the state before turning to rin
//         void setup();

//         // Starts the state and its appropriate actions
//         void run();

//         // Ends the state 
//         void end();

//         // UNSAFE - THIS IS NOT FOR DEPLOYMENT
//         IMU* getIMU();
//         GPS* getGPS();
//         Altimeter* getAlt();
//         // Telemetry* getTrans();
//     private:
//         // POINTER VARIABLES - MUST NOT BE DYNAMICALLY ALLOCATED
//         // MUST LOOK INTO NOT USING POINTERS. COPY PASS BY VALUE WILL BE FASTER
//         // CHANGE AFTER EVERYTHING IS IMPLEMENTED
//         IMU imu;
//         GPS gps;
//         Altimeter alt;
//         MemberFuncPtr MemMethod;
//         // StorageController *storage;
//         // Apgoee *aps;
//         void setMethod(MemberFuncPtr m);
//         void stateStart();
//         void stateArming();
// };


// // note if its gonna be done simpler, the task wrapper for the scheduler needs to incorporate any changes
// // run will run anymethod that has been set in memmethod
// // the task wrapper will run the state run method only
// possibly faster/ better alternative is to use if-else to pick / identifty which state to be in
// void State::run() {
//     (this->*MemMethod)();
// }

// void State::setMethod(MemberFuncPtr m) {
//     MemMethod = m;
// };

// void State::stateStart() {
//     setMethod(&State::stateArming);
// }









#endif