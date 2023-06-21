#define MQ3 A0
 //#define led 2
#define LED 2
// #define BLYNK_TEMPLATE_ID "TMPL3aUHyKY1H"
// #define BLYNK_TEMPLATE_NAME "alcohol"
// #define BLYNK_AUTH_TOKEN "TKh4JxTtXpppimG6HJ0Fp-eSgOHf8bjU"
#define Thres_Val 1200
#include <ThingSpeak.h>

 #include <WiFi.h>
  WiFiClient Client;
 int value;
 
//  int enA = 16;//d0
//  int enB = 13;//d7
//  int in1 = 5;//d1
//  int in2 = 4;//d2
//  int in3 = 14;//d5
 
 //int in4 = 12;//d6

 const char *nam="Yolo";
 const char *password="Yogesh@1";
 
const char *host ="api.thingsspeak.com";
const char apiKey[]="ER953QCS15ZOJDEV";
const int buzzer=21;
 
 void setup() 
 {
  Serial.begin(9600); 

  WiFi.begin(nam, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
   Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());

   pinMode(MQ3, INPUT);
   pinMode(LED, OUTPUT);
   pinMode(buzzer,OUTPUT);
   //pinMode(LED, OUTPUT);
   Serial.begin(9600); 
  // pinMode(enA, OUTPUT);
  // pinMode(enB, OUTPUT);
  // pinMode(in1, OUTPUT);
  // pinMode(in2, OUTPUT);
  // pinMode(in3, OUTPUT);
  // pinMode(in4, OUTPUT);
  ThingSpeak.begin(Client);
  
 }
 void loop() {
   int value;
   value=analogRead(MQ3);   
   Serial.println(value);
 if ( value > Thres_Val )   //if alcohol is detected
   {
     digitalWrite ( LED ,HIGH );   
     digitalWrite(buzzer,HIGH); 
     
    //  digitalWrite(in1, LOW);
    //  digitalWrite(in2, LOW);
    //  digitalWrite(in3, LOW);
    //  digitalWrite(in4, LOW);
     
                 
 }
 else {
     digitalWrite(LED,LOW);       
     digitalWrite(buzzer,LOW); 
    //  enA = 1;
    //  enB = 1;
    //  digitalWrite(in1, HIGH);
    //  digitalWrite(in2, HIGH);
    //  digitalWrite(in3, HIGH);
    //  digitalWrite(in4, HIGH);              
 }
  ThingSpeak.writeField(2179064, 1, value, apiKey);
 delay (500);            
 }