 /*******************************************************************************************************
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Ahmed Desoky
 *******************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_

/* Id for the company in the AUTOSAR
 * for example 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* PORT Module ID*/
#define PORT_MODULE_ID		(124U)

/* PORT Instance ID*/
#define PORT_INTSTANCE_ID	(0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3 - Note: The given SWS Version is 4.0.2
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/*
 *  Macros for Port Pin Direction Changeability
 */
#define PORT_PIN_DIRECTION_CHANGEABLE_ENABLED	(TRUE)
#define PORT_PIN_DIRECTION_CHANGEABLE_DISABLED	(FALSE)

/*
 * Macros for Port Pin Mode Changeability
 */
#define PORT_PIN_MODE_CHANGEABLE_ENABLED		(TRUE)
#define PORT_PIN_MODE_CHANGEABLE_DISABLED		(FALSE)

/*
 * Define Ports Names
 */
#define PORT_A	(0U)
#define PORT_B	(1U)
#define PORT_C	(2U)
#define PORT_D	(3U)
#define PORT_E	(4U)
#define PORT_F	(5U)

/*
 * Define Lock Register Magic Number
 */
#define LOCK_MAGIC_NUMBER	(0x4C4F434B)

/*
 * Define Max Number of Modes
 */
#define MAX_MODES_NUMBER	(15U)


/* Include Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Include Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Include Non AUTOSAR files */
#include "Common_Macros.h"

/********************************************************************************************************
 *                     				 API Service ID Macros
 *******************************************************************************************************/
/* Service ID for PORT Init */
#define PORT_INIT_SID						((uint8) 0x00)

/*Service ID for PORT Set Pin Direction*/
#define PORT_SET_PIN_DIRECTION_SID			((uint8) 0x01)

/* Service ID for PORT Refresh Port Direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID		((uint8) 0x02)

/* Service ID for PORT Get Version Info*/
#define PORT_GET_VERSION_INFO_SID			((uint8) 0x03)

/* Service ID for PORT Set Pin Mode*/
#define PORT_SET_PIN_MODE_SID				((uint8) 0x04)

/********************************************************************************************************
 *                     					DET Errors Codes
 *******************************************************************************************************/
/*	PORT051:	*/
/* DET Code to report Invalid Port Pin*/
#define PORT_E_PARAM_PIN					((uint8) 0x0A)

/* DET Code to report changing direction of a Pin has unchangeable direction */
#define PORT_E_DIRECTION_UNCHANGEABLE		((uint8) 0x0B)

/* DET Code to report Port_Init called with wrong parameter or passing a Null Pointer to Structure to it*/
#define PORT_E_PARAM_CONFIG					((uint8) 0x0C)

/* DET Code to report Invalid Set Pin Mode*/
#define PORT_E_PARAM_INVALID_MODE 			((uint8) 0x0D)

/*DET Code to report changing mode of a Pin has unchangeable mode */
#define PORT_E_MODE_UNCHANGEABLE 			((uint8) 0x0E)

/*DET Code to report API Service Called without module initialization */
#define PORT_E_UNINIT 						((uint8) 0x0F)

/* DET Code to report passing Null pointer to an API Service */
#define PORT_E_PARAM_POINTER 				((uint8) 0x10)

/********************************************************************************************************
 *                     					Module Data Types
 *******************************************************************************************************/

/* Type definition for Port_PinType used by the Port APIs*/
typedef uint8 Port_PinType;

/* Type definition for Port_PortType used for Pin Config */
typedef uint8 Port_PortType;

/* Type definition for Port_LevelType used by the Port APIs */
typedef uint8 Port_LevelType;

/* Type definition for Port_PinModeType used by the Port APIs */
typedef uint8 Port_PinModeType;

/* Type definition for PinDirectionChangeable used by the Port APIs */
typedef boolean Port_PinDirectionChangeable;

/* Type definition for PinModeChangeable used by the Port APIs */
typedef boolean Port_PinModeChangeable;

/* Enumeration holds Port_PinDirectionType*/
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Enumeration holds Port_InternalResistance*/
typedef enum
{
	INTERNAL_PULL_UP,INTERNAL_PULL_DOWN,NO_INTERNAL_RESISTANCE
}Port_InternalResistanceType;

/* Enumeration holds either Pin is in Analog Mode or Not */
typedef enum
{
	ANALOG_MODE_OFF,ANALOG_MODE_ON
}Port_AnalogModeType;

/* Enumeration holds either Pin is in Digital Mode or Not */
typedef enum
{
	DIGITAL_MODE_OFF,DIGITAL_MODE_ON
}Port_DigitalModeType;

/* Structure contains Pins Configurations */
typedef struct
{
	/* Member contains Configured Pin Port Number */
	Port_PortType Port_Num[PORT_CONFIGURED_PINS];
	/* Member contains configured Pin Number*/
	Port_PinType Port_Pin_Num[PORT_CONFIGURED_PINS];
	/* Member contains Config of either the pin is in Analog mode or not */
	Port_AnalogModeType Port_AnlaogMode[PORT_CONFIGURED_PINS];
	/* Member contains Config of either the pin is in Digital mode or not */
	Port_DigitalModeType Port_DigitalMode[PORT_CONFIGURED_PINS];
	/* Member contains Config of Pin Mode */
	Port_PinModeType Pin_Mode[PORT_CONFIGURED_PINS];	/* User Must know every mode number from micro-controller*/
														/* data-sheet to re-configure Port Driver*/
	/* Member contains Config of Pin Direction */
	Port_PinDirectionType Pin_Direction[PORT_CONFIGURED_PINS];
	/* Member contains Config of Pin Internal Resistance Type */
	Port_InternalResistanceType	Pin_InternalResistance[PORT_CONFIGURED_PINS];
	/* Member contains Config of Pin Initial Level Value */
	Port_LevelType Pin_InitialLevelValue[PORT_CONFIGURED_PINS];
	/* Member contains Config of Pin Mode Changeability */
	Port_PinModeChangeable	Pin_ModeChangeable[PORT_CONFIGURED_PINS];
	/* Member contains Config of Pin Direction Changeability */
	Port_PinDirectionChangeable	Pin_DirectionChangeable[PORT_CONFIGURED_PINS];
}Port_ConfigType;

/********************************************************************************************************
 *                     					Functions Prototypes
 *******************************************************************************************************/
/* Function for Port Initialization */
void Port_Init(const Port_ConfigType* ConfigPtr);

/* Function for Port SetPinDirection During Run Time */
#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin_ID,Port_PinDirectionType Direction);
#endif

/* Function to Refresh Directions of Pins During Run Time */
void Port_RefreshPortDirection(void);

/* Function to get Port Module Version Info */
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/* Function to SetPinMode During Run Time */
#if(PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin_ID,Port_PinModeType Mode);
#endif

/********************************************************************************************************
 *                     					External Variables
 *******************************************************************************************************/
/* Extern PB Structure to be used by Port and other Modules*/
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H_ */
