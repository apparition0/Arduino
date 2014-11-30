#include <stdio.h>

int i;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.print("started\n");
  Serial.print("() from GSM to Console\n");
  Serial.print("[] from Console to GSM\n");
  
}

void loop()
{
  char b=0;

  if(Serial1.available())
  {
    b = Serial1.read();
      //Serial.print("(");
      Serial.print(b);
      //Serial.print(")");
      i++;
  }
  if(Serial.available())
  {
    b = Serial.read();
    //Serial.print("[");
    Serial1.print(b);
    //Serial.print("]");
  }
  if(b==10)
  {
    Serial.print(" i=");
    Serial.print(i);
    Serial.print("\n");
    i=0;
  }
}
