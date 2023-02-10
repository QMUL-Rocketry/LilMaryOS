#ifndef _SCHEDULER_
#define _SCHEDULER_

#include "Task.h"

// need to juggle execution time of functions with 
// time intervals
class Scheduler {
public:
    Scheduler();
    ~Scheduler(); 

    void add(Task *t);

    void execute();

    Task *tasks[10];
    int length;
};




#endif