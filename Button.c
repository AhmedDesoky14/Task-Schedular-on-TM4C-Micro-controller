/************************************************************************************************************
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Button Module.
 * 				This Module supports 1 Button.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
/*
 * Include needed header files
 */
#include "Button.h"
#include "Dio.h"

/* Define Global Static (Private) variable to store button state */
static uint8 g_button_state = BUTTON_RELEASED;

/*************************************************************************************************************
* Service Name: BUTTON_getState
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): Button State
* Return value: None
* Description: Function to get button state
*************************************************************************************************************/
uint8 BUTTON_getState(void)
{
    return g_button_state;
}

/*************************************************************************************************************
* Service Name: BUTTON_refreshState
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to check and refresh button state
*************************************************************************************************************/
void BUTTON_refreshState(void)
{
    uint8 state = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    /* Count the number of Pressed times increment if the switch pressed for 20 ms */
    static uint8 g_Pressed_Count  = 0;

    /* Count the number of Released times increment if the switch released for 20 ms */
    static uint8 g_Released_Count = 0;

    if(state == BUTTON_PRESSED)
    {
        g_Pressed_Count++;
	g_Released_Count = 0;
    }
    else
    {
	g_Released_Count++;
	g_Pressed_Count = 0;
    }

    if(g_Pressed_Count == 3)
    {
	g_button_state = BUTTON_PRESSED;
	g_Pressed_Count       = 0;
	g_Released_Count      = 0;
    }
    else if(g_Released_Count == 3)
    {
	g_button_state = BUTTON_RELEASED;
	g_Released_Count      = 0;
	g_Pressed_Count       = 0;
    }
}
