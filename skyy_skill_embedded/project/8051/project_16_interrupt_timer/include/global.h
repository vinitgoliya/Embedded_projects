#ifndef _global_h_
#define _global_h_
#include<reg51.h>

#define Set_Bit(Reg,Bpas) Reg = Reg | (1<<Bpas)

#define Clr_Bit(Reg,Bpas) Reg = Reg & (~(1<<Bpas))

#define Clr_Reg(Reg) Reg = Reg & 0

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

sbit DOOR = P1^0;
sbit FAN = P1^1;
sbit LIGHT = P1^2;
sbit SW3 = P1^3;
sbit SW4 = P1^4;
sbit SW5 = P1^5;
sbit SW6 = P1^6;
sbit SW7 = P1^7;


#endif