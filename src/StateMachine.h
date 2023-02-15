#ifndef _STATEMACHINE_
#define _STATEMACHINE_

#include "Sensors/SensorBundle.h";
#include "Apogee/Apogee.h";
#include "Storage/StorageController.h";
#include "Scheduler/Scheduler.h";
#include "Sensors/SensorBundle.h";

// SensorBundle, Apogee, StorageController
// class StateMachine {
// public:
//     void setup();
//     void run();
//     void end();
//     void transferState(State *state);
// private:
//     SensorBundle *sensors;
//     Apogee *height;
//     StorageController *storage;
//     Scheduler *sch;
//     State *state;
// };

class StateMachine {
public:
    void setup();
    void run();
    void end();
    // void transferState(State *state);
    SensorBundle *sensors;
    Apogee *height;
    StorageController *storage;
    Scheduler *sch;
    StateMachine *state;
};



#endif