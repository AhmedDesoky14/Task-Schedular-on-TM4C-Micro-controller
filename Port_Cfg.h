/*******************************************************************************************************
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Ahmed Desoky
 *******************************************************************************************************/
#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3 - Note: The given SWS Version is 4.0.2
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT               (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API				(STD_ON)

/* Pre-compile option for Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_API			(STD_ON)

/* Pre-compile option for Set Pin Mode API */
#define PORT_SET_PIN_MODE_API				(STD_ON)

/* Number of Configured Port Pins*/	/*SWS Item: PORT124_Conf*/
#define PORT_CONFIGURED_PINS				(2U)

/* Default I/O Digital Port Mode Number for all Pins */
#define DIGITAL_IO							(0U)

/* Pins Index in the array of structures in Port_PBcfg.c */	/*SWS Item: PORT127_Conf*/
#define PortConf_LED1_PIN_ID_INDEX        (uint8)0x00
#define PortConf_SW1_PIN_ID_INDEX         (uint8)0x01

/* Port Configured Port Numbers  */
#define PortConf_LED1_PORT_NUM                (Port_PortType)5 /* PORTF */
#define PortConf_SW1_PORT_NUM                 (Port_PortType)5 /* PORTF */

/* Port Configured Pins Numbers */
#define PortConf_LED1_PIN_NUM             (Port_PinType)1 /* Pin 1 in PORTF */
#define PortConf_SW1_PIN_NUM              (Port_PinType)4 /* Pin 4 in PORTF */

#endif /* PORT_CFG_H_ */
