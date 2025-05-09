#include <delay.h>
#include <pconp.h>
#include <i2c.h>
#include <lcd.h>
#include <pll0.h>
#include <lpc2148.h>

int main()
{
	unsigned char received_data = 0;
	
	Power_Off_Peripherals();
	Init_PLL0();
	Init_I2C0();
  Init_Lcd();
	
	//Writing the data -> EEPROME - 0x80
	// 0x80 + write bit -> 0xA0
	
	Start_I2C0(0xA0);
	
	Set_I2C0_data('A');
	
	Stop_I2C0();
	
	// Receiving data
	Start_I2C0(0xA0);
	Set_I2C0_data(0x00); // Dummy Data
	
	Start_I2C0(0xA1);
	
	received_data = Get_I2C_Data();
	
	Stop_I2C0();
	
	while(1)
	{
	Set_Lcd_Command(0x80);
	
	//Set_Lcd_String ("SASWAT PRADHAN");
		Set_Lcd_Char(received_data);
		delay(500);
  }
}

