#include <stdio.h>

#define ARRAYSIZE 200
int  iarray=0;
char array[ARRAYSIZE];

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.print("started\n");
  Serial.print("() from GSM to Console\n");
  Serial.print("[] from Console to GSM\n");
  memset(array,0,ARRAYSIZE);
}

void loop()
{
  char b=0;

  if(Serial1.available())
  {
    b = Serial1.read();
    //Serial.print(b);
    array[iarray] = b;
    iarray++;
  }
  if(Serial.available())
  {
    b = Serial.read();
    Serial1.print(b);
  }
  if(b==10)
  {
    Serial.print(array);
    Serial.print(" iarray size=");
    Serial.print(iarray);
    Serial.print("\n");
    memset(array,0,ARRAYSIZE);
    iarray=0;
  }
  if(iarray>ARRAYSIZE)
    iarray=0;
}
