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

Adafruit_MQTT_Publish photocell = Adafruit_MQTT_Publish(&mqtt,usern"/feeds/photocell");

void setup() {
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
Serial.println("Cennected to MQTT");
while(mqtt.connect())
{ 
  Serial.print(".");
}
}
void loop() {
if(mqtt.connected())
{
  int data=analogRead(ldr);
  Serial.print("\nSending LDR val");
  Serial.print(data);
  Serial.print("...");
  if(photocell.publish(data))
  {
    Serial.println("Success");
  }
  else
  {
    Serial.println("UnSuccess");
  }
  delay(800);
}
}
