
#include<stdlib.h>
#include<global.h>
#include<FreeRTOS.h>
#include<task.h>
#include<pll0.h>
#include<pconp.h>
#include<pcb.h>
#include<lpc214x.h>
#include<uart0.h>
#include "semphr.h"
#include "queue.h"

void task1(void *q);
void task2(void *a);
void task3(void *q);
void config_pins(void);
xSemaphoreHandle xMutex = NULL;

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
	Init_UART0();
	//vSemaphoreCreateBinary(binarysem);
	xMutex = xSemaphoreCreateMutex();
	xTaskCreate(task1,"task1",128,NULL,1,NULL);
	xTaskCreate(task2,"task2",128,NULL,1,NULL);
	//xTaskCreate(task3,"task3",128,"Parameter Passed",1,NULL);
	vTaskStartScheduler();

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
	while(1)
	{
	xSemaphoreTake(xMutex,portMAX_DELAY);
	Set_UART_string("XYSSS");
	Set_UART_string("\r\n");
	xSemaphoreGive(xMutex);
	vTaskDelay(5);
  }
}


void task2(void *a)
{
	while(1)
	{
	xSemaphoreTake(xMutex,portMAX_DELAY);
	Set_UART_string("vinit kumar Hello world");
	Set_UART_string("\r\n");
	//Config_pins();
	//Set_Bit(IO0SET, BIT13);
	xSemaphoreGive(xMutex);
	vTaskDelay(5);
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


