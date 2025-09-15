#ifndef _global_h_
#define _global_h_

#define Set_Bit(reg,bpos)     reg|=(1<<bpos)
#define Clr_Bit(reg,bpos)     reg&=~(1<<bpos)
#define Toggle_Bit(reg,bpos) reg ^=(1<<bpos)

#define Is_Bit_Clr(reg,bpos)  (!(reg&(1<<bpos)))
#define Is_Bit_Set(reg,bpos)  (reg&(1<<bpos))

  

#define TRUE  1
#define FALSE 0

typedef unsigned char   	u8_t;
typedef signed char     	s8_t;
typedef unsigned int    	u16_t;
typedef signed int      	s16_t;
typedef unsigned long int 	u32_t;
typedef unsigned char       bool_t;


#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7
#define BIT8 8
#define BIT9 9
#define BIT10 10
#define BIT11 11
#define BIT12 12
#define BIT13 13
#define BIT14 14
#define BIT15 15
#define BIT16 16
#define BIT17 17
#define BIT18 18
#define BIT19 19
#define BIT20 20
#define BIT21 21
#define BIT22 22
#define BIT23 23
#define BIT24 24
#define BIT25 25
#define BIT26 26
#define BIT27 27
#define BIT28 28
#define BIT29 29
#define BIT30 30
#define BIT31 31

#endif
