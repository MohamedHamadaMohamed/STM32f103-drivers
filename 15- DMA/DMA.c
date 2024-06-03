/******************************************************************************
 *
 * Module: DMA
 *
 * File Name: DMA.c
 *
 * Description:  source file for DMA driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "DMA.h"
 #include "DMA_Regs.h"
 #include "DMA_config.h"
 
 /*
    DMA_CHANNEL 								channel; 	

	DMA_Memory_to_memory_mode 					Memory_to_memory_mode;
	DMA_Channel_priority_level 					Channel_priority_level;
	DMA_memorySize 								memorySize;
	DMA_Peripheral_size 						Peripheral_size;
	DMA_Memory_increment_mode 					Memory_increment_mode;
	DMA_Peripheral_increment_mode 				Peripheral_increment_mode;
	DMA_Circular_mode 							Circular_mode; 
	DMA_Data_transfer_direction 				Data_transfer_direction;
	DMA_Transfer_error_interrupt_enable 		Transfer_error_interrupt_enable;
	DMA_Half_transfer_interrupt_enable 			Half_transfer_interrupt_enable;
	DMA_Transfer_complete_interrupt_enable 		Transfer_complete_interrupt_enable;
 */
 
 /******************* global variable **********************/
 void (*DMA1_Channel1_callBack)(void)=NULL;
 void (*DMA1_Channel2_callBack)(void)=NULL;
 void (*DMA1_Channel3_callBack)(void)=NULL;
 void (*DMA1_Channel4_callBack)(void)=NULL;
 void (*DMA1_Channel5_callBack)(void)=NULL;
 void (*DMA1_Channel6_callBack)(void)=NULL;
 void (*DMA1_Channel7_callBack)(void)=NULL;

 void DMA_init(DMA_configType *configType);
 {
	switch (configType->channel)
	{
		case DMA_CHANNEL1 :
						  CLEAR_BIT(DMA_CCR1,0); break;

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR1,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR1,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR1,13);CLEAR_BIT(DMA_CCR1,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR1,13);SET_BIT(DMA_CCR1,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR1,13);CLEAR_BIT(DMA_CCR1,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR1,13);SET_BIT(DMA_CCR1,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR1,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR1,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR1,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR1,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR1,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR1,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR1,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR1,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR1,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR1,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR1,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR1,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR1,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR1,1); break;
						  }
							
						  
						  
						  
		case DMA_CHANNEL2 :
						  
						  CLEAR_BIT(DMA_CCR2,0); break;
						  
						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR2,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR2,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR2,13);CLEAR_BIT(DMA_CCR2,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR2,13);SET_BIT(DMA_CCR2,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR2,13);CLEAR_BIT(DMA_CCR2,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR2,13);SET_BIT(DMA_CCR2,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR2,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR2,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR2,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR2,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR2,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR2,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR2,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR2,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR2,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR2,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR2,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR2,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR2,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR2,1); break;
						  }
						
		case DMA_CHANNEL3 :
						  CLEAR_BIT(DMA_CCR3,0); break;
						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR3,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR3,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR3,13);CLEAR_BIT(DMA_CCR3,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR3,13);SET_BIT(DMA_CCR3,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR3,13);CLEAR_BIT(DMA_CCR3,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR3,13);SET_BIT(DMA_CCR3,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR3,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR3,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR3,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR3,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR3,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR3,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR3,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR3,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR3,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR3,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR3,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR3,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR3,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR3,1); break;
						  }
						
		case DMA_CHANNEL4 :	
						  CLEAR_BIT(DMA_CCR4,0); break;

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR4,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR4,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR4,13);CLEAR_BIT(DMA_CCR4,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR4,13);SET_BIT(DMA_CCR4,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR4,13);CLEAR_BIT(DMA_CCR4,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR4,13);SET_BIT(DMA_CCR4,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR4,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR4,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR4,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR4,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR4,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR4,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR4,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR4,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR4,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR4,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR4,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR4,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR4,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR4,1); break;
						  }
							
		case DMA_CHANNEL5 :
						  CLEAR_BIT(DMA_CCR5,0); break;

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR5,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR5,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR5,13);CLEAR_BIT(DMA_CCR5,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR5,13);SET_BIT(DMA_CCR5,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR5,13);CLEAR_BIT(DMA_CCR5,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR5,13);SET_BIT(DMA_CCR5,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR5,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR5,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR5,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR5,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR5,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR5,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR5,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR5,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR5,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR5,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR5,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR5,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR5,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR5,1); break;
						  }
						
		case DMA_CHANNEL6 :
						  CLEAR_BIT(DMA_CCR6,0); break;
		
						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR6,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR6,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR6,13);CLEAR_BIT(DMA_CCR6,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR6,13);SET_BIT(DMA_CCR6,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR6,13);CLEAR_BIT(DMA_CCR6,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR6,13);SET_BIT(DMA_CCR6,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR6,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR6,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR6,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR6,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR6,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR6,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR6,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR6,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR6,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR6,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR6,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR6,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR6,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR6,1); break;
						  }
						
		case DMA_CHANNEL7 :  
						  CLEAR_BIT(DMA_CCR7,0); break;

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR7,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENSABLE: SET_BIT(DMA_CCR7,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR7,13);CLEAR_BIT(DMA_CCR7,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR7,13);SET_BIT(DMA_CCR7,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR7,13);CLEAR_BIT(DMA_CCR7,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR7,13);SET_BIT(DMA_CCR7,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR7,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR7,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR7,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR7,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_Circular mode disabled: CLEAR_BIT(DMA_CCR7,5); break;
							case DMA_Circular mode enabled : SET_BIT(DMA_CCR7,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR7,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR7,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR7,3); break;
							case DMA_TE_INTERRUPT_ENSABLED:  SET_BIT(DMA_CCR7,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR7,2); break;
							case DMA_HT_INTERRUPT_ENSABLED:SET_BIT(DMA_CCR7,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR7,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR7,1); break;
						  }
						  
								

	}	
 }
 void DMA_start(DMA_CHANNEL channel,uint32 *sourceAdress, uint32 *distinationAdress ,uint16 blockLength);
 {
	switch (channel)
	{
		case DMA_CHANNEL1 : DMA_CPAR1 = sourceAdress;
							DMA_CMAR1 = distinationAdress;
							DMA_CNDTR1= blockLength;
    						SET_BIT(DMA_CCR1,0); break;

							break;
		case DMA_CHANNEL2 : DMA_CPAR2 = sourceAdress;
							DMA_CMAR2=distinationAdress;
							DMA_CNDTR2= blockLength;
							SET_BIT(DMA_CCR2,0); break;
							break;
		case DMA_CHANNEL3 : DMA_CPAR3 = sourceAdress;
							DMA_CMAR3=distinationAdress;
							DMA_CNDTR3= blockLength;
							SET_BIT(DMA_CCR3,0); break;
							break;
		case DMA_CHANNEL4 : DMA_CPAR4 = sourceAdress;
							DMA_CMAR4=distinationAdress;
							DMA_CNDTR4= blockLength;
							SET_BIT(DMA_CCR4,0); break;
							break;
		case DMA_CHANNEL5 : DMA_CPAR5 = sourceAdress;
							DMA_CMAR5=distinationAdress;
							DMA_CNDTR5= blockLength;
							SET_BIT(DMA_CCR5,0); break;
							break;
		case DMA_CHANNEL6 : DMA_CPAR6 = sourceAdress;
							DMA_CMAR6=distinationAdress;
							DMA_CNDTR6= blockLength;
							SET_BIT(DMA_CCR6,0); break;
							break;
		case DMA_CHANNEL7 : DMA_CPAR7 = sourceAdress;
							DMA_CMAR7=distinationAdress;
							DMA_CNDTR7= blockLength;
							SET_BIT(DMA_CCR7,0); break;
							break;
	}
	
	 
 }
 void DMA_setCallBack(DMA_CHANNEL channel,void *ptr(void) )
 {
		switch (channel)
		{
			case DMA_CHANNEL1 : DMA1_Channel1_callBack = ptr; break;					
			case DMA_CHANNEL2 : DMA1_Channel2_callBack = ptr; break;		
			case DMA_CHANNEL3 : DMA1_Channel3_callBack = ptr; break;
            case DMA_CHANNEL4 : DMA1_Channel4_callBack = ptr; break;
			case DMA_CHANNEL5 : DMA1_Channel5_callBack = ptr; break;				
			case DMA_CHANNEL6 : DMA1_Channel6_callBack = ptr; break;
 		    case DMA_CHANNEL7 : DMA1_Channel7_callBack = ptr; break;
		} 
 }
 void DMA1_Channel1_IRQHandler(void)
 {  
 /*24, 20, 16, 12,8, 4, 0*/
    SET_BIT(DMA_IFCR , 0);
    SET_BIT(DMA_IFCR , 1);


/*25, 21, 17, 13,9, 5, 1*/
	if (DMA1_Channel1_callBack != NULL)
				DMA1_Channel1_callBack();
 }
 void DMA1_Channel2_IRQHandler(void)
 {      
    SET_BIT(DMA_IFCR , 4);	
    SET_BIT(DMA_IFCR , 5);

	if (DMA1_Channel2_callBack != NULL)
				DMA1_Channel2_callBack();
 }
 void DMA1_Channel3_IRQHandler(void)
 {  
    SET_BIT(DMA_IFCR , 8);
    SET_BIT(DMA_IFCR , 9);

    	 
	if (DMA1_Channel3_callBack != NULL)
				DMA1_Channel3_callBack();
 } 
 void DMA1_Channel4_IRQHandler(void)
 {  
    SET_BIT(DMA_IFCR , 12);
    SET_BIT(DMA_IFCR , 13);


	if (DMA1_Channel4_callBack != NULL)
				DMA1_Channel4_callBack();
 }
 void DMA1_Channel5_IRQHandler(void)
 { 
    SET_BIT(DMA_IFCR , 16);
    SET_BIT(DMA_IFCR , 17);

 
	if (DMA1_Channel5_callBack != NULL)
				DMA1_Channel5_callBack();
 }
 void DMA1_Channel6_IRQHandler(void)
 {/******************************************************************************
 *
 * Module: DMA
 *
 * File Name: DMA.c
 *
 * Description:  source file for DMA driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "DMA.h"
 #include "DMA_Regs.h"
 #include "DMA_config.h"
 
 /*
    DMA_CHANNEL 								channel; 	

	DMA_Memory_to_memory_mode 					Memory_to_memory_mode;
	DMA_Channel_priority_level 					Channel_priority_level;
	DMA_memorySize 								memorySize;
	DMA_Peripheral_size 						Peripheral_size;
	DMA_Memory_increment_mode 					Memory_increment_mode;
	DMA_Peripheral_increment_mode 				Peripheral_increment_mode;
	DMA_Circular_mode 							Circular_mode; 
	DMA_Data_transfer_direction 				Data_transfer_direction;
	DMA_Transfer_error_interrupt_enable 		Transfer_error_interrupt_enable;
	DMA_Half_transfer_interrupt_enable 			Half_transfer_interrupt_enable;
	DMA_Transfer_complete_interrupt_enable 		Transfer_complete_interrupt_enable;
 */
 
 /******************* global variable **********************/
 void (*DMA1_Channel1_callBack)(void)=NULL;
 void (*DMA1_Channel2_callBack)(void)=NULL;
 void (*DMA1_Channel3_callBack)(void)=NULL;
 void (*DMA1_Channel4_callBack)(void)=NULL;
 void (*DMA1_Channel5_callBack)(void)=NULL;
 void (*DMA1_Channel6_callBack)(void)=NULL;
 void (*DMA1_Channel7_callBack)(void)=NULL;

 void DMA_init(DMA_configType *configType)
 {
	switch (configType->channel)
	{
		case DMA_CHANNEL1 :
						  CLEAR_BIT(DMA_CCR1,0);

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR1,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR1,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR1,13);CLEAR_BIT(DMA_CCR1,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR1,13);SET_BIT(DMA_CCR1,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR1,13);CLEAR_BIT(DMA_CCR1,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR1,13);SET_BIT(DMA_CCR1,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR1,11);CLEAR_BIT(DMA_CCR1,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR1,11);SET_BIT(DMA_CCR1,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR1,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR1,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR1,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR1,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case 	DMA_CIRCULAR_MODE_DISABLED : CLEAR_BIT(DMA_CCR1,5); break;
							case DMA_CIRCULAR_MODE_ENABLED: SET_BIT(DMA_CCR1,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR1,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR1,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR1,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR1,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR1,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR1,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
							DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR1,1); break;
							DMA_TC_INTERRUPT_ENSABLED: SET_BIT(DMA_CCR1,1); break;
						  }
							
						  
						  
						  
		case DMA_CHANNEL2 :
						  
						  CLEAR_BIT(DMA_CCR2,0);
						  
						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR2,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR2,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR2,13);CLEAR_BIT(DMA_CCR2,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR2,13);SET_BIT(DMA_CCR2,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR2,13);CLEAR_BIT(DMA_CCR2,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR2,13);SET_BIT(DMA_CCR2,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR2,11);CLEAR_BIT(DMA_CCR2,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR2,11);SET_BIT(DMA_CCR2,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR2,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR2,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR2,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR2,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_CIRCULAR_MODE_DISABLED: CLEAR_BIT(DMA_CCR2,5); break;
							case DMA_CIRCULAR_MODE_ENABLED : SET_BIT(DMA_CCR2,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR2,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR2,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR2,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR2,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR2,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR2,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
						  case DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR2,1); break;
						  case DMA_TC_INTERRUPT_ENABLED: SET_BIT(DMA_CCR2,1); break;
						  }
						
		case DMA_CHANNEL3 :
						  CLEAR_BIT(DMA_CCR3,0);
						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR3,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR3,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR3,13);CLEAR_BIT(DMA_CCR3,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR3,13);SET_BIT(DMA_CCR3,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR3,13);CLEAR_BIT(DMA_CCR3,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR3,13);SET_BIT(DMA_CCR3,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR3,11);CLEAR_BIT(DMA_CCR3,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR3,11);SET_BIT(DMA_CCR3,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR3,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR3,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR3,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR3,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_CIRCULAR_MODE_DISABLED: CLEAR_BIT(DMA_CCR3,5); break;
							case DMA_CIRCULAR_MODE_ENABLED : SET_BIT(DMA_CCR3,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR3,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR3,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR3,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR3,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR3,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR3,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
						    case DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR3,1); break;
						    case DMA_TC_INTERRUPT_ENABLED: SET_BIT(DMA_CCR3,1); break;
						  }
						
		case DMA_CHANNEL4 :	
						  CLEAR_BIT(DMA_CCR4,0);

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR4,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR4,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR4,13);CLEAR_BIT(DMA_CCR4,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR4,13);SET_BIT(DMA_CCR4,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR4,13);CLEAR_BIT(DMA_CCR4,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR4,13);SET_BIT(DMA_CCR4,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR4,11);CLEAR_BIT(DMA_CCR4,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR4,11);SET_BIT(DMA_CCR4,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR4,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR4,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR4,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR4,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_CIRCULAR_MODE_DISABLED: CLEAR_BIT(DMA_CCR4,5); break;
							case DMA_CIRCULAR_MODE_ENABLED : SET_BIT(DMA_CCR4,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR4,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR4,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR4,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR4,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR4,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR4,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
						    case DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR4,1); break;
						    case DMA_TC_INTERRUPT_ENABLED: SET_BIT(DMA_CCR4,1); break;
						  }
							
		case DMA_CHANNEL5 :
						  CLEAR_BIT(DMA_CCR5,0);

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR5,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR5,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR5,13);CLEAR_BIT(DMA_CCR5,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR5,13);SET_BIT(DMA_CCR5,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR5,13);CLEAR_BIT(DMA_CCR5,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR5,13);SET_BIT(DMA_CCR5,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR5,11);CLEAR_BIT(DMA_CCR5,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR5,11);SET_BIT(DMA_CCR5,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR5,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR5,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR5,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR5,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_CIRCULAR_MODE_DISABLED: CLEAR_BIT(DMA_CCR5,5); break;
							case DMA_CIRCULAR_MODE_ENABLED : SET_BIT(DMA_CCR5,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR5,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR5,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR5,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR5,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR5,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR5,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
						    case DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR5,1); break;
						    case DMA_TC_INTERRUPT_ENABLED: SET_BIT(DMA_CCR5,1); break;
						  }
						
		case DMA_CHANNEL6 :
						  CLEAR_BIT(DMA_CCR6,0);
		
						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR6,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR6,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR6,13);CLEAR_BIT(DMA_CCR6,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR6,13);SET_BIT(DMA_CCR6,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR6,13);CLEAR_BIT(DMA_CCR6,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR6,13);SET_BIT(DMA_CCR6,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR6,11);CLEAR_BIT(DMA_CCR6,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR6,11);SET_BIT(DMA_CCR6,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR6,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR6,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR6,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR6,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_CIRCULAR_MODE_DISABLED: CLEAR_BIT(DMA_CCR6,5); break;
							case DMA_CIRCULAR_MODE_ENABLED : SET_BIT(DMA_CCR6,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR6,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR6,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR6,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR6,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR6,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR6,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
						    case DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR6,1); break;
						    case DMA_TC_INTERRUPT_ENABLED: SET_BIT(DMA_CCR6,1); break;
						  }
						
		case DMA_CHANNEL7 :  
						  CLEAR_BIT(DMA_CCR7,0);

						  switch (configType->Memory_to_memory_mode )
						  {
							case DMA_MEMORY_TO_MEMORY_MODE_DISABLE: CLEAR_BIT(DMA_CCR7,14);break;
							case DMA_MEMORY_TO_MEMORY_MODE_ENABLE: SET_BIT(DMA_CCR7,14);  break;
						  }
						  switch (configType->Channel_priority_level)
						  {
							case DMA_LOW:CLEAR_BIT(DMA_CCR7,13);CLEAR_BIT(DMA_CCR7,12);    break;
							case DMA_MEDIUM:CLEAR_BIT(DMA_CCR7,13);SET_BIT(DMA_CCR7,12);   break;
							case DMA_HIGH:SET_BIT(DMA_CCR7,13);CLEAR_BIT(DMA_CCR7,12);     break; 
							case DMA_VERY_HIGH :SET_BIT(DMA_CCR7,13);SET_BIT(DMA_CCR7,12); break;
							  
						  }
						  switch (configType->memorySize)
						  {
							case DMA_MEMORY_SIZE_8_BITS:CLEAR_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);    break;
							case DMA_MEMORY_SIZE_16_BITS:CLEAR_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);     break;
							case DMA_MEMORY_SIZE_32_BITS:SET_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);     break; 
							case DMA_MEMORY_SIZE_RESERVED:SET_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);      break; 
						  }
						  switch(configType->Peripheral_size)
						  {
							case DMA_PERIPHERAL_SIZE_8_BITS  :CLEAR_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);    break;
							case DMA_PERIPHERAL_SIZE_16_BITS :CLEAR_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);      break;
							case DMA_PERIPHERAL_SIZE_32_BITS :SET_BIT(DMA_CCR7,11);CLEAR_BIT(DMA_CCR7,10);      break; 
							case DMA_PERIPHERAL_SIZE_RESERVED:SET_BIT(DMA_CCR7,11);SET_BIT(DMA_CCR7,10);        break;   
						  }
						  switch(configType->Memory_increment_mode)
						  {
							case DMA_MEMORY_INCREMENT_MODE_DISABLED : CLEAR_BIT(DMA_CCR7,7); break;
							case DMA_MEMORY_INCREMENT_MODE_ENABLED  : SET_BIT(DMA_CCR7,7); break;
						  }
						  switch(configType->Peripheral_increment_mode)
						  {
							case DMA_PERIPHERAL_INCREMENT_MODE_DISABLED: CLEAR_BIT(DMA_CCR7,6); break;
							case DMA_PERIPHERAL_INCREMENT_MODE_ENABLED : SET_BIT(DMA_CCR7,6); break;
						  
						  }
						  switch(configType->Circular_mode)
						  {
							case DMA_CIRCULAR_MODE_DISABLED: CLEAR_BIT(DMA_CCR7,5); break;
							case DMA_CIRCULAR_MODE_ENABLED : SET_BIT(DMA_CCR7,5); break;
						  } 
						  switch(configType->Data_transfer_direction)
						  {
							case DMA_READ_FROM_PERIPHERAL: CLEAR_BIT(DMA_CCR7,4); break;
							case DMA_READ_FROM_MEMORY    : SET_BIT(DMA_CCR7,4); break;
						  }
						  switch(configType->Transfer_error_interrupt_enable)
						  {
							case DMA_TE_INTERRUPT_DISABLED:  CLEAR_BIT(DMA_CCR7,3); break;
							case DMA_TE_INTERRUPT_ENABLED:  SET_BIT(DMA_CCR7,3); break;
						  }
						  switch(configType->Half_transfer_interrupt_enable)
						  {
							case DMA_HT_INTERRUPT_DISABLED:CLEAR_BIT(DMA_CCR7,2); break;
							case DMA_HT_INTERRUPT_ENABLED:SET_BIT(DMA_CCR7,2); break;
						  }
						  switch(configType->Transfer_complete_interrupt_enable)
						  {
						     case DMA_TC_INTERRUPT_DISABLED: CLEAR_BIT(DMA_CCR7,1); break;
						     case DMA_TC_INTERRUPT_ENABLED: SET_BIT(DMA_CCR7,1); break;
						  }
						  
								

	}	
 }
 void DMA_start(DMA_CHANNEL channel,uint32 *sourceAdress, uint32 *distinationAdress ,uint16 blockLength)
 {
	switch (channel)
	{
		case DMA_CHANNEL1 : DMA_CPAR1 = sourceAdress;
							DMA_CMAR1 = distinationAdress;
							DMA_CNDTR1= blockLength;
    						SET_BIT(DMA_CCR1,0); break;

							break;
		case DMA_CHANNEL2 : DMA_CPAR2 = sourceAdress;
							DMA_CMAR2=distinationAdress;
							DMA_CNDTR2= blockLength;
							SET_BIT(DMA_CCR2,0); break;
							break;
		case DMA_CHANNEL3 : DMA_CPAR3 = sourceAdress;
							DMA_CMAR3=distinationAdress;
							DMA_CNDTR3= blockLength;
							SET_BIT(DMA_CCR3,0); break;
							break;
		case DMA_CHANNEL4 : DMA_CPAR4 = sourceAdress;
							DMA_CMAR4=distinationAdress;
							DMA_CNDTR4= blockLength;
							SET_BIT(DMA_CCR4,0); break;
							break;
		case DMA_CHANNEL5 : DMA_CPAR5 = sourceAdress;
							DMA_CMAR5=distinationAdress;
							DMA_CNDTR5= blockLength;
							SET_BIT(DMA_CCR5,0); break;
							break;
		case DMA_CHANNEL6 : DMA_CPAR6 = sourceAdress;
							DMA_CMAR6=distinationAdress;
							DMA_CNDTR6= blockLength;
							SET_BIT(DMA_CCR6,0); break;
							break;
		case DMA_CHANNEL7 : DMA_CPAR7 = sourceAdress;
							DMA_CMAR7=distinationAdress;
							DMA_CNDTR7= blockLength;
							SET_BIT(DMA_CCR7,0); break;
							break;
	}
	
	 
 }
 void DMA_setCallBack(DMA_CHANNEL channel,void *ptr(void) )
 {
		switch (channel)
		{
			case DMA_CHANNEL1 : DMA1_Channel1_callBack = ptr; break;					
			case DMA_CHANNEL2 : DMA1_Channel2_callBack = ptr; break;		
			case DMA_CHANNEL3 : DMA1_Channel3_callBack = ptr; break;
            case DMA_CHANNEL4 : DMA1_Channel4_callBack = ptr; break;
			case DMA_CHANNEL5 : DMA1_Channel5_callBack = ptr; break;				
			case DMA_CHANNEL6 : DMA1_Channel6_callBack = ptr; break;
 		    case DMA_CHANNEL7 : DMA1_Channel7_callBack = ptr; break;
		} 
 }
 void DMA1_Channel1_IRQHandler(void)
 {  
 /*24, 20, 16, 12,8, 4, 0*/
    SET_BIT(DMA_IFCR , 0);
    SET_BIT(DMA_IFCR , 1);


/*25, 21, 17, 13,9, 5, 1*/
	if (DMA1_Channel1_callBack != NULL)
				DMA1_Channel1_callBack();
 }
 void DMA1_Channel2_IRQHandler(void)
 {      
    SET_BIT(DMA_IFCR , 4);	
    SET_BIT(DMA_IFCR , 5);

	if (DMA1_Channel2_callBack != NULL)
				DMA1_Channel2_callBack();
 }
 void DMA1_Channel3_IRQHandler(void)
 {  
    SET_BIT(DMA_IFCR , 8);
    SET_BIT(DMA_IFCR , 9);

    	 
	if (DMA1_Channel3_callBack != NULL)
				DMA1_Channel3_callBack();
 } 
 void DMA1_Channel4_IRQHandler(void)
 {  
    SET_BIT(DMA_IFCR , 12);
    SET_BIT(DMA_IFCR , 13);


	if (DMA1_Channel4_callBack != NULL)
				DMA1_Channel4_callBack();
 }
 void DMA1_Channel5_IRQHandler(void)
 { 
    SET_BIT(DMA_IFCR , 16);
    SET_BIT(DMA_IFCR , 17);

 
	if (DMA1_Channel5_callBack != NULL)
				DMA1_Channel5_callBack();
 }
 void DMA1_Channel6_IRQHandler(void)
 {
    SET_BIT(DMA_IFCR , 20);
    SET_BIT(DMA_IFCR , 21);
	if (DMA1_Channel6_callBack != NULL)
				DMA1_Channel6_callBack();
 } 
 void DMA1_Channel7_IRQHandler(void)
 {
    SET_BIT(DMA_IFCR , 24); 	 
    SET_BIT(DMA_IFCR , 25);	
	 
	if (DMA1_Channel7_callBack != NULL)
				DMA1_Channel7_callBack();
 } 
 

    SET_BIT(DMA_IFCR , 20);
    SET_BIT(DMA_IFCR , 21);
	if (DMA1_Channel6_callBack != NULL)
				DMA1_Channel6_callBack();
 } 
 void DMA1_Channel7_IRQHandler(void)
 {
    SET_BIT(DMA_IFCR , 24); 	 
    SET_BIT(DMA_IFCR , 25);	
	 
	if (DMA1_Channel7_callBack != NULL)
				DMA1_Channel7_callBack();
 } 
 