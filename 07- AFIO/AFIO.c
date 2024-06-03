/******************************************************************************
 *
 * Module: AFIO
 *
 * File Name: AFIO.c
 *
 * Description: source file for AFIO Driver
 *
 * Author: Mohamed Hamada
 ******************************************************************************/
 
#include "Common_Macros.h"
#include "Std_Types.h" 

#include"AFIO.h"
#include "AFIO_Regs.h"
#include "AFIO_config.h"


/*	 function prototypes		*/


void setEXTIConfiguation(uint8 line ,uint8 portMap)
{
	switch (line)
	{
		case EXT0 :
		case EXT1 :
		case EXT2 :
		case EXT3 :		AFIO_EXTICR1 &=~((0b1111)<<((line%4)*4));
						AFIO_EXTICR1 |=((portMap)<<((line%4)*4));
						break;
		
		case EXT4 :
		case EXT5 :
		case EXT6 :
		case EXT7 :		AFIO_EXTICR2 &=~((0b1111)<<((line%4)*4));
						AFIO_EXTICR2 |=((portMap)<<((line%4)*4));
						break;
		case EXT8 :
		case EXT9 : 
		case EXT10:
		case EXT11:		AFIO_EXTICR3 &=~((0b1111)<<((line%4)*4));
						AFIO_EXTICR3 |=((portMap)<<((line%4)*4));
						break;
		case EXT12:
		case EXT13:
		case EXT14:
		case EXT15:		AFIO_EXTICR4 &=~((0b1111)<<((line%4)*4));
						AFIO_EXTICR4 |=((portMap)<<((line%4)*4));
						break;
		
		
		
	}
	
	
	
}