/******************************************************************************
 *
 * Module: STP
 *
 * File Name: STP.h
 *
 * Description:  header file for STP driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "DIO.h"
 #include "Systick.h"
 
 #include "STP.h"
 #include "STP_config.h"
 
 
 void STP_init(void)
 {
	Systick_init();
	
    DIO_ConfigType config1={STP_SERIAL_DATA_PORT,STP_SERIAL_DATA_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config2={STP_STORE_CLOCK_PORT,STP_STORE_CLOCK_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_ConfigType config3={STP_SHIFT_CLOCK_PORT,STP_SHIFT_CLOCK_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL};

	DIO_init(&config1);
	DIO_init(&config2);
   	DIO_init(&config3); 
 }

 
 void STP_sendSynchronus(uint8 dataTosend)
 {
	sint8 counter ;
    uint8 bit ;
	
	DIO_WriteChannel(STP_SERIAL_DATA_PORT,STP_SERIAL_DATA_PIN, LOW);
	DIO_WriteChannel(STP_STORE_CLOCK_PORT,STP_STORE_CLOCK_PIN, LOW);
	DIO_WriteChannel(STP_SHIFT_CLOCK_PORT,STP_SHIFT_CLOCK_PIN, LOW);

    for(counter =7 ;counter >=0;counter--)
	{
		bit = GET_BIT(dataTosend,counter);
		DIO_WriteChannel(STP_SERIAL_DATA_PORT,STP_SERIAL_DATA_PIN, bit);
		
		Systick_setBusyWait(1);
		//for(uint32 i =0;i<10;i++);
		DIO_WriteChannel(STP_SHIFT_CLOCK_PORT,STP_SHIFT_CLOCK_PIN, HIGH);
		Systick_setBusyWait(1);
		//for(uint32 i =0;i<10;i++);

		DIO_WriteChannel(STP_SHIFT_CLOCK_PORT,STP_SHIFT_CLOCK_PIN, LOW);
    	Systick_setBusyWait(1);
		//for(uint32 i =0;i<10;i++);

	}	
	
	   DIO_WriteChannel(STP_STORE_CLOCK_PORT,STP_STORE_CLOCK_PIN,HIGH);
       Systick_setBusyWait(1);
	//for(uint32 i =0;i<10;i++);

	DIO_WriteChannel(STP_STORE_CLOCK_PORT,STP_STORE_CLOCK_PIN,LOW);
 }

 
 
