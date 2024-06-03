/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: External_Interrupt.c
 *
 * Description: source file for External Interrupt Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#include "Common_Macros.h"
#include "Std_Types.h" 

#include "External_Interrupt.h"
#include "External_Interrupt_Regs.h"
#include "External_Interrupt_config.h"

 
static void (*EXTI_callBackPtr[16])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 
void EXT_Interrupt_init(uint8 line, uint8 mode , void (*ptr)(void) )
{
	EXTI_callBackPtr[line] = ptr;
	switch(mode)
	{
		case RISING    :		SET_BIT(EXTI_RTSR,line);    break;
		case FALLING   :		SET_BIT(EXTI_FTSR,line);	break;
		case ON_CHANGE : 	    SET_BIT(EXTI_RTSR,line);
							    SET_BIT(EXTI_FTSR,line);	break;
	    default        :									break;

		
	}
}

void EXT_Interrupt_enableExternalInterrupt(uint8 line)
{
	SET_BIT(EXTI_IMR,line);	
}
void EXT_Interrupt_disableExternalInterrupt(uint8 line)
{
	CLEAR_BIT(EXTI_IMR,line);	
}
void EXT_Interrupt_SwTrigger(uint8 line)
{
	SET_BIT(EXTI_SWIER,line);		
}

/************  ISR Handler **************/

void EXTI0_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[0]();
		
    SET_BIT(EXTI_PR,EXTI0);	
}
void EXTI1_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[1]();
    SET_BIT(EXTI_PR,EXTI1);	

}
void EXTI2_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[2]();
    SET_BIT(EXTI_PR,EXTI2);	
	
}
void EXTI3_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[3]();
    SET_BIT(EXTI_PR,EXTI3);	
	
}
void EXTI4_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[4]();
    SET_BIT(EXTI_PR,EXTI4);	
	
}
void EXTI5_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[5]();
    SET_BIT(EXTI_PR,EXTI5);	
	
}
void EXTI6_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[6]();
    SET_BIT(EXTI_PR,EXTI6);	
	
}
void EXTI7_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[7]();
    SET_BIT(EXTI_PR,EXTI7);	
	
}
void EXTI8_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[8]();
    SET_BIT(EXTI_PR,EXTI8);	
	
}
void EXTI9_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[9]();
    SET_BIT(EXTI_PR,EXTI9);	

}
void EXTI10_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[10]();
    SET_BIT(EXTI_PR,EXTI10);	
	
}
void EXTI11_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[11]();
    SET_BIT(EXTI_PR,EXTI11);	
	
}
void EXTI12_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[12]();
    SET_BIT(EXTI_PR,EXTI12);	
	
}
void EXTI13_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[13]();
    SET_BIT(EXTI_PR,EXTI13);	
	
}
void EXTI14_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[14]();
    SET_BIT(EXTI_PR,EXTI14);	
	
}
void EXTI15_IRQHandler(void)
{
	if(EXTI_callBackPtr != NULL)
		EXTI_callBackPtr[15]();
    SET_BIT(EXTI_PR,EXTI15);	
	
}














