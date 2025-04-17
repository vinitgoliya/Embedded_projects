#include<reg51.h>
#include<global.h>
#include<uart.h>

unsigned char rdata = 0;

void main()
 {
	 Config_UART();
	 Set_UART_String("Vinit kumar :");
	 Clr_Bit(P2,BIT0);
	 Clr_Bit(P2,BIT1);
	 Clr_Bit(P2,BIT2);
	 while(1)
	   {
			 rdata = Get_UART_Data();  // Received dat
			 //Set_UART_Data(rdata);
			 if(rdata)
			 {
				 Set_UART_Data(rdata);  // Receive dat ---> and again sending to terminal
				 switch(rdata)
				 {
					 case 'L' : Set_Bit(P2,BIT0);
					            break;
					 case 'l' : Clr_Bit(P2,BIT0);
					            break;
					 case 'B' : Set_Bit(P2,BIT1);
					            break;
					 case 'b' : Clr_Bit(P2,BIT1);
					            break;
					 case 'F' : Set_Bit(P2,BIT2);
					            break;
					 case 'f' : Clr_Bit(P2,BIT2);
					            break;
				 }
				 
			 }
			 
		 }
 }