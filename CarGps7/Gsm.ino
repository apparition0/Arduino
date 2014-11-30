#include "Include.h"

long int mm;
char resp[ARRAYSIZE];

void Gsm::init()
{
  long int to = 2000;
  mm = millis();
  Serial2.begin(9600);
  Console::print(sendATcommand("ATZ","OK",to));
  Console::print(sendATcommand("AT+CGPSPWR=1","OK",to));
  Console::print(sendATcommand("AT+CGPSOUT=51","OK",to));
  Console::print(sendATcommand("AT+CGPSRST=1","OK",to)); 
}

char *Gsm::sendATcommand(char *cmd,char *ans, long int timeout)
{
  int i=0;
  bool answer = false;
  long int start = millis();
  memset(resp,0,ARRAYSIZE);
  while(Serial2.available()>0) Console::print(Serial2.read());
  Serial2.println(cmd);
  Console::print("-");
  do 
  {
    Console::print(".");
    if(Serial2.available() != 0)
    {
       resp[i] = Serial2.read();
       Console::print(resp);
       i++;
       if(strstr(resp,ans) != NULL)
         answer = true;
    }
  } while ( (!answer) && (millis() < (start+timeout) ) );
  Console::print("+");
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

