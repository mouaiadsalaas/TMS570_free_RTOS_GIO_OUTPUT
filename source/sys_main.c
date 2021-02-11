//
//#include "gio.h"
//
///* USER CODE END */
//
//void main(void) {
//
///* USER CODE BEGIN (3) */
//
//gioInit();
//while(1) {
//        gioToggleBit(gioPORTA, 2U);
//}
//
///* USER CODE END */
//
//}
#include "sys_common.h"
#include "system.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* USER CODE BEGIN (1) */
/* Include FreeRTOS scheduler files */
#include "FreeRTOS.h"
#include "os_task.h"

/* Include HET header file - types, definitions and function declarations for system driver */
#include "het.h"
#include "gio.h"

/* Define Task Handles */
xTaskHandle xTask1Handle,
            xTask2Handle;

/* Task1 */
void vTask1(void *pvParameters)
{
    for(;;)
    {
        /* Taggle HET[1] with timer tick */
        gioSetBit(gioPORTA, 2U,  1);
        vTaskDelay(100);
        gioSetBit(gioPORTA, 2U,  0);
        vTaskDelay(100);
    }
}

/* Task2 */
void vTask2(void *pvParameters)
{
    for(;;)
    {
        /* Taggle HET[1] with timer tick */
        gioSetBit(hetPORT1, 8, gioGetBit(hetPORT1, 8) ^ 1);
//        gioSetBit(gioPORTA, 2U,  1);
//
        vTaskDelay(100);
    }
}
/* USER CODE END */


/* USER CODE BEGIN (2) */
/* USER CODE END */


void main(void)
{
/* USER CODE BEGIN (3) */
    gioInit();
    gioSetDirection(gioPORTA, 0xFFFFFFFF);
    gioSetDirection(hetPORT1, 0xFFFFFFFF);
    gioSetBit(gioPORTA, 2U,  1);

    /* Create Task 1 */
    if (xTaskCreate(vTask1,"Task1", configMINIMAL_STACK_SIZE, NULL, 1, &xTask1Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }

    /* Create Task 1 */
    if (xTaskCreate(vTask2,"Task2", configMINIMAL_STACK_SIZE, NULL, 1, &xTask2Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }
    /* Start Scheduler */
    vTaskStartScheduler();

    /* Run forever */
    while(1);
/* USER CODE END */
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
