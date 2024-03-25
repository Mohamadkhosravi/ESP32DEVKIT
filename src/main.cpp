#include <Arduino.h>
// #include<BlouetoothServer.h>
#include<myWifi.h>
#include<ArduinoJson.h>




//BlouetoothServer myBLI; 
myWifi wifi ;
void setup(){
Serial.begin(9600);
// myBLI.setup();

//wifi.wifiSetup("AndroidAP54E7","12345678");
wifi.wifiSetup("mohammad","79006944805L8s#");
//wifi.wifiSetup("mohamadkh","809236ML7368S");
wifi.WebServerSetup();

}

 char adress[65] = "https://holidayapi.ir/jalali/{year}}/{month}/{day}";
void loop() {
   //char my_massage[]="Hello word"; 
  // myBLI.sendMassage(my_massage);
  String APIReding="";
   wifi.runWifi();
   wifi.WebServerRun();
     APIReding = wifi.HTPPGetReguste(adress);
      Serial.println(APIReding);
   delay(200);
   
}



 
  


