 /******************************************************************************
 *
 * Module: Seven Segment
 *
 * File Name: SevenSegment.c
 *
 * Description: header file for config STM32F103C8  Microcontroller - Seven Segment Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Common_Macros.h"
 
 #include"DIO.h"
 #include"SevenSegment.h"
 #include"SevenSegment_config.h"
 /************************************************************************************
* Service Name: SevenSegment_init
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): number.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize pin in Seven Segment .
************************************************************************************/
void SevenSegment_init(void )
{
	#if DATA_BITS_MODE==4
	          
            
  
	#if DATA_BITS_4_MODE == FIRST_4_PINS
		DIO_SetPinDirection( SevenSegment_port,PIN0, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN1, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN2, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN3, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
	#elif DATA_BITS_4_MODE == SECOND_4_PINS
		DIO_SetPinDirection( SevenSegment_port,PIN4, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN5, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN6, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN7, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
	#elif DATA_BITS_4_MODE == THIRD_4_PINS
		DIO_SetPinDirection( SevenSegment_port,PIN8, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN9, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN10, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN11, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
	#elif DATA_BITS_4_MODE == FOURTH_4_PINS
		DIO_SetPinDirection( SevenSegment_port,PIN12, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN13, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN14, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		DIO_SetPinDirection( SevenSegment_port,PIN15, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
	#endif
	#elif DATA_BITS_MODE==8
		#if DATA_BITS_8_MODE == FIRST_8_PINS
			DIO_SetPinDirection( SevenSegment_port,PIN0, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN1, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN2, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN3, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN4, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN5, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN6, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN7, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		#elif DATA_BITS_8_MODE == SECOND_8_PINS
			DIO_SetPinDirection( SevenSegment_port,PIN8, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN9, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN10, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN11, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN12, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN13, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN14, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
			DIO_SetPinDirection( SevenSegment_port,PIN15, OUTPUT_SPEED_2MHZ_PUSH_PULL);/* Configure the data pin(pin 0) as output pin */
		#endif
	#endif
}

 /************************************************************************************
* Service Name: SevenSegment_init
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): number.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize pin in Seven Segment .
************************************************************************************/
void SevenSegment_writeNumber(uint8 num)
{
	#if DATA_BITS_MODE==4
	          
            
  
	#if DATA_BITS_4_MODE == FIRST_4_PINS
		DIO_WritePort( SevenSegment_port,PIN0, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN1, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN2, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN3, num%2);/* Configure the data pin(pin 0) as output pin */

	#elif DATA_BITS_4_MODE == SECOND_4_PINS
		DIO_WritePort( SevenSegment_port,PIN4, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN5, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN6, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN7, num%2);/* Configure the data pin(pin 0) as output pin */
	#elif DATA_BITS_4_MODE == THIRD_4_PINS
				DIO_WritePort( SevenSegment_port,PIN8, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN9, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN10, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN11, num%2);/* Configure the data pin(pin 0) as output pin */

	#elif DATA_BITS_4_MODE == FOURTH_4_PINS
				DIO_WritePort( SevenSegment_port,PIN12, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN13, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN14, num%2);/* Configure the data pin(pin 0) as output pin */
		num=num/2;
		DIO_WritePort( SevenSegment_port,PIN15, num%2);/* Configure the data pin(pin 0) as output pin */

	#endif
	#elif DATA_BITS_MODE==8
		#if DATA_BITS_8_MODE == FIRST_8_PINS
		switch(num)
		{
			case 0 : SevenSegment_Data_Reg =(SevenSegment_Data_Reg &)
			
		}
		
		#elif DATA_BITS_8_MODE == SECOND_8_PINS
	    
		#endif
	#endif
	
	
	
}












