#include "include.h"

/* 
  I'm thinking just list "first pin"
  
    a
  f   b
    g
  e   c
    d    dot
  
  pin 1 = g,f,'com',a,b    // skip 'com' pin obviously
  pin 5 = e,d,'com',c,dot  // so total of 8 pins
  
  Requiring 330-470ohm resistor
*/
Display::Display(int startpin)
{
  _startpin = startpin;
  _pin_A   = _startpin + 2;
  _pin_B   = _startpin + 3;
  _pin_C   = _startpin + 6;
  _pin_D   = _startpin + 5;
  _pin_E   = _startpin + 4;
  _pin_F   = _startpin + 1;
  _pin_G   = _startpin + 0;
  _pin_DOT = _startpin + 7;
  
  _dot_status = LOW:
}

Display::displayminutes()
{
  blink();
}

Display::finished()
{
  digitalWrite(_pin_A,OFF);
  digitalWrite(_pin_B,OFF);
  digitalWrite(_pin_C,OFF);
  digitalWrite(_pin_D,OFF);
  digitalWrite(_pin_E,OFF);
  digitalWrite(_pin_F,OFF);
  digitalWrite(_pin_G,OFF);

}

Display:blink()
{
  if(_dot_status = LOW)
      _dot_status = HIGH;
  else
      _dot_status = LOW;
  digitalWrite(_pin_DOT,_dot_status);
}

Display:one()
{
  digitalWrite(_pin_A,OFF);
  digitalWrite(_pin_B,ON);
  digitalWrite(_pin_C,ON);
  digitalWrite(_pin_D,OFF);
  digitalWrite(_pin_E,OFF);
  digitalWrite(_pin_F,OFF);
  digitalWrite(_pin_G,OFF);
}
Display:two()
{
  digitalWrite(_pin_A,ON);
  digitalWrite(_pin_B,ON);
  digitalWrite(_pin_C,OFF);
  digitalWrite(_pin_D,ON);
  digitalWrite(_pin_E,ON);
  digitalWrite(_pin_F,OFF);
  digitalWrite(_pin_G,ON);
}
Display:three()
{
  digitalWrite(_pin_A,ON);
  digitalWrite(_pin_B,ON);
  digitalWrite(_pin_C,ON);
  digitalWrite(_pin_D,ON);
  digitalWrite(_pin_E,OFF);
  digitalWrite(_pin_F,OFF);
  digitalWrite(_pin_G,ON);
}
Display:four()
{
  digitalWrite(_pin_A,OFF);
  digitalWrite(_pin_B,ON);
  digitalWrite(_pin_C,ON);
  digitalWrite(_pin_D,OFF);
  digitalWrite(_pin_E,OFF);
  digitalWrite(_pin_F,ON);
  digitalWrite(_pin_G,ON);
}

