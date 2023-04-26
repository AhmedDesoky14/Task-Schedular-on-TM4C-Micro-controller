/************************************************************************************************************
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *				This Module supports 1 Button.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

/*
 * Include needed header files
 */
#include "Button_Cfg.h"

/*************************************************************************************************************
 *                     					Functions Prototypes
 ************************************************************************************************************/
/* Function to get button state */
uint8 BUTTON_getState(void);

/* Function to check and refresh button state */
void BUTTON_refreshState(void);

#endif /* BUTTON_H_ */
