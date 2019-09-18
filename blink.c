
#include <stdio.h>

#include "driver/gpio.h"
#include "sdkconfig.h"
#include "proj_inc/main.h"
#include "proj_inc/motors_setting.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <time.h>

#define LED_INDICATOR 2

void setNewState(unsigned char newState)
{
	yoloState = newState;
}

unsigned char getState()
{
	return yoloState;
}

void initSettings()
{

	setNewState(HOMING_SETUP);
/**** ortal old tests *********/
//	gpio_pad_select_gpio(LED_INDICATOR);
//	gpio_set_direction(LED_INDICATOR, GPIO_MODE_OUTPUT);
//	xTaskCreatePinnedToCore(
//			 	 	 	 ortal,          /* Task function. */
//	                    "TaskOne",        /* String with name of task. */
//	                    10000,            /* Stack size in bytes. */
//	                    NULL,             /* Parameter passed as input of the task */
//	                    1,                /* Priority of the task. */
//	                    NULL,            /* Task handle. */
//						CORE_ZERO);
//
//	xTaskCreatePinnedToCore(
//	                    taskTwo,          /* Task function. */
//	                    "TaskTwo",        /* String with name of task. */
//	                    10000,            /* Stack size in bytes. */
//	                    NULL,             /* Parameter passed as input of the task */
//	                    1,                /* Priority of the task. */
//	                    NULL,            /* Task handle. */
//						CORE_ONE);
//	vTaskDelay(1000 / portTICK_PERIOD_MS);
}

//check
void app_main()
{
	printf("start our main loop\n");
	initSettings();
	while(1)
	{
		printf("main loop\n");

		switch (yoloState)
		{
			case HOMING_SETUP:
				break;

			case RFID_CHECK:
				break;

			case MIXING:
				break;

			case HOMING:
				break;

			case AMOUNT_SETUP:
				break;

			default:
				break;

		}


	}
}
