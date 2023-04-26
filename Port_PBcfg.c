 /*******************************************************************************************************
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Ahmed Desoky
 *******************************************************************************************************/

#include "Port.h"
/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)
/*
 * AUTOSAR Version 4.0.3 - Note: The given SWS Version is 4.0.2
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/*	PB Structure Used*/
/* Arrange the configuration according to their ID */
/* Add Every Pin Mode Number according to micro-controller data-sheet */
const Port_ConfigType Port_Configuration =
{
		/* Index 0 */								/* Index 1 */
PortConf_LED1_PORT_NUM,						PortConf_SW1_PORT_NUM,
PortConf_LED1_PIN_NUM,						PortConf_SW1_PIN_NUM,
ANALOG_MODE_OFF,							ANALOG_MODE_OFF,
DIGITAL_MODE_ON,							DIGITAL_MODE_ON,
DIGITAL_IO,									DIGITAL_IO,
PORT_PIN_OUT,								PORT_PIN_IN,
NO_INTERNAL_RESISTANCE,						INTERNAL_PULL_UP,
STD_LOW,									STD_HIGH,
PORT_PIN_MODE_CHANGEABLE_DISABLED,			PORT_PIN_MODE_CHANGEABLE_DISABLED,
PORT_PIN_DIRECTION_CHANGEABLE_DISABLED,		PORT_PIN_DIRECTION_CHANGEABLE_DISABLED
};
