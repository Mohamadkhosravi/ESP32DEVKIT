
#include<myWifi.h>

bool myWifi::wifiSetup(char *userName,char *pasword)
{
    unsigned long timeOut;
    timeOut=millis();
    //WiFi.begin("AndroidAP54E7", "12345678");
    WiFi.begin(userName, pasword);
    while (WiFi.status() != WL_CONNECTED)
    {
    Serial.println(".");
    if (millis()-timeOut>=TIME_OUT_WIFI_SETUP)return false;
    }
    return true;
}


void myWifi::runWifi(void)
{


Serial.printf("wifi DNS IP is = %d \n",(WiFi.dnsIP()));
Serial.printf("wifi macAddress IP is = %d \n",(WiFi.macAddress()));


}
