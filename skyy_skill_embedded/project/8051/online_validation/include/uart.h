#ifndef _uart_h_
#define _uart_h_
/*
 extern volatile unsigned char rdata;

 void Config_UART(void);

 void Set_UART_Data(unsigned char dat);

 void Set_UART_String(unsigned char *str);

 //unsigned cha Get_UART_Data(void);
 */
 
extern volatile unsigned char rdata;
 
//unsigned char Get_UART_Data(void);

void Config_UART(void);

void Set_UART_Data(unsigned char dat);

void Set_UART_String(unsigned char *str);

#endif