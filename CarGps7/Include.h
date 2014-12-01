#ifndef _CarGPS7Include
#define _CarGPS7Include

#define ARRAYSIZE 200
#define INTERVAL  10000 

class Gsm {
  public:
  static void init();
  static void transmit(char *str);
  static void realtransmit(char *str);
  static bool sendATcommand(char *cmd,char *resp,long int t);
};

class Gps {
  public:
  static void init();
  static void check();
  static bool done();
  static char* outstring();
};

class Console {
#define REDPIN   53
#define GREENPIN 51
#define BLUEPIN  49
  public:
  static void init();
  static void print(char *str);
  static void println(char *str);
  static void print(char c);
  void Console::redOn();
  void Console::redOff();
  void Console::greenOn();
  void Console::greenOff();
  void Console::blueOn();
  void Console::blueOff();
};

#endif
