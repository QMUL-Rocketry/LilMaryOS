#include "imu.h"

IMU::IMU(int32_t id, uint8_t add){
    bno = Adafruit_BNO055(id, add, &Wire);
    bno.getSensor(&sensor);
};

IMU::~IMU(){};

void IMU::printSensorInformation(){
    Serial.println("------------------------------------");
    Serial.print  ("Sensor:       "); Serial.println(sensor.name);
    Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
    Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
    Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" xxx");
    Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" xxx");
    Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" xxx");
    Serial.println("------------------------------------");
    Serial.println("");
    delay(500);
};

void IMU::printSensorStatus() {
  /* Get the system status values (mostly for debugging purposes) */
  uint8_t system_status, self_test_results, system_error;
  system_status = self_test_results = system_error = 0;
  bno.getSystemStatus(&system_status, &self_test_results, &system_error);

  /* Display the results in the Serial Monitor */
  Serial.println("");
  Serial.print("System Status: 0x");
  Serial.println(system_status, HEX);
  Serial.print("Self Test:     0x");
  Serial.println(self_test_results, HEX);
  Serial.print("System Error:  0x");
  Serial.println(system_error, HEX);
  Serial.println("");
  delay(500);
};

void IMU::refreshSensorInformation() {
    bno.getSensor(&sensor);
};

sensors_event_t IMU::getSensorEvent() {
    bno.getEvent(&event);
    return event;
}

/**************************************************************************/
/*
    Display sensor calibration status
*/
/**************************************************************************/
void IMU::displayCalStatus()
{
  /* Get the four calibration values (0..3) */
  /* Any sensor data reporting 0 should be ignored, */
  /* 3 means 'fully calibrated" */
  uint8_t system, gyro, accel, mag;
  system = gyro = accel = mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);

  /* The data should be ignored until the system calibration is > 0 */
  Serial.print("\t");
  if (!system)
  {
    Serial.print("! ");
  }

  /* Display the individual values */
  Serial.print("Sys (3 means calibrated):");
  Serial.print(system, DEC);
  Serial.print(" Gyro:");
  Serial.print(gyro, DEC);
  Serial.print(" Accel:");
  Serial.print(accel, DEC);
  Serial.print(" Mag:");
  Serial.print(mag, DEC);
}

