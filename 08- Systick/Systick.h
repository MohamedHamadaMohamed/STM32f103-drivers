/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.h
 *
 * Description: header file for Systick Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef SYSTICH_H_
 #define SYSTICH_H_
 
 
 
 #define     Systick_SRC_AHB_8           0
 #define     Systick_SRC_AHB             1

 #define    Systick_SINGLE_INTERVAL      0
 #define    Systick_PERIOD_INTERVAL      1
 
 /******* Function prototypes *******/
 
 void Systick_init(void);
 void Systick_setBusyWait(uint32 tick);
 void Systick_setIntervalSingle(uint32 tick, void (*ptr)(void));
 void Systick_setIntervalPeriodic(uint32 tick, void (*ptr)(void));
 void Systick_stopInterval(void);
 uint32 Systick_getElapsedTime(void);
 uint32 Systick_getRemainingTime(void);

 

 
 #endif
