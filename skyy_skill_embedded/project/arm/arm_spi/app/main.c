#include<lpc2148.h>
#include<pconp.h>
#include<pll0.h>
#include<global.h>
#include<delay.h>
#include<spi.h>
#include<lcd.h>
#include<pcb.h>


int main()
{
	unsigned char rData = 0;
	Power_Off_Peripherals();
	Init_PLL0();
	Init_Lcd();
	Init_Spi0();
	
	Set_SPI0_String("Vinit Kumar");
	
	while(1)
	{
		rData = Get_SPI0_Data();
		Set_Lcd_Command(0x80);
		Set_Lcd_Char(rData);
//		Set_Lcd_String(rData);
		delay(500);
   }
}
