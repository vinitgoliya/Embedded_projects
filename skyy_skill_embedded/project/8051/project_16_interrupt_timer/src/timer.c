#include<timer.h>
#include<reg51.h>

unsigned int counter = 0; 

void config_25msec(void)
  {
		TMOD = 0x01;  // Timer 0 Mode 1
		TH0 = 0xA5;
		TL0 = 0xFE;
		TR0 = 1;   // Start timer 0
	}
	
void overflow_check(void)
  {
		while(TF0==1)
		{
			TF0 = 0;
		  TH0 = 0xA5;
		  TL0 = 0xFE;
			counter++;
		}
	}
	