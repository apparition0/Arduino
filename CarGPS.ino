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
boolean usesdcard = true;
boolean printeachchar = false;
char message[100];
int  messageindex=0;
unsigned long currentMillis;
unsigned long previousMillis;
unsigned long interval;
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
  //Serial.println("$PUBX,40,GLL,0,0,0,0*5C");
  //Serial.println("$PUBX,40,GGA,0,0,0,0*5A");
  Serial.println("$PUBX,40,GSA,0,0,0,0*4E");
  //Serial.println("$PUBX,40,RMC,0,0,0,0*47");
  Serial.println("$PUBX,40,GSV,0,0,0,0*59");
  //Serial.println("$PUBX,40,VTG,0,0,0,0*5E");  
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
  
  interval = 1000 * 10; // ten seconds
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
    if(printeachchar)// print NEMA strings
      Serial.print( c );
      
    if(messageindex>100) messageindex = 0; // don't walk off the end of memory!
    message[messageindex++] = c;
    
    if(i==10)  // enter on newline
    {
      if(strncmp(message,"$GPRMC,",6)==0)
        if( (currentMillis = millis()) - previousMillis > interval) 
        {
          Serial.print("########################### ");
          Serial.println(currentMillis / 1000);
          previousMillis = currentMillis; 
          if(usesdcard)
          {
            if(!dataFile)
              dataFile = SD.open("pswlog.txt", FILE_WRITE);
            dataFile.print(message);
            dataFile.flush();
            dataFile.close();
          }  //if usesdcard
        }    
      Serial.print("[");
      message[messageindex-1] = '\0'; // remove newline?
      Serial.print(message);  // print WHOLE message to console
      Serial.println("]");
      
      for(messageindex=0;messageindex<100;messageindex++)
        message[messageindex] = '\0';
      messageindex=0;
    } // if i==10 // 
  } // while ss avail
}

