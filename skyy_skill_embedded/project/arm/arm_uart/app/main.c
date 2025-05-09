#include<global.h>
#include<pcb.h>
#include<lpc2148.h>
#include<pll0.h>
#include<delay.h>
#include<pconp.h>
#include<uart0.h>

int main()
{
	unsigned char rData;
	Power_Off_Peripherals();
	Init_PLL0();
	Init_UART0();
	//Set_UART_Data('A');
	Set_UART_string("vinit kumar Hello world");
	
	while(1)
	{
		rData = Get_UART0_Data();
		Set_UART_Data(rData);
  }

}

