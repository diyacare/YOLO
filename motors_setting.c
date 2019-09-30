#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "proj_inc/motors_setting.h"


void homingSetup()
{
	printf("YOLO is at homing setup\n");
}


void homing_state(void *param)
{
	printf("YOLO is at homing state\n");

//	gpio_set_level(LED_INDICATOR,1);
//    vTaskDelay(1000 / portTICK_PERIOD_MS);
//	gpio_set_level(LED_INDICATOR,0);
//	coreType = xPortGetCoreID();


}

void motorSteps(void *param)
{

	unsigned char motorNum;

	motorNum = (unsigned char *)param;

	do{

	}while(0/*condition to test*/);

	printf("Motor steps settings\n");
	for (int step = 0; step < 400; ++step)
	{
		if (gpio_get_level(motorParam[motorNum].stepGpio))
			break;

		gpio_set_level(MTR1_DRI, 0);
		gpio_set_level(MTR2_DRI, 0);

		//TO DO -> add task delay in here
		gpio_set_level(MTR1_DRI, 1);
		gpio_set_level(MTR2_DRI, 1);


	}


}

void motorsInit()
{
    printf("Motor init settings\n");
	gpio_set_direction(MTR1_DRI,  GPIO_MODE_OUTPUT);
    gpio_set_direction(MTR1_STEP, GPIO_MODE_OUTPUT);
    gpio_set_direction(MTR2_DRI,  GPIO_MODE_OUTPUT);
    gpio_set_direction(MTR2_STEP, GPIO_MODE_OUTPUT);

}
