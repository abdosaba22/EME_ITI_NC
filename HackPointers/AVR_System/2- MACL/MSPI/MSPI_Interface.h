/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : SPI				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 26, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

#ifndef _MSPI_INTERFACE_H_
#define _MSPI_INTERFACE_H_

#define MSPI_PORT				                         MDIO_PORTB
#define MSPI_SS												4
#define MSPI_MOSI											5
#define MSPI_MISO											6
#define MSPI_SCK											7
					
#define MSPI_DATA_MSB										(0<<5)
#define MSPI_DATA_LSB										(1<<5)
					
#define MSPI_MODE_MASTER                					(1<<4) 
#define MSPI_MODE_SLAVE										(0)

#define MSPI_POLPHA_NONINVERTING_LEADING					(0<<2)
#define MSPI_POLPHA_NONINVERTING_TAILLING					(1<<2)
#define MSPI_POLPHA_INVERTING_LEADING						(2<<2)
#define MSPI_POLPHA_INVERTING_TAILLING						(3<<2)

#define MSPI_RATE_FOSC_4   		    		00 
#define MSPI_RATE_FOSC_16  		    		01 
#define MSPI_RATE_FOSC_64  		    		10 
#define MSPI_RATE_FOSC_128 		    		11 
#define MSPI_RATE_FOSC_2   		    		100
#define MSPI_RATE_FOSC_8   		    		101
#define MSPI_RATE_FOSC_32  		    		110
//#define MSPI_RATE_fosc_64					111


STD_error_t MSPI_stderrInit( u8 ARG_u8Mode, u8 ARG_u8ClockPolpha, u8 ARG_u8Prescaler, u8 ARG_u8DataOrder );

void MSPI_voidEnableSPI();
void MSPI_voidDisableSPI();

void MSPI_voidEnableInterrupt();
void MSPI_voidDisableInterrupt();
STD_error_t MSPI_stderrSetCallback(void (*ARG_pvoidfUserFunction)(void));

void MSPI_voidSPIFFlagPolling();

char  MSPI_charTranceive(char ARG_u8CharData);


#endif