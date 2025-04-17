#include<reg51.h>
#include<timer.h>
#include<global.h>
#include<interrupt.h>




void main()
	 {
		 Enable_Interrupt();  // Enable Global Interrupt
		 Enable_Timer0_Interrupt(); //Enable Timer0 overflow interrupts
		 
		config_25msec();
		while(1)
			 {
				overflow_check();
				if(counter==160)
				 {
					 counter = 0;
					 P1 = ~P1;
				 }
			}
	}