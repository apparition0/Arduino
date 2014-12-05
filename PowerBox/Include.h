
#ifndef _POWERBOX_HEADER
#define _POWERBOX_HEADER

#include <avr/interrupt.h>
#include <avr/io.h>
 
class Relay
{
  public:
    void on();
    void off();
    void on2();
    void off2();
    Relay(int pin1,int pin2);
  private:
    int _pin1;
    int _pin2;
    int _on_value  = HIGH;
    int _off_value = LOW;
};

class Timer
{
  public:
    void Timer(int minutesleft);
    int done();
  private:
    unsigned long _start_millis;
    unsigned long _last_millis;
    int _done;
}
class Button
{
  public:
    void Button(int resetPin, int hourPin);
  private:
    static unsigned long last_interrupt_time;
}
#endif // _POWERBOX_HEADER
