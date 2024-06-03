 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO_Regs.h
 *
 * Description: Header file for DIO Registers STM32F103C8  Microcontroller - DIO Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/

#ifndef DIO_REGS_H_
#define DIO_REGS_H_
			
			/* register definations*/
/* GPIO PORT A */
#define GPIO_PORT_A_BASE      0x40010800

#define GPIOA_CRL			  (*((volatile uint32 *)0x40010800))
#define GPIOA_CRH			  (*((volatile uint32 *)0x40010804))
#define GPIOA_IDR			  (*((volatile uint32 *)0x40010808))
#define GPIOA_ODR			  (*((volatile uint32 *)0x4001080C))
#define GPIOA_BSRR			  (*((volatile uint32 *)0x40010810))
#define GPIOA_BRR			  (*((volatile uint32 *)0x40010814))
#define GPIOA_LCKR			  (*((volatile uint32 *)0x40010818))

/* GPIO PORT B */
#define GPIO_PORT_B_BASE      0x40010C00

#define GPIOB_CRL			  (*((volatile uint32 *)0x40010C00))
#define GPIOB_CRH			  (*((volatile uint32 *)0x40010C04))
#define GPIOB_IDR			  (*((volatile uint32 *)0x40010C08))
#define GPIOB_ODR			  (*((volatile uint32 *)0x40010C0C))
#define GPIOB_BSRR			  (*((volatile uint32 *)0x40010C10))
#define GPIOB_BRR			  (*((volatile uint32 *)0x40010C14))
#define GPIOB_LCKR			  (*((volatile uint32 *)0x40010C18))

/* GPIO PORT C */
#define GPIO_PORT_C_BASE      0x40011000

#define GPIOC_CRL			  (*((volatile uint32 *)0x40011000))
#define GPIOC_CRH			  (*((volatile uint32 *)0x40011004))
#define GPIOC_IDR			  (*((volatile uint32 *)0x40011008))
#define GPIOC_ODR			  (*((volatile uint32 *)0x4001100C))
#define GPIOC_BSRR			  (*((volatile uint32 *)0x40011010))
#define GPIOC_BRR			  (*((volatile uint32 *)0x40011014))
#define GPIOC_LCKR			  (*((volatile uint32 *)0x40011018))


#endif
