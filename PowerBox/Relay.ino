#include "include.h"
 
void Relay::on()
    {
      digitalWrite(_pin1,_on_value);
    }
void Relay::off()
    {
      digitalWrite(_pin1,_off_value);
    }
void Relay::on2()
    {
      digitalWrite(_pin2,_on_value);
    }
void Relay::off2()
    {
      digitalWrite(_pin2,_off_value);
    }
Relay::Relay(int pin1,int pin2)
    {
      _pin1 = pin1;
      _pin2 = pin2;
    }

