#include<reg51.h>
#include<timer.h>

	void main()
	  {
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