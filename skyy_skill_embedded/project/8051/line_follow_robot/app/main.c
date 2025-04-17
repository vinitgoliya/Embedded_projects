#include<reg51.h>
#include<robot.h>
#include<delay.h>

void farword();
void backword();
void right();
void left();
void stop();
void runMotor(void f());

void main(){
	delay(1000000);
	while(1)
	{
		if(INPUT0 == 0)
		{

		//	while(P1^BIT0 == 0);

		//		runMotor(farword);

			
	//		farword();
		}else if(P1^BIT1 == 0)
		{
			while(P1^BIT1 == 0)
			{
				runMotor(backword);
			}
		//	backword();
		}else if(P1^BIT2 == 0)
		{
			while(P1^BIT2 == 0)
			{
				runMotor(right);
			}
		//	right();
		}else if(P1^BIT3 == 0)
		{
			while(P1^BIT3 == 0)
			{
				runMotor(left);
			}
		//	left();
		}else if(P1^BIT4 == 0)
		{
			while(P1^BIT4 == 0)
			{
				runMotor(stop);
			}
		//	stop();
		}
	}
	
}

void farword()
	{
		 Set_Bit(P2,BIT0);
		 Clr_Bit(P2,BIT1);
		
		 Set_Bit(P2,BIT2);
		 Clr_Bit(P2,BIT3);
	}
	
void backword()
	{
		Set_Bit(P2,BIT1);
		Clr_Bit(P2,BIT0);
		
		Set_Bit(P2,BIT3);
		Clr_Bit(P2,BIT2);
	}
	
void right()
	{
		Clr_Bit(P2,BIT0);
		Clr_Bit(P2,BIT1);
		
		Set_Bit(P2,BIT2);
		Clr_Bit(P2,BIT3);
	}
	
void left()
	{
		Set_Bit(P2,BIT0);
		Clr_Bit(P2,BIT1);
		
		Clr_Bit(P2,BIT2);
		Clr_Bit(P2,BIT3);
	}
	
void stop()
	{
		Clr_Bit(P2,BIT0);
		Clr_Bit(P2,BIT1);
		Clr_Bit(P2,BIT2);
		Clr_Bit(P2,BIT3);
	}
	

	
void runMotor(void f())
  {
		while(P1^BIT0==1 && P1^BIT1 && P1^BIT2 && P1^BIT3 && P1^BIT4)
		{
			f();
		}
  }