/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : MEXTI                              */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 12, 2023                    */
/* Last Edit   : N/A 			                    */
/* ************************************************ */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MEXTI_private.h"
#include "MEXTI_interface.h"


/*Global Array of Pointers to function to take The CallBack Functions*/
static void (*MEXTI_pvoidUserFunction[3])(void)={NULL_POINTER, NULL_POINTER, NULL_POINTER};

STD_error_t MEXTI_stderrInit(u8 ARG_u8InterruptNo,u8 ARG_u8SenseMode)
{	
	STD_error_t L_stderrError =E_OK;
	switch( ARG_u8InterruptNo )
	{
	case MEXTI_INT0: MCUCR &=~(3<<ISC00); MCUCR |=(ARG_u8SenseMode<<ISC00);     break; 
	case MEXTI_INT1: MCUCR &=~(3<<ISC10); MCUCR |=(ARG_u8SenseMode<<ISC10);     break; 
	case MEXTI_INT2:  
		switch(ARG_u8SenseMode){
		case MEXTI_MODE_FALLING:CLEAR_BIT(MCUCSR,ISC2); break;
		case MEXTI_MODE_RISING: SET_BIT(MCUCSR,ISC2); break;
		default: L_stderrError=E_NOK; break;
		}
		break; 
	default: L_stderrError=E_NOK; break; 
	}
	return L_stderrError;
}

STD_error_t MEXTI_stderrCallBack(void (*ARG_pvoidUserFunction)(void), u8 ARG_u8InterruptNo )
{
	STD_error_t L_stderrError =E_OK;
	if(NULL_POINTER == ARG_pvoidUserFunction  ) 
	{
		L_stderrError = E_NULL_POINTER;
	}
	else if(ARG_u8InterruptNo >= MEXTI_INT0  &&  ARG_u8InterruptNo <= MEXTI_INT2 ){
		MEXTI_pvoidUserFunction[ARG_u8InterruptNo]=ARG_pvoidUserFunction;
	}
	else{
		L_stderrError=E_NOK;
	}
	return L_stderrError;
}

/*
 * Enable INT Function
 */
STD_error_t MEXTI_stderrEnable(u8 ARG_u8InterruptNo)
{
	STD_error_t L_stderrError =E_OK;
	switch(ARG_u8InterruptNo){
		case MEXTI_INT0:	SET_BIT(GICR, INT0); break;
		case MEXTI_INT1:    SET_BIT(GICR, INT1); break;
		case MEXTI_INT2:    SET_BIT(GICR, INT2); break;
		default: L_stderrError=E_NOK; break;
	}
	return L_stderrError;
}

/*
 * Disable INT Function
 */
STD_error_t MEXTI_stderrDisable(u8 ARG_u8InterruptNo)
{
	STD_error_t L_stderrError =E_OK;
	switch(ARG_u8InterruptNo){
		case MEXTI_INT0:	CLEAR_BIT(GICR, INT0); break;
		case MEXTI_INT1:    CLEAR_BIT(GICR, INT1); break;
		case MEXTI_INT2:    CLEAR_BIT(GICR, INT2); break;
		default: L_stderrError=E_NOK; break;
	}
	return L_stderrError;
}

/* ISR INT0 INT 1 INT2 */

void __vector_1(void) __attribute__((signal)); /* This line is not prototype */
void __vector_1(void)
{
	MEXTI_pvoidUserFunction[MEXTI_INT0]();
}

void __vector_2(void) __attribute__((signal)); /* This line is not prototype */
void __vector_2(void)
{
	MEXTI_pvoidUserFunction[MEXTI_INT1]();
}

void __vector_3(void) __attribute__((signal)); /* This line is not prototype */
void __vector_3(void)
{
	MEXTI_pvoidUserFunction[MEXTI_INT2]();
}
