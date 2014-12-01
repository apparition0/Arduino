#include "Include.h"


void Console::init()
{
  Serial.begin(9600);
  pinMode(REDPIN,OUTPUT);
}

void Console::print(char *str)
{
  Serial.print(str);
}
void Console::println(char *str)
{
  Serial.println(str);
}
void Console::print(char c)
{
  Serial.print(c);
}
void Console::redOn() {digitalWrite(REDPIN,HIGH);}
void Console::redOff() {digitalWrite(REDPIN,LOW);}
void Console::greenOn() {digitalWrite(GREENPIN,HIGH);}
void Console::greenOff() {digitalWrite(GREENPIN,LOW);}
void Console::blueOn() {digitalWrite(BLUEPIN,HIGH);}
void Console::blueOff() {digitalWrite(BLUEPIN,LOW);}
void Console::allOn() 
{
  blueOn();
  greenOn();
  redOn();
  
}
void Console::allOff()
{
  redOff();
  greenOff();
  blueOff();
}
