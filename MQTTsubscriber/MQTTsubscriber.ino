#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define ldr A0
#define wifi "K6"
#define pass "11111111"
#define server "io.adafruit.com"
#define prt 1883
#define usern "ksanthosh95"
#define key "946b636e44ab42f0857fbe289aa3cf71"

WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server,prt,usern,key);

Adafruit_MQTT_Subscribe photocell = Adafruit_MQTT_Subscribe(&mqtt,usern"/feeds/photocell");

int led=16;
void setup() {
pinMode(led,OUTPUT);
Serial.begin(115200);
delay(10);
Serial.println("Adafruit MQTT demo");
Serial.println("Connecting to");
Serial.println(wifi);

WiFi.begin(wifi,pass);
while(WiFi.status()!=WL_CONNECTED)
{
 delay(500);
 Serial.print("*"); 
}
Serial.println("Wifi Connected");
Serial.println("IP Address: ");
Serial.println(WiFi.localIP());
mqtt.subscribe(&photocell);
Serial.println("Cennected to MQTT");

while(mqtt.connect())
{ 
  delay(500);
  Serial.print(".");
}
}
void loop() {
while(mqtt.readSubscription(5000))
{
  Serial.print("Got:  ");
  Serial.print((char *)photocell.lastread);
  int a = atoi((char *)photocell.lastread);
  Serial.print(" ");
  Serial.println(a);
  
  if(a>620)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}}
