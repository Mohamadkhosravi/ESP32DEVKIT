
#ifndef _MY_WIFI_H
#define _MY_WIFI_H
#include <Arduino.h>
#include<WiFi.h>
#include<WiFiClient.h>

class myWifi
{
private:
    /* data */
public:
    void wifiBegin(void)
    {
     unsigned long timeOut;
     timeOut=millis();
     WiFi.begin("AndroidAP54E7", "12345678");
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.println(".");
        if (millis()-timeOut>=9000)break;
        }
  }
    bool runWifi(void)
    {


   Serial.printf("wifi DNS IP is = %d \n",(WiFi.dnsIP()));
   Serial.printf("wifi macAddress IP is = %d \n",(WiFi.macAddress()));


    }

   
};






#endif
