 /******************************************************************************
 *
 * Module: UART_Regs
 *
 * File Name: UART_Regs.h
 *
 * Description: Header file for STM32F103C8  Microcontroller - UART Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef UART_REGS_H_
 #define UART_REGS_H_
 
 /*
 
 0x4000 5000 - 0x4000 53FF				 UART5
 0x4000 4C00 - 0x4000 4FFF 				 UART4
 0x4000 4800 - 0x4000 4BFF 				 USART3
 0x4000 4400 - 0x4000 47FF				 USART2
 */
 
 /******************* 	USART 1	Rgisters **********************/
 #define USART1_SR			  (*((volatile uint32 *)0x40013800))
 #define USART1_DR			  (*((volatile uint32 *)0x40013804))
 #define USART1_BRR			  (*((volatile uint32 *)0x40013808))
 #define USART1_CR1			  (*((volatile uint32 *)0x4001380C))
 #define USART1_CR2			  (*((volatile uint32 *)0x40013810))
 #define USART1_CR3			  (*((volatile uint32 *)0x40013814))
 #define USART1_GTPR		  (*((volatile uint32 *)0x40013818))
 
  /******************* 	USART 2	Rgisters **********************/
  
 #define USART2_SR			  (*((volatile uint32 *)0x40004400))
 #define USART2_DR			  (*((volatile uint32 *)0x40004404))
 #define USART2_BRR			  (*((volatile uint32 *)0x40004408))
 #define USART2_CR1			  (*((volatile uint32 *)0x4000440C))
 #define USART2_CR2			  (*((volatile uint32 *)0x40004410))
 #define USART2_CR3			  (*((volatile uint32 *)0x40004414))
 #define USART2_GTPR		  (*((volatile uint32 *)0x40004418))
 
  /******************* 	USART 3	Rgisters  *********************/
  
 #define USART3_SR			  (*((volatile uint32 *)0x40004800))
 #define USART3_DR			  (*((volatile uint32 *)0x40004804))
 #define USART3_BRR			  (*((volatile uint32 *)0x40004808))
 #define USART3_CR1			  (*((volatile uint32 *)0x4000480C))
 #define USART3_CR2			  (*((volatile uint32 *)0x40004814))
 #define USART3_CR3			  (*((volatile uint32 *)0x40004818))
 #define USART3_GTPR		  (*((volatile uint32 *)0x4000481C))

 
 

 
 
 
 
 #endif