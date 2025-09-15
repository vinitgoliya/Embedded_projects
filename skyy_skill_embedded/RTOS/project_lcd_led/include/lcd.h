#ifndef _LCD_H_
#define _LCD_H_


void Set_Lcd_Command(u8_t cmd);
void Set_Lcd_Char(u8_t char1);
void Set_Lcd_String(u8_t *);
void Set_Lcd_String_Scrolling(u8_t *str);
void Set_Lcd_num(u32_t num);
void Init_Lcd(void);

#endif
