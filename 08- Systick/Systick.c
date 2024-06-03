/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.c
 *
 * Description: source file for Systick Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "Systick.h"
 #include "Systick_Regs.h"
 #include "Systick_config.h"
 
 static void (*callBackPtr)(void)= NULL;
 
 static uint8 modeOfInterval = 0;
 
 
 void Systick_init(void)
 {
	 
	 #if Systick_TIMER_FREQ == Systick_SRC_AHB
			STK_CTRL = 0x00000004;
	 #elif Systick_TIMER_FREQ == Systick_SRC_AHB_8
			STK_CTRL = 0;
	 #endif
	 
	 
 }
 void Systick_setBusyWait(uint32 tick)
 {
	 STK_LOAD =tick;
	 SET_BIT(STK_CTRL, 0);

	 while(BIT_IS_CLEAR(STK_CTRL,16));
	 SET_BIT(STK_CTRL, 0);
	 STK_LOAD =0;
	 STK_VAL=0; 
 }
 void Systick_setIntervalSingle(uint32 tick, void (*ptr)(void))
 {
	 	 STK_LOAD =tick;
		 SET_BIT(STK_CTRL, 0);
		 modeOfInterval=Systick_SINGLE_INTERVAL;
		 callBackPtr =ptr;
		 SET_BIT(STK_CTRL, 1);


 }
 void Systick_setIntervalPeriodic(uint32 tick, void (*ptr)(void))
 {
		 STK_LOAD =tick;
		 SET_BIT(STK_CTRL, 0);

		 modeOfInterval=Systick_PERIOD_INTERVAL;

		 callBackPtr =ptr;
		 SET_BIT(STK_CTRL, 1);

 }
 void Systick_stopInterval(void)
 {
	CLEAR_BIT(STK_CTRL, 1);
	
	SET_BIT(STK_CTRL, 0);
	STK_LOAD =0;
	STK_VAL=0;
	 
 }
 uint32 Systick_getElapsedTime(void)
 {
	 return STK_LOAD - STK_VAL;
 }
 uint32 Systick_getRemainingTime(void)
 {
	 return  STK_VAL;
	 
 }
 
 void SysTick_Handler(void)
 {
	 
		
		
	uint8 temp;
	if (modeOfInterval == Systick_SINGLE_INTERVAL)
	{
		CLEAR_BIT(STK_CTRL, 1);
		SET_BIT(STK_CTRL, 0);
		STK_LOAD = 0;
		STK_VAL  = 0;
	}
	
	if(callBackPtr!=NULL)
		callBackPtr();
	
	temp = GET_BIT(STK_CTRL,16);
 }
