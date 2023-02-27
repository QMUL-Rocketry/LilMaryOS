#include "../StateMachine.h"

class Start : public StateMachine {
    void calibrateSensors();
    void displayErrorMessage();
    void run();
    void setup();
};

