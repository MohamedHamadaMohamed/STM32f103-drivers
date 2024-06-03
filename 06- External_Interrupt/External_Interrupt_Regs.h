/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: External_Interrupt_Regs.h
 *
 * Description: header file for External Interrupt Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#ifndef EXTERNAL_INTERRUPT_REGS_H_
#define EXTERNAL_INTERRUPT_REGS_H_ 

#define EXTI_IMR		     						(*((volatile uint8 *)0x40010400))
#define EXTI_EMR		     						(*((volatile uint8 *)0x40010404))
#define EXTI_RTSR		     						(*((volatile uint8 *)0x40010408))
#define EXTI_FTSR		     						(*((volatile uint8 *)0x4001040C))
#define EXTI_SWIER		     						(*((volatile uint8 *)0x40010410))
#define EXTI_PR		     				    		(*((volatile uint8 *)0x40010414))


  




#endif
