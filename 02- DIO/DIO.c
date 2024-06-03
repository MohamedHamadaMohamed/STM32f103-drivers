/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO.c
 *
 * Description: Source file for STM32F103C8  Microcontroller - DIO Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Common_Macros.h"
 
 #include"DIO.h"
 #include"DIO_Regs.h"
 #include"DIO_config.h"

/************************************************************************************
* Service Name: DIO_init
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to pin configuration.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize pin in DIO port .
************************************************************************************/ 
void DIO_init(const DIO_ConfigType* ConfigPtr )
{

	switch(ConfigPtr->port_num)
	{
      case PORTA :
			if (ConfigPtr->pin_num <=7)
			{
				GPIOA_CRL&=~((0B1111)<<(ConfigPtr->pin_num * 4));
				GPIOA_CRL|=((ConfigPtr->direction)<<(ConfigPtr->pin_num * 4));
			}
			else if (ConfigPtr->pin_num <=15)
			{
				GPIOA_CRH&=~((0B1111)<<((ConfigPtr->pin_num-8) * 4));
				GPIOA_CRH|=((ConfigPtr->direction)<<((ConfigPtr->pin_num-8) * 4));
				
			}
			else
			{
				/* error */
				
			}
			break;
	  case PORTB :
			if (ConfigPtr->pin_num <=7)
			{
				GPIOB_CRL&=~((0B1111)<<(ConfigPtr->pin_num * 4));
				GPIOB_CRL|=((ConfigPtr->direction)<<(ConfigPtr->pin_num * 4));
			}
			else if (ConfigPtr->pin_num <=15)
			{
				GPIOB_CRH&=~((0B1111)<<((ConfigPtr->pin_num-8) * 4));
				GPIOB_CRH|=((ConfigPtr->direction)<<((ConfigPtr->pin_num-8) * 4));
				
			}
			else
			{
				/* error */
				
			}
			break;
	  case PORTC :
			if (ConfigPtr->pin_num <=7)
			{
				GPIOC_CRL&=~((0B1111)<<(ConfigPtr->pin_num * 4));
				GPIOC_CRL|=((ConfigPtr->direction)<<(ConfigPtr->pin_num * 4));
			}
			else if (ConfigPtr->pin_num <=15)
			{
				GPIOC_CRH&=~((0B1111)<<((ConfigPtr->pin_num-8) * 4));
				GPIOC_CRH|=((ConfigPtr->direction)<<((ConfigPtr->pin_num-8) * 4));
				
			}
			else
			{
				/* error */
				
			}
			break;
	  default    : /* error */ break;
		
	}
	
	
}
/************************************************************************************
* Service Name: DIO_SetPinDirection
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): port type , pin type , direction.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set  Direction for pin .
************************************************************************************/
void DIO_SetPinDirection( DIO_PortType port,DIO_PinType Pin, DIO_PinDirectionType Direction )
{
	switch(port)
	{
      case PORTA :
			if (Pin <=7)
			{
				GPIOA_CRL&=~((0B1111)<<(Pin * 4));
				GPIOA_CRL|=((Direction)<<(Pin * 4));
			}
			else if (Pin <=15)
			{
				GPIOA_CRH&=~((0B1111)<<((Pin-8) * 4));
				GPIOA_CRH|=((Direction)<<((Pin-8) * 4));
				
			}
			else
			{
				/* error */
				
			}
			break;
	  case PORTB :
			if (Pin <=7)
			{
				GPIOB_CRL&=~((0B1111)<<(Pin * 4));
				GPIOB_CRL|=((Direction)<<(Pin * 4));
			}
			else if (Pin <=15)
			{
				GPIOB_CRH&=~((0B1111)<<((Pin-8) * 4));
				GPIOB_CRH|=((Direction)<<((Pin-8) * 4));
				
			}
			else
			{
				/* error */
				
			}
			break;
	  case PORTC :
			if (Pin <=7)
			{
				GPIOC_CRL&=~((0B1111)<<(Pin * 4));
				GPIOC_CRL|=((Direction)<<(Pin * 4));
			}
			else if (Pin <=15)
			{
				GPIOC_CRH&=~((0B1111)<<((Pin-8) * 4));
				GPIOC_CRH|=((Direction)<<((Pin-8) * 4));
				
			}
			else
			{
				/* error */
				
			}
			break;
	  default    : 
		  /* error */
			break;
		
	}
		
	
	
	
}
/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): DIO_PortType  ;
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Read port  in DIO ports .
************************************************************************************/
uint32 DIO_ReadPort(DIO_PortType Port)
{
uint32 result =LOW;
switch(Port)
{
	case PORTA : result = GPIOA_IDR; break;
	case PORTB : result = GPIOA_IDR; break;
	case PORTC : result = GPIOA_IDR; break;
	default    :  break;
}
return result;		
}
/************************************************************************************
* Service Name: DIO_WritePort
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): DIO_PortType , DIO_LevelType .
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to write value in port .
************************************************************************************/
void DIO_WritePort(DIO_PortType Port, uint32 Level)
{
	switch(Port)
	{
		case PORTA :  GPIOA_ODR= Level;     break;
		case PORTB :  GPIOB_ODR= Level;     break;
		case PORTC :  GPIOC_ODR= Level;     break;
		default    :  /*  error  */  break;
	}		
	
}
/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): DIO_PortType ,DIO_PinType ;
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Read Channel  in DIO port .
************************************************************************************/
DIO_LevelType Dio_ReadChannel(DIO_PortType port,DIO_PinType Channel)
{
DIO_LevelType result =LOW;
switch(port)
{
	case PORTA : result=GET_BIT(GPIOA_IDR,Channel); break;
	case PORTB : result=GET_BIT(GPIOB_IDR,Channel); break;
	case PORTC : result=GET_BIT(GPIOC_IDR,Channel); break;
	default    :  break;
}
return result;
	
	
	
}
/************************************************************************************
* Service Name: DIO_WriteChannel
* Service ID[hex]: 
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): DIO_PortType port,DIO_PinType Channel, DIO_LevelType Level.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Write logic number in pin in port .
************************************************************************************/
void DIO_WriteChannel(DIO_PortType port,DIO_PinType Channel, DIO_LevelType Level)
{
	switch(port)	
	{
		case PORTA :
			if(Level == HIGH)
			{
				SET_BIT(GPIOA_ODR,Channel);     
			}
			else if (Level == LOW)
			{
				CLEAR_BIT(GPIOA_ODR,Channel);     
			}
			else 
			{
				/*  error  */
			}
			break;
		case PORTB :
			if(Level == HIGH)
			{
				SET_BIT(GPIOB_ODR,Channel);     
			}
			else if (Level == LOW)
			{
				CLEAR_BIT(GPIOB_ODR,Channel);     
			}
			else 
			{
				/*  error  */
			}
			break;
		case PORTC :
			if(Level == HIGH)
			{
				SET_BIT(GPIOC_ODR,Channel);     
			}
			else if (Level == LOW)
			{
				CLEAR_BIT(GPIOC_ODR,Channel);     
			}
			else 
			{
				/*  error  */
			}
			break;
		default :  /*  error  */ break;
	}
	
}
