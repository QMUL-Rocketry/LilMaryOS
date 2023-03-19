#include "Scheduler.h"

Scheduler::Scheduler() {
    length = 0;
};

Scheduler::~Scheduler(){};

// need to adjsut for nullptrs
// must adapt to a queue
// void Scheduler::add(Task *t) {
void Scheduler::add(Task *t) {
    if (length == SCHED_LENGTH) {
        return;
    }
    tasks[length] = t;
    length++;
};

void Scheduler::execute() {
    for(int i = 0; i<length; i++) {
        
        if(tasks[i] == nullptr) {
            break;
        }

        if(!(tasks[i]->checkEnd())){
            tasks[i]->run();
        } else {
            tasks[i] = nullptr;
        }
       
    }
};