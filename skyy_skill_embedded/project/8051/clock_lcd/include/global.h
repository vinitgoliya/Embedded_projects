#ifndef _global_h_
#define _global_h_

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




#endif