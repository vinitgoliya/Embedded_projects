#include<reg51.h>
#include<lcd.h>
#include<global.h>
#include<stepper.h>
#include<delay.h>
#include<home.h>

void main() {
    int door_status = 0;
    int fan_status = 0;
    int light_status = 0;
    int door_pressed = 0;
    int fan_pressed = 0;
    int light_pressed = 0;
    Clr_Bit(P3,0);
    Init_LCD();
    Set_LCD_Command(0x01);  // Clear LCD screen

    while (1) {
        
        if (DOOR == 0 && !door_pressed) {  
            delay(5000);  
            if (DOOR == 0) {
                door_pressed = 1;  
                if (door_status == 0) {
                    openDoor();
                    door_status = 1;
                } else {
                    closeDoor();
                    door_status = 0;
                }
            }
        } else if (DOOR == 1) {
            door_pressed = 0; 
        }

       
        if (FAN == 0 && !fan_pressed) {
            delay(5000);  
            if (FAN == 0) {
                fan_pressed = 1;
                if (fan_status == 0) {
                    fanon();
                    fan_status = 1;
                } else {
                    fanoff();
                    fan_status = 0;
                }
            }
        } else if (FAN == 1) {
            fan_pressed = 0;
        }

    
        if (LIGHT == 0 && !light_pressed) {
            delay(5000);
            if (LIGHT == 0) {
                light_pressed = 1;
                if (light_status == 0) {
                    lighton();
                    light_status = 1;
                } else {
                    lightoff();
                    light_status = 0;
                }
            }
        } else if (LIGHT == 1) {
            light_pressed = 0;
        }
    }
}
