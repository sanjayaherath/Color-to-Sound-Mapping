#include <PCM.h>
#include "sounddata.h"

#define RED_PIN 8
#define GREEN_PIN 9
#define BLUE_PIN 10
#define SPEAKER_PIN 11
#define COLOUR_SCAN_DELAY 200

int r;
int g;
int b;
double z;


void setup() {
  
  pinMode(RED_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  
  Serial.begin(9600);
}


void loop() {
  
  
  //RED LED ON MODE
 
  delay(1500);
  
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,LOW);
  delay(COLOUR_SCAN_DELAY);
  r=analogRead(A0);
  
  //GREEN LED ON MODE
  digitalWrite(RED_PIN,LOW);
  digitalWrite(GREEN_PIN,HIGH);
  digitalWrite(BLUE_PIN,LOW);
  delay(COLOUR_SCAN_DELAY);
  g=analogRead(A0);

  //BLUE LED ON MODE
  digitalWrite(RED_PIN,LOW);
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,HIGH);
  delay(300);
  b=analogRead(A0);
  delay(300);
  digitalWrite(BLUE_PIN,LOW); 

  
 z=-0.164087102182184*r-0.438337949153713*g+0.883705417675580*b;
 Serial.print(z);
Serial.print("\n");
  if(z<200){}
 
  else if(z<230){
   Serial.print("blue\n");
   startPlayback(g1, sizeof(g1));
   //delay(1000);
  }
  else if(z<250){
    Serial.print("violet\n");
    startPlayback(b1, sizeof(b1));
    //delay(1000);
  }
  else if(z<265){
    Serial.print("cyan\n");
    startPlayback(a1, sizeof(a1));
    //delay(1000);
  }
  else if(z<305){
     Serial.print("black\n");  
  }
  else if(z<325){
    Serial.print("red\n");
    startPlayback(c1, sizeof(c1));
    //delay(1000);
    
  }
  else if(z<350){
    Serial.print("green\n");
    startPlayback(f1, sizeof(f1));
    // delay(1000);
    
  }
   else if(z<400){
    Serial.print("orange\n");
    startPlayback(d1, sizeof(d1));
    // delay(1000);
    
  }
   else if(z<450){
    Serial.print("yellow\n");
    startPlayback(e1, sizeof(e1));
    // delay(1000);
    
  }
    
  }
  
  
         

