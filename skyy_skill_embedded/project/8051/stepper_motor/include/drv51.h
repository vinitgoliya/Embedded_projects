#ifndef drv51_h_
#define dev51_h_

#include<reg51.h>
sbit SW0 = P1^0;
sbit SW1 = P1^1;
sbit SW2 = P1^2;
sbit SW3 = P1^3;
sbit SW4 = P1^4;
sbit SW5 = P1^5;
sbit SW6 = P1^6;
sbit SW7 = P1^7;

void delay(unsigned int count);

#endif