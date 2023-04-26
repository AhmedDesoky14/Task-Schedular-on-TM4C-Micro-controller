/************************************************************************************************************
 * Module: Systick_Timer
 *
 * File Name: Systick_Timer.h
 *
 * Description: Header file for TM4C123GH6PM Micro-controller - SysTick Timer Driver - Non-AUTOSAR Driver.
 *
 * Author: Mohamed Tarek / Ahmed Desoky
 ************************************************************************************************************/
#ifndef SYSTICK_TIMER_H_
#define SYSTICK_TIMER_H_

/*
 * Include Used header files
 */
#include "Std_Types.h"
#include "Common_Macros.h"
#include "Systick_Timer_Cfg.h"
#include "Systick_Timer_Regs.h"

/*
 * Define necessary values
 */
#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_INTERRUPT_PRIORITY  3
#define SYSTICK_PRIORITY_BITS_POS   29
#define ITERATIONS_FOR_1MS				((ECU_CPU_DOMINANT_FREQ_MHz*1000))

/*************************************************************************************************************
 *                     					Functions Prototypes
 ************************************************************************************************************/
/* Function to start Timer */
void SysTick_Start(uint16 Tick_Time);

/* Function to stop Timer */
void SysTick_Stop(void);

/* Function to Setup the SysTick Timer call back */
void SysTick_SetCallBack(void (*Ptr2Func)(void));

#endif /* SYSTICK_TIMER_H_ */
