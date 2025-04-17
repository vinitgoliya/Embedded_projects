#ifndef _lcd_h_
#define _lcd_h_

#define LCD_PORT P2
#define Set_LCD_Command_Mode() Clr_Bit(P3, BIT5) 
#define Set_LCD_Data_Mode() Set_Bit(P3, BIT5)
void Set_LCD_Clock(void);
void Write_LCD_Port(unsigned char value);
void Set_LCD_Command(unsigned char command);
void Set_LCD_Char(unsigned char dat);
void Init_LCD(void);
void Set_LCD_String(unsigned char *);
#endif