/******************************************************************************
 *
 * Module: Seven Segment configuartion
 *
 * File Name: SevenSegment_config.h
 *
 * Description: header file for config STM32F103C8  Microcontroller - Seven Segment configuration Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef SEVEN_SEGEMNT_CONFIG
 #define SEVEN_SEGEMNT_CONFIG
 #include "DIO.h"
 /*
 OPTION : 4 bit mode 
		  8 bit mode
 */
#define DATA_BITS_MODE 		       4 
#define SevenSegment_port    	   PORTA
#define SevenSegment_Data_Reg      GPIOA_ODR
#if (DATA_BITS_MODE == 4)

/*
 FIRST_4_PINS           
 SECOND_4_PINS          
 THIRD_4_PINS           
 FOURTH_4_PINS 
*/

#define DATA_BITS_4_MODE         FIRST_4_PINS
         
#elif (DATA_BITS_MODE == 8)
/*
 FIRST_8_PINS           
 SECOND_8_PINS 
*/

#define DATA_BITS_8_MODE         FIRST_8_PINS         

#endif
 
 
 
#endif