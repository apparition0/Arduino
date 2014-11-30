#ifndef _CarGPS7Include
#define _CarGPS7Include

#define ARRAYSIZE 200
#define INTERVAL  10000 

class Gsm {
  public:
  static void init();
  static void transmit(char *str);
  static void realtransmit(char *str);
  static char *sendATcommand(char *cmd,char *resp,long int t);
};

class Gps {
  public:
  static void init();
  static void check();
  static bool done();
  static char* outstring();
};

class Console {
  public:
  static void init();
  static void print(char *str);
  static void println(char *str);
  static void print(char c);
};

#endif
