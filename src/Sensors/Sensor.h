/**
 * @author Ahnaf Khalique
*/

#ifndef SENSOR
#define SENSOR

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

class Sensor {
    public:
        // virtual sensor_t getSensorInformation() = 0;
        virtual sensors_event_t getSensorEvent() = 0;
    protected:
        sensor_t sensor;
        sensors_event_t event;
};



#endif