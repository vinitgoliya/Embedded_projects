#include<global.h>
#include<pcb.h>
#include<lpc2148.h>
#include<pll0.h>
#include<lcd.h>
#include<delay.h>
#include<adc.h>
#include<pconp.h>

/*
#define Disable_ADC0_Powerdownmode()     Set_Bit(AD0CR,BIT21)
#define Enable_ADC0_Powerdownmode()      Clr_Bit(AD0CR,BIT21)
#define Select_AD01()     Set_Bit(AD0CR,BIT1)
#define Select_AD02()     Set_Bit(AD0CR,BIT2)
#define Start_ADC0()       Set_Bit(AD0CR,BIT24)
#define Stop_ADC0()        Clr_Bit(AD0CR,BIT24)
#define Wait_ADC0()    while(!(AD0DR1 & (1<<BIT31)))
*/

void init_ADC0(void)
{
	DE_Select_ADC0_Input(); // Deselect all ADC inputs
	
  Config_ADC_Pin();           // Configure ADC pin
	
	Disable_ADC0_Powerdownmode(); // operational ADC0
	
  Power_On_ADC0();        // Power on ADC

  Set_ADC0_Clock();       // Set ADC clock
	
  Select_AD01();          // Select ADC channel 1
}


void Config_ADC_Pin()
{
	PINSEL1.P0_28 = P0_28_AD01;	
}

void DE_Select_ADC0_Input()
{

  Clr_Bit(AD0CR,BIT0);
	Clr_Bit(AD0CR,BIT1);
	Clr_Bit(AD0CR,BIT2);
	Clr_Bit(AD0CR,BIT3);
	Clr_Bit(AD0CR,BIT4);
	Clr_Bit(AD0CR,BIT5);
	Clr_Bit(AD0CR,BIT6);
	Clr_Bit(AD0CR,BIT7);
//OR

//AD0CR = AD0CR & (~(0x000000FF));
}

void Set_ADC0_Clock()
{
	AD0CR |= (59 << 8);
	//AD0CR |= (14 << 8);
 // AD0CR = (AD0CR & 0xFFFF00FF) | (59<<8);
//	 AD0CR = (AD0CR & 0xFFFF00FF) | (1<<8);
}


//void Set_ADC0_Clock(void)
//{
//	AD0CR |= (1<<BIT13) | (1<<BIT10); // DIV = 39
	// ADC_CLOCK = PCLK/(DIV + 1)
	//           = (60/40)MHz
	//			     = 1.5MHz
//}

// Get ADC count value
unsigned int Get_AD01_Count() {
    unsigned int adc_result = 0;
    Start_ADC0();      // Start conversion
    Wait_ADC0();       // Wait for conversion to finish
    adc_result = (AD0DR1 >> 6) & 0x3FF;  // Extract 10-bit result
    Stop_ADC0();       // Stop ADC
    return adc_result;
}
