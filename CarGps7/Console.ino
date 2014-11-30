#include "Include.h"

void Console::init()
{
  Serial.begin(9600);
}
void Console::print(char *str)
{
  Serial.print(str);
}
