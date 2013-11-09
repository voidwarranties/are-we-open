/*
 Are-We-Open
 This scripts checks if we are open, and can also be used to read temprature and humidity 
 
 The DHT library used can be found here: http://playground.arduino.cc/Main/DHTLib
 
 Author: Ward De Ridder (github - at - warddr - dot - eu)
 
 commands:
 t = temprature
 h = humidity
 s = spacestatus
 */

#define AreWeOpen 4
#define DHT22_PIN 2

#include <dht.h>

dht DHT;



void setup() {
  Serial.begin(9600);
  pinMode(AreWeOpen, OUTPUT); //dit is geen vergissing deze werkt veel beter
}

void loop() {
  if (Serial.available() > 0) {
     int inputrequest = Serial.read();
     if (inputrequest == 115){ // s
       int spaceStatus = digitalRead(AreWeOpen);
       Serial.println(spaceStatus); //print een 1 als we open zijn, en een 0 als we gesloten zijn
     }
     if (inputrequest == 116){ // t
          int chk = DHT.read22(DHT22_PIN);
          switch (chk)
          {
            case DHTLIB_OK:  
                        Serial.println(DHT.temperature); //CRC check is in orde
                        break;
            default: 
        		Serial.println(0); //check failed
          }

     }
     if (inputrequest == 104){ // h
          int chk = DHT.read22(DHT22_PIN);
          switch (chk)
          {
            case DHTLIB_OK:  
                        Serial.println(DHT.humidity); //CRC check is in orde
                        break;
            default: 
        		Serial.println(0); //check failed
          }

     }
  }
  
}



