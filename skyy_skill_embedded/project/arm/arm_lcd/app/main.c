#include<global.h>
#include<pcb.h>
#include<lpc2148.h>
#include<pll0.h>
#include<lcd.h>
#include<delay.h>



int main()
{
	Init_PLL0();
	Init_Lcd();
	while(1)
	{
	Set_Lcd_Command(0x80);
	
	Set_Lcd_String ("SASWAT PRADHAN");
	}
	
}
