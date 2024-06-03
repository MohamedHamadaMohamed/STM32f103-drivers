 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC.c
 *
 * Description: Source file for STM32F103C8  Microcontroller - RCC Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "RCC.h"
 #include "RCC_Regs.h"
 #include "RCC_config.h"
 
 
 /************************************************************************************
* Service Name: RCC_initSystemClock
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize system clock .
************************************************************************************/
 void RCC_initSystemClock(void)
 {
	#if  RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
			RCC_CR = 0X00010000;		/*  enable high speed external clock , crystal       */
			RCC_CFGR=0X00000001;
			RCC_CFGR|=(AHB_SYSCLK_not_divided<<4)|(APB1_HCLK_not_divided<<8)|(APB2_HCLK_not_divided<<11);
	
	#elif  RCC_CLOCK_TYPE==RCC_HSE_RC  
			RCC_CR = 0X0X00050000;		/*  enable high speed internal clock   , RC Circuit  */
			RCC_CFGR=0X00000001;
			RCC_CFGR|=(AHB_SYSCLK_not_divided<<4)|(APB1_HCLK_not_divided<<8)|(APB2_HCLK_not_divided<<11);

	#elif  RCC_CLOCK_TYPE==RCC_HSI		            
			RCC_CR = 0X00000081;         /*  enable high speed internal clock  		    	 */
			RCC_CFGR=0X00000000;
			RCC_CFGR|=(AHB_SYSCLK_not_divided<<4)|(APB1_HCLK_not_divided<<8)|(APB2_HCLK_not_divided<<11);

	#elif  RCC_CLOCK_TYPE==RCC_PLL	
			#if RCC_PLL_INPUT==	RCC_PLL_IN_HSI_DIV_2
					/* complete*/
			#elif RCC_PLL_INPUT==	RCC_PLL_IN_HSE_DIV_2
					/* complete*/
			#elif RCC_PLL_INPUT==	RCC_PLL_IN_HSE
					/* complete*/
			#else
				#error("you choise wrong PLL input")
			#endif

	#else
			#error("you choise wrong clock type")
    #endif	
	 
	 
 }
 
 
/************************************************************************************
* Service Name: RCC_enableClock
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): bus type && the peripheral
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to enable clock for peripherial module.
************************************************************************************/
void RCC_enableClock(bus Bus , peripheral Peripheral)
{
	if(Peripheral < 32)
	{
		switch(Bus)
		{
			case RCC_AHB  :   SET_BIT(RCC_AHBENR,Peripheral);     break;
			case RCC_APB1 :   SET_BIT(RCC_APB1ENR,Peripheral);    break;
			case RCC_APB2 :   SET_BIT(RCC_APB2ENR,Peripheral);    break;
			default       :    /* 		return error		*/    break;
			
		}
		
	}
	else 
	{
		
		/* return error  */
		
	}
	
}

/************************************************************************************
* Service Name: RCC_enableClock
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): bus type && the peripheral
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to enable clock for peripherial module.
************************************************************************************/
void RCC_disableClock(bus Bus , peripheral Peripheral)
{

	if(Peripheral < 32)
	{
		switch(Bus)
		{
			case RCC_AHB  :   CLEAR_BIT(RCC_AHBENR,Peripheral);     break;
			case RCC_APB1 :   CLEAR_BIT(RCC_APB1ENR,Peripheral);    break;
			case RCC_APB2 :   CLEAR_BIT(RCC_APB2ENR,Peripheral);    break;
			default       :    /* 		return error		*/      break;
			
		}
		
	}
	else 
	{
		
		/* return error  */
		
	}
	
}




