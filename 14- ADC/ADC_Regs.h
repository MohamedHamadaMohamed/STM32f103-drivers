/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Regs.h
 *
 * Description:  header file for ADC driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef ADC_REGS_H_
 #define ADC_REGS_H_
 
 
 /*0x40013C00 - 0x4001 3FFF ADC3*/
 /*0x40012800 - 0x4001 2BFF ADC2*/
 /*0x40012400 - 0x4001 27FF ADC1*/
 
 #define ADC_SR			  (*((volatile uint32 *)0x40012400))
 #define ADC_CR1		  (*((volatile uint32 *)0x40012404))
 #define ADC_CR2		  (*((volatile uint32 *)0x40012408))
 #define ADC_SMPR1		  (*((volatile uint32 *)0x4001240C))

 #define ADC_SMPR2		  (*((volatile uint32 *)0x40012410))
 #define ADC_JOFR1		  (*((volatile uint32 *)0x40012414))
 #define ADC_JOFR2		  (*((volatile uint32 *)0x40012418))
 #define ADC_JOFR3		  (*((volatile uint32 *)0x4001241C))
  
 #define ADC_JOFR4		  (*((volatile uint32 *)0x40012420))
 #define ADC_HTR 		  (*((volatile uint32 *)0x40012424))
 #define ADC_LTR		  (*((volatile uint32 *)0x40012428))
 #define ADC_SQR1		  (*((volatile uint32 *)0x4001242C))

 #define ADC_SQR2		  (*((volatile uint32 *)0x40012430))
 #define ADC_SQR3		  (*((volatile uint32 *)0x40012434))
 #define ADC_JSQR		  (*((volatile uint32 *)0x40012438))
 #define ADC_JDR1		  (*((volatile uint32 *)0x4001243C))
  
 #define ADC_JDR2		  (*((volatile uint32 *)0x40012440))
 #define ADC_JDR3 		  (*((volatile uint32 *)0x40012444))
 #define ADC_JDR4		  (*((volatile uint32 *)0x40012448))
 #define ADC_DR 		  (*((volatile uint32 *)0x4001244C))  

 
 
 #endif
 
 
 
 
 
 
 
 