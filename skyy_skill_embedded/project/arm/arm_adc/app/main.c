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
	//u8_t str_adc_value[6];
	Init_PLL0();

	Init_Lcd();

  DE_Select_ADC0_Input(); // Deselect all ADC inputs
	
  Config_ADC_Pin();           // Configure ADC pin
	
	Disable_ADC0_Powerdownmode(); // operational ADC0
	
  Power_On_ADC0();        // Power on ADC

  Set_ADC0_Clock();       // Set ADC clock
	
  Select_AD01();          // Select ADC channel 1
	
	
	while(1)
	{
		
	adc_Count = Get_AD01_Count();  // Read ADC value
  voltage_measured = adc_Count * 3;  // Convert to voltage (1 count = 3mV)
 
	Set_Lcd_Command(0x80);
  Set_Lcd_num(voltage_measured);
	//Set_Lcd_String(str_adc_value);
	//Set_Lcd_String("Hello World");
		
	delay(500);
	}
	
}

