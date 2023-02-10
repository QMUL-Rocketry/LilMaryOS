#include "Task.h"

Task::Task(unsigned long i, void (*FuncPtr)()) {
    method = FuncPtr;
    interval = i;
};

Task::Task() {};

Task::~Task(){};

void Task::run() {
    unsigned long current = millis();
    // Serial.println(current);
    if (current - last_executed >= interval) {
        last_executed = current;
        (*method)();
        // Serial.println(interval);
    }
};