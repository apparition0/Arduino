#include "Include.h"

long int mm;
char resp[ARRAYSIZE];

void Gsm::init()
{
  long int to = 2000;
  mm = millis();
  Serial2.begin(9600);
  Console::print(sendATcommand("ATZ","OK",to));
}

char *Gsm::sendATcommand(char *cmd,char *ans, long int timeout)
{
  int i=0;
  memset(resp,0,ARRAYSIZE);
  while(Serial2.available()>0) Serial2.read();
  Serial2.println(cmd);
  
  while(Serial2.available() != 0)
    {
       resp[i] = Serial2.read();
       i++;
       if(strstr(resp,ans) != NULL)
         break;
    }
    return resp;
}

void Gsm::transmit(char *str)
{
  if(millis() > (mm + INTERVAL))
  {
    //Console::print("    transmitting ");
    realtransmit(str);
    mm = millis();
  }
  else
  {
    //Console::print("not transmitting ");
    //Console::print(str);
  }
}
void Gsm::realtransmit(char *str)
{
  Console::print("b");
}

