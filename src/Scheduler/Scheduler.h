#ifndef _SCHEDULER_
#define _SCHEDULER_

#define SCHED_LENGTH 20 // chnage to maybe 5

#include "Task.h"

// THE SCHEDULER CAN ONLY TAKE 20 ITEMS MAX, WE CAN CHANGE LATER,
// THIS SHOULD BE A FIXED SIZE, WE CAN DETERMINE SIZE BEFORE RUNTIME
// Items that will be scheduled: STATE, STORAGE, ... (items should be scheduled which can have/requrie independent running time)
// need to juggle execution time of functions with 
// time intervals
class Scheduler {
public:
    Scheduler();
    ~Scheduler(); 

    void add(Task *t);

    void execute();
private:
    Task *tasks[SCHED_LENGTH];
    int length;
};




#endif