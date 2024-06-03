/******************************************************************************
 *
 * Module: AFIO
 *
 * File Name: AFIO.h
 *
 * Description: header file for AFIO Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef AFIO_H_
 #define AFIO_H_
 
typedef enum{EXT0,EXT1,EXT2,EXT3,EXT4,EXT5,EXT6,EXT7,EXT8,EXT9,EXT10,EXT11,EXT12,EXT13,EXT14,EXT15}EXTI;
typedef enum{PA,PB,PC}P;

void setEXTIConfiguation(uint8 line ,uint8 portMap);

 
 
 #endif