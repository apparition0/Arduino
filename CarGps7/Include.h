#ifndef _CarGPS7Include
#define _CarGPS7Include

#define ARRAYSIZE 200

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
};

#endif
