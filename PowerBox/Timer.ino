#include "include.h"

void Timer::Timer(int minutesleft);
    {
    /*
      // initialize Timer1
    cli();             // disable global interrupts
    TCCR1A = 0;        // set entire TCCR1A register to 0
    TCCR1B = 0;
 
    // enable Timer1 overflow interrupt:
    TIMSK1 = (1 << TOIE1);
    // Set CS10 bit so timer runs at clock speed:
    TCCR1B |= (1 << CS10);
    // enable global interrupts:
    sei();
    */
    _last_millis = _start_millis = millis();
    
      _done = 0;
    }
int  Timer::done()
    {
      unsigned long _current_millis = millis();
      unsigned long _passed_millis = _current_millis - _start_millis;
      unsigned long _passed_min = _passed_millis / 1000;
      if( (minutesleft - _passed_min) < 0 )
        _done = 1;
      _last_millis = millis();
      return _done;
    }

