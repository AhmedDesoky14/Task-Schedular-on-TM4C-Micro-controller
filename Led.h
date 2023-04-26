/************************************************************************************************************
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *				This Module supports 1 Led.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/*
 * Include needed header files
 */
#include "Led_Cfg.h"
/*************************************************************************************************************
 *                     					Functions Prototypes
 ************************************************************************************************************/
/* Function to set Led ON */
void LED_setOn(void);

/* Function to set Led OFF */
void LED_setOff(void);

/* Function to toggle Led */
void LED_toggle(void);

/* Function to refresh Led output */
void LED_refreshOutput(void);

#endif /* LED_H_ */
