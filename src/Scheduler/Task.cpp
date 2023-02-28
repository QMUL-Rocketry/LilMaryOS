#include "Task.h"

Task::Task(repetition r, unsigned long i, RunMember *mem) {
    interval = i;
    member = mem;
    rep = r;
    enable();
}

// assume it's going to be repeated again and again
Task::Task(unsigned long i, RunMember *mem) {
    interval = i;
    member = mem;
    rep = repetition::INFINITE;
    enable();
}

Task::Task(unsigned long i, void (*FuncPtr)()) {
    method = FuncPtr;
    interval = i;
    // we dont define repetitions as we are gonna assume its gonna run forever unless turned off
    rep = repetition::INFINITE;
    enable();
};

Task::Task(repetition r, unsigned long i, void (*FuncPtr)()) {
    method = FuncPtr;
    interval = i;
    rep = r;
    enable();
};

Task::Task() {};

Task::~Task(){};

void Task::enable() {isEnabled = true;};
void Task::disable() {isEnabled = false;};
void Task::end() {isEnabled = false; isEnd = true;};
bool Task::checkEnd() {return isEnd;};

void Task::run() {
    if(isEnabled && !isEnd) {
        unsigned long current = millis();
        if (current - last_executed >= interval) {
            last_executed = current;
            if (member != nullptr) {
                member->run();
            } else {
                (*method)();
            }
            
        }
    }
};

void Task::runWithTime() {
    unsigned long cur = millis();
    run();
    st.average += millis() - cur;
    st.iterations++;
};