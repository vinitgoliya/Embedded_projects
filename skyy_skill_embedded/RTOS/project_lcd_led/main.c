
#include<stdlib.h>
#include<global.h>
#include<FreeRTOS.h>
#include<task.h>
#include<pll0.h>
#include<pconp.h>
#include<pcb.h>
#include<lpc214x.h>
#include<uart0.h>
#include<lcd.h>
#include<delay.h>

void config_GPIO_Pins(void);
void task1(void *q);
void task2(void *a);

int main()
{
    Power_Off_Peripherals();
    Init_PLL0();
    Init_Lcd();
    //xTaskCreate(task1,"task1",128,NULL,1,NULL);
    xTaskCreate(task1, "LCDTask", 128, NULL, 1, NULL);
    xTaskCreate(task2, "LEDTask", 128, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1);
}


void task1(void *q)
{
    while (1)
    {   
			  int i = 0;
        Set_Lcd_Command(0x80);       // Move cursor to start of first line
        Set_Lcd_String("Vinit");     // Display the string

        vTaskDelay(1000); // Wait before scrolling starts

        // Scroll right until the string is out of view (assuming 16x2 LCD)
        for (i = 0; i < 16; i++)
        {
            Set_Lcd_Command(0x1C);   // Shift entire display to right
            vTaskDelay(500);
        }

        Set_Lcd_Command(0x01);       // Clear display
        vTaskDelay(500);
    }
}


void task2(void *a)
{
    config_GPIO_Pins();

    while (1)
    {   
			  int i = 0;
        for ( i = 16; i <= 19; i++)
        {
            IO1CLR = (0xF << 16);    // Clear all 4 LED bits
            IO1SET = (1 << i);       // Turn ON current LED

            vTaskDelay(500); // Delay between LEDs
        }
    }
}



void config_GPIO_Pins()
{
	

    // Configure P1.16 to P1.19 as GPIO
    PINSEL2.P1_16 = P1_16_GPIO;
    PINSEL2.P1_17 = P1_17_GPIO;
    PINSEL2.P1_18 = P1_18_GPIO;
    PINSEL2.P1_19 = P1_19_GPIO;

    // Set P1.16 to P1.19 as output
    IO1DIR |= (1 << 16);  // OR use: Set_Bit(IO1DIR, BIT16);
    IO1DIR |= (1 << 17);
    IO1DIR |= (1 << 18);
    IO1DIR |= (1 << 19);



 // PINSEL0.P0_12 = P0_12_GPIO;
//  IO0DIR |= (1<<BIT12);    // Set_Bit(IO0DIR,BIT12)
}


//#include "semphr.h"

/*
void config_GPIO_Pins(void);
void LED_Blink(void);
void task1(void *q);
void task2(void *a);
void task3(void *q);
void config_pins(void);
//xSemaphoreHandle binarysem;

void Config_pins()
{
	PINSEL0.P0_12 = P0_12_GPIO;
	PINSEL0.P0_13 = P0_13_GPIO;
	
//	PINSEL0 &= ~(0x3 << 24);  // 0x3 << 24 = 0x03000000
//	PINSEL0 &= ~(0x3 << 26);  // 0x3 << 26 = 0x0C000000
	
	
	Set_Bit(IO0DIR, BIT12);
	Set_Bit(IO0DIR, BIT13);
}


int main()
{
	Power_Off_Peripherals();
	Init_PLL0();
	Init_Lcd();

	//Init_UART0();
	//vSemaphoreCreateBinary(binarysem);
	xTaskCreate(task1,"task1",128,NULL,1,NULL);
	//xTaskCreate(task2,"task2",128,NULL,1,NULL);
	//xTaskCreate(task3,"task3",128,"Parameter Passed",1,NULL);
	vTaskStartScheduler();
//	while(1){
		
//}
}


void task1(void *q)
{

	//	while(1)
//	{
	//	rData = Get_UART0_Data();
	//	Set_UART_Data("\r\n");
	//	Set_UART_Data(rData);
//  }
	//Config_pins();
	//Set_Bit(IO0SET, BIT12);
	//vTaskDelay(9999999);
	Set_Lcd_Command(0x80);
	
	Set_Lcd_String("Vinit");
	
	while(1)
	{
		//Set_Lcd_String_Scrolling("Vinit");
		//Set_Lcd_Command(0x05);
	  vTaskDelay(500);
		Set_Lcd_Command(0x1C);   // Shift entire display to the right
		
//	xSemaphoreTake(binarysem,portMAX_DELAY);
//	Set_UART_string("XYSSS");
//	Set_UART_string("\r\n");
//	xSemaphoreGive(binarysem);
	  vTaskDelay(500);
  }
}


void task2(void *a)
{
	config_GPIO_Pins();
	while(1)
	{
//	xSemaphoreTake(binarysem,portMAX_DELAY);
//	Set_UART_string("vinit kumar Hello world");
//	Set_UART_string("\r\n");
	//Config_pins();
	//Set_Bit(IO0SET, BIT13);
//	xSemaphoreGive(binarysem);
	LED_Blink();
		
	vTaskDelay(1);
	}
}


void task3(void *q)
{
	while(1)
  {
	unsigned char *p;

	p = (unsigned char *)q;

	Set_UART_string(p);
	Set_UART_string("\r\n");
	
	vTaskDelay(1);
	}
}


void config_GPIO_Pins()
{
	

    // Configure P1.16 to P1.19 as GPIO
    PINSEL2.P1_16 = P1_16_GPIO;
    PINSEL2.P1_17 = P1_17_GPIO;
    PINSEL2.P1_18 = P1_18_GPIO;
    PINSEL2.P1_19 = P1_19_GPIO;

    // Set P1.16 to P1.19 as output
    IO1DIR |= (1 << 16);  // OR use: Set_Bit(IO1DIR, BIT16);
    IO1DIR |= (1 << 17);
    IO1DIR |= (1 << 18);
    IO1DIR |= (1 << 19);



 // PINSEL0.P0_12 = P0_12_GPIO;
//  IO0DIR |= (1<<BIT12);    // Set_Bit(IO0DIR,BIT12)
}


void LED_Blink(void)
{
	int i = 0;
	
	for(i=16;i<=19;i++)
	{
		IO1SET = (1<<i);
		vTaskDelay(500);
		IO1CLR = (1 << i);
  }
  //  IO1SET = (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19);  // LEDs ON
  //  vTaskDelay(500);

  //  IO1CLR = (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19);  // LEDs OFF
  //  vTaskDelay(500);
}
*/


