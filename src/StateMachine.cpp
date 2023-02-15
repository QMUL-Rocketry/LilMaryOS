#include "StateMachine.h"

StateMachine::StateMachine() {
};

void StateMachine::end() {
    work.task->end();

    nextState->work = work;
    nextState->work.task->reuse(repetition::INFINITE, 500, nextState);
    nextState->setup();
    
    // nextState->work.task.
    // Task* t = new Task();
    // // Task *ptr = &t;
    // nextState->work.task = t;

};