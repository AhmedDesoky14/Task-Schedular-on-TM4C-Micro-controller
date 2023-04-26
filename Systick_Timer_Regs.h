/************************************************************************************************************
 * Module: Systick_Timer
 *
 * File Name: Systick_Timer_Regs.h
 *
 * Description: Registers header file for TM4C123GH6PM Micro-controller - SysTick Timer Driver - Non-AUTOSAR Driver.
 *
 * Author: Mohamed Tarek / Ahmed Desoky
 ************************************************************************************************************/
#ifndef SYSTICK_TIMER_REGS_H_
#define SYSTICK_TIMER_REGS_H_

#include "Std_Types.h"

#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))
#define NVIC_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))


#endif /* SYSTICK_TIMER_REGS_H_ */
