#ifndef _STATEMACHINE_
#define _STATEMACHINE_

#include "Sensors/SensorBundle.h"
#include "Apogee/Apogee.h"
#include "Storage/StorageController.h"
#include "Scheduler/Scheduler.h"
#include "Sensors/SensorBundle.h"
#include "Scheduler/Task.h"

class StateMachine : public RunMember {
public:

    StateMachine();
    ~StateMachine();

    // from the beginning, this is run to setup any configuration
    // when transitioning states ...
    // this is run with transferState. Once a new task is added to the scheduler, the setup function is run
    virtual void setup();
    // this function is binded with Task and will run indefintely
    virtual void run();
    // once run() finds the correct condition to transfer state, this function is executed
    // transfers work struct to the new state we want to transition to
    // we then create a new task that runs this new state. we also END the task that we are running now
    // the struct holds the current process that we are in and we can call the end function so that the scheduler
    // doesnt run it. WE NEED TO CHANGE THE SCEDULER INTO A CIRCULAR QUEUE
    void end(); // DONT EDIT - DO NOT CHANGE DEFAULT FUNCTIONALITY
    struct work {
        SensorBundle *sensors; // SENSORS THAT WE NEED
        Apogee *height; // CALCULATES HEIGHT
        StorageController *storage; // HANDLES STORAGE
        Scheduler *sch; // SCHEDULERS OF ALL PROCESSES IN MICROCONTROLLER
        Task *task; // CURRENT PROCESS OF THE STATE MACHINE
    } work;
    // this points to the next state to which we want to transition to
    // CHANGE RunMember to just be the STATEMACHINE STUFF?
    // IMPLEMENT IT SIMPLER FIRST WITHOUT USING STATEMACHINE
    // use the one state class - look at commected implementation
    StateMachine *nextState;    // DONT EDIT - DO NOT CHANGE DEFAULT FUNCTIONALITY

};



#endif