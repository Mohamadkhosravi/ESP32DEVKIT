#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#define   LED  2


void setup() {
  //pinMode(10, OUTPUT);
  Serial.begin(9600);
  WiFi.begin("AndroidAP54E7", "12345678");
  pinMode(LED,OUTPUT);
  // put your setup code here, to run once:
 // Serial.printf("status%s", WiFi.status);
 while (WiFi.status() != WL_CONNECTED)
  {

    Serial.println(".");
     
  }
 
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(1000);
   digitalWrite(LED,LOW);
   delay(1000);
  // put your main code here, to run repeatedly:
}