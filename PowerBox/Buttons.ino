#include "include.h"

last_interrupt_time = 0;
/*
  Uno has 
    interrupt 0 on pin 2
    interrupt 1 on pin 3
*/
Button::Button(resetPin,hourPin)
{
  pinMode(hourPin,INPUT);
  // TODO fix to valid pins with if()
  attachInterrupt(hourPin,interrupt_handler,RISING);
}

void interrupt_handler()
{
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 200) 
  {
    minutesleft += 60;
  }
  last_interrupt_time = interrupt_time;
}
