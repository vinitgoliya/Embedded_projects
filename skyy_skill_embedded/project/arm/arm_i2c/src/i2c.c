#include <i2c.h>
#include <global.h>
#include <lpc2148.h>
#include <pll0.h>
#include <pconp.h>
#include <pcb.h>

void Config_I2C0_Pins(void)
{
	PINSEL0.P0_2 = P0_2_SCL0;
  PINSEL0.P0_3 = P0_3_SDA0;
}

void Set_I2C_Clock(void)
{
	/*
	I2C0SCLL - It will consist low cycle of SCL
  I2C0SCLH - It will consist High cycle of SCL

  I2C-> For setting clock we will consider 50% duty cycle
  Ton -> 50%   Toff-50%

 I2c Frequency = FpCLK/I2C0SCLL + I2C0SCLH

 Clock Frequency = 100 Khz
 Fpclk = 60 MHz
	*/

	 I2C0SCLL = 300;
   I2C0SCLH = 300;
}

/*
- Enable of I2C0
ENABLE_I2C_BIT();      // Let decide later what to do with that
*/


void Wait_Fot_status(void)
{
   CLR_SI_BIT();    // data is passing
   while(!(I2C0CONSET & (1<<BIT3)));     // Wait for I2C bus busy
}

/*
-> Send the start condition
-> Wait for I2C bus Status
-> Disable the start Bit
-> Send slave address
-> Wait for status
*/

void Start_I2C0(unsigned char slave_adress)
{
  ENABLE_START_BIT();
  Wait_Fot_status();
  DISABLE_START_BIT();
  I2C0DAT = slave_adress;
  Wait_Fot_status();
}

// Send Data to slave
void Set_I2C0_data(unsigned char DAT)
{
 I2C0DAT = DAT;
 Wait_Fot_status();
}

void Stop_I2C0(void)
{
	CLR_SI_BIT();
  ENABLE_STOP_BIT();
}


//Receiving Data 
unsigned char Get_I2C_Data(void)
{
	unsigned char raw_data = 0;
	Wait_Fot_status();
	ASSERT_ACK_BIT();
	raw_data = I2C0DAT;
	return raw_data;
}

unsigned char Get_I2C_Data_Last(void)
{
	unsigned char raw_data = 0;
	Wait_Fot_status();
	ACCERT_NACK_BIT();
	raw_data = I2C0DAT;
	return raw_data;
}

void Init_I2C0(void)
{
	Config_I2C0_Pins();
	Power_On_I2C0();
	Set_I2C_Clock();
}


