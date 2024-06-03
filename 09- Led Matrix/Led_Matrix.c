/******************************************************************************
 *
 * Module: Led Matrix
 *
 * File Name: LedMatrix.c
 *
 * Description: source file for Led Matrix  Driver
 *
 * Author: 			Mohamed Hamada
	
 ******************************************************************************/
 #include "Common_Macros.h"
 #include "Std_Types.h" 

 #include"DIO.h"
 #include "Systick.h"
 
 #include "Led_Matrix.h"
 #include "Led_Matrix_config.h"
 
 static void Led_Matrix_disableAllColums(void);
 static void Led_Matrix_setRowValue(uint8 data);


 
 
  void Led_Matrix_init(void)
  {
	  DIO_SetPinDirection( LED_MATRIX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  
	  DIO_SetPinDirection( LED_MATRIX_COLUM0_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM1_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM2_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM3_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM4_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM5_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM6_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  DIO_SetPinDirection( LED_MATRIX_COLUM7_PIN,OUTPUT_SPEED_2MHZ_PUSH_PULL );
	  
	  Systick_init();
	  
  }
  
   void Led_Matrix_display(uint8 * data)
   {

	   while(1)
	   {
		   for(uint16 i=0;i<100;i++)
		   {
		        	/*	Enable Colum 0*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[0]);
					DIO_WriteChannel(LED_MATRIX_COLUM0_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 1*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[1]);
					DIO_WriteChannel(LED_MATRIX_COLUM1_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 2*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[2]);
					DIO_WriteChannel(LED_MATRIX_COLUM2_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 3*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[3]);
					DIO_WriteChannel(LED_MATRIX_COLUM3_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 4*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[4]);
					DIO_WriteChannel(LED_MATRIX_COLUM4_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 5*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[5]);
					DIO_WriteChannel(LED_MATRIX_COLUM5_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 6*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[6]);
					DIO_WriteChannel(LED_MATRIX_COLUM6_PIN,LOW);
					Systick_setBusyWait(2500);

					/*	Enable Colum 7*/
					Led_Matrix_disableAllColums();
					Led_Matrix_setRowValue(data[7]);
					DIO_WriteChannel(LED_MATRIX_COLUM7_PIN,LOW);
					Systick_setBusyWait(2500);


		   }

		   for(uint8 j=0;j<47;j++)
		   {
			   data[j]=data[j+1];
		   }
		   data[47]=0;
	   }
   }
   static void Led_Matrix_disableAllColums(void)
   {
	    DIO_WriteChannel(LED_MATRIX_COLUM0_PIN,HIGH);
	   	DIO_WriteChannel(LED_MATRIX_COLUM1_PIN,HIGH);
		DIO_WriteChannel(LED_MATRIX_COLUM2_PIN,HIGH);
		DIO_WriteChannel(LED_MATRIX_COLUM3_PIN,HIGH);
		DIO_WriteChannel(LED_MATRIX_COLUM4_PIN,HIGH);
		DIO_WriteChannel(LED_MATRIX_COLUM5_PIN,HIGH);
		DIO_WriteChannel(LED_MATRIX_COLUM6_PIN,HIGH);
		DIO_WriteChannel(LED_MATRIX_COLUM7_PIN,HIGH);
	   
   }
   static void Led_Matrix_setRowValue(uint8 data)
   {
	   	uint8 BIT=0;

		BIT= GET_BIT(data,0);
		DIO_WriteChannel(LED_MATRIX_ROW0_PIN,BIT);
		BIT= GET_BIT(data,1);
		DIO_WriteChannel(LED_MATRIX_ROW1_PIN,BIT);
		BIT= GET_BIT(data,2);
		DIO_WriteChannel(LED_MATRIX_ROW2_PIN,BIT);
		BIT= GET_BIT(data,3);
		DIO_WriteChannel(LED_MATRIX_ROW3_PIN,BIT);
		BIT= GET_BIT(data,4);
		DIO_WriteChannel(LED_MATRIX_ROW4_PIN,BIT);
		BIT= GET_BIT(data,5);
		DIO_WriteChannel(LED_MATRIX_ROW5_PIN,BIT);		
	    BIT= GET_BIT(data,6);
		DIO_WriteChannel(LED_MATRIX_ROW6_PIN,BIT);
		BIT= GET_BIT(data,7);
		DIO_WriteChannel(LED_MATRIX_ROW7_PIN,BIT);   
	   
   }
  
   
  
  
