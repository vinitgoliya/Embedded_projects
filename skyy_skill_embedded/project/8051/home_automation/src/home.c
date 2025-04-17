#include<reg51.h>
#include<home.h>
#include<lcd.h>
#include<global.h>
#include<stepper.h>
#include<delay.h>


void openDoor()
  {
		   Set_LCD_Command(0x01);  // Clear LCD screen
		 	 stepper_forward();
		 	 Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		   Set_LCD_String("DOOR");
       Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		   Set_LCD_String("OPEN");
	}
	
void closeDoor()
  {    
		   Set_LCD_Command(0x01);  // Clear LCD screen
		 	 stepper_backward();
		 	 Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		   Set_LCD_String("DOOR");
       Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		   Set_LCD_String("CLOSE");
	}
	
	void fanon()
  {
		   Set_LCD_Command(0x01);  // Clear LCD screen
		 	 stepper_forward();
		 	 Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		   Set_LCD_String("FAN");
       Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		   Set_LCD_String("ON");
	}
	
void fanoff()
  {
		   Set_LCD_Command(0x01);  // Clear LCD screen
		 	 stepper_backward();
		 	 Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		   Set_LCD_String("FAN");
       Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		   Set_LCD_String("OFF");
	}
	
void lighton()
  {
		   Set_LCD_Command(0x01);  // Clear LCD screen
		 	 Set_Bit(P3,0);
		 	 Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		   Set_LCD_String("LIGHT");
       Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		   Set_LCD_String("ON");
	}
	
void lightoff()
  {
		   Set_LCD_Command(0x01);  // Clear LCD screen
		 	 Clr_Bit(P3,0);
		 	 Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		   Set_LCD_String("LIGHT");
       Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		   Set_LCD_String("OFF");
	}