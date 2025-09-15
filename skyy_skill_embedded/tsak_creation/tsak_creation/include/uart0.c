#include<uart0.h>
#include<lpc214x.h>
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
	//U0LCR = U0LCR | (1<<BIT7);
	//U0DLL = 0x17;
	//U0DLM = 0x01;
	//U0FDR = 0x52; // DIVADDVALUE = 2, MULVALUE = 5
	//U0LCR=0X83;                                     //8-data bits, 1 Stop bit, Disable Parity and Enable DLAB
	//U0LCR |= (1<<BIT7);              // Enable access to Divisor Latches
	U0LCR=0X83;   
	//U0LCR |= ((1<<BIT0)|(1<<BIT1));  // setting 8-bit character length
	/*
	U0LCR Register
	Bit 1:0 - Word Length Select
  00 = 5-bit character length
  01 = 6-bit character length
  10 = 7-bit character length
  11 = 8-bit character length
  Bit 7 - Divisor Latch Access Bit (DLAB)
  0 = Disable access to Divisor Latches
  1 = Enable access to Divisor Latches
	*/
	
	U0DLM=1;
  U0DLL=135;
  U0LCR=0X03; 
 
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

/*
unsigned char Get_UART0_Data()
{
	unsigned char RawData = 0;
	while((U0LSR & (1<<BIT0))==0)
	RawData = U0RBR;
	return RawData;
}
*/

unsigned char Get_UART0_Data(void)							 /*receiving data*/
{
	unsigned char Rawdata=0;
	while((U0LSR&(1<<BIT0))==0);
  Rawdata=U0RBR;
	return Rawdata;
}

 void Set_UART_string(unsigned char *str)
   {
		 while(*str != '\0')
		 {
			 Set_UART_Data(*str);
			 str++;
		 }
	 }

void Init_UART0(void)
{
	config_UART0_pins();
	Power_On_UART0();
	Set_BaudRate_9600();
	Set_UART0_Data_Frame();
}
