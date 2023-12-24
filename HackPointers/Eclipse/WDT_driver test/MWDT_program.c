/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : WDT				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 23, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "MWDT_private.h"
#include "MWDT_interface.h"

STD_error_t MWDT_stderrInit(u8 ARG_u8Prescaler)
{
	STD_error_t L_sterrStatus=E_OK;
	if(ARG_u8Prescaler <=7){
		WDTCR = (WDTCR & 0xF8) | ARG_u8Prescaler;	
	}
	else
	{
			L_sterrStatus=E_NOK;
	}
	return L_sterrStatus;
}
void MWDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDE);
}
void MWDT_voidDisable(void)
{
	WDTCR |=  (0b11<<WDE) ;
	CLEAR_BIT(WDTCR,WDE);
}
void MWDT_voidReset(void)
{
	__asm__ __volatile__ ("wdr");
	/* after it need to reconfig  */
	// Disable .. Init Enable 
}
