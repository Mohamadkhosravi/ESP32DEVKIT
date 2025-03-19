#include <Arduino.h>
#include<myWifi.h>
#include <WiFiClientSecure.h>
#include<HTTPClient.h>

#define LED 2
myWifi wifi("mohammad","79006944805L8S#");
HTTPClient http;
WiFiClientSecure client;
unsigned long   lastTime=0;
//String serverName = "https://holidayapi.ir/gregorian/{1394}}/{10}/{10}";
String serverName = "https://timeapi.io/api/time/current/zone?timeZone=Europe%2FAmsterdam";
void setup() {
Serial.begin(9600); 
wifi.wifiSetup();
wifi.runWifi();
client.setInsecure(); 
pinMode(LED,OUTPUT);
lastTime=millis();
}

void loop() {
  if(millis() - lastTime > 10000){

    lastTime=millis();
    if (WiFi.status() == WL_CONNECTED) { 
      wifi.getInfo();
      http.begin(client, serverName);  
      int httpResponseCode = http.GET(); 
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      if (httpResponseCode > 0) {
        String payload = http.getString(); 
        Serial.println("Payload:");
        Serial.println(payload);
      } else {
        Serial.print("Error: ");
        Serial.println(http.errorToString(httpResponseCode));
      }

      http.end(); 
    } else {
      Serial.println("WiFi Disconnected");
    }
  } 
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
 
  
}
