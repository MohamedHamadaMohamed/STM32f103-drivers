/******************************************************************************
 *
 * Module: genernal purpose timer
 *
 * File Name: GPT.h
 *
 * Description:  header file for GPT driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef GPT_H_
 #define GPT_H_
 
 typedef enum 
 {
	GPT_tDTS_tCK_INT,GPT_tDTS_2_MUL_tCK_INT,GPT_tDTS_4_MUL_tCK_INT,GPT_tDTS_RESERVED 
 }GPT_Clock_division;
 
 typedef enum 
 {
	 GPT_ARR_register_is_not_buffered,GPT_ARR_register_is_buffered
 }GPT_Auto_reload_preload_enable;
  typedef enum 
 {
	GPT_EDGE_ALIGNED_MODE_THE_COUNTER_COUNTS_UP_OR_DOWN_DEPENDING_ON_THE_DIRECTION_BIT,
	GPT_CENTER_ALIGNED_MODE_OUTPUT_COMPARE_INTERRUPT_FLAGS_OF_CHANNELS_CONFIGURED_IN_OUTPUT_ARE_SET_ONLY_WHEN_THE_COUNTER_IS_COUNTING_DOWN,
	GPT_CENTER_ALIGNED_MODE_OUTPUT_COMPARE_INTERRUPT_FLAGS_OF_CHANNELS_CONFIGURED_IN_OUTPUT_ARE_SET_ONLY_WHEN_THE_COUNTER_IS_COUNTING_UP,
	GPT_CENTER_ALIGNED_MODE_OUTPUT_COMPARE_INTERRUPT_FLAGS_OF_CHANNELS_CONFIGURED_IN_OUTPUT_ARE_SET_ONLY_WHEN_THE_COUNTER_IS_COUNTING_DOWN_OR_UP
 }GPT_Center_aligned_mode_selection;
 typedef enum 
 {
	GPT_COUNTER_USED_AS_UPCOUNTER,GPT_COUNTER_USED_AS_DOWNCOUNTER 
 }GPT_Direction;
 
 typedef enum 
 {
	GPT_COUNTER_IS_NOT_STOPPED_AT_UPDATE_EVENT,GPT_COUNTER_STOPS_COUNTING_AT_THE_NEXT_UPDATE_EVENT 
 }GPT_One_pulse_mode;
 
 typedef enum 
 {
	GPT_COUNTER_OVERFLOW_UNDERFLOW__SETTING_THE_UG_BIT__UPDATE_GENERATION_THROUGH_THE_SLAVE_MODE_CONTROLLER,
	GPT_ONLY COUNTER OVERFLOW_UNDERFLOW_GENERATES_AN_UPDATE_INTERRUPT_OR_DMA_REQUEST_IF_ENABLED
 }GPT_Update_request_source;
 
 typedef struct 
 {
	 
 }GPT_configType;
 #endif