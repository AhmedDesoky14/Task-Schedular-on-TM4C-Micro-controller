/************************************************************************************************************
 * Module: Led
 *
 * File Name: Led_Cfg.h
 *
 * Description: Header file for Led Module.
 * 				This Module supports 1 Led.
 *
 * Author: Mohamed Tarek / Ahmed Desoky
 ************************************************************************************************************/
#ifndef LED_CFG_H_
#define LED_CFG_H_

/*
 * Include needed header files
 */
#include "Std_Types.h"

/* Led State according to its configuration Positive logic or Negative logic */
/* Led Pin is configured in Port Driver */
/* Its configuration now is Positive Logic */
#define LED_ON 		STD_HIGH
#define LED_OFF 	STD_LOW

#endif /* LED_CFG_H_ */
