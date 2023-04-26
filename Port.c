 /*******************************************************************************************************
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Ahmed Desoky
 *******************************************************************************************************/

/* Including Header Files */
#include "Port.h"
#include "Port_Regs.h"

#if(PORT_DEV_ERROR_DETECT == STD_ON)
/* Include Development Error Header File */
#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif

/* Global Static (Private) Variable to clarify Port Module Status */
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;
/* GLobal Pointer to Port_ConfigType Data Type */
STATIC const Port_ConfigType* Port_PinsPtr = NULL_PTR;

/*************************************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
*************************************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INTSTANCE_ID, PORT_INIT_SID,PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		volatile uint32 *Port_Ptr = NULL_PTR; /* Points to the required Port Registers base address */
		volatile uint32 delay = 0;	/* dummy variable */
		/* Enabling Clock for all Ports A,B,C,D,E and F */
		SYSCTL_REGCGC2_REG |= (0x3F);
		delay = SYSCTL_REGCGC2_REG;	/* Making Delay */
		/************************** Initializing all pins by default settings **************************/
		/************************************* Normal Input Digital ************************************/
		/* Disabling Analog Mode */
		PORTA_AMSEL_REG &= (0XFFFFFF00);	/* 8 Pins */
		PORTB_AMSEL_REG &= (0XFFFFFF00);	/* 8 Pins */
		PORTC_AMSEL_REG &= (0XFFFFFF00);	/* 8 Pins */
		PORTD_AMSEL_REG &= (0XFFFFFF00);	/* 8 Pins */
		PORTE_AMSEL_REG &= (0XFFFFFFC0);	/* 6 Pins Only */
		PORTF_AMSEL_REG &= (0XFFFFFFE0);	/* 5 Pins Only */
		/*  Clearing Data Registers */
		PORTA_DATA_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTB_DATA_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTC_DATA_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTD_DATA_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTE_DATA_REG &= (0xFFFFFFC0);		/* 6 Pins Only */
		PORTF_DATA_REG &= (0xFFFFFFE0);		/* 5 Pins Only */
		/* Setting Ports as regular I/O Digital Ports */
		PORTA_PCTL_REG = 0x0;				/* 8 Pins */
		PORTB_PCTL_REG = 0x0;				/* 8 Pins */
		PORTC_PCTL_REG = 0x0;				/* 8 Pins */
		PORTD_PCTL_REG = 0x0;				/* 8 Pins */
		PORTE_PCTL_REG &= 0xFF000000;		/* 6 Pins Only */
		PORTF_PCTL_REG &= 0xFFF00000;		/* 5 Pins Only */
		/* Setting Ports Directions to Input */
		/* Note: All Pins are input by default */
		PORTA_DIR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTB_DIR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTC_DIR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTD_DIR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTE_DIR_REG &= (0xFFFFFFC0);		/* 6 Pins Only */
		PORTF_DIR_REG &= (0xFFFFFFE0);		/* 5 Pins Only */
		/* Disabling Alternative Functionality */
		PORTA_AFSEL_REG &= (0xFFFFFF00);	/* 8 Pins */
		PORTB_AFSEL_REG &= (0xFFFFFF00);	/* 8 Pins */
		PORTC_AFSEL_REG &= (0xFFFFFF00);	/* 8 Pins */
		PORTD_AFSEL_REG &= (0xFFFFFF00);	/* 8 Pins */
		PORTE_AFSEL_REG &= (0xFFFFFFC0);	/* 6 Pins Only */
		PORTF_AFSEL_REG &= (0xFFFFFFE0);	/* 5 Pins Only */
		/* Disabling all Internal Resistors */
		PORTA_PUR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTA_PDR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTB_PUR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTB_PDR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTC_PUR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTC_PDR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTD_PUR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTD_PDR_REG &= (0xFFFFFF00);		/* 8 Pins */
		PORTE_PUR_REG &= (0xFFFFFFC0);		/* 6 Pins Only */
		PORTE_PDR_REG &= (0xFFFFFFC0);		/* 6 Pins Only */
		PORTF_PUR_REG &= (0xFFFFFFE0);		/* 5 Pins Only */
		PORTF_PDR_REG &= (0xFFFFFFE0);		/* 5 Pins Only */
		/* Enabling Digital Functionality */
		PORTA_DEN_REG |= (0x000000FF);		/* 8 Pins */
		PORTB_DEN_REG |= (0x000000FF);		/* 8 Pins */
		PORTC_DEN_REG |= (0x000000FF);		/* 8 Pins */
		PORTD_DEN_REG |= (0x000000FF);		/* 8 Pins */
		PORTE_DEN_REG |= (0x0000003F);		/* 6 Pins Only */
		PORTF_DEN_REG |= (0x0000001F);		/* 5 Pins Only */
		/**********************************************************************************************/
		/***************** Initializing the configured pins with their configuration ******************/
		/*************************** Pins are configured in order of their ID *************************/
		for(uint8 Config_Pins_Counter=0 ; Config_Pins_Counter<PORT_CONFIGURED_PINS ; Config_Pins_Counter++)
		{
			/* Storing Port Base Address in the pointer Port_Ptr */
			switch(ConfigPtr->Port_Num[Config_Pins_Counter])
			{
				case PORT_A:
					Port_Ptr = (volatile uint32 *)PORTA_BASE_ADDRESS;
					break;
				case PORT_B:
					Port_Ptr = (volatile uint32 *)PORTB_BASE_ADDRESS;
					break;
				case PORT_C:
					Port_Ptr = (volatile uint32 *)PORTC_BASE_ADDRESS;
					break;
				case PORT_D:
					Port_Ptr = (volatile uint32 *)PORTD_BASE_ADDRESS;
					break;
				case PORT_E:
					Port_Ptr = (volatile uint32 *)PORTE_BASE_ADDRESS;
					break;
				case PORT_F:
					Port_Ptr = (volatile uint32 *)PORTF_BASE_ADDRESS;
					break;
			}

			if(((ConfigPtr->Port_Num[Config_Pins_Counter] == PORT_D)&&(ConfigPtr->Port_Pin_Num[Config_Pins_Counter] == 7))||\
					((ConfigPtr->Port_Num[Config_Pins_Counter] == PORT_F)\
					&&(ConfigPtr->Port_Pin_Num[Config_Pins_Counter] == 0)))	/* Pin PD7 or of PF0 */
			{
				/* Unlocking GPIOCR Register */
				*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = LOCK_MAGIC_NUMBER;
				/* Set the corresponding bit in GPIOCR register to allow changes on this pin */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
			}
			else if((ConfigPtr->Port_Num[Config_Pins_Counter] == 2)&&(ConfigPtr->Port_Pin_Num[Config_Pins_Counter] <= 3))	/* Pins from PC0:PC3 */
			{
				/* Do Nothing, JTAG Pins */
			}
			else
			{
				/* Do Nothing, No need to Unlock the Registers*/
			}

			/*switch(ConfigPtr->Port_AnlaogMode[Config_Pins_Counter])	The Easy Way
			{
				case ANALOG_MODE_OFF:
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
					break;
				case ANALOG_MODE_ON:
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
					break;
			}*/

			/* Pin Analog Mode Selection */
			(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET))\
			|= (ConfigPtr->Port_AnlaogMode[Config_Pins_Counter]<<ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);

			/* Setting Pin Mode  */
			(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET))\
			|= ((uint8)(ConfigPtr->Pin_Mode[Config_Pins_Counter])<<(4*ConfigPtr->Port_Pin_Num[Config_Pins_Counter]));

			/* Pin Direction Settings */
			if(PORT_PIN_IN == ConfigPtr->Pin_Direction[Config_Pins_Counter])
			{
				CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
			}
			else if(PORT_PIN_OUT == ConfigPtr->Pin_Direction[Config_Pins_Counter])
			{
				SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
			}
			else
			{
				/* Do Nothing */
			}

			/* Alternative Mode Settings */
			if(ConfigPtr->Pin_Mode[Config_Pins_Counter] > 0)
			{
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
			}
			else
			{
				/* Do Nothing, This bit is already cleared */
			}

			/* Internal Resistance Settings */
			if(ConfigPtr->Pin_Direction[Config_Pins_Counter] == PORT_PIN_IN)
			{
				switch(ConfigPtr->Pin_InternalResistance[Config_Pins_Counter])
				{
					case INTERNAL_PULL_UP:
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
						break;
					case INTERNAL_PULL_DOWN:
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET),ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
						break;
					case NO_INTERNAL_RESISTANCE:
						/* Do Nothing, Registers are already cleared*/
						break;
				}
			}
			else
			{
				/* Do Nothing */
			}

			/* Pin Digital Mode Selection */
			(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET))\
			|= (ConfigPtr->Port_DigitalMode[Config_Pins_Counter]<<ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);

			if(ConfigPtr->Pin_Direction[Config_Pins_Counter] == PORT_PIN_OUT)
			{
				/* Pin Initial Value */
				(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET))\
				|= (ConfigPtr->Pin_InitialLevelValue[Config_Pins_Counter]<<ConfigPtr->Port_Pin_Num[Config_Pins_Counter]);
			}
			else
			{
				/* Do Nothing */
			}
		}
		/* Storing Configuration Structure Address in the Global Pointer */
		Port_PinsPtr = ConfigPtr;
		/* Port is Initialized and Ready */
		Port_Status = PORT_INITIALIZED;
	}
}

/*************************************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - ID of Port Pin.
*                  Direction - Pin Direction to be set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set Port Pin Direction During Run Time.
*************************************************************************************************************/
#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin_ID,Port_PinDirectionType Direction)
{
	boolean Error = FALSE;					/* Boolean variable to store if there's an error or not */
	volatile uint32 *Port_Ptr = NULL_PTR;	/* Points to the required Port Registers base address */
#if(PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if correct pin ID is passed or not */
	if(Pin_ID >= PORT_CONFIGURED_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INTSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_PARAM_PIN);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	/* check if Pin Direction is Unchangeable */
	if(Port_PinsPtr->Pin_DirectionChangeable[Pin_ID] == PORT_PIN_DIRECTION_CHANGEABLE_DISABLED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INTSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_DIRECTION_UNCHANGEABLE);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing*/
	}
	/* Check if Port is not Initialized or Not */
	if(PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID,PORT_INTSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_UNINIT);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
#endif
	if(FALSE == Error)
	{
		/* Storing Port Base Address in the Port_Ptr Pointer */
		switch(Port_PinsPtr->Port_Num[Pin_ID])
		{
			case PORT_A:
				Port_Ptr = (volatile uint32 *)PORTA_BASE_ADDRESS;
				break;
			case PORT_B:
				Port_Ptr = (volatile uint32 *)PORTB_BASE_ADDRESS;
				break;
			case PORT_C:
				Port_Ptr = (volatile uint32 *)PORTC_BASE_ADDRESS;
				break;
			case PORT_D:
				Port_Ptr = (volatile uint32 *)PORTD_BASE_ADDRESS;
				break;
			case PORT_E:
				Port_Ptr = (volatile uint32 *)PORTE_BASE_ADDRESS;
				break;
			case PORT_F:
				Port_Ptr = (volatile uint32 *)PORTF_BASE_ADDRESS;
				break;
		}
		/* Check if JTAG Pins or not */
		if((Port_PinsPtr->Port_Num[Pin_ID] == 2)&&(Port_PinsPtr->Port_Pin_Num[Pin_ID] <= 3))	/* Pins from PC0:PC3 */
		{
			/* Do Nothing, JTAG Pins */
		}
		else
		{
			/* Setting Pin Direction after making in DET Errors checking that the Pin direction is changeable */
			if(PORT_PIN_IN == Direction)
			{
				CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),Port_PinsPtr->Port_Pin_Num[Pin_ID]);
			}
			else if(PORT_PIN_OUT == Direction)
			{
				SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),Port_PinsPtr->Port_Pin_Num[Pin_ID]);
			}
			else
			{
				/* Do Nothing */
			}
		}
	}
}
#endif

/*************************************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refresh Port Pins Directions, excluding the unchangeable ones.
*************************************************************************************************************/
void Port_RefreshPortDirection(void)
{
	volatile uint32 *Port_Ptr = NULL_PTR; /* Points to the required Port Registers base address */
#if(PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if Port is Initialized or Not */
	if(PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INTSTANCE_ID,PORT_REFRESH_PORT_DIRECTION_SID,PORT_E_UNINIT);
	}
	else
#endif
	{
		/* Loop for the configured pins */
		for(uint8 Pins_Counter=0 ; Pins_Counter<PORT_CONFIGURED_PINS ; Pins_Counter++)
		{
			/* Storing Port Base Address in the Port_Ptr Pointer */
			switch(Port_PinsPtr->Port_Num[Pins_Counter])
			{
				case PORT_A:
					Port_Ptr = (volatile uint32 *)PORTA_BASE_ADDRESS;
					break;
				case PORT_B:
					Port_Ptr = (volatile uint32 *)PORTB_BASE_ADDRESS;
					break;
				case PORT_C:
					Port_Ptr = (volatile uint32 *)PORTC_BASE_ADDRESS;
					break;
				case PORT_D:
					Port_Ptr = (volatile uint32 *)PORTD_BASE_ADDRESS;
					break;
				case PORT_E:
					Port_Ptr = (volatile uint32 *)PORTE_BASE_ADDRESS;
					break;
				case PORT_F:
					Port_Ptr = (volatile uint32 *)PORTF_BASE_ADDRESS;
					break;
			}
			/* Check if JTAG Pins or not */
			if((Port_PinsPtr->Port_Num[Pins_Counter] == 2)&&(Port_PinsPtr->Port_Pin_Num[Pins_Counter] <= 3))
			{
				/* Do Nothing, JTAG Pins */
			}
			else
			{
				/* Check if pin direction is changeable or not */
				if(Port_PinsPtr->Pin_DirectionChangeable[Pins_Counter] == PORT_PIN_DIRECTION_CHANGEABLE_DISABLED)
				{
					/* Refreshing Pins Directions */
					if(BIT_IS_SET((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),Port_PinsPtr->Port_Pin_Num[Pins_Counter]))
					{
						SET_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),Port_PinsPtr->Port_Pin_Num[Pins_Counter]);
					}
					else if(BIT_IS_CLEAR((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),Port_PinsPtr->Port_Pin_Num[Pins_Counter]))
					{
						CLEAR_BIT((*(volatile uint32 *)((volatile uint8 *)Port_Ptr+PORT_DIR_REG_OFFSET)),Port_PinsPtr->Port_Pin_Num[Pins_Counter]);
					}
					else
					{
						/* Do Nothing */
					}
				}
				else if(Port_PinsPtr->Pin_DirectionChangeable[Pins_Counter] == PORT_PIN_DIRECTION_CHANGEABLE_ENABLED)
				{
				/* Do Nothing - Exclude Direction Changeable Pins - PORT061 */
				}
				else
				{
				/* Do Nothing */
				}
			}
		}
	}
}

/*************************************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to structure stores the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
*************************************************************************************************************/
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	boolean Error = FALSE;
#if(PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INTSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	if(PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INTSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_UNINIT);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
#endif
	if(FALSE == Error)
	{
		/* Copy the vendor ID */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
	else
	{
		/* Do Nothing */
	}
}
#endif

/*************************************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - ID of Port Pin.
*                  Mode - Pin Mode to be set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set Port Pin Mode During Run Time.
*************************************************************************************************************/
#if(PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin_ID,Port_PinModeType Mode)
{
	boolean Error = FALSE;					/* Boolean variable to store if there's an error or not */
	volatile uint32 *Port_Ptr = NULL_PTR;	/* Points to the required Port Registers base address */
#if(PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if correct pin ID is passed or not */
	if(Pin_ID >= PORT_CONFIGURED_PINS)
	{
		Det_ReportError(PORT_MODULE_ID,PORT_INTSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_PARAM_PIN);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	/* check if Pin Direction is Unchangeable */
	if(Port_PinsPtr->Pin_ModeChangeable[Pin_ID] == PORT_PIN_MODE_CHANGEABLE_DISABLED)
	{
		Det_ReportError(PORT_MODULE_ID,PORT_INTSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_MODE_UNCHANGEABLE);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing*/
	}
	/* Check if Port is not Initialized or Not */
	if(PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID,PORT_INTSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_UNINIT);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
	if(Mode>=MAX_MODES_NUMBER)
	{
		Det_ReportError(PORT_MODULE_ID,PORT_INTSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_PARAM_INVALID_MODE);
		Error = TRUE;
	}
	else
	{
		/* Do Nothing */
	}
#endif
	if(FALSE == Error)
	{
		/* Storing Port Base Address in the Port_Ptr Pointer */
		switch(Port_PinsPtr->Port_Num[Pin_ID])
		{
			case PORT_A:
				Port_Ptr = (volatile uint32 *)PORTA_BASE_ADDRESS;
				break;
			case PORT_B:
				Port_Ptr = (volatile uint32 *)PORTB_BASE_ADDRESS;
				break;
			case PORT_C:
				Port_Ptr = (volatile uint32 *)PORTC_BASE_ADDRESS;
				break;
			case PORT_D:
				Port_Ptr = (volatile uint32 *)PORTD_BASE_ADDRESS;
				break;
			case PORT_E:
				Port_Ptr = (volatile uint32 *)PORTE_BASE_ADDRESS;
				break;
			case PORT_F:
				Port_Ptr = (volatile uint32 *)PORTF_BASE_ADDRESS;
				break;
		}
		/* Check if JTAG Pins or not */
		if((Port_PinsPtr->Port_Num[Pin_ID] == 2)&&(Port_PinsPtr->Port_Pin_Num[Pin_ID] <= 3))
		{
			/* Do Nothing, JTAG Pins */
		}
		else
		{
			uint32 dummy_var = 0x0000000F;
			dummy_var = (dummy_var<<4*Port_PinsPtr->Port_Pin_Num[Pin_ID]);
			/* Clearing Previous Mode */
			(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(dummy_var);
			/* Setting Pin Mode after making in DET Errors checking that the Pin Mode is changeable */
			(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET))\
			|= ((uint8)(Mode)<<(4*Port_PinsPtr->Port_Pin_Num[Pin_ID]));
		}
	}
	else
	{
		/* Do Nothing */
	}
}
#endif
