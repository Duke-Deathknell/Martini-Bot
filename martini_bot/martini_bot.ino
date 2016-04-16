#include "Ultrasonic2.h"

int distance;
Ultrasonic ultrasonic(9,8);
bool findingMode;
int distanceToMove;
int Trig_pin = 9;

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

void setup() {  
  // setup the xbee connection 
  Serial.begin(115200);
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
  
  findingMode = false;
  distanceToMove = 0;
}

void loop() {

  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  //Serial.println(distance);
  /*if(distance > 100) 
  {
    advance (255,255); 
  }
  else
  {
    stop();
  }*/
  /*if(Serial.available() > 0)
  {
      char input = Serial.read();
      if(input == 'W')
      {
        advance (255,255);   //move forward in max speed
        delay(200);
        stop();
      }
      if(input == 'A')
      {
        turn_L (100,100);   
        delay(200);
        stop();
      }
      if(input == 'S')
      {
        back_off (255,255); 
        delay(200);
        stop();
      }
      if(input == 'D')
      {
        turn_R (100,100);  
        delay(200);
        stop();
      }
  }
    /*
  //wait for user to enter the button
  if(!findingMode && Serial.available > 0)
  {
      //controller sends radio signal to start search
      char input = Serial.read();
      if(input == 'y')
        findingMode = true;
  }

  if(findingMode)
  {
    if(distanceToMove == 0)
    {
      //trigger for reading
      Serial.write('s');
    }
    
    //if no reading found, rotate 45 degrees trigger for reading (repeat)
  
     //move forward x units, trigger for new reading (repeat)
     
     //when within threashold, stop
  }
  */
}

void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
