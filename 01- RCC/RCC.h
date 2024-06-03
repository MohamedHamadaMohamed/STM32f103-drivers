 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC.h
 *
 * Description: Header file for STM32F103C8  Microcontroller - RCC Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#ifndef RCC_H_
#define RCC_H_


#include "Std_Types.h"

typedef uint8 bus;
typedef uint8 peripheral;
		/*	   Buses Types		*/
#define RCC_AHB                 0U
#define RCC_APB1                1U
#define RCC_APB2                2U

		/*  RCC Clock Types        */
#define RCC_HSE_CRYSTAL         0U
#define RCC_HSE_RC              1U
#define RCC_HSI		            2U
#define RCC_PLL		            3U

		/* RCC PLL clock input     */
#define	RCC_PLL_IN_HSI_DIV_2    0U
#define RCC_PLL_IN_HSE_DIV_2    1U
#define RCC_PLL_IN_HSE          2U

		/* PLL Multiply value     */
typedef enum {
	PLL_INPUT_CLOCK_MUL_2  =0   , PLL_INPUT_CLOCK_MUL_3 =1   , PLL_INPUT_CLOCK_MUL_4 =2,
	PLL_INPUT_CLOCK_MUL_5  =3   , PLL_INPUT_CLOCK_MUL_6 =4   , PLL_INPUT_CLOCK_MUL_7 =5,
	PLL_INPUT_CLOCK_MUL_8  =6   , PLL_INPUT_CLOCK_MUL_9 =7   , PLL_INPUT_CLOCK_MUL_10 =8,
	PLL_INPUT_CLOCK_MUL_11 =9   , PLL_INPUT_CLOCK_MUL_12 =10 , PLL_INPUT_CLOCK_MUL_13 =11,
	PLL_INPUT_CLOCK_MUL_14 =12  , PLL_INPUT_CLOCK_MUL_15 =13 , PLL_INPUT_CLOCK_MUL_16 =14
	}PLL_INPUT_CLOCK_MULTIPLY;
typedef enum {
	DMA1EN =0 	    /*  DMA1 clock enable				      */
	,DMA2EN=1		/*  DMA2 clock enable				      */
	,SRAMEN=2		/*	SRAM interface clock enable		      */
	,FLITFEN=4		/*  FLITF clock enable 				      */
	,CRCEN=6   		/*  CRC clock enable   				      */
	,FSMCEN=8		/*  FSMC clock enable  					  */
	,SDIOEN=10		/*  SDIO clock enable  				      */
	}AHB_peripheral_clk_enable;
typedef enum {
	AFIOEN =0    	/*  Alternate function IO clock enable    */
	,IOPAEN=2    	/*  IO port A clock enable				  */
	,IOPBEN=3    	/*  IO port B clock enable				  */
	,IOPCEN=4       /*  IO port C clock enable				  */
	,IOPDEN=5       /*  IO port D clock enable				  */
	,IOPEEN=6  		/*  IO port E clock enable				  */
	,IOPFEN=7 		/*  IO port F clock enable				  */
	,IOPGEN=8	 	/*  IO port G clock enable				  */
	,ADC1EN=9  		/*  ADC 1 interface clock enable		  */
	,ADC2EN=10  	/*  ADC 2 interface clock enable		  */
	,TIM1EN=11  	/*  TIM1 timer clock enable			      */
	,SPI1EN=12		/*  SPI1 clock enable				   	  */
	,TIM8EN=13		/*  TIM8 Timer clock enable			      */
	,USART1EN=14	/*  USART1 clock enable				      */
	,ADC3EN=15		/*  ADC3 interface clock enable		      */
	,TIM9EN=19		/*  TIM9 timer clock enable			      */
	,TIM10EN=20		/*  TIM10 timer clock enable			  */
	,TIM11EN=21		/*  TIM11 timer clock enable			  */
	}APB2_peripheral_clk_enable;
typedef enum {
	TIM2EN=0		/*  TIM2 timer clock enable			      */
	,TIM3EN=1		/*  TIM3 timer clock enable				  */
	,TIM4EN=2		/*  TIM4 timer clock enable			      */
	,TIM5EN=3		/*  TIM5 timer clock enable			      */
	,TIM6EN=4		/*  TIM6 timer clock enable			      */
	,TIM7EN=5		/*  TIM7 timer clock enable			      */
	,TIM12EN=6		/*  TIM12 timer clock enable			  */
	,TIM13EN=7		/*  TIM13 timer clock enable			  */
	,TIM14EN=8 		/*  TIM14 timer clock enable			  */
	,WWDGEN=11		/*  Window watchdog clock enable		  */
	,SPI2EN=14 		/*  SPI2 clock enable					  */
	,SPI3EN=15 		/*  SPI 3 clock enable					  */
	,USART2EN=17 	/*  USART2 clock enable					  */
	,USART3EN=18 	/*  USART3 clock enable					  */
	,UART4EN=19 	/*  USART4 clock enable					  */
	,UART5EN =20 	/*  USART5 clock enable					  */
	,I2C1EN =21 	/*  I2C1 clock enable					  */
	,I2C2EN =22 	/*  I2C2 clock enable				      */
	,USBEN =23 		/*  USB clock enable				      */
	,CANEN =25 		/*  CAN clock enable				      */
	,BKPEN = 27 	/*  Backup interface clock enable		  */
	,PWREN =28 		/*  Power interface clock enable		  */
	,DACEN =29 		/*  DAC interface clock enable		      */

}APB1_peripheral_clk_enable;

/* Bits 13:11 in Clock configuration register (RCC_CFGR) PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock
(PCLK2).
*/
typedef enum {
	 APB2_HCLK_not_divided=0
	,APB2_HCLK_divided_by_2=4
	,APB2_HCLK_divided_by_4=5
	,APB2_HCLK_divided_by_8=6
	,APB2_HCLK_divided_by_16=7
}APB2_HCLK_divided;

/*Bits 10:8 in Clock configuration register (RCC_CFGR) PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.*/
typedef enum {
	 APB1_HCLK_not_divided=0
	,APB1_HCLK_divided_by_2=4
	,APB1_HCLK_divided_by_4=5
	,APB1_HCLK_divided_by_8=6
	,APB1_HCLK_divided_by_16=7
}APB1_HCLK_divided;

/*Bits 7:4 in Clock configuration register (RCC_CFGR) HPRE: AHB prescaler
Set and cleared by software to control the division factor of the AHB clock.*/
typedef enum {
	 AHB_SYSCLK_not_divided=0
	,AHB_SYSCLK_divided_by_2=8
	,AHB_SYSCLK_divided_by_4=9
	,AHB_SYSCLK_divided_by_8=10
	,AHB_SYSCLK_divided_by_16=11
	,AHB_SYSCLK_divided_by_64=12
	,AHB_SYSCLK_divided_by_128=13
	,AHB_SYSCLK_divided_by_256=14
	,AHB_SYSCLK_divided_by_512=15
}AHB_SYSCLK_divided;

/* function declaraction*/

void RCC_initSystemClock(void);

void RCC_enableClock(bus Bus , peripheral Peripheral);

void RCC_disableClock(bus Bus , peripheral Peripheral);





#endif
