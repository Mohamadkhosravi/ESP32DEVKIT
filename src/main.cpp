#include <Arduino.h>
#include<BlouetoothServer.h>
BlouetoothServer myBLI; 
void setup(){
Serial.begin(115200);
myBLI.setup();

}
void loop() {
   char my_massage[]="Hello word"; 
   myBLI.sendMassage(my_massage);
 

}



 
  


