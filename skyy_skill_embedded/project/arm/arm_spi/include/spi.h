#ifndef	__SPI_H
#define	__SPI_H

#define Wait_for_Status()     while(!(S0SPSR & (1<<BIT7)))
	 
void Init_Spi0(void);

void Set_SPI0_Data(unsigned char Dat); 
void Set_SPI0_String(unsigned char *str);
unsigned char Get_SPI0_Data(void);

#endif

