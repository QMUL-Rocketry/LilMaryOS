/* 
 * Sensor Monitoring using Arduino and LoRa SX1278 Module, receiver code
 * 
  Module SX1278 // Arduino UNO/NANO    
    Vcc         ->   3.3V
    MISO        ->   D12
    MOSI        ->   D11     
    SLCK        ->   D13
    Nss         ->   D10
    GND         ->   GND 
 */

#include <SPI.h>
#include <LoRa.h>  
String inString = "";    // string to hold incoming input
int val = 0;

void setup() {
  Serial.begin(9600);
  
  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(868E6)) { // transmission frequency at 868 MHz
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) { 
    // read packet    
    while (LoRa.available())
    {
      int inChar = LoRa.read();
      inString += (char)inChar;
      val = inString.toInt();      //Converting the incoming data to int
    }
    inString = "";     
    LoRa.packetRssi();    
  }
  Serial.print("POT:");    
  Serial.println(val);  

}