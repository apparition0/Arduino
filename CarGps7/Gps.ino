
#include "Include.h"

int iarray=0;
char array[ARRAYSIZE];
char outarray[ARRAYSIZE];
bool newline = false;

void Gps::init()
{
    Serial1.begin(9600);
    memset(array,0,ARRAYSIZE);
}
void Gps::check()
{
  char b=0;
  if(Serial1.available())
  {
    b = Serial1.read();
    //Serial.print(b);
    array[iarray] = b;
    iarray++;
  }
  if(b==10)
    newline=true;    
  if(iarray>ARRAYSIZE)
    iarray=0;  // just loop if excedes string length
}

bool Gps::done()
{
  return newline;
}

char *Gps::outstring()
{
  memcpy(outarray,array,ARRAYSIZE); // copy WHOLE string, to get trailing zeros
  memset(array,0,ARRAYSIZE);
  iarray=0;
  newline=false;
  return outarray;
}
