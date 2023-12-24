/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : SPI				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 26, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MSPI_private.h"
#include "MSPI_interface.h"

static void(* pvoidfUserFuncCallback)(void) ;
STD_error_t MSPI_stderrInit( u8 ARG_u8Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8Prescaler, u8 ARG_u8DataOrder )
{
	STD_error_t L_stderrState=E_OK;
	if( ( (MSPI_MODE_MASTER == ARG_u8Mode)||(MSPI_MODE_SLAVE == ARG_u8Mode) )&& ((MSPI_POLPHA_NONINVERTING_LEADING==ARG_u8ClockPolPha)||(MSPI_POLPHA_NONINVERTING_TAILLING==ARG_u8ClockPolPha)||(MSPI_POLPHA_NONINVERTING_TAILLING==ARG_u8ClockPolPha)||(MSPI_POLPHA_INVERTING_TAILLING==ARG_u8ClockPolPha)) && (ARG_u8Prescaler<=MSPI_RATE_FOSC_32) && ( (MSPI_DATA_MSB==ARG_u8DataOrder)||(MSPI_DATA_LSB==ARG_u8DataOrder)) )
	{
		SPCR = (SPCR & 0xC0) | ARG_u8Mode |  ARG_u8ClockPolPha | (ARG_u8Prescaler&0b11) | ARG_u8DataOrder ;
		SPSR = (SPSR & 0xFE) | (ARG_u8Prescaler>>2) ;
		
	}
	else 
	{
		L_stderrState=E_NOK;
		
	}
	return  L_stderrState;
}

void MSPI_voidEnableSPI(void)
{
	SET_BIT(SPCR,SPE);
}
void MSPI_voidDisableSPI(void)
{
	CLEAR_BIT(SPCR,SPE);
}

void MSPI_voidEnableInterrupt(void)
{
	SET_BIT(SPCR,SPIE);
}
void MSPI_voidDisableInterrupt(void)
{
	CLEAR_BIT(SPCR,SPIE);
}

STD_error_t MSPI_stderrSetCallback(void (*ARG_pvoidfUserFunction)(void))
{
	STD_error_t L_stderrState=E_OK;
	if(NULL_POINTER != ARG_pvoidfUserFunction)
	{
		pvoidfUserFuncCallback= ARG_pvoidfUserFunction;
	}
	else 
	{
		L_stderrState=E_NOK;
	}
	return L_stderrState;
}

void MSPI_voidSPIFFlagPolling(void)
{
	while(!GET_BIT(SPSR,SPIF));
}

char  MSPI_charTranceive(char ARG_u8CharData)
{
	SPDR= ARG_u8CharData;
	MSPI_voidSPIFFlagPolling();
	ARG_u8CharData=SPDR; 
	return ARG_u8CharData;
}
