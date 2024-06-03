/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_private.h
 *
 * Description: Header file for STM32F103C8  Microcontroller - UART Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef UART_PRIVATE_H_
 #define UART_PRIVATE_H_
 
 
 /******************************************************************************
                               Configuration bits
*******************************************************************************/
/* Register bits definition*/

/* SR bits register definition*/
#define PE                    0
#define FE                    1
#define OREE                  2
#define NE                    3
#define IDLE                  4
#define RXNE                  5
#define TC                    6
#define TXE                   7
#define LDB                   8
#define CTS                   9
/* CR1 bits register definition*/
#define SPK                   0
#define RWU                   1  
#define RE                    2
#define TE                    3
#define IDLEIE                4
#define RXNEIE                5
#define TCIE                  6
#define TXEIE                 7
#define PEIE                  8
#define PS                    9
#define PCE                   10
#define WAKE                  11
#define M                     12
#define UE                    13
/* CR2 bits register definition*/
#define ADD                   0
#define LBDL                  5
#define LBDIE                 6
#define LBCL                  8
#define CPHA                  9
#define CPOL                  10
#define CLKEN                 11
#define STOP                  12
#define LINEN                 14
/* CR3 bits register definition*/
#define EIE                   0
#define IREN                  1
#define IRLP                  2
#define HDSEL                 3
#define NACK                  4
#define SCEN                  5
#define DMAR                  6
#define DMAT                  7
#define RTSE                  8
#define CTSE                  9
#define CTSIE                 10
 
 
 
 
 
 #endif