#include<reg51.h>
#include<global.h>

void Config_UART(void)
 {
	 TMOD = 0x20;    // Timer 1 mode 2(aut o reload mode ) - Baud rate generation
	 TH1 = 0xFD;     // to set baud rate - 9600
	 SCON = 0x50;    // stop bi + 8 bi dat + start bi
	 TR1 = 1;        // start the timer 1
 }
 
 void Set_UART_Data(unsigned char dat)
 {
	 SBUF = dat;
	 while(TI == 0);   //wait to complete the dat transmission
	 TI = 0;           // Ready to transmit the next dat
 }
 
 void Set_UART_string(unsigned char *str)
   {
		 while(*str != '\0')
		 {
			 Set_UART_Data(*str);
			 str++;
		 }
	 }
	 
	 
 unsigned char Get_UART_Data(void)
 {
	 unsigned char rawdata = 0;
	 while(RI == 1)
	 {
		 rawdata = SBUF;  // Pass the dat to local variable
		 RI = 0;
	 }
	 return rawdata;
 }