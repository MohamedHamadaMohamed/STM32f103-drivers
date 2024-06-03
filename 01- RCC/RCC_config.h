 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_config.h
 *
 * Description: header file for STM32F103C8  Microcontroller - RCC Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef RCC_CONFIG_H_
 #define RCC_CONFIG_H_
 
/************** RCC Clock Types **************/
 
/*  options :          
				RCC_HSE_CRYSTAL         
				RCC_HSE_RC              
				RCC_HSI		            
				RCC_PLL	
*/
#define RCC_CLOCK_TYPE		RCC_HSI

/****************RCC PLL Clock input types **********/
/*  options :
				RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE
*/

/* select value only if the RCC clock type is PLL option   */
#if RCC_CLOCK_TYPE == RCC_PLL

#define RCC_PLL_INPUT      RCC_PLL_IN_HSE 

/********* chiose multiply value  ********/
#define RCC_PLL_MUL_VALUE  PLL_INPUT_CLOCK_MUL_4

#endif 
 
#endif
 
 
 
 
 
