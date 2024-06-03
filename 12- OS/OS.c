/******************************************************************************
 *
 * Module: operating systems
 *
 * File Name: OS.c
 *
 * Description:  source file for OS driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #include "Std_Types.h" 
 #include "Common_Macros.h"
 
 #include "Systick.h"
 
 #include "OS.h"
 #include "OS_private.h"
 #include "OS_config.h"
 
 Task OS_Tasks[NUM_OF_TASKS];
 
 volatile uint8 TaskCount =0;
 
 void OS_createTask(uint8 priority ,uint16 priodicity , void (*ptr)(void))
 {
	OS_Tasks[priority].priodicity = priodicity;
	OS_Tasks[priority].ptr=ptr;
 }
 
 void OS_start(void)
 {
	Systick_init();

	Systick_setIntervalPeriodic(1000,Schedular);
	 
	 
 }
 
 void Schedular(void)
 {
	if ((TaskCount % OS_Tasks[i].priodicity)==0)
	{
	    OS_Tasks[priority].ptr();	
	}
	TaskCount++; 
	 
	 
	 
 }
