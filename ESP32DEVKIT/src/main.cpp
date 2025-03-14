#include <Arduino.h>
#include<myWifi.h>
#define LED 2
myWifi wifi("mohamadkh","809236ML7368S");
void setup() {
Serial.begin(9600); 
wifi.wifiSetup();
wifi.runWifi();
pinMode(LED,OUTPUT);
}

void loop() {
  
  wifi.getInfo();
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  // put your main code here, to run repeatedly:
}
