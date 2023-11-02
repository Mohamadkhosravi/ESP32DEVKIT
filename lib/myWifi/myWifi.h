
#ifndef _MY_WIFI_H
#define _MY_WIFI_H
#include <Arduino.h>
#include<WiFi.h>
#include<WiFiClient.h>

#define TIME_OUT_WIFI_SETUP 1000 //ms
//fd.wifiSetup("AndroidAP54E7","12345678");
class myWifi
{
private:
    /* data */
public :
    
 bool wifiSetup(char *userName,char *pasword);
 void runWifi(void);
    
   
};





#endif
