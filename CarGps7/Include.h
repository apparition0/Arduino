#ifndef _CarGPS7Include
#define _CarGPS7Include

#define ARRAYSIZE 200
#define INTERVAL  20000 

class Gsm {
  public:
  static void init();
  static void transmit(char *str);
  static void realtransmit(char *str);
  private:
  static bool sendATcommand(char *cmd,char *resp,long int t);
  static void readdata();
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
  static void redOn();
  static void redOff();
  static void greenOn();
  static void greenOff();
  static void blueOn();
  static void blueOff();
  static void allOn();
  static void allOff();
};

#endif
