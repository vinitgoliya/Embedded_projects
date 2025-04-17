#include<reg51.h>

//sbit LED0 = P1^0;
//sbit LED1 = P1^1;
//sbit LED2 = P1^2;
//sbit LED3 = P1^3;
//sbit LED4 = P1^4;
//sbit LED5 = P1^5;
//sbit LED6 = P1^6;
//sbit LED7 = P1^7;

void clrReg();

void main()
	{
		
		//LED0 = 0;
	//	P1 = ~P1;
	//	LED1 = 0;
		clrReg();
		while(1)
		{
			int i = 0;
			//LED0 = 1;
			//P0<<1;
			//for(i=0;i<30000;i++);
			for(i=0;i<=7;i++)
			{
				int j = 0;
				P2 = P2 | (1<<i);
				for(j=0;j<10000;j++);
				P2 = P2 & (~(1<<i));
			}
		}
	}
	
void clrReg()
{
	int i = 0;
	for(i=0;i<=7;i++)
	{
		P2 = P2 & (~(1<<i));
	}
}