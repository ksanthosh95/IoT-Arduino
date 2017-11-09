#include <ESP8266WebServer.h>

ESP8266WebServer server;

const char usern[]="Team45";
const char passw[]="11111111";
int val;
void setup() {
pinMode(16,OUTPUT);//Declared:pin 13 for output
Serial.begin(115200);//Baud rate bps
WiFi.softAP(usern,passw);
IPAddress myIP=WiFi.softAPIP();
Serial.print("AP IP Address: ");
Serial.println(myIP);
server.begin();
server.on("/ESP8266",led);
server.on("/Check",check);
}
void loop() {
server.handleClient();
}
void led()
{
  String myhtml="<!DOCTYPE html><html><head><title>MyFirstIOT</title></head><body style=\"background-color: orange\"><H1><center>IOT</center></H1><H2><center>Board ON/OFF</center></H2><H3><center>NODE MCU</center></H3><form><center><button type=\"submit\" name=\"State\" value=\"1\">LED OFF</button><button type=\"submit\" name=\"State\" value=\"0\">LED ON</button></form></center></body></html>";
  server.send(200,"text/html",myhtml);
  if(server.arg("State")=="1")
  {
    digitalWrite(16,HIGH);
    val=1;
  }
else
{
  digitalWrite(16,LOW);
  val=0;
}
}
void check()
{
  if(val==0)
  server.send(200,"text/html","torchon");
  else
  server.send(200,"text/html","torchoff");  
}

