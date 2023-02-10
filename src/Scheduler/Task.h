#ifndef _TASK_
#define _TASK_

#include <Arduino.h>

class Task {
public:

    typedef void (*FuncPtr)();

    Task(unsigned long interval, void (*FuncPtr)());
    Task();
    ~Task();

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
    void *callback;
    // idk i just added it
    bool hasCallback();
    // execute the the callback task instead of the original task
    // more like a redirect
    // dependecy tells us if the callback should be tied to the task time interval
    // or be independent from it - independet execution time should be defined by scheduler
    void setCallback(void *func, bool dependency);

    bool isEnabled;
    // turn on task immediately
    void enable();
    // turn it off
    void disable();
    // add it to the queue
    void scheduleEnable();

    void isReady();
    void run();

    // how many time we want to repeat this task,
    // we could add custom limit but not neeed in this scope?
    enum repetition_type {
        ONCE, INFINITE
    };


};

#endif