
/*
  The button presses are detected by interrupts
  The time is watched and incremented via timers
  The only action in the loop() is to update the display
  and disable the relays.  
  
  Timers could have also been used for the shutdown time,
  however the display probably should blink to show activity.

  Somewhat assuming:
  1. Only per-hour countdown intervals
  2. per second blinks
  3. normally off relays, in case of power trips
  
  Future enhancements might include:
  A. Ethernet or wifi power cycling, 
      controlled via web or arduino?
  B. Interval activation?  Like wake up once per?
  C. Most relay's have more than one relay, 
      do something with the other(s)
      
  main = done?
  button = done?
  display = 1/3 done
  relay = done
  timer = done?
*/

