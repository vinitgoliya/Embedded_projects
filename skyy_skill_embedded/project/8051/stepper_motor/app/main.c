#include<reg51.h>
#include<global.h>
#include<drv51.h>


void forward();
void backward();

	 
unsigned char position[] = {0x10,0x02,0x06,0x04,0x05,0x01,0x09,0x08};

void main()
  {
		Clr_Reg(P2);
		while(1)
		{
			if(SW0 == 0)
			{
			  forward();
				
			}else if(SW1 == 0)
			   {
					 		backward();
				 }
		}
	}
	
	void forward()
    {
			int i = 0;
			for(i=0;i<=7;i++)
			  {
					P2 = position[i];
					if(SW0 == 1) break;
					delay(8000);
				}
//			P2 = 0x010;
//				delay();
//			P2 = 0x02;
//				delay();
//			P2 = 0x06;
//				delay();
//			P2 = 0x04;
//				delay();
//			P2 = 0x05;
//				delay();
//			P2 = 0x01;
//				delay();
//			P2 = 0x09;
//				delay();
//			P2 = 0x08;
//				delay();

		}
		
		
		void backward()
    {
      int i = 0;
			for(i=7;i>=0;i--)
			  {
					P2 = position[i];
					delay(8000);
				}
		}