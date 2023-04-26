/************************************************************************************************************
 * Module: Application
 *
 * File Name: App.h
 *
 * Description: Header file for Application Tasks.
 *
 * Author: Mohamed Tarek
 ************************************************************************************************************/
#ifndef APP_H_
#define APP_H_

/*
 * Include needed header files
 */
#include "Std_Types.h"
/*************************************************************************************************************
 *                     					Tasks Prototypes
 ************************************************************************************************************/
/* Task executes once to initialize all the Modules */
void Init_Task(void);

/* Task executes every 20 Mili-seconds to check the button state */
void Button_Task(void);

/* Task executes every 40 Mili-seconds to refresh the LED */
void Led_Task(void);

/* Task executes every 60 Mili-seconds to get the button status and toggle the led */
void App_Task(void);

#endif /* APP_H_ */
