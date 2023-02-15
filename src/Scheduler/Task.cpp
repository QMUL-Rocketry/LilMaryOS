#include "Task.h"

Task::Task(unsigned long i, void (*FuncPtr)()) {
    method = FuncPtr;
    interval = i;
    // we dont define repetitions as we are gonna assume its gonna run forever unless turned off
    // rep = repetition::INFINITE;
};

Task::Task(repetition r, unsigned long i, void (*FuncPtr)()) {
    method = FuncPtr;
    interval = i;
    rep = r;
};

// Task::Task(repetition r, unsigned long i, void (*FuncPtr)(), Scheduler *sch) {
//     method = FuncPtr;
//     interval = i;
//     rep = r;
//     sch->add(this);
// };

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
            (*method)();
        }
    }
};

void Task::runWithTime() {
    unsigned long cur = millis();
    run();
    st.average += millis() - cur;
    st.iterations++;
};