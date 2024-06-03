/******************************************************************************
 *
 * Module: DMA
 *
 * File Name: DMA_Regs.h
 *
 * Description:  header file for DMA driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef DMA_REGS_H_
 #define DMA_REGS_H_
  
 /*0x40020000 - 0x400203FF	 DMA1*/ 
  
 #define DMA_ISR			  (*((volatile uint32 *)0x40020000))
 #define DMA_IFCR			  (*((volatile uint32 *)0x40020004))
 
 #define DMA_CCR1			  (*((volatile uint32 *)0x40020008))
 #define DMA_CNDTR1			  (*((volatile uint32 *)0x4002000C))
 #define DMA_CPAR1			  (*((volatile uint32 *)0x40020010))
 #define DMA_CMAR1			  (*((volatile uint32 *)0x40020014))

 #define DMA_CCR2			  (*((volatile uint32 *)0x4002001C))
 #define DMA_CNDTR2			  (*((volatile uint32 *)0x40020020))
 #define DMA_CPAR2			  (*((volatile uint32 *)0x40020024))
 #define DMA_CMAR2			  (*((volatile uint32 *)0x40020028))
 
 #define DMA_CCR3			  (*((volatile uint32 *)0x40020030))
 #define DMA_CNDTR3			  (*((volatile uint32 *)0x40020034))
 #define DMA_CPAR3			  (*((volatile uint32 *)0x40020038))
 #define DMA_CMAR3			  (*((volatile uint32 *)0x4002003C))
 
 #define DMA_CCR4			  (*((volatile uint32 *)0x40020044))
 #define DMA_CNDTR4			  (*((volatile uint32 *)0x40020048))
 #define DMA_CPAR4			  (*((volatile uint32 *)0x4002004C))
 #define DMA_CMAR4			  (*((volatile uint32 *)0x40020050))
 
 #define DMA_CCR5			  (*((volatile uint32 *)0x40020058))
 #define DMA_CNDTR5			  (*((volatile uint32 *)0x4002005C))
 #define DMA_CPAR5			  (*((volatile uint32 *)0x40020060))
 #define DMA_CMAR5			  (*((volatile uint32 *)0x40020064))
 
 #define DMA_CCR6			  (*((volatile uint32 *)0x4002006C))
 #define DMA_CNDTR6			  (*((volatile uint32 *)0x40020070))
 #define DMA_CPAR6			  (*((volatile uint32 *)0x40020074))
 #define DMA_CMAR6			  (*((volatile uint32 *)0x40020078))
 
 #define DMA_CCR7			  (*((volatile uint32 *)0x40020080))
 #define DMA_CNDTR7			  (*((volatile uint32 *)0x40020084))
 #define DMA_CPAR7			  (*((volatile uint32 *)0x40020088))
 #define DMA_CMAR7			  (*((volatile uint32 *)0x4002008C))
 
 

  
 #endif