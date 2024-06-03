/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.h
 *
 * Description: header file for NVIC Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
#ifndef NVIC_H_
#define NVIC_H_

#define GROUP_4_SUBGROUP_0 			0x05FA0300
#define GROUP_3_SUBGROUP_1 			0x05FA0400
#define GROUP_2_SUBGROUP_2 			0x05FA0500
#define GROUP_1_SUBGROUP_3 			0x05FA0600
#define GROUP_0_SUBGROUP_4 			0x05FA0700

 void NVIC_Init(void);

void  NVIC_enableInterrupt(uint8 perphial);
void  NVIC_disableInterrupt(uint8 perphial);
void  NVIC_setPendingFlag(uint8 perphial);
void  NVIC_clearPendingFlag(uint8 perphial);
uint8 NVIC_getActiveFlag(uint8 perphial);
void  NVIC_setPriority(sint8 interruptID , uint8 Priority );






#endif
