 /******************************************************************************
 *
 * Module: Seven Segment
 *
 * File Name: SevenSegment.h
 *
 * Description: header file for config STM32F103C8  Microcontroller - Seven Segment Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifnef SEVEN_SEGMENT
 #define SEVEN_SEGMENT
 
 /* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)



#define FIRST_4_PINS           0U
#define SECOND_4_PINS          1U
#define THIRD_4_PINS           2U
#define FOURTH_4_PINS          3U


#elif (DATA_BITS_MODE == 8)

#define FIRST_8_PINS           0U
#define SECOND_8_PINS          1U

#endif
void SevenSegment_init(void );

void SevenSegment_writeNumber(uint8 num);
 
 
 
 #endif