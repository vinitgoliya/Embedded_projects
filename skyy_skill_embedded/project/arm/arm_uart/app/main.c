#include<global.h>
#include<pcb.h>
#include<lpc2148.h>
#include<pll0.h>
#include<delay.h>
#include<pconp.h>
#include<uart0.h>

int main()
{
	Power_Off_Peripherals();
	Init_PLL0();
	Init_UART0();
	Set_UART_Data('A');
	
	while(1)
	{
		
  }

}

