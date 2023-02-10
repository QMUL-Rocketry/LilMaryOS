#include "Scheduler.h"

Scheduler::Scheduler() {
    // init tasks
    length = 0;
};

Scheduler::~Scheduler(){};

void Scheduler::add(Task *t) {
    if (length == 10) {
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
        tasks[i]->run();
    }
};