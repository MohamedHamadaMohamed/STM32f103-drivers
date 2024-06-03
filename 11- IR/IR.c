/******************************************************************************
 *
 * Module: IR
 *
 * File Name: IR.c
 *
 * Description: source file for IR Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include"DIO.h"
 #include "NVIC.h"
 #include "External_Interrupt.h"
 #include "SysTick.h"

 
 #include "IR_config.h"
 #include "IR.h"
 
 /********************* Global variable  ****************************/
 
 volatile bool flag=0;
 volatile uint32 frameData[50]={0};
 volatile uint8 counter=0;
 volatile uint8 data=0;
 static void (*callBackPtr)(void)= NULL;

 

/*********************function defination  ************************/
 void IR_init(void (*ptr)(void))
 {
	Systick_init();
	NVIC_voidInit();
	DIO_ConfigType config={IR_OUT_PORT ,IR_OUT_PIN ,INPUT_FLOATING};
	DIO_init(&config);
	
	callBackPtr =ptr;
	EXT_Interrupt_init(IR_EXTI, IR_MODE,IR_getFrame);
	NVIC_setPriority(IR_EXTI + 6 , IR_EXTI_PRIORITY );
	NVIC_enableInterrupt(IR_EXTI +6);
                            
 }
 
 void IR_getFrame(void)
{


	if(flag ==0)
	{
		Systick_setIntervalSingle(1000000,takeAction);
		flag=1;

	}
	else
	{
		frameData[counter]= Systick_getElapsedTime();
		Systick_setIntervalSingle(IR_ONE_SECOND,takeAction);

        counter++;
	}
}

void takeAction(void)
{
	data =0;
	if((frameData[0]>10000)&&(frameData[0]<14000))
	{

		for(uint8 i=0;i<8;i++)
		{
			if((frameData[17+i]>2000)&&(frameData[17+i]<2300))
			{
				SET_BIT(data,i);
			}
			else
			{
				CLEAR_BIT(data,i);

			}


		}
        if (callBackPtr !=NULL)
					callBackPtr();

    }
	else
	{

	}
	 flag=0;
	 frameData[0]=0;
	 counter=0;
	 data=0;
}
 
 

