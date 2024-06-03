/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI.c
 *
 * Description:  source file for STP driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "DIO.h"
 
 #include "SPI.h"
 #include "SPI_Regs.h"
 #include "SPI_config.h"
 

 
 void SPI_init(SPI_configType *configType)
 {
	 
	switch (type)
	{
	case SPI1 :
		switch(Bidirectional_data_mode_enable)
		{
			case SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE_SELECTED:	CLEAR_BIT(SPI1_CR1,15); break;
			case SPI_1_LINE_BIDIRECTIONAL_DATA_MODE_SELECTED:   SET_BIT(SPI1_CR1,15);   break;
		}
		switch(Output_enable_in_bidirectional_mode)
		{
			case SPI_OUTPUT_DISABLED_RECEIVE_ONLY_MODE : CLEAR_BIT(SPI1_CR1,14); break;
			case SPI_OUTPUT_ENABLED_TRANSMIT_ONLY_MODE : SET_BIT(SPI1_CR1,14);   break;
		}	
		switch(Hardware_CRC_calculation_enable)
		{
			case SPI_CRC_CALCULATION_DISABLED:CLEAR_BIT(SPI1_CR1,13); break;
			case SPI_CRC_CALCULATION_ENABLED: SET_BIT(SPI1_CR1,13);	 break;
		}
		switch(CRC_transfer_next)
		
		{
			case SPI_DATA_PHASE_NO_CRC_PHASE       : CLEAR_BIT(SPI1_CR1,12); break;
			case SPI_NEXT_TRANSFER_IS_CRC_CRC_PHASE: SET_BIT(SPI1_CR1,12); 	break;
		}		
		switch(Data_frame)
		{
			case SPI_8_BIT_DATA_FRAME :  CLEAR_BIT(SPI1_CR1,11); break;
			case SPI_16_BIT_DATA_FRAME:  SET_BIT(SPI1_CR1,11); 	break;
		}	
		switch(Receive_only)
		{
			case SPI_FULL_DUPLEX_TRANSMI_AND_RECEIVE  :  CLEAR_BIT(SPI1_CR1,10); break;
			case SPI_OUTPUT_DISABLED_RECEIVE_ONLY_MODE:  SET_BIT(SPI1_CR1,10); 	break;
		}	
		switch(Software_slave_management)
		{
			case SPI_SOFTWARE_SLAVE_MANAGEMENT_DISABLED : CLEAR_BIT(SPI1_CR1,9); break;
			case SPI_SOFTWARE_SLAVE_MANAGEMENT_ENABLED  : SET_BIT(SPI1_CR1,9);   break; 
		}
		switch(Frame_format)
		{
			case SPI_MSB_TRANSMITTED_FIRST : CLEAR_BIT(SPI1_CR1,7);  break;
			case SPI_LSB_TRANSMITTED_FIRST : SET_BIT(SPI1_CR1,7); 	break;
		}
		switch(enable)
		{
			case SPI_PERIPHERAL_DISABLED : CLEAR_BIT(SPI1_CR1,6);    break;
			case SPI_PERIPHERAL_ENABLED  : SET_BIT(SPI1_CR1,6); 		break;
		}
		switch(Baud_rate_control)
		
		{
			case SPI_fPCLK_DIV_2  :CLEAR_BIT(SPI1_CR1,5);CLEAR_BIT(SPI1_CR1,4);CLEAR_BIT(SPI1_CR1,3); break;
			case SPI_fPCLK_DIV_4  :CLEAR_BIT(SPI1_CR1,5);CLEAR_BIT(SPI1_CR1,4);SET_BIT(SPI1_CR1,3)  ; break;
			case SPI_fPCLK_DIV_8  :CLEAR_BIT(SPI1_CR1,5);SET_BIT(SPI1_CR1,4)  ;CLEAR_BIT(SPI1_CR1,3); break;
			case SPI_fPCLK_DIV_16 :CLEAR_BIT(SPI1_CR1,5);SET_BIT(SPI1_CR1,4)  ;SET_BIT(SPI1_CR1,3)  ; break;
			case SPI_fPCLK_DIV_32 :SET_BIT(SPI1_CR1,5)  ;CLEAR_BIT(SPI1_CR1,4);CLEAR_BIT(SPI1_CR1,3); break;
			case SPI_fPCLK_DIV_64 :SET_BIT(SPI1_CR1,5)  ;CLEAR_BIT(SPI1_CR1,4);SET_BIT(SPI1_CR1,3)  ; break;
			case SPI_fPCLK_DIV_128:SET_BIT(SPI1_CR1,5)  ;SET_BIT(SPI1_CR1,4)  ;CLEAR_BIT(SPI1_CR1,3); break;
			case SPI_fPCLK_DIV_256:SET_BIT(SPI1_CR1,5)  ;SET_BIT(SPI1_CR1,4)  ;SET_BIT(SPI1_CR1,3)  ; break;
		}		
		switch(Master_selection)
		{
			case SPI_SLAVE_CONFIGURATION :  CLEAR_BIT(SPI1_CR1,2); break;
			case SPI_MASTER_CONFIGURATION:  SET_BIT(SPI1_CR1,2); break;
		}	
		switch(Clock_polarity)
		{
			case SPI_CK_TO_0_WHEN_IDLE:  CLEAR_BIT(SPI1_CR1,1); break;
			case SPI_CK_TO_1_WHEN_IDLE:  SET_BIT(SPI1_CR1,1); break;
		}			
		switch(Clock_phase)
		{
			case SPI_The_first_clock_transition_is_the_first_data_capture_edge : CLEAR_BIT(SPI1_CR1,0); break;
			case SPI_The_second_clock_transition_is_the_first_data_capture_edge: SET_BIT(SPI1_CR1,0); break;
		}
		
		break ;
	
	case SPI2 : 
		switch(Bidirectional_data_mode_enable)
		{
			case SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE_SELECTED:	CLEAR_BIT(SPI2_CR1,15); break;
			case SPI_1_LINE_BIDIRECTIONAL_DATA_MODE_SELECTED:   SET_BIT(SPI2_CR1,15);   break;
		}
		switch(Output_enable_in_bidirectional_mode)
		{
			case SPI_OUTPUT_DISABLED_RECEIVE_ONLY_MODE : CLEAR_BIT(SPI2_CR1,14); break;
			case SPI_OUTPUT_ENABLED_TRANSMIT_ONLY_MODE : SET_BIT(SPI2_CR1,14);   break;
		}	
		switch(Hardware_CRC_calculation_enable)
		{
			case SPI_CRC_CALCULATION_DISABLED:CLEAR_BIT(SPI2_CR1,13); break;
			case SPI_CRC_CALCULATION_ENABLED: SET_BIT(SPI2_CR1,13);	 break;
		}
		switch(CRC_transfer_next)
		
		{
			case SPI_DATA_PHASE_NO_CRC_PHASE       : CLEAR_BIT(SPI2_CR1,12); break;
			case SPI_NEXT_TRANSFER_IS_CRC_CRC_PHASE: SET_BIT(SPI2_CR1,12); 	break;
		}		
		switch(Data_frame)
		{
			case SPI_8_BIT_DATA_FRAME :  CLEAR_BIT(SPI2_CR1,11); break;
			case SPI_16_BIT_DATA_FRAME:  SET_BIT(SPI2_CR1,11); 	break;
		}	
		switch(Receive_only)
		{
			case SPI_FULL_DUPLEX_TRANSMI_AND_RECEIVE  :  CLEAR_BIT(SPI2_CR1,10); break;
			case SPI_OUTPUT_DISABLED_RECEIVE_ONLY_MODE:  SET_BIT(SPI2_CR1,10); 	break;
		}	
		switch(Software_slave_management)
		{
			case SPI_SOFTWARE_SLAVE_MANAGEMENT_DISABLED : CLEAR_BIT(SPI2_CR1,9); break;
			case SPI_SOFTWARE_SLAVE_MANAGEMENT_ENABLED  : SET_BIT(SPI2_CR1,9);   break; 
		}
		switch(Frame_format)
		{
			case SPI_MSB_TRANSMITTED_FIRST : CLEAR_BIT(SPI2_CR1,7);  break;
			case SPI_LSB_TRANSMITTED_FIRST : SET_BIT(SPI2_CR1,7); 	break;
		}
		switch(enable)
		{
			case SPI_PERIPHERAL_DISABLED : CLEAR_BIT(SPI2_CR1,6);    break;
			case SPI_PERIPHERAL_ENABLED  : SET_BIT(SPI2_CR1,6); 		break;
		}
		switch(Baud_rate_control)
		
		{
			case SPI_fPCLK_DIV_2  :CLEAR_BIT(SPI2_CR1,5);CLEAR_BIT(SPI2_CR1,4);CLEAR_BIT(SPI2_CR1,3); break;
			case SPI_fPCLK_DIV_4  :CLEAR_BIT(SPI2_CR1,5);CLEAR_BIT(SPI2_CR1,4);SET_BIT(SPI2_CR1,3)  ; break;
			case SPI_fPCLK_DIV_8  :CLEAR_BIT(SPI2_CR1,5);SET_BIT(SPI2_CR1,4)  ;CLEAR_BIT(SPI2_CR1,3); break;
			case SPI_fPCLK_DIV_16 :CLEAR_BIT(SPI2_CR1,5);SET_BIT(SPI2_CR1,4)  ;SET_BIT(SPI2_CR1,3)  ; break;
			case SPI_fPCLK_DIV_32 :SET_BIT(SPI2_CR1,5)  ;CLEAR_BIT(SPI2_CR1,4);CLEAR_BIT(SPI2_CR1,3); break;
			case SPI_fPCLK_DIV_64 :SET_BIT(SPI2_CR1,5)  ;CLEAR_BIT(SPI2_CR1,4);SET_BIT(SPI2_CR1,3)  ; break;
			case SPI_fPCLK_DIV_128:SET_BIT(SPI2_CR1,5)  ;SET_BIT(SPI2_CR1,4)  ;CLEAR_BIT(SPI2_CR1,3); break;
			case SPI_fPCLK_DIV_256:SET_BIT(SPI2_CR1,5)  ;SET_BIT(SPI2_CR1,4)  ;SET_BIT(SPI2_CR1,3)  ; break;
		}		
		switch(Master_selection)
		{
			case SPI_SLAVE_CONFIGURATION :  CLEAR_BIT(SPI2_CR1,2); break;
			case SPI_MASTER_CONFIGURATION:  SET_BIT(SPI2_CR1,2); break;
		}	
		switch(Clock_polarity)
		{
			case SPI_CK_TO_0_WHEN_IDLE:  CLEAR_BIT(SPI2_CR1,1); break;
			case SPI_CK_TO_1_WHEN_IDLE:  SET_BIT(SPI2_CR1,1); break;
		}			
		switch(Clock_phase)
		{
			case SPI_The_first_clock_transition_is_the_first_data_capture_edge : CLEAR_BIT(SPI2_CR1,0); break;
			case SPI_The_second_clock_transition_is_the_first_data_capture_edge: SET_BIT(SPI2_CR1,0); break;
		}
		
		break ;
	
	}	
	
 } 
 void SPI_sendRecieveSynchronus(SPI_type type,uint8 slavePort ,uint8 slavePort,uint16 dataToTransmit , uint16 * dataToRecieve)
 {
	DIO_ConfigType ConfigSlave ={slavePort,slavePort,OUTPUT_SPEED_2MHZ_PUSH_PULL};
	DIO_init(&ConfigSlave );


     DIO_WriteChannel(slavePort,slavePort,LOW);
    
    	switch(type)
		{
			case SPI1 :
				SPI1_DR = dataToTransmit ;
			case SPI2 :
				SPI2_DR = dataToTransmit ; 
			
		}
	 

	 
     DIO_WriteChannel(slavePort,slavePort,HIGH);	

 }
 