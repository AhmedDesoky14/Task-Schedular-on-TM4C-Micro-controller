/************************************************************************************************************
 * Module: OS
 *
 * File Name: OS.c
 *
 * Description: Source file for OS Scheduler.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
/*
 * Include needed header files
 */
#include "OS.h"
#include "App.h"

/* Global variable store the OS Time */
static uint8 g_Time_Tick_Count = 0;

/* Global variable to indicate that the timer has a new tick */
static boolean g_New_Time_Tick_Flag = 0;

/*************************************************************************************************************
* Service Name: OS_start
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description:
* Function responsible for:
* 1. Enable Interrupts
* 2. Start the OS timer
* 3. Execute the Init Task
* 4. Start the Scheduler to run the tasks
*************************************************************************************************************/
void OS_start(void)
{
    /* Global Interrupts Enable */
    Enable_Interrupts();

    /*
     * Set the Call Back function to call Os_NewTimerTick
     * this function will be called every SysTick Interrupt (20ms)
     */
    SysTick_SetCallBack(OS_NewTimerTick);

    /* Execute the Init Task */
    Init_Task();

    /* Start SysTickTimer to generate interrupt every 20ms */
    SysTick_Start(OS_BASE_TIME);

    /* Start the OS Scheduler */
    OS_Scheduler();
}

/*************************************************************************************************************
* Service Name: OS_NewTimerTick
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function called by the Systick_Timer Driver in the MCAL layer using the call back pointer
*************************************************************************************************************/
void OS_NewTimerTick(void)
{
    /* Increment the OS time by OS_BASE_TIME */
    g_Time_Tick_Count   += OS_BASE_TIME;

    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*************************************************************************************************************
* Service Name: OS_Scheduler
* Sync/Async: Synchronous
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: The Engine of the OS Scheduler used for switch between different tasks
*************************************************************************************************************/
void OS_Scheduler(void)
{
    while(1)
    {
    	/* Code is only executed in case there is a new timer tick due to the Flag condition*/
    	if(g_New_Time_Tick_Flag == 1)
    	{
    		switch(g_Time_Tick_Count)
    		{
				case 20:
				case 100:
					Button_Task();
					g_New_Time_Tick_Flag = 0;
					break;
				case 40:
				case 80:
					Button_Task();
					Led_Task();
					g_New_Time_Tick_Flag = 0;
					break;
				case 60:
					Button_Task();
					App_Task();
					g_New_Time_Tick_Flag = 0;
					break;
				case 120:
					Button_Task();
					App_Task();
					Led_Task();
					g_New_Time_Tick_Flag = 0;
					g_Time_Tick_Count = 0;
					break;
    		}
    	}
    }
}
