#include "../StateMachine.h"

class Ascends : public StateMachine {

    virtual void setup() {
        /*
        Data needed: Rocket must have taken off 
        ->> check motor acceleration is > 0 and continuing
        (i.e. is ascending and getting faster)

        When Ascending motion is confirmed, move on to run();

        */
    };

    virtual void run() {
        /*
        Currently implementing: Ascends

        Need to constantly check altitiude ->> call HEIGHT function
        (altitude must be from SEA LEVEL)
        ->> use STRUCT content (Apogee *height)

        When acceleration < 0 -> stop motor

        Proceed to Next State (StateMaching *nextSTate) -> Coasts
        */
    };


};

