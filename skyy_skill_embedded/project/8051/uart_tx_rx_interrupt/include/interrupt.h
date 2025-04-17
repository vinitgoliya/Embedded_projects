#ifndef _interrupt_h_
#define _interrupt_h_
#include<global.h>

#define Enable_Interrupt() Set_Bit(IE,BIT7)  // Enable Global Interrupt
#define Disable_Interrupt() Clr_Bit(IE,BIT7)

#define Enable_Timer0_Interrupt() Set_Bit(IE,BIT1) //Enable Timer0 overflow interrupts
#define Disable_timer0_Interrupt() Clr_Bit(IE,BIT1)

#define Enable_UART_Interrupt() Set_Bit(IE,BIT4) //Enable Timer0 overflow interrupts
#define Disable_UART_Interrupt() Clr_Bit(IE,BIT4)

/*
void TIMER_ISR(void) interrupt 1
  {
		TH0 = 0xA5;
		TL0 = 0xFE;
		counter++;
	}
*/


#endif