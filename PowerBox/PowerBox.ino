#include "Include.h"

Button btn;
Display dis;
Relay rly;
Timer tmr;
int minutesleft;

void setup()
{
  btn = new Button(resetPin,hourPin);
  dis = new Display(displayPins);
  rly = new Relay(relayPin1,relayPin2);
  tmr = new Timer(minutesleft = 60); // set to a default of 60 minutes
  
  rly.on(); // turn power on  
}

void loop()
{
  dis.displayminutes(minutesleft); // will blink per call
  if(tmr.done())
  {
    rly.off();
    dis.finished()
  }
  delay(1000); // loop every second
}
