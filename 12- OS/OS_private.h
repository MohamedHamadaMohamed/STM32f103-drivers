/******************************************************************************
 *
 * Module: operating systems
 *
 * File Name: OS_private.h
 *
 * Description:  header file for OS driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 
 #ifndef OS_PRIVATE_H_
 #define OS_PRIVATE_H_
 
 typedef struct 
 {
	uint16 priodicity;

    void (*ptr)(void);	
	 
 }Task;
 
 
 #endif