  int redvalint     = 0;   int greenvalint   =0;     int bluevalint    =0;int delayfint = 2;
   int redvalintlast     = 0;   int greenvalintlast   =0;     int bluevalintlast    =0; 
int flasherdelay = 1000;
int flasherdelaylocal = 0 ;
int flasheron = 15;
  int redflash ,greenflash,blueflash;
  int flash6state = 0 ;
  int valueraghsemin ;

  int redghabl6 = 255 ;  int greenghabl6 = 255 ;  int blueghabl6 = 255 ;
  unsigned long flasherdelaytime6change = 0;  
int flasherstat=0;
unsigned long flasherdelaytime = 0;  
   int shedatnoor = 100;
  const int numReadings = 10;
 int varianse ;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;          
int inputPin = A0;
  #include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoOTA.h>
#include <ESP8266HTTPUpdateServer.h> 

const char* update_path = "/";
const char* update_username = "jafarib";
const char* update_password = "sara1@#4";

const char* ssid = "MHJ-MHJ";
const char* password = "masoode*8sarakoopaei1234";

const char* www_username = update_username;
const char* www_password = update_password;



int resetbottom = 4;

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 10000;   

ESP8266WebServer serverfsbrowser(28571);
ESP8266WebServer httpServer(28572);

ESP8266HTTPUpdateServer httpUpdater;

ESP8266WebServer server(80);

#include <FS.h>
int counterwifi = 0;
File fsUploadFile;
  #include "FSbrows.h"
#include "updateota.h" 
 #include "spfi.h"
int raghsenoorrang = 1;

int sensorpin = A0;
int green = 4;
int blue = 13;
int red = 15;

 int hasasiatesensormic =8;//analougebayad890bashe
  int maxvarianse = 2;
unsigned long maxvariansetime = 0;
unsigned long delayraghsenoor = 0;
unsigned long lastanalougeread = 0;  


 
  int fan = 16;
int  sensorValue ;
int functionnumber = 0;
unsigned long lastchange = 0; 
//تنظیم دستی نور// 0 برای 
 //// 1 برای رقص نور مدل 1
 //2برای رقص نور مدل 2 
//3 flasher1
//4 flasher2

//5 flasher3
//6 flasher4

//12 flasher5
//13 flasher6

//14 flasher7
//15 flasher8

 
//11   off


//7 برای رندوم 1
//8برای رندوم 2
//9 برای رندوم 3
//10 رندوم 4
// 20 random5


int flasher5numberrang= 0;

//11  offf
 #include "raghse1.h"
  #include "raghse2.h"
   #include "raghse3.h"
    #include "raghse4.h"
    #include "raghse5.h"
    #include "raghse6.h"
   #include "flasher1.h"
   #include "flasher2.h"
   #include "flasher3.h"
   #include "flasher4.h"
      #include "flasher5.h"
         #include "flasher6.h"
               #include "flasher7.h" 
               #include "flasher8.h"
  
  #include "reachcolor.h"
   #include "random1.h"
    #include "random2.h"
     #include "random3.h"
      #include "random4.h"
      #include "random5.h"
       #include "random6.h"
  #include "webserwerfunction.h"
#ifndef APSSID
#define APSSID "ESPap"
#define APPSK  "salam1234salam"
#endif

/* Set these to your desired credentials. */
const char *ssid1 = APSSID;
const char *password1 = APPSK;

  int redmain ;   int greenmain ;     int bluenmain;
 String psw;


 

IPAddress Ip(192, 168, 77, 1);
  IPAddress NMask(255, 255, 255, 0);

  
void setup() {
  
  ArduinoOTA.begin();

 
  Serial.begin(115200);
   EEPROM.begin(4096);
   

       int startepromm = EEPROM.read(5);
 if (startepromm!=123 )
{
  EEPROM.write(3630, 10);
EEPROM.write(3631,'1');EEPROM.write(3632,'2');EEPROM.write(3633,'3');EEPROM.write(3634,'4');EEPROM.write(3635,'5');
EEPROM.write(3636,'6');EEPROM.write(3637,'7');EEPROM.write(3638,'8');EEPROM.write(3639,'9');EEPROM.write(3640,'0');
  EEPROM.write(5, 123);


   EEPROM.write(4000, 30);
    EEPROM.write(4001, 30);
     EEPROM.write(4001, 30);
  
    
  
  EEPROM.commit();
}
  redmain = EEPROM.read(4000);
     greenmain = EEPROM.read(4001); 
      bluenmain = EEPROM.read(4002);
int tedadarghampass =  EEPROM.read(3630);
       Serial.println("******tedadarghampass"); 
       Serial.println(tedadarghampass); 
         Serial.println("******"); 
         tedadarghampass = tedadarghampass+1;
for (int i = 3631; i < tedadarghampass+3631; i++)psw+= char(EEPROM.read(i));char __passap[tedadarghampass];psw.toCharArray(__passap    , tedadarghampass);Serial.println(__passap);
         Serial.println("******"); 
    Serial.println("------");
     Serial.println("------");
  
   Serial.println("------");
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  
  Serial.printf("Connecting to %s\n", ssid);
  WiFi.softAPConfig(Ip, Ip, NMask);
   WiFi.mode(WIFI_AP);
//  if (String(WiFi.SSID()) != String(ssid)) {
//    WiFi.mode(WIFI_AP_STA);
//   
// 
//    WiFi.begin(ssid, password);
//  }
 // WiFi.softAP(ssid1, password1);
WiFi.softAP( "RGBLED-"+ String (system_get_chip_id(),HEX) , __passap);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
   Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
 
 fsbrowssetup();

  httpUpdater.setup(&httpServer, update_path, update_username, update_password);
  httpServer.begin();
  
  
 
//  while (WiFi.status() != WL_CONNECTED) {
//   // delay(500);
//    Serial.print(".");
//    Serial.println( counterwifi);
//    counterwifi = counterwifi+1;
//    if( counterwifi > 20){
//       break;
//    }
//  }
 
 Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  
 
   for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  
  Serial.print("\n");
analogWriteRange(255);
   

 
  pinMode(A0, INPUT); pinMode(resetbottom, INPUT);
 pinMode(green, OUTPUT);pinMode(blue, OUTPUT); pinMode(red, OUTPUT);       pinMode(fan, OUTPUT);    digitalWrite(fan, HIGH);
    
    analogWrite(blue, bluenmain);
       analogWrite(green, greenmain); 
      analogWrite(red, redmain);
 
 Serial.println("");
//  
 SPIFFS.begin();
    server.on("/"               ,[](){File f=SPIFFS.open("/index.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
    server.on("/index.htm"      ,[](){File f=SPIFFS.open("/index.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
    server.on("/roy.jpg"       ,[](){File f=SPIFFS.open("/roy.jpg"       ,"r");server.streamFile(f,"image/jpg"      );f.close();});
    server.on("/mainflasher.htm"      ,[](){File f=SPIFFS.open("/mainflasher.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
  
      server.on("/changepass.htm"      ,[](){File f=SPIFFS.open("/changepass.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
    
    
     
 
     server.on("/lighdance.htm"      ,[](){
      hasasiatesensormic = 8;
      
      File f=SPIFFS.open("/lighdance.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
         
     
     server.on("/random.htm"      ,[](){
      shedatnoor = 100 ;
      delayfint = 1;
      File f=SPIFFS.open("/random.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
    
     server.on("/flasher3.htm"      ,[](){
      
      redvalint     =  150;
       greenvalint   = 150;
       bluevalint    = 150;
flasherdelaylocal =  400; 
      functionnumber = 5 ;
        
      
      File f=SPIFFS.open("/flasher3.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
 server.on("/changeusernameandpasswordact", changeusernameandpasswordact);
       server.on("/flasher4.htm"      ,[](){
      
     
flasherdelaylocal =  400; 
      functionnumber = 6 ;
        
      
      File f=SPIFFS.open("/flasher4.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});





       server.on("/flasher5.htm"      ,[](){
      
     
flasherdelaylocal =  400; 
      functionnumber = 12 ;
        
      
      File f=SPIFFS.open("/flasher4.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});





       server.on("/flasher6.htm"      ,[](){
      
     
flasherdelaylocal =  400; 
      functionnumber = 13 ;
        
      
      File f=SPIFFS.open("/flasher4.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});

      
       server.on("/flasher7.htm"      ,[](){
      
     
flasherdelaylocal =  400; 
      functionnumber = 14 ;
        
      
      File f=SPIFFS.open("/flasher4.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});

       server.on("/flasher8.htm"      ,[](){
      
     
flasherdelaylocal =  400; 
      functionnumber = 15 ;
        
      
      File f=SPIFFS.open("/flasher4.htm"      ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});

      
   server.on("/manual.htm"     ,[](){functionnumber = 0; 
   
       redmain = EEPROM.read(4000);
     greenmain = EEPROM.read(4001); 
      bluenmain = EEPROM.read(4002);
    
   redvalint = redmain ;greenvalint = greenmain ; bluevalint = bluenmain;delayfint = 2;
  // analogWrite(blue, 0);    analogWrite(green, 0);   analogWrite(red, 0);
   
   File f=SPIFFS.open("/manual.htm"     ,"r"); Serial.println("---------------");server.streamFile(f,"text/html"      );f.close();});
   server.on("/jscolor.js"     ,[](){File f=SPIFFS.open("/jscolor.js"     ,"r");server.streamFile(f,"text/javascript");f.close();});
   server.on("/setcolor"              , setcolor); 
    server.on("/savecolor"              , savecolor); 
    server.on("/setdelayrandom1"              , setdelayrandom1); 
    server.on("/setdelayrandom2"              , setdelayrandom2); 
    server.on("/setdelayrandom3"              , setdelayrandom3); 
     server.on("/setdelayrandom4"              , setdelayrandom4);
        server.on("/setdelayrandom5"              , setdelayrandom5);
           server.on("/setdelayrandom6"              , setdelayrandom6);
 
      server.on("/setshedatnoor"              , setshedatnoor);
       server.on("/hasasiatesensormictanzim"              , hasasiatesensormictanzim);
       server.on("/setflasherdelaylocal"              , setflasherdelaylocal);
      server.on("/flasher1set"              , flasher1set);
        server.on("/flasher2set"              , flasher2set);
      server.on("/flasher3set"              , flasher3set);
        server.on("/raghse1"              , raghse1function);
          server.on("/raghse2"              , raghse2function);
           server.on("/raghse3"              , raghse3function);
            server.on("/raghse4"              , raghse4function);
             server.on("/raghse5"              , raghse5function);
              server.on("/raghse6"              , raghse6function);
              
            server.on("/off"              , off);
  server.begin();
   maxvariansetime = millis();
   delayraghsenoor =  millis();
   lastanalougeread =  millis();
   flasherdelaytime =  millis();
   flasherdelaytime6change =  millis();
}

 

void loop() {
valueraghsemin = 200;
  int resetstate =   digitalRead(resetbottom);  ;

if (resetstate ==1){

   lastDebounceTime = millis();
}

 if ((millis() - lastDebounceTime) > debounceDelay) {
 
  




 }

  
server.handleClient();
 ArduinoOTA.handle();
  serverfsbrowser.handleClient();
   httpServer.handleClient();

 variansedetect();
     
  
  
  
 

  if(functionnumber == 0 ){
    digitalWrite(fan, HIGH);
     reachcolor();
  }
  if(functionnumber == 1 ){
    digitalWrite(fan, LOW);
     raghse1();
  }
    if(functionnumber == 2 ){
      digitalWrite(fan, LOW);
     raghse2();
  }

    if(functionnumber == 25 ){
      digitalWrite(fan, LOW);
     raghse3();
  }
  if(functionnumber == 26 ){
    digitalWrite(fan, LOW);
     raghse4();
  }
  if(functionnumber == 27 ){
    digitalWrite(fan, LOW);
     raghse5();
  }if(functionnumber == 28 ){
    digitalWrite(fan, LOW);
     raghse6();
  }


  if(functionnumber == 3 ){
    digitalWrite(fan, HIGH);
     flasher1();
  }
  
  if(functionnumber == 4 ){
    digitalWrite(fan, HIGH);
     flasher2();
  }

  
  if(functionnumber == 5 ){
    digitalWrite(fan, HIGH);
     flasher3();
  }

  if(functionnumber == 6 ){
    digitalWrite(fan, HIGH);
 
      flasher4();
  }


 if(functionnumber == 12 ){
  digitalWrite(fan, HIGH);
     flasher5();
  }

  if(functionnumber == 13 ){
    digitalWrite(fan, HIGH);
     flasher6();
  }

  if(functionnumber == 14 ){
    digitalWrite(fan, HIGH);
     flasher7();
  }

  if(functionnumber == 15 ){
    digitalWrite(fan, HIGH);
     flasher8();
  }




  if(functionnumber == 7 ){
    digitalWrite(fan, HIGH);
     random1();
  }

  
  if(functionnumber == 8 ){
    digitalWrite(fan, HIGH);
     random2();
  }

  
  if(functionnumber == 9 ){
    digitalWrite(fan, HIGH);
     random3();
  }

  
  if(functionnumber == 10 ){
    digitalWrite(fan, HIGH);
     random4();
  }
  
  if(functionnumber == 20 ){
    digitalWrite(fan, HIGH);
     random5();
  }

   if(functionnumber == 21 ){
    digitalWrite(fan, HIGH);
     random6();
  }


 
  if(functionnumber == 11 ){     digitalWrite(red, LOW);digitalWrite(green, LOW);digitalWrite(blue, LOW);  digitalWrite(fan, LOW); }


 
 
    
}
