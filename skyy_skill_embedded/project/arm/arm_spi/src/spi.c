#include<spi.h>
#include<pcb.h>
#include<pconp.h>
#include<pcb.h>
#include<global.h>
#include<lpc2148.h>


static void config_SPI0_Pins()
{
  PINSEL0.P0_4 = P0_4_SCK0;
  PINSEL0.P0_5 = P0_5_MISO0;
  PINSEL0.P0_6 = P0_6_MOSI0;
  PINSEL0.P0_7 = P0_7_SSEL0;

  Set_Bit(IO0DIR,BIT7);     // IO0DIR = IO0DIR | (1<<BIT7);
  Set_Bit(IO0SET,BIT7);     // IO0SET = IO0SET | (1<<BIT7);   -----> De selecting slave
  
}


void Init_Spi0()
{
	config_SPI0_Pins();
	Power_On_SPI0();
	S0SPCCR = 0x3c;  // set clock to 1 MHz
	S0SPCR = 0x0020; // SPIO is configured as master
}

void Set_SPI0_Data(unsigned char Dat)     // Always not 8 bit data ...It may be 10 bit also.. According that decide data type
{
   //unsigned char Value;
   //Set_Bit(IO0CLR,BIT7);    // Select the slave
	 Clr_Bit(IO0CLR,BIT7);    // Select the slave
   S0SPDR = Dat;
   Wait_for_Status();
  // Value = S0SPDR;
	 Set_Bit(IO0SET, BIT7);    // Deselect slave (pull high)
}

void Set_SPI0_String(unsigned char *str)
{
  while(*str != '\0')
  {
   Set_SPI0_Data(*str);
   str++;
  }
}

unsigned char Get_SPI0_Data()
{
  Clr_Bit(IO0CLR, BIT7);   // Select slave
  S0SPDR = 0x55;             // Send dummy byte
  Wait_for_Status();
  Set_Bit(IO0SET, BIT7);     // Deselect slave
  return S0SPDR;             // Return received byte
}


/*
unsigned char Get_SPI0_Data()
{
 // unsigned char Value;
  S0SPDR = 0x55;  // Dummy Data pass to get actual slave data
  Wait_for_Status();
  //Value = S0SPDR;     // Actual Data - slave will send through S0SPDR register
  return S0SPDR;
	//return Value;
}
*/

