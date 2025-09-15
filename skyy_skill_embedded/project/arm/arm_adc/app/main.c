#include<global.h>
#include<pcb.h>
#include<lpc2148.h>
#include<pll0.h>
#include<lcd.h>
#include<delay.h>
#include<pconp.h>
#include<adc.h>

int main()
{
	unsigned int adc_Count;
  int voltage_measured=0;
	Init_PLL0();

	Init_ADC0();
	
	Init_Lcd();
	
	while(1)
	{
		
	adc_Count = Get_AD01_Count();  // Read ADC value
  voltage_measured = adc_Count * 3;  // Convert to voltage (1 count = 3mV)
 
	Set_Lcd_Command(0x80);
  Set_Lcd_Long(voltage_measured);
	//Set_Lcd_Long(99434399);
	// Set_Lcd_String(str_adc_value);
	//Set_Lcd_String("Hello World");
		
	delay(500);
	}
	
}

