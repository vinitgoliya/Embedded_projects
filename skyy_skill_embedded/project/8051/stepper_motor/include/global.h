#ifndef _global_h_
#define _global_h_

#define Set_Bit(Reg,Bpas) Reg = Reg | (1<<Bpas)

#define Clr_Bit(Reg,Bpas) Reg = Reg & (~(1<<Bpas))

#define Clr_Reg(Reg) Reg = Reg & 0




#endif