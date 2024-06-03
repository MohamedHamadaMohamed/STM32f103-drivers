/******************************************************************************
 *
 * Module: operating systems
 *
 * File Name: main.c
 *
 * Description:  source file for APP driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #include "Std_Types.h" 
 #include "Common_Macros.h"
 
 
 void led1()
 {
	DIO_WriteChannel(PORTA,PIN0, HIGH);
	DIO_WriteChannel(PORTA,PIN1, LOW);
	DIO_WriteChannel(PORTA,PIN2, LOW);
		
 }
 void led2()
 {
	DIO_WriteChannel(PORTA,PIN0, LOW);
	DIO_WriteChannel(PORTA,PIN1,HIGH );
	DIO_WriteChannel(PORTA,PIN2, LOW);
		
 }
 void led3()
 {
	DIO_WriteChannel(PORTA,PIN0,LOW );
	DIO_WriteChannel(PORTA,PIN1, LOW);
	DIO_WriteChannel(PORTA,PIN2,HIGH );
		
 }
 
 
 int main()
 {
	
	RCC_initSystemClock();
	RCC_enableClock(RCC_APB2 , IOPAEN);

	DIO_ConfigType config1={PORTA,PIN0,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config2={PORTA,PIN1,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config3={PORTA,PIN2,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	
	DIO_init(&config1);
	DIO_init(&config2);
   	DIO_init(&config3);
	
	OS_createTask(0 ,1000 , led1);
	OS_createTask(1 ,2000, led2);
	OS_createTask(2 ,300 , led3);
	
	OS_start();
	
	
	while(1)
	{
		

	}
	
 
 
 }