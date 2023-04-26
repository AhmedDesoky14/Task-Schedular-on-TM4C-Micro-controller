/************************************************************************************************************
 * Module: Button
 *
 * File Name: Button_Cfg.h
 *
 * Description: Header file for Button Module.
 * 				This Module supports 1 Button.
 *
 * Author: Mohamed Tarek / Ahmed Desoky
 ************************************************************************************************************/
#ifndef BUTTON_CFG_H_
#define BUTTON_CFG_H_

/*
 * Include needed header files
 */
#include "Std_Types.h"

/* Button State according to its configuration PULL UP/Down */
/* Button Pin is configured in Port Driver */
/* Its configuration now is Pull Up */
#define BUTTON_PRESSED  STD_LOW
#define BUTTON_RELEASED STD_HIGH

#endif /* BUTTON_CFG_H_ */
