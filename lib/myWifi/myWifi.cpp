#include <myWifi.h>

WebServer server(80);
bool myWifi::wifiSetup(char *userName, char *pasword)
{
  unsigned long timeOut;
  timeOut = millis();
  // WiFi.begin("AndroidAP54E7", "12345678");
  WiFi.begin(userName, pasword);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    if (millis() - timeOut >= TIME_OUT_WIFI_SETUP)
      return false;
  }
  return true;
}

void myWifi::runWifi(void)
{
  //WiFi.mode(WIFI_STA);
  //  String IP="wifi DNS IP is";
  //  Serial.println(IP);
  //  Serial.println(WiFi.localIP());
  //  Serial.printf("wifi macAddress IP is = %d \n", (WiFi.macAddress()));
}
void myWifi::WebServerSetup(void)
{
  // server.send(200, "text/html", "<!DOCTYPE html><html><head> <title>Hello World ESP Web Server</title></head><body><h1>Hello World!</h1><p>This is a basic HTML page served by an ESP web server.</p></body></html>");

  // String webSite = "<!DOCTYPE html><html><head><title>Page Title</title></head><body style='background-color: #EEEEEE;'><span style='color: #003366;'><h1>Lets generate a random number</h1><p>The random number is: </p></span></body></html>";

  server.begin();
  // server.handleClient();
}
void myWifi::WebServerRun(void)
{
  String pullServer;
  server.handleClient();
  WiFiClient client = server.client();
  if (client)
  {
    if (server.method() == HTTP_GET)
    {

      // server.send(200, "text/html", SendHTML(0, 0));

      // server.send(200, "text/html", "<!DOCTYPE html><html><head><title>Hello World ESP Web Server</title></head><body><h1>Hello World!</h1><p>This is a basic HTML page served by an ESP web server.</p></body></html>");
      // server.send(200, "text/plain", "Hello from ESP32!");
    }
    String value = server.arg("data");
    Serial.println(value);
  }
}

String myWifi::SendHTML(uint8_t led1stat, uint8_t led2stat)
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #3498db;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server</h1>\n";
  ptr += "<h3>Using Access Point(AP) Mode</h3>\n";

  if (led1stat)
  {
    ptr += "<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
  }
  else
  {
    ptr += "<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";
  }

  if (led2stat)
  {
    ptr += "<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";
  }
  else
  {
    ptr += "<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";
  }

  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
void myWifi::handle_OnConnect()
{
}
String myWifi::HTPPGetReguste(char *ServerName)
{
  HTTPClient http;
  http.begin(ServerName);
  String payload = "{}";
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  return payload;
}

// void handle_led1on() {
//   LED1status = HIGH;
//   Serial.println("GPIO4 Status: ON");
//   server.send(200, "text/html", SendHTML(true,LED2status));
// }

// void handle_led1off() {
//   LED1status = LOW;
//   Serial.println("GPIO4 Status: OFF");
//   server.send(200, "text/html", SendHTML(false,LED2status));
// }

// void handle_led2on() {
//   LED2status = HIGH;
//   Serial.println("GPIO5 Status: ON");
//   server.send(200, "text/html", SendHTML(LED1status,true));
// }

// void handle_led2off() {
//   LED2status = LOW;
//   Serial.println("GPIO5 Status: OFF");
//   server.send(200, "text/html", SendHTML(LED1status,false));
// }

// void handle_NotFound(){
//   server.send(404, "text/plain", "Not found");
// }