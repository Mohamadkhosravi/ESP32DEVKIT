#include <Arduino.h>
// #include<BlouetoothServer.h>
#include<myWifi.h>



//BlouetoothServer myBLI; 
myWifi wifi ;
void setup(){
Serial.begin(9600);
// myBLI.setup();

//wifi.wifiSetup("AndroidAP54E7","12345678");
wifi.wifiSetup("mohamadkh","809236ML7368S");
wifi.WebServerSetup();

}
void loop() {
   //char my_massage[]="Hello word"; 
  // myBLI.sendMassage(my_massage);
  
   wifi.runWifi();
   wifi.WebServerRun();
   delay(200);
}



 
  


