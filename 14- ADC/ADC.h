/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description:  header file for ADC driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef ADC_H_
 #define ADC_H_

 typedef struct 
 {
	Adc_ChannelType 					channel							;
	Adc_GroupType 						GroupType						;
	Adc_ValueGroupType  				ValueGroupType					;
	Adc_PrescaleType 					PrescaleType					;
	Adc_ConversionTimeType  			ConversionTimeType				;
	Adc_SamplingTimeType  				SamplingTimeType				;
	Adc_ResolutionType  				ResolutionType					;
	Adc_StatusType  					StatusType  					;
	Adc_TriggerSourceType   			TriggerSourceType 				;
	Adc_GroupConvModeType   			GroupConvModeType 				;
	Adc_GroupPriorityType				GroupPriorityType 				;
	Adc_GroupDefType					GroupDefType					;
	Adc_StreamNumSampleType 			StreamNumSampleType	    		;
	Adc_StreamBufferModeType	 		StreamBufferModeType			;
	Adc_GroupAccessModeType 			GroupAccessModeType 			;   
	Adc_HwTriggerSignalType 			HwTriggerSignalType 			;
	Adc_HwTriggerTimerType 				HwTriggerTimerType				;
	Adc_PriorityImplementationType 		PriorityImplementationType		;
	Adc_GroupReplacementType 			GroupReplacementType			;
	Adc_ChannelRangeSelectType			ChannelRangeSelectType			;
	Adc_ResultAlignmentType 			ResultAlignmentType				;
	Adc_PowerStateType	     			PowerStateType					;	
	Adc_PowerStateRequestResultType 	PowerStateRequestResultType		; 
 }Adc_ConfigType;
 
 typedef enum 
 { 
	CHANNEL0,CHANNEL1,CHANNEL2,CHANNEL3,CHANNEL4,
	CHANNEL5,CHANNEL6,CHANNEL7,CHANNEL8,CHANNEL9
 }Adc_Channels;

 typedef uint8        Adc_ChannelType   
 typedef uint8        Adc_GroupType;
 typedef uint32       Adc_ValueGroupType; 
 typedef uint8        Adc_PrescaleType;
 typedef uint8        Adc_ConversionTimeType;
 typedef uint8        Adc_SamplingTimeType;
 typedef uint8        Adc_ResolutionType;
 
 typedef enum
 {
	ADC_IDLE,ADC_BUSY,ADC_COMPLETED,ADC_STREAM_COMPLETED
	
 }Adc_StatusType;
 
 typedef enum
 {
	ADC_TRIGG_SRC_SW,ADC_TRIGG_SRC_HW 
 }Adc_TriggerSourceType;
 
 typedef enum
 { 
    ADC_CONV_MODE_ONESHOT,ADC_CONV_MODE_CONTINUOUS
 }Adc_GroupConvModeType;
 
 typedef uint8 Adc_GroupPriorityType;
  
 typedef implementation_specific		Adc_GroupDefType;
 typedef uint8						    Adc_StreamNumSampleType;
 
 typedef enum
 {
	ADC_STREAM_BUFFER_LINEAR,ADC_STREAM_BUFFER_CIRCULAR
 }Adc_StreamBufferModeType;
 
 typedef enum
 {
	ADC_ACCESS_MODE_SINGLE,ADC_ACCESS_MODE_STREAMING
 }Adc_GroupAccessModeType;
 
 typedef enum
 {
	ADC_HW_TRIG_RISING_EDGE,ADC_HW_TRIG_FALLING_EDGE,ADC_HW_TRIG_BOTH_EDGES
 }Adc_HwTriggerSignalType;
 
 typedef uint32      		 Adc_HwTriggerTimerType;
 
 typedef enum
 { 
 ADC_PRIORITY_NONE,ADC_PRIORITY_HW,ADC_PRIORITY_HW_SW
 }Adc_PriorityImplementationType;
 
 typedef enum
 {
	ADC_GROUP_REPL_ABORT_RESTART,ADC_GROUP_REPL_SUSPEND_RESUME 
	 
 }Adc_GroupReplacementType;
  
 typedef enum
 {
	ADC_RANGE_UNDER_LOW,ADC_RANGE_BETWEEN,ADC_RANGE_OVER_HIGH,ADC_RANGE_ALWAYS,
	ADC_RANGE_NOT_UNDER_LOW,ADC_RANGE_NOT_BETWEEN,ADC_RANGE_NOT_OVER_HIGH
	
 }Adc_ChannelRangeSelectType;
 typedef enum
 { 
    ADC_ALIGN_LEFT,ADC_ALIGN_RIGHT
 }Adc_ResultAlignmentType;

 typedef enum
 {
	ADC_FULL_POWER
 }Adc_PowerStateType;	

 typedef enum
 { 
    ADC_SERVICE_ACCEPTED,ADC_NOT_INIT,ADC_SEQUENCE_ERROR,ADC_HW_FAILURE,
	ADC_POWER_STATE_NOT_SUPP,ADC_TRANS_NOT_POSSIBLE
 }Adc_PowerStateRequestResultType; 
 
	 
 


/********************	function defination		************************/

 void Adc_Init(const Adc_ConfigType* ConfigPtr);
 uint32 Adc_SetupResultBuffer( Adc_GroupType Group, const Adc_ValueGroupType* DataBufferPtr );
 void Adc_DeInit( void );
 void Adc_StartGroupConversion( Adc_GroupType Group );
 void Adc_StopGroupConversion( Adc_GroupType Group );
 uint32 Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );
 void Adc_EnableHardwareTrigger( Adc_GroupType Group );
 void Adc_DisableHardwareTrigger( Adc_GroupType Group );
 void Adc_EnableGroupNotification( Adc_GroupType Group );
 void Adc_DisableGroupNotification( Adc_GroupType Group );
 Adc_StatusType Adc_GetGroupStatus( Adc_GroupType Group );
 Adc_StreamNumSampleType Adc_GetStreamLastPointer( Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr );
 void Adc_GetVersionInfo( Std_VersionInfoType* versioninfo );
 uint32 Adc_SetPowerState(Adc_PowerStateRequestResultType* Result );
 uint32 Adc_GetCurrentPowerState( Adc_PowerStateType* CurrentPowerState, Adc_PowerStateRequestResultType* Result );
 uint32 Adc_GetTargetPowerState( Adc_PowerStateType* TargetPowerState, Adc_PowerStateRequestResultType* Result );
 uint32 Adc_PreparePowerState( Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType* Result )
 
 
 
 
 
 
 #endif