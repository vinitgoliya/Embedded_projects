#include<lcd.h>
#include<reg51.h>
#include<global.h>
#include<delay.h>

void Set_LCD_Clock(void)
  {
		Clr_Bit(P3, BIT7);
		delay(1000);
		Set_Bit(P3, BIT7);
	} 
	
void Write_LCD_Port(unsigned char value)
  {
		LCD_PORT = value;
	}
	
void Set_LCD_Command(unsigned char command)
   {
		 Write_LCD_Port(command);
		 Set_LCD_Command_Mode();
		 Set_LCD_Clock();
	 }
	 
void Set_LCD_Char(unsigned char dat)
  {
		Write_LCD_Port(dat);
		Set_LCD_Data_Mode();
		Set_LCD_Clock();
	}
	
void Init_LCD(void)
  {
		Set_LCD_Command(0x38);  // 	2 lines and 5×7 matrix
		Set_LCD_Command(0x0E);  // Display on, cursor blinking
		Set_LCD_Command(0x06); // Increment cursor (shift cursor to right)
	}
	
void Set_LCD_String(unsigned char *str)
  {
		while(*str != '\0')
		  {
				Set_LCD_Char(*str);
				str++;
			}
	}