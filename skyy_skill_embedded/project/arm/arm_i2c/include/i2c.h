#ifndef _I2C_h_
#define _I2C_h_

#define ASSERT_ACK_BIT()     I2C0CONSET |= (1<<BIT2)

#define ACCERT_NACK_BIT()    I2C0CONCLR |= (1<<BIT2)

#define ENABLE_START_BIT()   I2C0CONSET |= (1<<BIT5)

#define DISABLE_START_BIT()  I2C0CONCLR |= (1<<BIT5)

#define ENABLE_STOP_BIT()    I2C0CONSET |= (1<<BIT4)

#define ENABLE_I2C_BIT()     I2C0CONSET |= (1<<BIT6)

#define DISABLE_I2C_BIT()    I2C0CONCLR |= (1<<BIT6)

#define CLR_SI_BIT()         I2C0CONCLR |= (1<<BIT6)

void Config_I2C0_Pins(void);

void Set_I2C_Clock(void);

void Wait_Fot_status(void);

void Start_I2C0(unsigned char slave_adress);

void Set_I2C0_data(unsigned char DAT);

void Stop_I2C0(void);

unsigned char Get_I2C_Data(void);

unsigned char Get_I2C_Data_Last(void);

void Init_I2C0(void);



















#endif 
