/*
  KmeStepper.h - Library for flashing KmeStepper code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef KmeStepper_h
#define KmeStepper_h

#include "Arduino.h"

class KmeStepper
{
  public:
    KmeStepper(int pin,int pin1,int pin2,int pin3);
   void  KmeDc(int pin ,int pin1);
    void left(int steps,int speed);
    void right(int steps,int speed);
    void Dcright();
    void Dcleft();
    void Loadcellbegin(int sck,int data);
    long Loadcell(int avr);

  private:
    int step1,step2,step3,step4;
    int Dc1,Dc2;
    int SCK,DT1;

};

#endif