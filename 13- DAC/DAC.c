/******************************************************************************
 *
 * Module: DAC
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
 
 #include "DIO.h"
 #include "Systick.h"
 
 #include "DAC.h"
 #include "DAC_config.h"

 
 volatile i=0;
 volatile uint8 *input;

 
 void setDAC();
 
 void DAC_init(void)
 {
	DIO_ConfigType config0={DAC_PORT,DAC_PIN0,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config1={DAC_PORT,DAC_PIN1,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config2={DAC_PORT,DAC_PIN2,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config3={DAC_PORT,DAC_PIN3,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config4={DAC_PORT,DAC_PIN4,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config5={DAC_PORT,DAC_PIN5,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config6={DAC_PORT,DAC_PIN6,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config7={DAC_PORT,DAC_PIN7,OUTPUT_SPEED_2MHZ_PUSH_PULL};

	DIO_init(&config0);
	DIO_init(&config1);
	DIO_init(&config2);
	DIO_init(&config3);
	DIO_init(&config4);
	DIO_init(&config5); 
	DIO_init(&config6);
	DIO_init(&config7);
	
	Systick_init();

 
	 
 }
 
void setDAC()
{
	DIO_WriteChannel(DAC_PORT,DAC_PIN0, input[i]%2);
	input[i]/= 2;
	DIO_WriteChannel(DAC_PORT,DAC_PIN1, input[i]%2);
	input[i]/= 2;
	DIO_WriteChannel(DAC_PORT,DAC_PIN2, input[i]%2);
	input[i]/= 2;
	DIO_WriteChannel(DAC_PORT,DAC_PIN3, input[i]%2);
    
    input[i]/= 2;	
	DIO_WriteChannel(DAC_PORT,DAC_PIN4, input[i]%2);
	input[i]/= 2;
	DIO_WriteChannel(DAC_PORT,DAC_PIN5, input[i]%2);
	input[i]/= 2;
	DIO_WriteChannel(DAC_PORT,DAC_PIN6, input[i]%2);
	input[i]/= 2;
	DIO_WriteChannel(DAC_PORT,DAC_PIN7, input[i]%2);
		
	
	i++;

	if (i==32713)
	{
		i=0;
	}
}

 
 void DAC_start(uint8 *input)
 {
	
	Systick_setIntervalPeriodic(125, setDAC);
	 
 }
