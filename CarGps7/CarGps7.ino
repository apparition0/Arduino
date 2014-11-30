#include <stdio.h>
#include "Include.h"

void setup()
{
  Console::init(); // assumes serial 0, 9600
  Gps::init();     // assumes serial 1, 9600
  Console::print("started\n");
}

void loop()
{
  Gps::check();
  if(Gps::done())
  {
    Console::print(Gps::outstring());
  }
}
