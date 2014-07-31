/*
 Are-We-Open
 This scripts checks if we are open, and can also be used to read temprature and humidity 
 
 The DHT library used can be found here: http://playground.arduino.cc/Main/DHTLib
 
 Author: Ward De Ridder (github - at - warddr - dot - eu)
 
 commands:
 s = space status (0 or 1)
 1 = temperature & humidity sensor 2 (temperature;humidity)
*/

#define AreWeOpen 4
#define DHT22_PIN 2
#define DHT22_lounge 3

#include <dht.h>

dht DHT;


void setup() {
  Serial.begin(9600);
  pinMode(AreWeOpen, OUTPUT); //dit is geen vergissing deze werkt veel beter
}

void loop() {
  if (Serial.available() > 0) {
     int inputrequest = Serial.read();
     //Serial.println(inputrequest); //debug
     if (inputrequest == 115){ // s
       int spaceStatus = digitalRead(AreWeOpen);
       Serial.println(spaceStatus); //print een 1 als we open zijn, en een 0 als we gesloten zijn
     }
     if (inputrequest == 49){ // 1
          int chk = DHT.read22(DHT22_PIN);
          switch (chk)
          {
            case DHTLIB_OK:  //CRC check is in orde
                        Serial.print(DHT.temperature);
                        Serial.print("-");
                        Serial.print(DHT.humidity);
                        Serial.print("-");
                        break;
            default:
        		Serial.println("0-0-"); //check failed
          }

          //lounge
          chk = DHT.read22(DHT22_lounge);
          switch (chk)
          {
            case DHTLIB_OK:  //CRC check is in orde
                        Serial.print(DHT.temperature);
                        Serial.print("-");
                        Serial.println(DHT.humidity);
                        break;
            default:
        		Serial.println("0-0"); //check failed
          }
     }
  }
  
}
