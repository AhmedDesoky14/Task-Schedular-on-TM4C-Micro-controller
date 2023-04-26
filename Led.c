/************************************************************************************************************
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 * 				This Module supports 1 Led.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
/*
 * Include needed header files
 */
#include "Led.h"
#include "Dio.h"

/*************************************************************************************************************
* Service Name: LED_setOn
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set ON the Led
*************************************************************************************************************/
void LED_setOn(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,LED_ON);  /* LED ON */
}

/*************************************************************************************************************
* Service Name: LED_setOff
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set OFF the Led
*************************************************************************************************************/
void LED_setOff(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,LED_OFF); /* LED OFF */
}

/*************************************************************************************************************
* Service Name: LED_toggle
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to toggle the Led
*************************************************************************************************************/
void LED_toggle(void)
{
    Dio_LevelType state = Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
}

/*************************************************************************************************************
* Service Name: LED_refreshOutput
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refresh the Led output
*************************************************************************************************************/
void LED_refreshOutput(void)
{
    Dio_LevelType state = Dio_ReadChannel(DioConf_LED1_CHANNEL_ID_INDEX);
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,state); /* re-write the same value */
}
