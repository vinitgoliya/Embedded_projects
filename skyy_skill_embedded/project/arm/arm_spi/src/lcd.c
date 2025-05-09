#include<global.h>
#include<pcb.h>
#include<lpc2148.h>
#include<lcd.h>
#include<delay.h>
#include<pll0.h>
#include<stdio.h>

/* lcd pins					        GPIO
		RS							P0_15
		RW							P0_16
		EN							P0_17
		
		D4							P0_18
		D5							P0_19
		D6							P0_20
		D7							P0_21			*/
		
#define CTRL_MASK	 (1<<BIT15)|(1<<BIT16)|(1<<BIT17)
#define DATA_MASK    (1<<BIT18)|(1<<BIT19)|(1<<BIT20)|(1<<BIT21)

//cOMAND/DATA MODE
#define Lcd_Command_Mode()			IO0CLR|=(1<<BIT15)			//RS=0 Lcd is in command mode
#define Lcd_Data_Mode()				IO0SET|=(1<<BIT15)			//RS=1 Lcd is in data mode

//READ/WRITE MODE
#define Lcd_Read_Mode()				IO0SET|=(1<<BIT16);\
								 	IO0DIR&=~(1<<BIT21)  //RW=1 to select lcd to read mode
		                              //D7 bit is cofigured as a input
#define Lcd_Write_Mode()			IO0CLR|=(1<<BIT16);\
									IO0DIR|=(1<<BIT21) //RW=0 to select lcd to write
										  //D7 bit is config as a output

//ENABLE CLOCK

#define High_Clock()	IO0SET|=(1<<BIT17)			//EN=1
#define Low_Clock()		IO0CLR|=(1<<BIT17)			//EN=0


__inline static  void Config_Lcd_Pins(void)
{
	PINSEL0.P0_15=P0_15_GPIO;
	PINSEL1.P0_16=P0_16_GPIO;
	PINSEL1.P0_17=P0_17_GPIO;
	PINSEL1.P0_18=P0_18_GPIO;
	PINSEL1.P0_19=P0_19_GPIO;
	PINSEL1.P0_20=P0_20_GPIO;
	PINSEL1.P0_21=P0_21_GPIO;
	
	
	IO0DIR |=CTRL_MASK;			//control pins confg for output
	IO0DIR |=DATA_MASK;		   //data pins config for output
  IO0CLR |=CTRL_MASK;		   //By default all pins are high so clear all pins
}

__inline static void  Write_Lcd_Port(unsigned char dat)
{
	IO0CLR =DATA_MASK;
	IO0SET =(dat<<BIT18)&(DATA_MASK);
}


/*__inline static void Get_Lcd_Status(void)
{
	Lcd_Command_Mode();
	Lcd_Read_Mode();	
	 High_Clock();
	
	while(Is_Bit_Set(IO0PIN,BIT21));
	Low_Clock();
	Lcd_Write_Mode();
}	
*/	
	

void Set_Lcd_Command(u8_t cmd)
{
	u8_t hnibble=0,lnibble=0;
	
	hnibble=cmd>>4;
	lnibble=cmd&0x0f;
	
	Lcd_Command_Mode();
	
	High_Clock();
	Write_Lcd_Port(hnibble);
	delay(500);
	Low_Clock();
	
	High_Clock();
	Write_Lcd_Port(lnibble);
	delay(500);
	Low_Clock();
	//Get_Lcd_Status();
	
}

void Set_Lcd_Char(u8_t char1)
{
	u8_t hnibble=0,lnibble=0;
	
	hnibble=char1>>4;
	lnibble=char1&0x0f;
	
	Lcd_Data_Mode();
	
	High_Clock();
	Write_Lcd_Port(hnibble);
	delay(500);
	Low_Clock();
	
	High_Clock();
	Write_Lcd_Port(lnibble);
	delay(500);
	Low_Clock();
	//Get_Lcd_Status();
}

void Set_Lcd_String(u8_t *str)
{
	
	while(*str!='\0')
	{
		Set_Lcd_Char(*str);
		str++;
	}
}

void Set_Lcd_num(u32_t num)
{
	u8_t n1=0,n2=0,n3=0;
	
	n1=num/100;
	n1%=10;
	
	n2=num%100;
	n2=n2/10;
	n2%=10;
	
	n3=num%10;
	n3%=10;
	
	Set_Lcd_Char(n1+'0');// to convert int to char
	Set_Lcd_Char(n2+'0');
	Set_Lcd_Char(n3+'0');
	/*u8_t num_str[16];  // Array to store the number as a string
  sprintf(num_str, "%d", num);  // Convert the integer to a string
	Set_Lcd_String(num_str);*/
}


/*void Set_Lcd_Float(float num)
{
	u8_t num_str[16];
	sprintf(num_str, "%.2f", num);  // Convert the float to a string
	Set_Lcd_String(num_str);
	
}*/
/*void hexa2ascii(unsigned char value)//0xff - 0 t0 255
{
	unsigned char x,d1,d2,d3;
	x = value/10;//25
	d3 = value%10;//5
	d2 = x%10;//5
	d1 = x/10;//2
	Set_Lcd_Char(d1+0x30);
	Set_Lcd_Char(d2+0x30);
	Set_Lcd_Char(d3+0x30);
}*/

void Init_Lcd(void)
{
	Config_Lcd_Pins();
	
	Lcd_Write_Mode();
	//Set_Lcd_Command(0x01);	
	//delay(500);
	Set_Lcd_Command(0x02);	
	//delay(500);
	//Set_Lcd_Command(0x0c);
	Set_Lcd_Command(0x28);		//4 bit two lines
	//delay(500);
	Set_Lcd_Command(0x0e);		//display on
	//delay(500);
	Set_Lcd_Command(0x06);		//incrementing the cursor value
	//delay(500);
}

