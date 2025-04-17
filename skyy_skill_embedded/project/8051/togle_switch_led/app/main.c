#include<reg51.h>

// switch
sbit SW = P1^0;

sbit LED = P2^5;

void main()
{
//	int i;
	LED = 0;
	
	while(1)
	{
	   if(SW == 0 && LED == 0)
		 {
			 LED = 1;
			 while(SW == 0);
			// for( i=0;i<30000;i++);
		 }
		 else if(SW == 0 && LED == 1)
		 {
			 LED = 0;
			 while(SW == 0);
			// for( i=0;i<30000;i++);
		 }
   }
}