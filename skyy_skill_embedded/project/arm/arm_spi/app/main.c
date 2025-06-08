#include<lpc2148.h>
#include<pconp.h>
#include<pll0.h>
#include<global.h>
#include<delay.h>
#include<spi.h>
#include<lcd.h>
#include<pcb.h>
/*
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
	
	Set_SPI0_Data('A');
	
	//Set_SPI0_String("Vinit Kumar");
	
	rData = Get_SPI0_Data();
	Set_Lcd_Command(0x80);
	Set_Lcd_Char(rData);
	
	while(1)
	{
	//	rData = Get_SPI0_Data();
	//	Set_Lcd_Command(0x80);
	//	Set_Lcd_Char(rData);
	//	Set_Lcd_Char('A');
//		Set_Lcd_String(rData);
		delay(5000);
   }
}
*/






void SPI_Master_Write(char data)
{
//	char flush;
	IO0CLR = (1<<7);  /* SSEL = 0, enable SPI communication with slave */
	S0SPDR = data;  /* Load data to be written into the data register */
	while ( (S0SPSR & 0x80) == 0 );  /* Wait till data transmission is completed */
//	flush = S0SPDR;
	IO0SET = (1<<7);  /* SSEL = 1, disable SPI communication with slave */
}

char SPI_Master_Read()
{
	IO0CLR = (1<<7);  /* SSEL = 0, enable SPI communication with slave */
	S0SPDR = 0xFF;  /* Transmit Flush byte */
	while ( (S0SPSR & 0x80) == 0 );  /* Wait till data transmission is completed */
	IO0SET = (1<<7);  /* SSEL = 1, disable SPI communication with slave */
	return S0SPDR;  /* Return the data received */
}



int main(void)
{
	char rData ;
	Power_Off_Peripherals();
	Init_PLL0();
	Init_Lcd();
	Init_Spi0();
	
	SPI_Master_Write('A');
	delay(5000);
	rData = SPI_Master_Read();
	Set_Lcd_Command(0x80);
	Set_Lcd_Char(rData);
}

