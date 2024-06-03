 /******************************************************************************
 *
 * Module: STD types
 *
 * File Name: STD_Types.h
 *
 * Description: STD types definations
 *
 * Author: Mohamed Hamada
 *
 *******************************************************************************/
 #ifndef STD_TYPES_H
 #define STD_TYPES_H
 /*     NULL pointer    */
 #ifndef NULL
 #define NULL   ((void*)0)
 #endif
 
 /*boolean data type*/
 typedef unsigned char bool;
 
 #ifndef TRUE 
 #define TRUE (1U)
 #endif 
 #ifndef FALSE 
 #define FALSE (0U)
 #endif 
 
 #ifndef HIGH 
 #define HIGH (1U)
 #endif 
 #ifndef LOW 
 #define LOW (0U)
 #endif 
 
 
 
 
 
 
 typedef unsigned char		    uint8;
 typedef signed char   			sint8;
 typedef unsigned short int 	uint16;
 typedef signed short int   	sint16;
 typedef unsigned long int 		uint32;
 typedef signed long int   		sint32;
 typedef float   				float32;
 typedef double   				float64;
 
 #endif