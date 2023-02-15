#ifndef _TASK_
#define _TASK_

#include <Arduino.h>
// #include "Scheduler.h"

// how many time we want to repeat this task,
// we could add custom limit but not neeed in this scope?
enum repetition {ONCE, INFINITE};

struct Sched_Timer {
    unsigned long average;
    int iterations;
};

// CYCLIC DEPENDENCYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
// class Scheduler;

class Task {
public:

    typedef void (*FuncPtr)();

    Task(unsigned long interval, void (*FuncPtr)());
    Task(repetition r, unsigned long i, void (*FuncPtr)());
    // Task(repetition r, unsigned long i, void (*FuncPtr)(), Scheduler *sch);
    Task();
    ~Task();

    // execute the the callback task instead of the original task
    // more like a redirect
    // dependecy tells us if the callback should be tied to the task time interval
    // or be independent from it - independet execution time should be defined by scheduler
    void setCallback(void (*FuncPtr)());

    // turn on task immediately
    void enable();
    // turn it off
    void disable();
    // // add it to the queue
    // void scheduleEnable();
    // free this task from the scheduler
    void end();
    // check if this program is meant to be ended from the scheduler
    bool checkEnd();

    // runs the method
    void run();
    // mesaures time spent per exectution
    void runWithTime();
private:
    // the function we want to execute, the task
    FuncPtr method;

    // time this task was last executed
    unsigned long last_executed;
    // time to wait before task should be executed again
    unsigned long interval;

    // CALLBACKS
    // we want to exit the function now but want to redirect it to another function to be added to the queue
    // there is no time delay - it will get executed whenever it gets the chance
    // GOOD for I/O, should be dependent to the task time for easy sake? add independent mode?
    FuncPtr callback;

    // for scheduler
    bool isEnabled;
    // for scheduler
    bool isEnd = false;
    // FOR THE REPETITION ENUM
    u_int8_t rep; 
    // for testing purposes
    Sched_Timer st;
};

#endif