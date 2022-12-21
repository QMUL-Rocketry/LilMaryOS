#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Create a BMP280 object

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1) {
      ; // loop forever
    }
  }
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" m");

  Serial.println();
  delay(2000);
}
