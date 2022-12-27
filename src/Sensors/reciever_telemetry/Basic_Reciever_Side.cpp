// /* 
//  *  Receiver Side Code
//  * 
//   Module SX1278 // Arduino UNO/NANO    
//     Vcc         ->   3.3V
//     MISO        ->   D12
//     MOSI        ->   D11     
//     SLCK        ->   D13
//     Nss         ->   D10
//     GND         ->   GND
//  */

// #include <SPI.h>
// #include <LoRa.h>  
// String inString = "";    // string to hold incoming charaters
// String MyMessage = ""; // Holds the complete message

// void setup() {
//   Serial.begin(9600);
 
//   while (!Serial);
//   Serial.println("LoRa Receiver");
//   if (!LoRa.begin(868E6)) { // transmission frequency at 868 MHz
//     Serial.println("Starting LoRa failed!");
//     while (1);
//   }
// }

// void loop() {
  
//   // try to parse packet
//   int packetSize = LoRa.parsePacket();
//   if (packetSize) { 
//     // read packet    
//     while (LoRa.available())
//     {
//       int inChar = LoRa.read();
//       inString += (char)inChar;
//       MyMessage = inString;       
//     }
//     inString = "";     
//     LoRa.packetRssi();    
//   }
      
//   Serial.println(MyMessage);  
  
// }