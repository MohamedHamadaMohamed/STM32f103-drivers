 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.h
 *
 * Description: Header file for STM32F103C8  Microcontroller - LCD Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef LCD_h_
 #define LCD_h_
 
 #include "Std_Types.h"
 #include "LCD_config.h"

 
 /*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD Data bits mode configuration */


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




/* LCD Commands */
#define CLEAR_COMMAND 					0x01
#define FOUR_BITS_DATA_MODE 			0x02
#define TWO_LINE_LCD_Four_BIT_MODE 		0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 	0x38
#define CURSOR_OFF						0x0C
#define CURSOR_ON 						0x0E
#define SET_CURSOR_LOCATION 			0x80 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);
 
 #endif
