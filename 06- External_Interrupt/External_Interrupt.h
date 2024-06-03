/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: External_Interrupt.h
 *
 * Description: header file for External Interrupt Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_ 

typedef enum{EXT0,EXT1,EXT2,EXT3,EXT4,EXT5,EXT6,EXT7,EXT8,EXT9,EXT10,EXT11,EXT12,EXT13,EXT14,EXT15}EXTI;
typedef enum{RISING,FALLING,ON_CHANGE}EXTI_MODE;

void EXT_Interrupt_init(uint8 line, uint8 mode);
void EXT_Interrupt_enableExternalInterrupt(uint8 line);
void EXT_Interrupt_disableExternalInterrupt(uint8 line);
void EXT_Interrupt_SwTrigger(uint8 line);
void NVIC_setCallBack(void (*NVIC_ptr)(void));





#endif
