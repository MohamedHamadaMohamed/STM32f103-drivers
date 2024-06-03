/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick_Regs.h
 *
 * Description: header file for Systick registers Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef SYSTICH_REGS_H_
 #define SYSTICH_REGS_H_
 
 #define STK_CTRL		     							(*((volatile uint32 *)0xE000E010))
 #define STK_LOAD		     							(*((volatile uint32 *)0xE000E014))
 #define STK_VAL		     							(*((volatile uint32 *)0xE000E018))
 #define STK_CALIB		     							(*((volatile uint32 *)0xE000E01C))

 
 #endif