#include<reg51.h>
#include<delay.h>
#include<interrupt.h>
#include<lcd.h>
#include<timer.h>
#include<global.h>
#include<uart.h>



//volatile unsigned cha rdata=0;
/*
void UART_ISR(void) interrup 4
 {
	 rdata = SBUF;  // Pass the dat to variable
	 RI = 0;
 }
 

void main()
 {
	 unsigned char isr_data;
	 Config_UART();
	 Enable_Interrupt();
	 Enable_UART_Interrupt();
	 Set_UART_String("Vinit kumar :");
	 Clr_Bit(P2,BIT0);
	 Clr_Bit(P2,BIT1);
	 Clr_Bit(P2,BIT2);
	 rdata = 'L';
	 while(1)
	   {
			// rdata = Get_UART_Data();  // Received dat

			 if(rdata != 0)
			 {
				 Set_UART_Data(rdata);  // Receive dat ---> and again sending to terminal
				 isr_data = rdata;
				 rdata = 0;
				 switch(isr_data)
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
*/

void UART_ISR(void) interrupt 4
{
    if (RI)
    {
        rdata = SBUF;  // Store received dat
        RI = 0;        // Clear receive interrup flag
    }
}

void main(void)
{
    unsigned char isr_data;
    
    Config_UART();
  //  Enable_Interrupt();
  //  Enable_UART_Interrupt();
	
    
    Set_UART_String("Vinit kumar :");
	
	  //Set_UART_Data('l');
    
    // Initialize LED pins to OFF state
    Clr_Bit(P2, BIT0);
    Clr_Bit(P2, BIT1);
    Clr_Bit(P2, BIT2);
    rdata = 'L';
    while(1)
    {
//			rdata = Get_UART_Data();
        if(rdata != 0)
        {
            Set_UART_Data(rdata);  // Echo received dat back to terminal
            isr_data = rdata;
            rdata = 0;             // Clear the received dat buffer
            
            switch(isr_data)
            {
                case 'L': Set_Bit(P2, BIT0); break;
                case 'l': Clr_Bit(P2, BIT0); break;
                case 'B': Set_Bit(P2, BIT1); break;
                case 'b': Clr_Bit(P2, BIT1); break;
                case 'F': Set_Bit(P2, BIT2); break;
                case 'f': Clr_Bit(P2, BIT2); break;
            }
        }
    }
}


