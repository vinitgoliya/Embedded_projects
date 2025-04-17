#include<global.h>
#include<LPC2148.h>
#include<pcb.h>
#include<delay.h>
#include<pll0.h>
#include<pconp.h>

void config_Pins()
{

  PINSEL0.P0_5 = P0_5_GPIO;
	PINSEL0.P0_10 = P0_10_GPIO;
	
	IO0DIR = IO0DIR & (~(1<<BIT5));  // Clr_Bit(IO0DIR,BIT5) --> SWITCH AS INPUT
	IO0DIR = IO0DIR | (1<<BIT10);    // Set_Bit(IO0DIR,BIT10) --> LED AS OUTPUT
}

void main()
{
	Power_Off_Peripherals();   // Configuring for GPIO
	Init_PLL0();               // Setting PPL0
  config_Pins();
  
	if((IO0PIN & (1<<BIT5)) == 0)
	{
		IO0SET = IO0SET | (1<<BIT10); // Set_Bit(IO0SET,BIT10);
  }
	else
	{
	  IO0CLR = IO0CLR | (1<<BIT10); // Set_Bit(IO0CLR,BIT10);
  }
}
