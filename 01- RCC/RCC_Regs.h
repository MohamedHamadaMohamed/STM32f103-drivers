 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_Regs.h
 *
 * Description: Header file for RCC Registers STM32F103C8  Microcontroller - RCC Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#ifndef RCC_REGS_H_
#define RCC_REGS_H_

/*  registers defination   */
#define RCC_base													  0x40021000

#define RCC_CR		     						(*((volatile uint32 *)0x40021000))
#define RCC_CFGR		     					(*((volatile uint32 *)0x40021004))
#define RCC_CIR		     						(*((volatile uint32 *)0x40021008))
#define RCC_APB2RSTR		     				(*((volatile uint32 *)0x4002100C))
#define RCC_APB1RSTR		     				(*((volatile uint32 *)0x40021010))
#define RCC_AHBENR		     					(*((volatile uint32 *)0x40021014))
#define RCC_APB2ENR 		     				(*((volatile uint32 *)0x40021018))
#define RCC_APB1ENR 		     				(*((volatile uint32 *)0x4002101C))
#define RCC_BDCR	 		     				(*((volatile uint32 *)0x40021020))
#define RCC_CSR     		     				(*((volatile uint32 *)0x40021024))



#endif