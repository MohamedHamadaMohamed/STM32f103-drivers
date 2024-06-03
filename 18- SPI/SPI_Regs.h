/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI_Regs.h
 *
 * Description:  header file for STP driver
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef SPI_REGS_H_
 #define SPI_REGS_H_
 
 /*0x4000 3800 - 0x4000 3BFF SPI2
 
   0x40013000 - 0x4001 33FF SPI1
 */
 
 /********************** SPI 1*****************************/
 
 #define SPI1_CR1		     						(*((volatile uint32 *)0x40013000))
 #define SPI1_CR2		     						(*((volatile uint32 *)0x40013004))
 #define SPI1_SR		     						(*((volatile uint32 *)0x40013008))

 #define SPI1_DR		     						(*((volatile uint32 *)0x4001300C))
 #define SPI1_CRCPR		     						(*((volatile uint32 *)0x40013010))
 #define SPI1_RXCRCR		     					(*((volatile uint32 *)0x40013014))

 #define SPI1_TXCRCR		     					(*((volatile uint32 *)0x40013018))
 #define SPI1_I2SCFGR		     					(*((volatile uint32 *)0x4001301C))
 #define SPI1_I2SPR		     						(*((volatile uint32 *)0x40013020))

 /**********************   SPI 2   *****************************/
 
 #define SPI2_CR1		     						(*((volatile uint32 *)0x40003800))
 #define SPI2_CR2		     						(*((volatile uint32 *)0x40003804))
 #define SPI2_SR		     						(*((volatile uint32 *)0x40003808))
 #define SPI2_DR		     						(*((volatile uint32 *)0x4000380C))
 #define SPI2_CRCPR		     						(*((volatile uint32 *)0x40003810))
 #define SPI2_RXCRCR		     					(*((volatile uint32 *)0x40003814))			
 #define SPI2_TXCRCR		     					(*((volatile uint32 *)0x40003818))
 #define SPI2_I2SCFGR		     					(*((volatile uint32 *)0x4000381C))
 #define SPI2_I2SPR		     						(*((volatile uint32 *)0x40003820))
																			

 
 
 #endif