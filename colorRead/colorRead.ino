/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
int r[15];
int g[15];
int b[15];

void setup() {
  
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}


void loop() {
  
  for (int i = 0; i < 15; i = i + 1) {
  //RED LED ON MODE
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(2000);
  
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(200);
  r[i]=analogRead(A0);
  delay(100);

  //GREEN LED ON MODE
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(200);
  g[i]=analogRead(A0);
  delay(100);

  //BLUE LED ON MODE
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(200);
  b[i]=analogRead(A0);
  delay(100);
  digitalWrite(10,LOW); 
       
  }
  for(int i = 0; i < 15; i++)
{
  //RED data array
  Serial.print(r[i]);
  Serial.print(" ");
  
}
 Serial.println(" ");
 for(int i = 0; i < 15; i++)
{
  //GREEN data array
  Serial.print(g[i]);
  Serial.print(" ");
  
}
  Serial.println(" ");
  for(int i = 0; i < 15; i++)
{
  //BLUE data array
  Serial.print(b[i]);
  Serial.print(" ");
  
}
 Serial.println(" "); 
 Serial.println(" ");
  digitalWrite(8,LOW);
  delay(2000);
         
}
