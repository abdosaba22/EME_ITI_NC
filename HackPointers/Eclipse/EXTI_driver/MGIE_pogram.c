/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Global Interrupt                   */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 13, 2023                    */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MGIE_private.h"

void MGIE_voidEnable(void){
	
	SET_BIT(SREG,I_BIT);
	
}
void MGIE_voidDisable(void){
	CLEAR_BIT(SREG,I_BIT);
}
