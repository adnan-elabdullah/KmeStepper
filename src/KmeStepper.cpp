
#include "Arduino.h"
#include "KmeStepper.h"

KmeStepper::KmeStepper(int pin ,int pin1,int pin2,int pin3)
{
  pinMode(pin, OUTPUT);
    pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

  step1 = pin;
 step2 = pin1;
  step3 = pin2;
  step4 = pin3;

}
void KmeStepper::KmeDc(int pin ,int pin1)
{
  pinMode(pin, OUTPUT);
    pinMode(pin1, OUTPUT);
  Dc1 = pin;
 Dc2 = pin1;
}

void KmeStepper::left(int steps,int speed)
{
  for(int t=0;t<=steps;t++){
         digitalWrite(step1,LOW);
digitalWrite(step2,HIGH);
digitalWrite(step3,LOW);
digitalWrite(step4,HIGH);  

delay (speed);
digitalWrite(step1,HIGH);
digitalWrite(step2,LOW);
digitalWrite(step3,LOW);
digitalWrite(step4,HIGH);
    
delay(speed);
digitalWrite(step1,HIGH);
digitalWrite(step2,LOW);
digitalWrite(step3,HIGH);
digitalWrite(step4,LOW);   
delay(speed);
    digitalWrite(step1,LOW);
digitalWrite(step2,HIGH);
digitalWrite(step3,HIGH);
digitalWrite(step4,LOW);
         delay(speed);
 }
  
}

void KmeStepper::right(int steps,int speed)
{
  for(int t=0;t<=steps;t++){

    digitalWrite(step1,LOW);
digitalWrite(step2,HIGH);
digitalWrite(step3,HIGH);
digitalWrite(step4,LOW);

delay (speed);
digitalWrite(step1,HIGH);
digitalWrite(step2,LOW);
digitalWrite(step3,HIGH);
digitalWrite(step4,LOW);    
delay(speed);
digitalWrite(step1,HIGH);
digitalWrite(step2,LOW);
digitalWrite(step3,LOW);
digitalWrite(step4,HIGH);      
delay(speed);
        digitalWrite(step1,LOW);
digitalWrite(step2,HIGH);
digitalWrite(step3,LOW);
digitalWrite(step4,HIGH); 
         delay(speed);
 }
     
}
void KmeStepper::Dcright()
{   
digitalWrite(Dc1,LOW);
digitalWrite(Dc2,HIGH);
    
}
void KmeStepper::Dcleft()
{   
digitalWrite(Dc2,LOW);
digitalWrite(Dc1,HIGH);
    
}

void KmeStepper::Loadcellbegin(int sck1 ,int  data1)
{

pinMode(sck1,OUTPUT);
    pinMode(data1,INPUT);
    SCK=sck1;
    DT1=data1;
}
long KmeStepper::Loadcell(int avr)
{   
        int h=0,j,k;
    long  sum = 0;
 long  datax;
  for ( k = 0; k < avr; k++) {
digitalWrite(DT1,HIGH);
  delayMicroseconds(1);

digitalWrite(SCK,LOW);
  delayMicroseconds(1);

    datax= 0;
while (digitalRead(DT1));
  
  delayMicroseconds(1);

  for ( j = 0; j < 24; j++) {
digitalWrite(SCK,HIGH);
delayMicroseconds(1);
datax = datax << 1;
digitalWrite(SCK,LOW);
delayMicroseconds(1);

    if (digitalRead(DT1)) {
      datax++;
    }
  }
digitalWrite(SCK,HIGH);

  datax = datax ^ 0x800000;
digitalWrite(SCK,LOW);
  
    sum = sum + datax;
  }
  sum = sum / avr;
  return sum;
}
