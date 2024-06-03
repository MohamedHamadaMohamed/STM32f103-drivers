/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.c
 *
 * Description: Header file for STM32F103C8  Microcontroller - UART Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 #include "Std_Types.h"
 #include "Common_Macros.h"
 
 #include "DIO.h"

 #include "UART.h"
 #include "UART_Regs.h"
 #include "UART_private.h"
 #include "UART_config.h"
 
 void UART_init(UART_configType *configType)
 {
	switch(configType->type)
	{
		case USART1 :
			      USART1_CR1 =0;
				  USART1_CR2 =0;
				  USART1_CR3 =0;
				  
				  
				/* A9 = TX output speed 50 MHZ */
                DIO_ConfigType TXconfig={UART_1_PORT , UART_1_TX,OUTPUT_SPEED_50MHZ_PUSH_PULL};
		        /* A10 = RX input floating */
		        DIO_ConfigType RXconfig={UART_1_PORT ,  UART_1_RX,INPUT_FLOATING};
				
				
				DIO_init(&TXconfig);
		        DIO_init(&RXconfig);
				  
			 switch(configType ->stop)
					{
						case STOP_1_BIT:
										CLEAR_BIT(USART1_CR2,STOP);
										CLEAR_BIT(USART1_CR2,STOP+1);		break;
										
						case STOP_HALF_BIT:
										SET_BIT(USART1_CR2,STOP);
										CLEAR_BIT(USART1_CR2,STOP+1);		break;
										
						case STOP_2_BIT:
										CLEAR_BIT(USART1_CR2,STOP);
										SET_BIT(USART1_CR2,STOP+1);			break;
										
						case STOP_ONE_AND_HALF_BIT:
										SET_BIT(USART1_CR2,STOP);
										SET_BIT(USART1_CR2,STOP+1);			break;
										
		
					}


			 switch(configType ->enableParity)
					{
						case DISABLE :CLEAR_BIT(USART1_CR1,PCE);		break;
						case ENABLE  :SET_BIT  (USART1_CR1,PCE);
						switch(configType ->parity)
						{
							case EVEN : CLEAR_BIT(USART1_CR1,PS);	break;
							case ODD  : SET_BIT(USART1_CR1,PS);      break;
						}

						break;
					}
					
					switch(configType ->wordLength)
					{
						case DATA_8_BITS: CLEAR_BIT(USART1_CR1,M);break;
						case DATA_9_BITS: SET_BIT(USART1_CR1,M);  break;
					}
					

                    USART1_BRR = configType->UART_baudRate;
					/* enable transmitter */
					SET_BIT(USART1_CR1,TE);
					/* enable receiver */
					SET_BIT(USART1_CR1,RE);

					
					/* enable uart */
					SET_BIT(USART1_CR1,UE);
					
					break;
					
		case USART2 : 
			      USART2_CR1 =0;
				  USART2_CR2 =0;
				  USART2_CR3 =0;
				 
				/* A2 = TX output speed 50 MHZ */
                DIO_ConfigType TXconfig={UART_2_PORT , UART_2_TX,OUTPUT_SPEED_50MHZ_PUSH_PULL};
		        /* A3 = RX input floating */
		        DIO_ConfigType RXconfig={UART_2_PORT ,  UART_2_RX,INPUT_FLOATING};
                
				DIO_init(&TXconfig);
		        DIO_init(&RXconfig);
				  
			 switch(configType ->stop)
					{
						case STOP_1_BIT:
										CLEAR_BIT(USART2_CR2,STOP);
										CLEAR_BIT(USART2_CR2,STOP+1);		break;
										
						case STOP_HALF_BIT:
										SET_BIT(USART2_CR2,STOP);
										CLEAR_BIT(USART2_CR2,STOP+1);		break;
										
						case STOP_2_BIT:
										CLEAR_BIT(USART2_CR2,STOP);
										SET_BIT(USART2_CR2,STOP+1);			break;
										
						case STOP_ONE_AND_HALF_BIT:
										SET_BIT(USART2_CR2,STOP);
										SET_BIT(USART2_CR2,STOP+1);			break;
										
		
					}


			 switch(configType ->enableParity)
					{
						case DISABLE :CLEAR_BIT(USART2_CR1,PCE);		break;
						case ENABLE  :SET_BIT  (USART2_CR1,PCE);
						switch(configType ->parity)
						{
							case EVEN : CLEAR_BIT(USART2_CR1,PS);	break;
							case ODD  : SET_BIT(USART2_CR1,PS);      break;
						}

						break;
					}
					
					switch(configType ->wordLength)
					{
						case DATA_8_BITS: CLEAR_BIT(USART2_CR1,M);break;
						case DATA_9_BITS: SET_BIT(USART2_CR1,M);  break;
					}
					

                    USART2_BRR = configType->UART_baudRate;
					/* enable transmitter */
					SET_BIT(USART2_CR1,TE);
					/* enable receiver */
					SET_BIT(USART2_CR1,RE);

					
					/* enable uart */
					SET_BIT(USART2_CR1,UE);
					
					break;
		case USART3 : 
			      USART3_CR1 =0;
				  USART3_CR2 =0;
				  USART3_CR3 =0;
				  
				/* B10 = TX output speed 50 MHZ */
                DIO_ConfigType TXconfig ={UART_3_PORT , UART_3_TX,OUTPUT_SPEED_50MHZ_PUSH_PULL};
		        /* B11 = RX input floating */
		        DIO_ConfigType RXconfig ={UART_3_PORT ,  UART_3_RX,INPUT_FLOATING};
				
				DIO_init(&TXconfig);
		        DIO_init(&RXconfig);

				  
			 switch(configType ->stop)
					{
						case STOP_1_BIT:
										CLEAR_BIT(USART3_CR2,STOP);
										CLEAR_BIT(USART3_CR2,STOP+1);		break;
										
						case STOP_HALF_BIT:
										SET_BIT(USART3_CR2,STOP);
										CLEAR_BIT(USART3_CR2,STOP+1);		break;
										
						case STOP_2_BIT:
										CLEAR_BIT(USART3_CR2,STOP);
										SET_BIT(USART3_CR2,STOP+1);			break;
										
						case STOP_ONE_AND_HALF_BIT:
										SET_BIT(USART3_CR2,STOP);
										SET_BIT(USART3_CR2,STOP+1);			break;
										
		
					}


			 switch(configType ->enableParity)
					{
						case DISABLE :CLEAR_BIT(USART3_CR1,PCE);		break;
						case ENABLE  :SET_BIT  (USART3_CR1,PCE);
						switch(configType ->parity)
						{
							case EVEN : CLEAR_BIT(USART3_CR1,PS);	break;
							case ODD  : SET_BIT(USART3_CR1,PS);      break;
						}

						break;
					}
					
					switch(configType ->wordLength)
					{
						case DATA_8_BITS: CLEAR_BIT(USART3_CR1,M);break;
						case DATA_9_BITS: SET_BIT(USART3_CR1,M);  break;
					}
					

                    USART3_BRR = configType->UART_baudRate;
					/* enable transmitter */
					SET_BIT(USART3_CR1,TE);
					/* enable receiver */
					SET_BIT(USART3_CR1,RE);

					
					/* enable uart */
					SET_BIT(USART3_CR1,UE);
					
					break;
		
		
		
		
	}
	 
	 
	
	

	
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void  UART_sendByte(UART_type type,const uint8 data)
 {
	 
	switch(type)
	{
		case USART1:
					USART1_DR = data;
					/*	wait transmision to complete	*/
					while(GET_BIT(USART1_SR,TC)==0);
					break;
				
		case USART2:
					USART2_DR = data;
					/*	wait transmision to complete	*/
					while(GET_BIT(USART2_SR,TC)==0  
					break;
		case USART3:
					USART3_DR = data;
					/*	wait transmision to complete	*/
					while(GET_BIT(USART3_SR,TC)==0);    
					break;
		
	}	
	
	
 }
 
 
  uint8 UART_recieveByte(UART_type type)
 {
	uint8 data;
	switch(type)
	{
		case USART1:
				  /*	wait receiver to complete	*/
					while(BIT_IS_CLEAR(USART1_SR,RXNE));
					data = ((0XFF) &(USART1_DR));
					break;

		case USART2:
				  /*	wait receiver to complete	*/
					while(BIT_IS_CLEAR(USART2_SR,RXNE));
					data = ((0XFF) &(USART2_DR));
					break;

		case USART3:
				  /*	wait receiver to complete	*/
					while(BIT_IS_CLEAR(USART3_SR,RXNE));
					data = ((0XFF) &(USART3_DR));
					break;


	}	 
	
	return data;

	 
 }
 
 void  UART_sendString(UART_type type,const uint8 *data)
 {
	uint8 i = 0;
	while(data[i] != '\0')
	{
		switch(type)
		{
			case USART1:		UART_sendByte(USART1,data[i]);	break;

			case USART2:		UART_sendByte(USART2,data[i]);  break;

			case USART3:		UART_sendByte(USART3,data[i]);  break;
		}	
		i++;
	}
 }
 void UART_receiveString(UART_type type,uint8 *data)
 {
	uint8 i = 0;
	switch(type)
	{
		case USART1:
					data[i] = UART_recieveByte(USART1);
					while(data[i] != 'Z')
					{
						i++;
						data[i] = UART_recieveByte(USART1);
					}
		
		case USART2:
					data[i] = UART_recieveByte(USART2);
					while(data[i] != '#')
					{
						i++;
						data[i] = UART_recieveByte(USART2);
					}
		
		case USART3:
					data[i] = UART_recieveByte(USART3);
					while(data[i] != '#')
					{
						i++;
						data[i] = UART_recieveByte(USART3);
					}

	}
	

	data[i] = '\0';
}
	 



