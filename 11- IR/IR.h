/******************************************************************************
 *
 * Module: IR
 *
 * File Name: IR.h
 *
 * Description: header file for IR Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #ifndef IR_H_
 #definr IR_H_
 
 /*********************function declaration  ***********************/
 void IR_init(void (*ptr)(void));
 void IR_getFrame(void);
 void takeAction(void);

 
 
 #endif