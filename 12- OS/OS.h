/******************************************************************************
 *
 * Module: operating systems
 *
 * File Name: OS.h
 *
 * Description:  header file for OS driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef OS_H_
 #define OS_H_
 
 typedef struct 
 {
	uint16 priodicity;

    void (*ptr)(void);	
	 
 }Task;
 
 void OS_createTask(uint8 priority ,uint16 priodicity , void (*ptr)(void));
 void OS_start(void);
 #endif
 