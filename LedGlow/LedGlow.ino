void setup() {
  // put your setup code here, to run once:
pinMode(16,OUTPUT);//Declared:pin 13 for output
Serial.begin(115200);//Baud rate bps
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(16,LOW);//pin 13 in use
Serial.println("LED ON");
}
