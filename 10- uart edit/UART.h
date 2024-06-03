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
 #ifndef UART_H_
 #define UART_H_
 
 typedef enum{ USART1=1,USART2=2,USART3=3}UART_type;
 
 typedef enum {DATA_8_BITS,DATA_9_BITS} UART_WordLength;
 
 typedef enum {EVEN,ODD}Parity;
 
 typedef enum {STOP_1_BIT,STOP_HALF_BIT,STOP_2_BIT,STOP_ONE_AND_HALF_BIT}STOP;
 
 typedef bool isEnableParity;

#define DISABLE          0U
#define ENABLE           1U

//Baudrate Configuration


typedef enum {
	
/*  Clock: 1 MHz   */
 UART_BAUDRATE_1200_sample_1M =0X0341,
 UART_BAUDRATE_2400_sample_1M =0X01A0,
 UART_BAUDRATE_4800_sample_1M =0X00D0,
 UART_BAUDRATE_9600_sample_1M =0X0068,
 UART_BAUDRATE_19200_sample_1M=0X0034,
 
/*  Clock: 8 MHz  */             
 UART_BAUDRATE_1200_sample_8M =0X1A0B,
 UART_BAUDRATE_2400_sample_8M =0X0D05,
 UART_BAUDRATE_4800_sample_8M =0X0683,
 UART_BAUDRATE_9600_sample_8M =0X0341,
 UART_BAUDRATE_19200_sample_8M=0X01A1
 
}UART_BAUDRATE;


 
 typedef struct 
 {
	UART_type type;//
	UART_WordLength wordLength; //
	Parity parity;//
	STOP stop;//
	isEnableParity enableParity;//
	UART_BAUDRATE UART_baudRate;
 }UART_configType;
 
 void UART_init(UART_configType *configType);
 void  UART_sendByte(UART_type type,const uint8 data);
 uint8 UART_recieveByte(UART_type type);
 void  UART_sendString(UART_type type,const uint8 *data);
 void UART_receiveString(UART_type type,uint8 *data);
 
 
 #endif
