#include "gps.h"

GPS::GPS(){
    ss.begin(GPSBaud);
    delay(5000); // Remove?
};

GPS::GPS(int RX, int TX){
    ss = SoftwareSerial(RX, TX);
    GPS();   
};

GPS::~GPS(){};

void GPS::displayInfo(){

  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
};

void GPS::checkGPSDetected(){

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    // while(true); // don't want code to hang, need to implement safety/passthrough feature
  }

};

void GPS::viewRead(unsigned long delay) {

  while (ss.available() > 0){
    if (gps.encode(ss.read())){
        displayInfo();
    }
  }
    // smartDelay(delay);
    
    // IMPLEMENTATION IS NOT FINISHED
    checkGPSDetected();

};

// This custom version of delay() ensures that the gps object
// is being "fed".
void GPS::smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}


// TinyPlusPlus IMPLEMENTATION OF SOMETHING

// #include <Arduino.h>
// #include <TinyGPSPlus.h>
// #include <SoftwareSerial.h>

// static const int RXPin = 0, TXPin = 1;
// static const uint32_t GPSBaud = 9600;

// static void smartDelay(unsigned long ms);
// static void printFloat(float val, bool valid, int len, int prec);
// static void printDateTime(TinyGPSDate &d, TinyGPSTime &t);
// static void printInt(unsigned long val, bool valid, int len);
// static void printStr(const char *str, int len);
// void displayInfo();

// // The TinyGPSPlus object
// TinyGPSPlus gps;

// // The serial connection to the GPS device
// SoftwareSerial ss(RXPin, TXPin);

// void setup()
// {
//   Serial.begin(115200);
//   ss.begin(GPSBaud);

//   Serial.println(F("Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
//   Serial.println(F("           (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
//   Serial.println(F("----------------------------------------------------------------------------------------------------------------------------------------"));
// }

// void loop()
// {
//   // This sketch displays information every time a new sentence is correctly encoded.
//   while (ss.available() > 0)
//     if (gps.encode(ss.read()))
//       displayInfo();

//   if (millis() > 5000 && gps.charsProcessed() < 10)
//   {
//     Serial.println(F("No GPS detected: check wiring."));
//     while(true);
//   }
// }


// void loop()
// {
//   static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;

//   printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
//   printFloat(gps.hdop.hdop(), gps.hdop.isValid(), 6, 1);
//   printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
//   printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
//   printInt(gps.location.age(), gps.location.isValid(), 5);
//   printDateTime(gps.date, gps.time);
//   printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
//   printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
//   printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
//   printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : "*** ", 6);

//   unsigned long distanceKmToLondon =
//     (unsigned long)TinyGPSPlus::distanceBetween(
//       gps.location.lat(),
//       gps.location.lng(),
//       LONDON_LAT, 
//       LONDON_LON) / 1000;
//   printInt(distanceKmToLondon, gps.location.isValid(), 9);

//   double courseToLondon =
//     TinyGPSPlus::courseTo(
//       gps.location.lat(),
//       gps.location.lng(),
//       LONDON_LAT, 
//       LONDON_LON);

//   printFloat(courseToLondon, gps.location.isValid(), 7, 2);

//   const char *cardinalToLondon = TinyGPSPlus::cardinal(courseToLondon);

//   printStr(gps.location.isValid() ? cardinalToLondon : "*** ", 6);

//   printInt(gps.charsProcessed(), true, 6);
//   printInt(gps.sentencesWithFix(), true, 10);
//   printInt(gps.failedChecksum(), true, 9);
//   Serial.println();
  
//   smartDelay(1000);

//   if (millis() > 5000 && gps.charsProcessed() < 10)
//     Serial.println(F("No GPS data received: check wiring"));
// }

// static void printFloat(float val, bool valid, int len, int prec)
// {
//   if (!valid)
//   {
//     while (len-- > 1)
//       Serial.print('*');
//     Serial.print(' ');
//   }
//   else
//   {
//     Serial.print(val, prec);
//     int vi = abs((int)val);
//     int flen = prec + (val < 0.0 ? 2 : 1); // . and -
//     flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
//     for (int i=flen; i<len; ++i)
//       Serial.print(' ');
//   }
//   smartDelay(0);
// }

// static void printInt(unsigned long val, bool valid, int len)
// {
//   char sz[32] = "*****************";
//   if (valid)
//     sprintf(sz, "%ld", val);
//   sz[len] = 0;
//   for (int i=strlen(sz); i<len; ++i)
//     sz[i] = ' ';
//   if (len > 0) 
//     sz[len-1] = ' ';
//   Serial.print(sz);
//   smartDelay(0);
// }

// static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
// {
//   if (!d.isValid())
//   {
//     Serial.print(F("********** "));
//   }
//   else
//   {
//     char sz[32];
//     sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
//     Serial.print(sz);
//   }
  
//   if (!t.isValid())
//   {
//     Serial.print(F("******** "));
//   }
//   else
//   {
//     char sz[32];
//     sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
//     Serial.print(sz);
//   }

//   printInt(d.age(), d.isValid(), 5);
//   smartDelay(0);
// }

// static void printStr(const char *str, int len)
// {
//   int slen = strlen(str);
//   for (int i=0; i<len; ++i)
//     Serial.print(i<slen ? str[i] : ' ');
//   smartDelay(0);
// }


// GPS Adafruit Library implementation

// Test code for Adafruit GPS modules using MTK3329/MTK3339 driver
//
// This code shows how to listen to the GPS module in an interrupt
// which allows the program to have more 'freedom' - just parse
// when a new NMEA sentence is available! Then access data when
// desired.
//
// Tested and works great with the Adafruit Ultimate GPS module
// using MTK33x9 chipset
//    ------> http://www.adafruit.com/products/746
// Pick one up today at the Adafruit electronics shop
// and help support open source hardware & software! -ada

// #include <Adafruit_GPS.h>
// #include <SoftwareSerial.h>

// // Connect the GPS Power pin to 5V
// // Connect the GPS Ground pin to ground
// // Connect the GPS TX (transmit) pin to Digital 8
// // Connect the GPS RX (receive) pin to Digital 7

// // you can change the pin numbers to match your wiring:
// SoftwareSerial mySerial(52, 53);
// Adafruit_GPS GPS(&mySerial);

// // Adafruit_GPS GPS(&Serial1); // WORKS

// // Set GPSECHO to 'false' to turn off echoing the GPS data to the Serial console
// // Set to 'true' if you want to debug and listen to the raw GPS sentences
// #define GPSECHO  true

// void setup()
// {

//   // connect at 115200 so we can read the GPS fast enough and echo without dropping chars
//   // also spit it out
//   Serial.begin(115200);
//   delay(5000);
//   Serial.println("Adafruit GPS library basic parsing test!");

//   // 9600 NMEA is the default baud rate for Adafruit MTK GPS's- some use 4800
//   GPS.begin(9600);

//   // uncomment this line to turn on RMC (recommended minimum) and GGA (fix data) including altitude
//   GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
//   // uncomment this line to turn on only the "minimum recommended" data
//   //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);
//   // For parsing data, we don't suggest using anything but either RMC only or RMC+GGA since
//   // the parser doesn't care about other sentences at this time

//   // Set the update rate
//   GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);   // 1 Hz update rate
//   // For the parsing code to work nicely and have time to sort thru the data, and
//   // print it out we don't suggest using anything higher than 1 Hz

//   // Request updates on antenna status, comment out to keep quiet
//   GPS.sendCommand(PGCMD_ANTENNA);

//   delay(1000);
//   // Ask for firmware version
//   // mySerial.println(PMTK_Q_RELEASE);
// }

// uint32_t timer = millis();
// void loop()                     // run over and over again
// {
//   char c = GPS.read();
//   // if you want to debug, this is a good time to do it!
//   if ((c) && (GPSECHO))
//     Serial.write(c);

//   // if a sentence is received, we can check the checksum, parse it...
//   if (GPS.newNMEAreceived()) {
//     // a tricky thing here is if we print the NMEA sentence, or data
//     // we end up not listening and catching other sentences!
//     // so be very wary if using OUTPUT_ALLDATA and trytng to print out data
//     //Serial.println(GPS.lastNMEA());   // this also sets the newNMEAreceived() flag to false

//     if (!GPS.parse(GPS.lastNMEA()))   // this also sets the newNMEAreceived() flag to false
//       return;  // we can fail to parse a sentence in which case we should just wait for another
//   }

//   // approximately every 2 seconds or so, print out the current stats
//   if (millis() - timer > 2000) {
//     timer = millis(); // reset the timer

//     Serial.print("\nTime: ");
//     if (GPS.hour < 10) { Serial.print('0'); }
//     Serial.print(GPS.hour, DEC); Serial.print(':');
//     if (GPS.minute < 10) { Serial.print('0'); }
//     Serial.print(GPS.minute, DEC); Serial.print(':');
//     if (GPS.seconds < 10) { Serial.print('0'); }
//     Serial.print(GPS.seconds, DEC); Serial.print('.');
//     if (GPS.milliseconds < 10) {
//       Serial.print("00");
//     } else if (GPS.milliseconds > 9 && GPS.milliseconds < 100) {
//       Serial.print("0");
//     }
//     Serial.println(GPS.milliseconds);
//     Serial.print("Date: ");
//     Serial.print(GPS.day, DEC); Serial.print('/');
//     Serial.print(GPS.month, DEC); Serial.print("/20");
//     Serial.println(GPS.year, DEC);
//     Serial.print("Fix: "); Serial.print((int)GPS.fix);
//     Serial.print(" quality: "); Serial.println((int)GPS.fixquality);
//     if (GPS.fix) {
//       Serial.print("Location: ");
//       Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
//       Serial.print(", ");
//       Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);

//       Serial.print("Speed (knots): "); Serial.println(GPS.speed);
//       Serial.print("Angle: "); Serial.println(GPS.angle);
//       Serial.print("Altitude: "); Serial.println(GPS.altitude);
//       Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
//       Serial.print("Antenna status: "); Serial.println((int)GPS.antenna);
//     }
//   }
// }