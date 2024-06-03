/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI.h
 *
 * Description:  header file for STP driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef SPI_H_
 #define SPI_H_
 
 typdef enum 
 {
	SPI1,SPI2 
 }SPI_type;
 
 typedef enum 
 {
  SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE_SELECTED,SPI_1_LINE_BIDIRECTIONAL_DATA_MODE_SELECTED	 
 } SPI_Bidirectional_data_mode_enable;
 
 
 typedef enum 
 {
	SPI_OUTPUT_DISABLED_RECEIVE_ONLY_MODE,SPI_OUTPUT_ENABLED_TRANSMIT_ONLY_MODE
 }SPI_Output_enable_in_bidirectional_mode;

 typedef enum 
 { 
    SPI_CRC_CALCULATION_DISABLED,SPI_CRC_CALCULATION_ENABLED
 }SPI_Hardware_CRC_calculation_enable;
 
  typedef enum 
 { 
    SPI_DATA_PHASE_NO_CRC_PHASE,SPI_NEXT_TRANSFER_IS_CRC_CRC_PHASE
 }SPI_CRC_transfer_next;
 
 typedef enum 
 {
	SPI_8_BIT_DATA_FRAME ,SPI_16_BIT_DATA_FRAME
 
 }SPI_Data_frame;
 
 typedef enum 
 {
	SPI_FULL_DUPLEX_TRANSMI_AND_RECEIVE,SPI_OUTPUT_DISABLED_RECEIVE_ONLY_MODE
 
 }SPI_Receive_only;

 typedef enum 
 {
	SPI_SOFTWARE_SLAVE_MANAGEMENT_DISABLED,SPI_SOFTWARE_SLAVE_MANAGEMENT_ENABLED
 }SPI_Software_slave_management;
 typedef enum 
 { 
    SPI_MSB_TRANSMITTED_FIRST,SPI_LSB_TRANSMITTED_FIRST
 }SPI_Frame_format;
 
 typedef enum 
 {
	SPI_PERIPHERAL_DISABLED,SPI_PERIPHERAL_ENABLED
 }SPI_enable;
 typedef enum 
 { 
 
    SPI_fPCLK_DIV_2,SPI_fPCLK_DIV_4,SPI_fPCLK_DIV_8,SPI_fPCLK_DIV_16,
	SPI_fPCLK_DIV_32,SPI_fPCLK_DIV_64,SPI_fPCLK_DIV_128,SPI_fPCLK_DIV_256

 }SPI_Baud_rate_control;
 
 typedef enum 
 {
	SPI_SLAVE_CONFIGURATION,SPI_MASTER_CONFIGURATION
 }  SPI_Master_selection;
 
 typedef enum 
 {
	SPI_CK_TO_0_WHEN_IDLE,SPI_CK_TO_1_WHEN_IDLE
 }SPI_Clock_polarity;

 typedef enum 
 { 
    SPI_The_first_clock_transition_is_the_first_data_capture_edge
   ,SPI_The_second_clock_transition_is_the_first_data_capture_edge
 }SPI_Clock_phase;
 
 typedef struct 
 {
	SPI_type type;
	SPI_Bidirectional_data_mode_enable 		 Bidirectional_data_mode_enable; 
	SPI_Output_enable_in_bidirectional_mode  Output_enable_in_bidirectional_mode;
	SPI_Hardware_CRC_calculation_enable	     Hardware_CRC_calculation_enable	;
	SPI_CRC_transfer_next                    CRC_transfer_next;
	SPI_Data_frame 							 Data_frame;
	SPI_Receive_only   						 Receive_only;
	SPI_Software_slave_management			 Software_slave_management;
	 
	SPI_Frame_format 						 Frame_format;
	
	SPI_enable								 enable;
	SPI_Baud_rate_control					 Baud_rate_control;
	SPI_Master_selection 					 Master_selection ;
	SPI_Clock_polarity						 Clock_polarity;
	SPI_Clock_phase 						 Clock_phase;
	
 }SPI_configType;
 
 
 /**************************** function declartion  ********************************/
 
 void SPI_init(SPI_configType *configType);		  
 void SPI_sendRecieveSynchronus(SPI_type type,uint8 slavePort ,uint8 slavePort,uint16 dataToTransmit , uint16 * dataToRecieve);
 
 #endif