#include <SD.h>
#include <SoftwareSerial.h>

//GPS variables
static const int RXPin = 3, TXPin = 4;
static const uint32_t GPSBaud = 4800;
SoftwareSerial ss(RXPin, TXPin);  // The serial connection to the GPS device, jumpers (reversed)
// SD Card variables
const int chipSelect = 10;
File dataFile;
// My variables
boolean usesdcard = false;
char message[100];
int  messageindex=0;
int loops;
void setup()
{
  Serial.begin(9600);  // talk to PC
  Serial.print(F("\n\nPhilip Wheatley\n\n"));

  //ss.begin(GPSBaud); ss.flush(); 
  ss.begin(38400);  ss.flush();    // GPS starts out too fast
  ss.print("$PUBX,41,1,0007,0003,4800,0*13\r\n");   
  // command 41 (set protocol and baud), com port ID,input protocol mask,output protocol mask,baudrate,autobauding enable=1,*checksum,return,newline
  ss.begin(GPSBaud);   // now GPS should talk slower
  ss.flush(); 
  
  if(usesdcard)
  {
    pinMode(10, OUTPUT);
    if (!SD.begin(chipSelect)) 
      Serial.println("Card failed, or not present");
    else
      Serial.println("card initialized.");
  }
  
  for(messageindex=0;messageindex<100;messageindex++)
    message[messageindex] = '\0';
  messageindex=0;
  loops = 0;
  Serial.println("setup() complete");
}

void loop()
{
  char c;  // GPS data, converted to a char
  int i;   // GPS data, one byte at a time

  while (ss.available() > 0)
  {
    i = ss.read();
    c = (char)i;
    if(false)// print NEMA strings
      Serial.print( c );
      
    if(messageindex>100) messageindex = 0; // don't walk off the end of memory!
    message[messageindex++] = c;
    
    if(i==10)  // enter on newline
    {
      if(strncmp(message,"$GPRMC,",6)==0)
        if(usesdcard)
        {
          if(!dataFile)
            dataFile = SD.open("pswlog.txt", FILE_WRITE);
          dataFile.print(message);
          dataFile.flush();
          dataFile.close();
        }  //if usesdcard
        
      Serial.print("[");
      message[messageindex-1] = '\0'; // remove newline?
      Serial.print(message);  // print WHOLE message to console
      Serial.println("]");
      loops++;;
      
      for(messageindex=0;messageindex<100;messageindex++)
        message[messageindex] = '\0';
      messageindex=0;
    } // if i==10 // 
    
  } // while ss avail

}

