 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.h
 *
 * Description: Header file for STM32F103C8  Microcontroller - UART Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef UART_CONFIG_H_
 #define UART_CONFIG_H_
 
 typedef enum{ USART1=1,USART1=2,USART1=3}UART_type;
 
 typedef enum {DATA_8_BITS,DATA_9_BITS} UART_WordLength;
 
 typedef enum {EVEN,ODD}Parity;
 
 typedef enum {STOP_1_BIT,STOP_HALF_BIT,STOP_2_BIT,STOP_ONE_AND_HALF_BIT}STOP;
 
 typedef enum {DISABLE,ENABLE}isEnableParity;

 
 typedef struct 
 {
	UART_type type;//
	UART_WordLength wordLength; //
	Parity parity;//
	STOP stop;//
	bool enableParity;//
 }UART_configType;
 
 void UART_init(UART_configType *configType);
 void  UART_sendByte(UART_type type,const uint8 data);
 uint8 UART_recieveByte(UART_type type);
 void  UART_sendString(UART_type type,const uint8 *data);
 void UART_receiveString(UART_type type,uint8 *data);
 
 
 #endif
