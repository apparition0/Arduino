#include <SoftwareSerial.h>

SoftwareSerial BTSerial(5,4); // RX | TX
#define KEY 3
unsigned long mm;
unsigned long interval = 1000;
bool on = false;
int c;

void setup()
{
  pinMode(KEY, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(KEY, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  //BTSerial.begin(9600);  // HC-05 default speed in AT command more
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  pinMode(13,OUTPUT);
  mm = millis();
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
  {
    digitalWrite(13,HIGH);
    c = BTSerial.read();
    Serial.write("[");
    Serial.write(c);
    Serial.write("]");
    digitalWrite(13,LOW);
  }

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    c = Serial.read();
    BTSerial.write(c);
    Serial.write("(");
    Serial.write(c);
    Serial.write(")");
  }
}  

