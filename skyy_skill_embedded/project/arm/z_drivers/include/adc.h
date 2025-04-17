#ifndef _adc_h_
#define _adc_h_
#include<pcb.h>
#include<lpc2148.h>
#include<pconp.h>

#define Disable_ADC0_Powerdownmode()     Set_Bit(AD0CR,BIT21)
#define Enable_ADC0_Powerdownmode()      Clr_Bit(AD0CR,BIT21)
#define Select_AD01()     Set_Bit(AD0CR,BIT1)
#define Select_AD02()     Set_Bit(AD0CR,BIT2)
#define Start_ADC0()       Set_Bit(AD0CR,BIT24)
#define Stop_ADC0()        Clr_Bit(AD0CR,BIT24)
//#define Wait_ADC0()    while(!(AD0DR1 & (1<<BIT31)))
#define Wait_ADC0()		while(!(AD0DR1 & 0x80000000))

void Config_ADC_Pin(void);

void DE_Select_ADC0_Input(void);

void Set_ADC0_Clock(void);

unsigned int Get_AD01_Count(void);

#endif
