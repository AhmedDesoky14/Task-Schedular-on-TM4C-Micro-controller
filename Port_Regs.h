 /*******************************************************************************************************
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: Registers Header file for TM4C123GH6PM Micro-controller - Port Driver
 *
 * Author: Ahmed Desoky
 *******************************************************************************************************/
#ifndef PORT_REGS_H_
#define PORT_REGS_H_

/* Ports Registers base addresses */
#define PORTA_BASE_ADDRESS           0x40004000
#define PORTB_BASE_ADDRESS           0x40005000
#define PORTC_BASE_ADDRESS           0x40006000
#define PORTD_BASE_ADDRESS           0x40007000
#define PORTE_BASE_ADDRESS           0x40024000
#define PORTF_BASE_ADDRESS           0x40025000

/* Registers Offset Address */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

/******************************************************************************************************
	 	 	 	 	 	 	 	 	 	 	 	registers
******************************************************************************************************/
/************************************************ PORTA **********************************************/
#define PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define PORTA_DIR_REG        (*((volatile uint32 *)0x40004400))
#define PORTA_AFSEL_REG      (*((volatile uint32 *)0x40004420))
#define PORTA_PUR_REG        (*((volatile uint32 *)0x40004510))
#define PORTA_PDR_REG        (*((volatile uint32 *)0x40004514))
#define PORTA_DEN_REG        (*((volatile uint32 *)0x4000451C))
#define PORTA_LOCK_REG       (*((volatile uint32 *)0x40004520))
#define PORTA_CR_REG         (*((volatile uint32 *)0x40004524))
#define PORTA_AMSEL_REG      (*((volatile uint32 *)0x40004528))
#define PORTA_PCTL_REG       (*((volatile uint32 *)0x4000452C))
/************************************************ PORTB **********************************************/
#define PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define PORTB_DIR_REG        (*((volatile uint32 *)0x40005400))
#define PORTB_AFSEL_REG      (*((volatile uint32 *)0x40005420))
#define PORTB_PUR_REG        (*((volatile uint32 *)0x40005510))
#define PORTB_PDR_REG        (*((volatile uint32 *)0x40005514))
#define PORTB_DEN_REG        (*((volatile uint32 *)0x4000551C))
#define PORTB_LOCK_REG       (*((volatile uint32 *)0x40005520))
#define PORTB_CR_REG         (*((volatile uint32 *)0x40005524))
#define PORTB_AMSEL_REG      (*((volatile uint32 *)0x40005528))
#define PORTB_PCTL_REG       (*((volatile uint32 *)0x4000552C))
/************************************************ PORTC **********************************************/
#define PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define PORTC_DIR_REG        (*((volatile uint32 *)0x40006400))
#define PORTC_AFSEL_REG      (*((volatile uint32 *)0x40006420))
#define PORTC_PUR_REG        (*((volatile uint32 *)0x40006510))
#define PORTC_PDR_REG        (*((volatile uint32 *)0x40006514))
#define PORTC_DEN_REG        (*((volatile uint32 *)0x4000651C))
#define PORTC_LOCK_REG       (*((volatile uint32 *)0x40006520))
#define PORTC_CR_REG         (*((volatile uint32 *)0x40006524))
#define PORTC_AMSEL_REG      (*((volatile uint32 *)0x40006528))
#define PORTC_PCTL_REG       (*((volatile uint32 *)0x4000652C))
/************************************************ PORTD **********************************************/
#define PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define PORTD_DIR_REG        (*((volatile uint32 *)0x40007400))
#define PORTD_AFSEL_REG      (*((volatile uint32 *)0x40007420))
#define PORTD_PUR_REG        (*((volatile uint32 *)0x40007510))
#define PORTD_PDR_REG        (*((volatile uint32 *)0x40007514))
#define PORTD_DEN_REG        (*((volatile uint32 *)0x4000751C))
#define PORTD_LOCK_REG       (*((volatile uint32 *)0x40007520))
#define PORTD_CR_REG         (*((volatile uint32 *)0x40007524))
#define PORTD_AMSEL_REG      (*((volatile uint32 *)0x40007528))
#define PORTD_PCTL_REG       (*((volatile uint32 *)0x4000752C))
/************************************************ PORTE **********************************************/
#define PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define PORTE_DIR_REG        (*((volatile uint32 *)0x40024400))
#define PORTE_AFSEL_REG      (*((volatile uint32 *)0x40024420))
#define PORTE_PUR_REG        (*((volatile uint32 *)0x40024510))
#define PORTE_PDR_REG        (*((volatile uint32 *)0x40024514))
#define PORTE_DEN_REG        (*((volatile uint32 *)0x4002451C))
#define PORTE_LOCK_REG       (*((volatile uint32 *)0x40024520))
#define PORTE_CR_REG         (*((volatile uint32 *)0x40024524))
#define PORTE_AMSEL_REG      (*((volatile uint32 *)0x40024528))
#define PORTE_PCTL_REG       (*((volatile uint32 *)0x4002452C))
/************************************************ PORTF **********************************************/
#define PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))
#define PORTF_DIR_REG        (*((volatile uint32 *)0x40025400))
#define PORTF_AFSEL_REG      (*((volatile uint32 *)0x40025420))
#define PORTF_PUR_REG        (*((volatile uint32 *)0x40025510))
#define PORTF_PDR_REG        (*((volatile uint32 *)0x40025514))
#define PORTF_DEN_REG        (*((volatile uint32 *)0x4002551C))
#define PORTF_LOCK_REG       (*((volatile uint32 *)0x40025520))
#define PORTF_CR_REG         (*((volatile uint32 *)0x40025524))
#define PORTF_AMSEL_REG      (*((volatile uint32 *)0x40025528))
#define PORTF_PCTL_REG       (*((volatile uint32 *)0x4002552C))

/* System Clock Port Register */
#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE108))

#endif /* PORT_REGS_H_ */
