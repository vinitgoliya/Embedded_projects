#include<global.h>
#include<LPC2148.h>
#include<pcb.h>
#include<delay.h>

void config_Pins()
{

  PINSEL0.P0_12 = P0_12_GPIO;
  IO0DIR |= (1<<BIT12);    // Set_Bit(IO0DIR,BIT12)
}

void main()
{
  config_Pins();
	while(1)
	{
		IO0SET |=(1<<BIT12);  // Set_Bit(IO0SET,BIT12);  // LED ON
		delay(30000);
    IO0CLR |=(1<<BIT12);   // Set_Bit(IO0CLR,BIT12)  // LED OFF
    delay(30000);
	}
}
