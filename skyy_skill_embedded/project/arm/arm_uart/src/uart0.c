#include<uart0.h>
#include<lpc2148.h>
#include<pcb.h>
#include<pconp.h>
#include<global.h>

/* CONFIG UART0 PINS */
static void config_UART0_pins(void)
{
	PINSEL0.P0_0 = P0_0_TXD0;
	PINSEL0.P0_1 = P0_1_RXD0;
}

/* Set Baud Rate 9600 */
static void Set_BaudRate_9600(void)
{
	U0LCR = U0LCR | (1<<BIT7);
	U0DLL = 0x17;
	U0DLM = 0x01;
	U0FDR = 0x52; // DIVADDVALUE = 2, MULVALUE = 5
}



static void Set_UART0_Data_Frame(void)
{
	U0LCR |= (1<<BIT0) | (1<<BIT1);
}


void Set_UART_Data(unsigned char Dat)
{
	U0THR = Dat;
	while(!(U0LSR & (1<<BIT5))); // if it is 0 then it will stay here
}

void Init_UART0(void)
{
	config_UART0_pins();
	Power_On_UART0();
	Set_BaudRate_9600();
	Set_UART0_Data_Frame();
}
