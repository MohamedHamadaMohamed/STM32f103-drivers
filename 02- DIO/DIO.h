 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: DIO.h
 *
 * Description: Header file for STM32F103C8  Microcontroller - DIO Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"

typedef enum {PORTA,PORTB,PORTC}DIO_PortType; 
  
typedef enum{PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15}DIO_PinType;

typedef enum { 
			/*  INPUT    */
		 INPUT_ANLOG=0b0000
		,INPUT_FLOATING=0b0100
		,INPUT_PULLUP_PULLDOWN=0b1000

		/* OUTPUT  For Speed 10   */
		,OUTPUT_SPEED_10MHZ_PUSH_PULL=0b0001
		,OUTPUT_SPEED_10MHZ_OPEN_DRAIN=0b0101
		,OUTPUT_SPEED_10MHZ_AFPP=0b1001
		,OUTPUT_SPEED_10MHZ_AFOD=0b1101

		/* OUTPUT  For Speed 2   */
		,OUTPUT_SPEED_2MHZ_PUSH_PULL=0b0010
		,OUTPUT_SPEED_2MHZ_OD=0b0110
		,OUTPUT_SPEED_2MHZ_AFPP=0b1010
		,OUTPUT_SPEED_2MHZ_AFOD=0b1110

		/* OUTPUT For Speed 50  */
		,OUTPUT_SPEED_50MHZ_PUSH_PULL=0b0011
		,OUTPUT_SPEED_50MHZ_OPEN_DRAIN=0b0111
		,OUTPUT_SPEED_50MHZ_AFPP=0b1011
		,OUTPUT_SPEED_50MHZ_AFOD=0b1111
		}DIO_PinDirectionType;
typedef enum { OFF,PULL_UP,PULL_DOWN}DIO_InternalResistor;
typedef uint8 DIO_LevelType;

typedef struct  {
DIO_PortType port_num ;
DIO_PinType  pin_num ;
DIO_PinDirectionType direction ;
}DIO_ConfigType;
 
 /* function prototypes */

void DIO_init(const DIO_ConfigType* ConfigPtr );
void DIO_SetPinDirection( DIO_PortType port,DIO_PinType Pin, DIO_PinDirectionType Direction );
uint32 DIO_ReadPort(DIO_PortType Port);
void DIO_WritePort(DIO_PortType Port, uint32 Level);
DIO_LevelType Dio_ReadChannel(DIO_PortType port,DIO_PinType Channel);
void DIO_WriteChannel(DIO_PortType port,DIO_PinType Channel, DIO_LevelType Level);


 
#endif
