#include<global.h>
#include<timer.h>
#include<uart.h>
#include<reg51.h>

#ifndef _interrupt_h_
#define _interrupt_h_


#define Enable_Interrupt() Set_Bit(IE,BIT7)  // Enable Global Interrupt
#define Disable_Interrupt() Clr_Bit(IE,BIT7)

#define Enable_Timer0_Interrupt() Set_Bit(IE,BIT1) //Enable Timer0 overflow interrupts
#define Disable_timer0_Interrupt() Clr_Bit(IE,BIT1)

//#define Enable_UART_Interrupt() Set_Bit(IE,BIT4) //Enable uart interrupts
#define Enable_UART_Interrupt() ES = 1
#define Disable_UART_Interrupt() Clr_Bit(IE,BIT4)

/*
void TIMER_ISR(void) interrup 1
  {
		TH0 = 0xA5;
		TL0 = 0xFE;
		counter++;
	}
	
void UART_ISR(void) interrup 4
 {
	 rdata = SBUF;  // Pass the dat to variable
	 RI = 0;
 }

*/

#endif