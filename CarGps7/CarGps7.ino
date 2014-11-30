#include <stdio.h>
#include "Include.h"

void setup()
{
  Console::init(); // assumes serial 0, 9600
  Gsm::init();     // assumes serial 2, 9600
  Gps::init();     // assumes serial 1, 9600
  Console::print("started\n");
}

void loop()
{
  char *mystring;
  Gps::check();
  if(Gps::done())
  {
    Console::print("a");
    mystring = Gps::outstring();  // no need to free, as Gps manages
    //Console::print(mystring);
    if(strncmp(mystring,"$GPGGA,",6)==0)
      Gsm::transmit(mystring);
  }
}
