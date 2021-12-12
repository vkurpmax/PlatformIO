/*
 Tolong jika menggunakan source code ini cantumkan :
 di buat oleh Ogi Sinatra
 dan di Upload https://www.youtube.com/atmoproduction_id
 
 ESP8266 NodeMCU LED Control over WiFi

 BERLANGGANAN GRATIS di AT-MO PRODUCTION
 https://goo.gl/M28DcR
 */

 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>

//---------------------------------------------------------------
//HTML CODE
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>WiFi LED on off versi AT-MO PRODUCTION</h1><br>
Tekan untuk <a href="ledOn" target="myIframe">LED ON</a><br>
Tekan untuk <a href="ledOff" target="myIframe">LED OFF</a><br>
LED dalam keadaan :<iframe name="myIframe" width="100" height="25" frameBorder="0"><br>

</center>

</body>
</html>
)=====";
//---------------------------------------------------------------


//menggunakan pin GPIO2 yang terhubung langsung dengan led di nodemcu
#define LED 2 
#define RELAY1 0 // pin yang di gunakan GPIO0 

//SSID and Password of your WiFi router
const char* ssid = "ganti WIFI kamu"; // WAJIB DI GANTI
const char* password = "ganti pass wifi kamu"; // WAJIB DI GANTI

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 Serial.println("You called root page");
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleLEDon() { 
 Serial.println("LED on page");
 digitalWrite(LED,LOW); //LED is connected in reverse
 digitalWrite(RELAY1,LOW);
 server.send(200, "text/html", "ON"); //Send ADC value only to client ajax request
 delay(20);
}

void handleLEDoff() { 
 Serial.println("LED off page");
 digitalWrite(LED,HIGH); //LED off
 digitalWrite(RELAY1,HIGH);
 server.send(200, "text/html", "OFF"); //Send ADC value only to client ajax request
 delay(20);
}


void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);       //Terhubung dengan WIFI router
  Serial.println("");

  //Onboard LED port Direction output
  pinMode(LED,OUTPUT); 
  //Power on LED state off
  digitalWrite(LED,HIGH);

  pinMode(RELAY1,OUTPUT);
  digitalWrite(RELAY1,HIGH);

  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Jika berhasil maka IP address akan di tampilkan di serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/ledOn", handleLEDon); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff", handleLEDoff);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
