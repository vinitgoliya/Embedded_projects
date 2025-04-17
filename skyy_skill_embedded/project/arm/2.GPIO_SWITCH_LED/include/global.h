#ifndef _global_h_
#define _global_h_

#define Set_Bit(Reg,Bpos)    Reg = Reg|(1<<Bpos)
#define Clr_Bit(Reg,Bpos)    Reg = Reg & (~(1<<Bpos))

#define Is_Bit_Clr(Reg,Bpos) (!(Reg & (1<<Bpos)))
#define Is_Bit_Set(Reg,Bpos) (Reg & (1<<Bpos))

#define BIT0  0
#define BIT1  1
#define BIT2  2
#define BIT3  3
#define BIT4  4
#define BIT5  5
#define BIT6  6
#define BIT7  7
#define BIT8  8
#define BIT9  9
#define BIT10  10
#define BIT11  11
#define BIT12  12
#define BIT13  13
#define BIT14  14
#define BIT15  15

#define TRUE  1
#define FALSE 0

typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned int u16_t;
typedef signed int s16_t;

#endif
