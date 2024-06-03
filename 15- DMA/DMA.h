/******************************************************************************
 *
 * Module: DMA
 *
 * File Name: DMA.h
 *
 * Description:  header file for DMA driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef DMA_H_
 #define DMA_H_
 
 
 typedef enum 
 {
	DMA_CHANNEL1,DMA_CHANNEL2,DMA_CHANNEL3,DMA_CHANNEL4,DMA_CHANNEL5,DMA_CHANNEL6,DMA_CHANNEL7  
 } DMA_CHANNEL;
 
 typedef enum 
 {
	DMA_MEMORY_TO_MEMORY_MODE_DISABLE ,DMA_MEMORY_TO_MEMORY_MODE_ENABLE
 }DMA_Memory_to_memory_mode;
 
 typedef enum 
 {
	DMA_LOW,DMA_MEDIUM,DMA_HIGH,DMA_VERY_HIGH 
 }DMA_Channel_priority_level;
 
 typedef enum
 {
	DMA_MEMORY_SIZE_8_BITS,DMA_MEMORY_SIZE_16_BITS,DMA_MEMORY_SIZE_32_BITS,DMA_MEMORY_SIZE_RESERVED
 }DMA_memorySize;
 
 typedef enum
 {
	DMA_PERIPHERAL_SIZE_8_BITS,DMA_PERIPHERAL_SIZE_16_BITS,DMA_PERIPHERAL_SIZE_32_BITS,DMA_PERIPHERAL_SIZE_RESERVED

 }DMA_Peripheral_size;
 
 typedef enum
 {
	DMA_MEMORY_INCREMENT_MODE_DISABLED ,DMA_MEMORY_INCREMENT_MODE_ENABLED
 }DMA_Memory_increment_mode;
 
 typedef enum
 {
	DMA_PERIPHERAL_INCREMENT_MODE_DISABLED,DMA_PERIPHERAL_INCREMENT_MODE_ENABLED
 }DMA_Peripheral_increment_mode;

typedef enum
 {
	DMA_CIRCULAR_MODE_DISABLED,DMA_CIRCULAR_MODE_ENABLED
 }DMA_Circular_mode;
 typedef enum
 {
	DMA_READ_FROM_PERIPHERAL,DMA_READ_FROM_MEMORY
 }DMA_Data_transfer_direction;
 
 typedef enum
 {
	DMA_TE_INTERRUPT_DISABLED,DMA_TE_INTERRUPT_ENABLED
 }DMA_Transfer_error_interrupt_enable;	 

 typedef enum
 {
	DMA_HT_INTERRUPT_DISABLED,DMA_HT_INTERRUPT_ENABLED

 }DMA_Half_transfer_interrupt_enable;
 typedef enum
 {
	DMA_TC_INTERRUPT_DISABLED,DMA_TC_INTERRUPT_ENABLED
 } DMA_Transfer_complete_interrupt_enable;
  typedef enum
 {
	DMA_CHANNEL_DISABLED,DMA_CHANNEL_ENABLED
 }DMA_Channel_enable;
 
 typedef struct
  {
 	DMA_CHANNEL channel;
 	DMA_Memory_to_memory_mode Memory_to_memory_mode;
 	DMA_Channel_priority_level Channel_priority_level;
 	DMA_memorySize memorySize ;
 	DMA_Peripheral_size Peripheral_size ;
 	DMA_Memory_increment_mode Memory_increment_mode;
 	DMA_Peripheral_increment_mode Peripheral_increment_mode;
 	DMA_Circular_mode Circular_mode;
 	DMA_Data_transfer_direction Data_transfer_direction;
 	DMA_Transfer_error_interrupt_enable Transfer_error_interrupt_enable;
 	DMA_Half_transfer_interrupt_enable Half_transfer_interrupt_enable;
 	DMA_Transfer_complete_interrupt_enable Transfer_complete_interrupt_enable;
  }DMA_configType;


 /* function declartion */
 void DMA_init(DMA_configType *configType);
 void DMA_start(DMA_CHANNEL channel,uint32 *sourceAdress, uint32 *distinationAdress ,uint16 blockLength);
 void DMA_setCallBack(DMA_CHANNEL channel,void *ptr(void) );
 
 #endif
