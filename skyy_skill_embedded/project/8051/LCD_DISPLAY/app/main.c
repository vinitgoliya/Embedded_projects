#include<reg51.h>
#include<delay.h>
#include<global.h>
#include<lcd.h>



	
void main()
  {
		Init_LCD();
		while(1)
		{
		Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		Set_LCD_String("Vinit");
		//Set_LCD_Char('A');
		Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		Set_LCD_String("Goliys");
	//	Set_LCD_Char('B');
		}
	}
	 

	 
