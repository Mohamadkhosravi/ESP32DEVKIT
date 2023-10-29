#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#define   LED  2

bool wifisetup(void);
void setup() {
  //pinMode(10, OUTPUT);
  Serial.begin(9600);
  WiFi.begin("AndroidAP54E7", "12345678");
  pinMode(LED,OUTPUT);
 //wifi setup
 while (WiFi.status() != WL_CONNECTED)
  {

    Serial.println(".");
     
  }
 
  // put your setup code here, to run once:
}

void loop() {
  wifisetup();
  
}
bool wifisetup(void) {

digitalWrite(LED,HIGH);
  delay(1000);
   digitalWrite(LED,LOW);
   delay(1000);
   Serial.printf("wifi DNS IP is = %d \n",(WiFi.dnsIP()));
  Serial.printf("wifi macAddress IP is = %d \n",(WiFi.macAddress()));
  // put your main code here, to run repeatedly:



}