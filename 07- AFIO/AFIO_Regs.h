/******************************************************************************
 *
 * Module: AFIO
 *
 * File Name: AFIO_Regs.h
 *
 * Description: header file for AFIO Register Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef AFIO_REGS_H_
 #define AFIO_REGS_H_
 
 
 #define AFIO_EVCR		     							(*((volatile uint32 *)0x40010000))
 #define AFIO_MAPR		     							(*((volatile uint32 *)0x40010004))
 #define AFIO_EXTICR1		     						(*((volatile uint32 *)0x40010008))
 #define AFIO_EXTICR2		     						(*((volatile uint32 *)0x4001000C))
 #define AFIO_EXTICR3		     						(*((volatile uint32 *)0x40010010))
 #define AFIO_EXTICR4		     						(*((volatile uint32 *)0x40010014))
 #define AFIO_MAPR2		     							(*((volatile uint32 *)0x40010018))

 

 
 
 
 #endif