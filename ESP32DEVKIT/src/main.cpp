#include <Arduino.h>
#include<myWifi.h>
#include <WiFiClientSecure.h>
#include<HTTPClient.h>

#define LED 2
myWifi wifi("mohammad","79006944805L8S#");
HTTPClient http;
WiFiClientSecure client;
//String serverName = "https://holidayapi.ir/gregorian/{1394}}/{10}/{10}";
String serverName = "https://timeapi.io/api/time/current/zone?timeZone=Europe%2FAmsterdam";
void setup() {
Serial.begin(9600); 
wifi.wifiSetup();
wifi.runWifi();
client.setInsecure(); 
pinMode(LED,OUTPUT);

}

void loop() {
  http.begin(serverName.c_str());
  wifi.getInfo();
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  int httpResponseCode = http.GET();
   Serial.println(httpResponseCode);  
   if (WiFi.status() == WL_CONNECTED) {
    http.begin(client, serverName);

    int httpResponseCode = http.GET();
    Serial.println(httpResponseCode);

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Errore ");
      Serial.println(http.errorToString(httpResponseCode));
    }
     http.end();
  } else {
    Serial.println("WiFi Error");
  }
 
  // put your main code here, to run repeatedly:
}
