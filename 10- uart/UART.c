/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.c
 *
 * Description: Header file for STM32F103C8  Microcontroller - UART Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Common_Macros.h"
 #include "Std_Types.h" 
 
 #include "UART.h"
 #include "UART_Regs.h"
 #include "UART_config.h"
 
 /* UART Driver Baud Rate */
#define USART_BAUDRATE    9600

 /* UART Driver FREQ CLOCK */
#define USART_FREQ_CLK    8000000

/* UART Driver FREQ CLOCK */
#define USART1_BRR_VALUE   0X341


 
 void UART_init(UART_configType *configType);
 {
	switch(configType -> type)
	{
		case USART1 :
		            switch(configType ->enableParity)
					{
						case DISABLE :CLEAR_BIT(USART1_CR1,10);		break;
						case ENABLE  :SET_BIT  (USART1_CR1,10);
						switch(configType ->parity)
						{
							case EVEN : CLEAR_BIT(USART1_CR1,9);	break;
							case ODD  : SET_BIT(USART1_CR1,9);      break;
						}

						break;
					}
					
					switch(configType ->wordLength)
					{
						case DATA_8_BITS: CLEAR_BIT(USART1_CR1,12);break;
						case DATA_9_BITS: SET_BIT(USART1_CR1,12);  break;
					}
					
					switch(configType ->stop)
					{
						case STOP_1_BIT:
										CLEAR_BIT(USART1_CR2,12);
										CLEAR_BIT(USART1_CR2,13);		break;
										
						case STOP_HALF_BIT:
										SET_BIT(USART1_CR2,12);
										CLEAR_BIT(USART1_CR2,13);		break;
										
						case STOP_2_BIT:
										CLEAR_BIT(USART1_CR2,12);
										SET_BIT(USART1_CR2,13);			break;
										
						case STOP_ONE_AND_HALF_BIT:
										SET_BIT(USART1_CR2,12);
										SET_BIT(USART1_CR2,13);			break;
										
		
					}
		             
                    USART1_BRR = USART1_BRR_VALUE;
					/* enable transmitter */
					SET_BIT(USART1_CR1,2);  
					
					/* enable receiver */
					SET_BIT(USART1_CR1,3);  
					
					/* enable uart */
					SET_BIT(USART1_CR1,13);
					
					USART1_SR=0; 
					break;
					
		case USART2 : 
		            switch(configType ->enableParity)
					{
						case DISABLE :CLEAR_BIT(USART2_CR1,10);		break;
						case ENABLE  :SET_BIT  (USART2_CR1,10);
						switch(configType ->parity)
						{
							case EVEN : CLEAR_BIT(USART2_CR1,9);	break;
							case ODD  : SET_BIT(USART2_CR1,9);      break;
						}

						break;
					}
					
					switch(configType ->wordLength)
					{
						case DATA_8_BITS: CLEAR_BIT(USART2_CR1,12);break;
						case DATA_9_BITS: SET_BIT(USART2_CR1,12);  break;
					}
					
					switch(configType ->stop)
					{
						case STOP_1_BIT:
										CLEAR_BIT(USART2_CR2,12);
										CLEAR_BIT(USART2_CR2,13);		break;
										
						case STOP_HALF_BIT:
										SET_BIT(USART2_CR2,12);
										CLEAR_BIT(USART2_CR2,13);		break;
										
						case STOP_2_BIT:
										CLEAR_BIT(USART2_CR2,12);
										SET_BIT(USART2_CR2,13);			break;
										
						case STOP_ONE_AND_HALF_BIT:
										SET_BIT(USART2_CR2,12);
										SET_BIT(USART2_CR2,13);			break;
										
		
					}
		             
                    USART2_BRR = USART2_BRR_VALUE;
					/* enable transmitter */
					SET_BIT(USART2_CR1,2);  
					
					/* enable receiver */
					SET_BIT(USART2_CR1,3);  
					
					/* enable uart */
					SET_BIT(USART2_CR1,13);
					
					USART2_SR=0; 
					break;
		case USART3 : 
		            switch(configType ->enableParity)
					{
						case DISABLE :CLEAR_BIT(USART3_CR1,10);		break;
						case ENABLE  :SET_BIT  (USART3_CR1,10);
						switch(configType ->parity)
						{
							case EVEN : CLEAR_BIT(USART3_CR1,9);	break;
							case ODD  : SET_BIT(USART3_CR1,9);      break;
						}

						break;
					}
					
					switch(configType ->wordLength)
					{
						case DATA_8_BITS: CLEAR_BIT(USART3_CR1,12);break;
						case DATA_9_BITS: SET_BIT(USART3_CR1,12);  break;
					}
					
					switch(configType ->stop)
					{
						case STOP_1_BIT:
										CLEAR_BIT(USART3_CR2,12);
										CLEAR_BIT(USART3_CR2,13);		break;
										
						case STOP_HALF_BIT:
										SET_BIT(USART3_CR2,12);
										CLEAR_BIT(USART3_CR2,13);		break;
										
						case STOP_2_BIT:
										CLEAR_BIT(USART3_CR2,12);
										SET_BIT(USART3_CR2,13);			break;
										
						case STOP_ONE_AND_HALF_BIT:
										SET_BIT(USART3_CR2,12);
										SET_BIT(USART3_CR2,13);			break;
										
		
					}
		             
                    USART3_BRR = USART3_BRR_VALUE;
					/* enable transmitter */
					SET_BIT(USART3_CR1,2);  
					
					/* enable receiver */
					SET_BIT(USART3_CR1,3);  
					
					/* enable uart */
					SET_BIT(USART3_CR1,13);
					
					USART3_SR=0; 
					break;
		
		
		
		
	}
	 
	 
	
	

	
 }
 void  UART_sendByte(UART_type type,const uint8 data);
 {
	 
	switch(type)
	{
		case USART1:
					USART1_DR = data;
					/*	wait transmision to complete	*/
					while(BIT_IS_CLEAR(USART1_SR,6));    break;
				
		case USART2:
					USART2_DR = data;
					/*	wait transmision to complete	*/
					while(BIT_IS_CLEAR(USART2_SR,6));    break;
		case USART3:
					USART3_DR = data;
					/*	wait transmision to complete	*/
					while(BIT_IS_CLEAR(USART3_SR,6));    break;
		
	}	
	
	
 }
 uint8 UART_recieveByte(UART_type type);
 {
	uint8 data;
	switch(type)
	{
		case USART1:
				  /*	wait receiver to complete	*/
					while(BIT_IS_CLEAR(USART1_SR,5));
					data = ((0XFF) &(USART1_DR));
					break;

		case USART2:
				  /*	wait receiver to complete	*/
					while(BIT_IS_CLEAR(USART2_SR,5));
					data = ((0XFF) &(USART2_DR));
					break;

		case USART3:
				  /*	wait receiver to complete	*/
					while(BIT_IS_CLEAR(USART3_SR,5));
					data = ((0XFF) &(USART3_DR));
					break;

	}	 
	
	return data;

	 
 }
 void  UART_sendString(UART_type type,const uint8 *data);
 {
	uint8 i = 0;
	while(data[i] != '\0')
	{
		switch(type)
		{
			case USART1:		UART_sendByte(USART1,data[i]);	break;

			case USART2:		UART_sendByte(USART2,data[i]);  break;

			case USART3:		UART_sendByte(USART3,data[i]);  break;
		}	
		i++;
	}
 }
 void UART_receiveString(UART_type type,uint8 *data);
 {
	uint8 i = 0;
	switch(type)
	{
		case USART1:
					data[i] = UART_recieveByte(USART1);
					while(data[i] != '#')
					{
						i++;
						data[i] = UART_recieveByte(USART1);
					}
		
		case USART2:
					data[i] = UART_recieveByte(USART2);
					while(data[i] != '#')
					{
						i++;
						data[i] = UART_recieveByte(USART2);
					}
		
		case USART3:
					data[i] = UART_recieveByte(USART3);
					while(data[i] != '#')
					{
						i++;
						data[i] = UART_recieveByte(USART3);
					}

	}
	

	data[i] = '\0';
}
	 

