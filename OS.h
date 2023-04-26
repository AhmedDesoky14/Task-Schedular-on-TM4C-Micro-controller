/************************************************************************************************************
 * Module: OS
 *
 * File Name: OS.h
 *
 * Description: Header file for OS Scheduler.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
#ifndef OS_H_
#define OS_H_

/*
 * Include needed header files
 */
#include "Std_Types.h"

/* Define Timer base counting time in ms */
#define OS_BASE_TIME 20

/************************************* Assembly Instructions Macros *****************************************/
/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")
/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")
/*************************************************************************************************************
 *                     					Functions Prototypes
 ************************************************************************************************************/
/* Function responsible for:
 * 1. Enable Interrupts
 * 2. Start the OS timer
 * 3. Execute the Init Task
 * 4. Start the Scheduler to run the tasks
 */
void OS_start(void);

/* The Engine of the OS Scheduler used for switch between different tasks */
void OS_Scheduler(void);

/* Function called by the Systick_Timer Driver in the MCAL layer using the call back pointer */
void OS_NewTimerTick(void);

#endif /* OS_H_ */
