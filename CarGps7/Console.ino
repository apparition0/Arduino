#include "Include.h"

void Console::init()
{
  Serial.begin(9600);
}

void Console::print(char *str)
{
  Serial.print(str);
}
void Console::println(char *str)
{
  Serial.println(str);
}
void Console::print(char c)
{
  Serial.print(c);
}
