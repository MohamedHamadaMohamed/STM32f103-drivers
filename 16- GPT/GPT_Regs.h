/******************************************************************************
 *
 * Module: genernal purpose timer
 *
 * File Name: GPT_Regs.h
 *
 * Description:  header file for GPT driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef GPT_Regs_H_
 #define GPT_Regs_H_
 
 /*0x4001 2C00 - 0x4001 2FFF TIM1 timer
   0x4000 0000 - 0x4000 03FF TIM2 timer
   0x4000 0800 - 0x4000 0BFF TIM4 timer
   0x4000 0400 - 0x4000 07FF TIM3 timer */
   
 /**************************  Timer 1  ***************************/
 #define TIM1_CR1			  (*((volatile uint32 *)0x40012C00))
 #define TIM1_CR2			  (*((volatile uint32 *)0x40012C04))
 #define TIM1_SMCR			  (*((volatile uint32 *)0x40012C08))
 #define TIM1_DIER			  (*((volatile uint32 *)0x40012C0C))
 #define TIM1_SR			  (*((volatile uint32 *)0x40012C10))
 #define TIM1_EGR			  (*((volatile uint32 *)0x40012C14))
 #define TIM1_CCMR1			  (*((volatile uint32 *)0x40012C18))
 #define TIM1_CCMR2			  (*((volatile uint32 *)0x40012C1C))

 #define TIM1_CCER			  (*((volatile uint32 *)0x40012C20))
 #define TIM1_CNT			  (*((volatile uint32 *)0x40012C24))
 #define TIM1_PSC			  (*((volatile uint32 *)0x40012C28))
 #define TIM1_ARR			  (*((volatile uint32 *)0x40012C2C))
 #define TIM1_RCR			  (*((volatile uint32 *)0x40012C30))
 #define TIM1_CCR1			  (*((volatile uint32 *)0x40012C34))
 #define TIM1_CCR2			  (*((volatile uint32 *)0x40012C38))
 #define TIM1_CCR3			  (*((volatile uint32 *)0x40012C3C)) 
 
 #define TIM1_CCR4			  (*((volatile uint32 *)0x40012C40))
 #define TIM1_BDTR			  (*((volatile uint32 *)0x40012C44))
 #define TIM1_DCR			  (*((volatile uint32 *)0x40012C48))
 #define TIM1_DMAR			  (*((volatile uint32 *)0x40012C4C))
 
 
 /**************************  Timer 2  ***************************/
 #define TIM2_CR1			  (*((volatile uint32 *)0x40000000))
 #define TIM2_CR2			  (*((volatile uint32 *)0x40000004))
 #define TIM2_SMCR			  (*((volatile uint32 *)0x40000008))
 #define TIM2_DIER			  (*((volatile uint32 *)0x4000000C))
 #define TIM2_SR			  (*((volatile uint32 *)0x40000010))
 #define TIM2_EGR			  (*((volatile uint32 *)0x40000014))
 #define TIM2_CCMR1			  (*((volatile uint32 *)0x40000018))
 
 #define TIM2_CCMR2			  (*((volatile uint32 *)0x4000001C))
 #define TIM2_CCER			  (*((volatile uint32 *)0x40000020))
 #define TIM2_CNT			  (*((volatile uint32 *)0x40000024))
 #define TIM2_PSC			  (*((volatile uint32 *)0x40000028))
 #define TIM2_ARR			  (*((volatile uint32 *)0x4000002C))
 #define TIM2_CCR1			  (*((volatile uint32 *)0x40000034))
 
 #define TIM2_CCR2			  (*((volatile uint32 *)0x40000038))
 #define TIM2_CCR3			  (*((volatile uint32 *)0x4000003C))
 
 #define TIM2_CCR4			  (*((volatile uint32 *)0x40000040))
 #define TIM2_DCR			  (*((volatile uint32 *)0x40000048))
 #define TIM2_DMAR			  (*((volatile uint32 *)0x4000004C))

/**************************  Timer 3  ***************************/
 #define TIM3_CR1			  (*((volatile uint32 *)0x40000000))
 #define TIM3_CR2			  (*((volatile uint32 *)0x40000004))
 #define TIM3_SMCR			  (*((volatile uint32 *)0x40000008))
 #define TIM3_DIER			  (*((volatile uint32 *)0x4000000C))
 #define TIM3_SR			  (*((volatile uint32 *)0x40000010))
 #define TIM3_EGR			  (*((volatile uint32 *)0x40000014))
 #define TIM3_CCMR1			  (*((volatile uint32 *)0x40000018))
			
 #define TIM3_CCMR2			  (*((volatile uint32 *)0x4000001C))
 #define TIM3_CCER			  (*((volatile uint32 *)0x40000020))
 #define TIM3_CNT			  (*((volatile uint32 *)0x40000024))
 #define TIM3_PSC			  (*((volatile uint32 *)0x40000028))
 #define TIM3_ARR			  (*((volatile uint32 *)0x4000002C))
 #define TIM3_CCR1			  (*((volatile uint32 *)0x40000034))
			
 #define TIM3_CCR2			  (*((volatile uint32 *)0x40000038))
 #define TIM3_CCR3			  (*((volatile uint32 *)0x4000003C))
			
 #define TIM3_CCR4			  (*((volatile uint32 *)0x40000040))
 #define TIM3_DCR			  (*((volatile uint32 *)0x40000048))
 #define TIM3_DMAR			  (*((volatile uint32 *)0x4000004C))

/**************************  Timer 4  ***************************/
 #define TIM4_CR1			  (*((volatile uint32 *)0x40000000))
 #define TIM4_CR2			  (*((volatile uint32 *)0x40000004))
 #define TIM4_SMCR			  (*((volatile uint32 *)0x40000008))
 #define TIM4_DIER			  (*((volatile uint32 *)0x4000000C))
 #define TIM4_SR			  (*((volatile uint32 *)0x40000010))
 #define TIM4_EGR			  (*((volatile uint32 *)0x40000014))
 #define TIM4_CCMR1			  (*((volatile uint32 *)0x40000018))
			
 #define TIM4_CCMR2			  (*((volatile uint32 *)0x4000001C))
 #define TIM4_CCER			  (*((volatile uint32 *)0x40000020))
 #define TIM4_CNT			  (*((volatile uint32 *)0x40000024))
 #define TIM4_PSC			  (*((volatile uint32 *)0x40000028))
 #define TIM4_ARR			  (*((volatile uint32 *)0x4000002C))
 #define TIM4_CCR1			  (*((volatile uint32 *)0x40000034))
			
 #define TIM4_CCR2			  (*((volatile uint32 *)0x40000038))
 #define TIM4_CCR3			  (*((volatile uint32 *)0x4000003C))
			
 #define TIM4_CCR4			  (*((volatile uint32 *)0x40000040))
 #define TIM4_DCR			  (*((volatile uint32 *)0x40000048))
 #define TIM4_DMAR			  (*((volatile uint32 *)0x4000004C))
						
 #endif