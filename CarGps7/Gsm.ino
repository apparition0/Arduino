#include "Include.h"

long int mm;
char resp[ARRAYSIZE];

void Gsm::init()
{
  long int to = 5000;
  mm = millis();
  delay(8000);  // if powered on at the same time, let gsm board setup
  Serial2.begin(9600);
  sendATcommand("ATZ","OK",to);
  sendATcommand("AT+CGPSPWR=1","OK",to);
  sendATcommand("AT+CGPSOUT=3","OK",to); // 51 is the common items
  sendATcommand("AT+CGPSRST=1","OK",to); 
}

bool Gsm::sendATcommand(char *cmd,char *ans, long int timeout)
{
  int i=0;
  bool answer = false;
  long int start = millis();
  memset(resp,0,ARRAYSIZE);
  while(Serial2.available()>0) Console::print(Serial2.read());
  Serial2.println(cmd);
  do 
  {
    //Console::print(".");
    if(Serial2.available() != 0)
    {
       resp[i] = Serial2.read();
       //Console::print(resp);
       i++;
       if(strstr(resp,ans) != NULL)
         answer = true;
    }
  } while ( (!answer) && (millis() < (start+timeout) ) );
  Console::println(resp);
  if(answer)
    {Console::redOff();Console::greenOn();}
  else
    {Console::redOn();Console::greenOff();delay(300);}
  return answer;
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
  bool r;
  char url[ARRAYSIZE];
  for(int i=0;i<ARRAYSIZE;i++)
    if( str[i]==10 || str[i] == 13)
      str[i] = 0;
  Console::print("b");
  sendATcommand("AT+SAPBR=3,1,\"Contype\",\"GPRS\"" ,"OK", 5000);
  sendATcommand("AT+SAPBR=3,1,\"APN\",\"APN\""      ,"OK", 5000);
  sendATcommand("AT+SAPBR=1,1"                      ,"OK", 5000);
  sendATcommand("AT+HTTPINIT"                       ,"OK", 5000);
  sendATcommand("AT+HTTPPARA=\"CID\",1"             ,"OK", 5000);
  strcpy(url,"AT+HTTPPARA=\"URL\",\"http://162.248.8.107/cgi-bin/db.py?");
  strcat(url,str);
  strcat(url,"\"");
  sendATcommand(url                                 ,"OK", 5000);
  r =
  sendATcommand("AT+HTTPACTION=0"                   ,"OK", 5000);
  if(r)readdata();
  sendATcommand("AT+HTTPTERM"                       ,"OK", 5000);
}

void Gsm::readdata()
{
  char aux_str[100];
  int x=0;
  sprintf(aux_str, "AT+HTTPREAD=%d,100", x);
  sendATcommand(aux_str, "+HTTPREAD:", 10000);
  
  char data[ARRAYSIZE];
  memset(data,0,ARRAYSIZE);
  
  while( Serial2.available() > 0) 
    data[x] = Serial2.read();
  Console::println(data);  
  
}
