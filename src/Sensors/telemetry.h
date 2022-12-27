#ifndef TELEMETRY
#define TELEMETRY

#include <LoRa.h>

class Telemetry {
    public:
        // 868E6 Transmission frequency at 868 MHz
        Telemetry(double freq);
        Telemetry() = default;
        ~Telemetry();
        void transmit(int val);
    private:
        LoRaClass lr;
        void setPinMode(int pot);
};


#endif