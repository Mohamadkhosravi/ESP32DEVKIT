
#ifndef _MY_WIFI_H
#define _MY_WIFI_H
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
// #include <WebSockets.h>
// #include<ArduinoJson.h>
#define TIME_OUT_WIFI_SETUP 1000 // ms
// fd.wifiSetup("AndroidAP54E7","12345678");
typedef enum {
    CONNECTED,
    DISCONNECTED
 }connection_t;
class myWifi
{
private:
const char *USERNAME="admin";
const char *PASSWORD="admin";
    /* data */
    connection_t wifiConnection ;
public:

    myWifi(const char *UserName,const char *Password):USERNAME(UserName),PASSWORD(Password){};
    bool wifiSetup(void);
    void runWifi(void);
    void WebServerSetup(void);
    void WebServerRun(void);
    String SendHTML(uint8_t led1stat,uint8_t led2stat);
    void getInfo(void);
    void handle_OnConnect();
    connection_t ConnectionStatus(void);
};

// void handle_led1on();
// void handle_led1off();
// void handle_led2on();
// void handle_led2off();
// void handle_NotFound();
#endif
