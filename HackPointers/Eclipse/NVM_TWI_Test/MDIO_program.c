/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : DIO                                */
/* Layer       : MCAL                               */
/* Version     : 1.2                                */
/* Date        : August 3, 2023                     */
/* Last Edit   : August 4, 2023                     */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MDIO_private.h"
#include "MDIO_interface.h"

STD_error_t MDIO_stderrSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction)
{
	STD_error_t L_stderrError = E_OK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: GPIOA -> DDR = ARG_u8Direction; break;
		case MDIO_PORTB: GPIOB -> DDR = ARG_u8Direction; break;
		case MDIO_PORTC: GPIOC -> DDR = ARG_u8Direction; break;
		case MDIO_PORTD: GPIOD -> DDR = ARG_u8Direction; break;
		default: L_stderrError = E_NOK; break; /* Report an Error */
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value)
{
	STD_error_t L_stderrError = E_OK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: GPIOA -> PORT = ARG_u8Value; break;
		case MDIO_PORTB: GPIOB -> PORT = ARG_u8Value; break;
		case MDIO_PORTC: GPIOC -> PORT = ARG_u8Value; break;
		case MDIO_PORTD: GPIOD -> PORT = ARG_u8Value; break;
		default: L_stderrError = E_NOK; break; /* Report an Error */
	}
	return L_stderrError;
}

STD_error_t	MDIO_stderrGetPortValue(u8* ARG_u8pValue, u8 ARG_u8Port)
{
	STD_error_t L_stderrError = E_OK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: *ARG_u8pValue = GPIOA -> PIN; break;
        case MDIO_PORTB: *ARG_u8pValue = GPIOB -> PIN; break;
        case MDIO_PORTC: *ARG_u8pValue = GPIOC -> PIN; break;
        case MDIO_PORTD: *ARG_u8pValue = GPIOD -> PIN; break;
        default: L_stderrError = E_NOK; break; /* Report an Error */
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction)
{
	STD_error_t L_stderrError = E_OK;
	if((ARG_u8Pin>=MDIO_PIN0) && (ARG_u8Pin<=MDIO_PIN7))
	{
		if(MDIO_OUTPUT == ARG_u8Direction)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA: SET_BIT(GPIOA -> DDR, ARG_u8Pin); break;
				case MDIO_PORTB: SET_BIT(GPIOB -> DDR, ARG_u8Pin); break;
				case MDIO_PORTC: SET_BIT(GPIOC -> DDR, ARG_u8Pin); break;
				case MDIO_PORTD: SET_BIT(GPIOD -> DDR, ARG_u8Pin); break;
				default: L_stderrError = E_NOK; break; /* Report an Error */
			}
		}
		else if(MDIO_INPUT == ARG_u8Direction)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA: CLEAR_BIT(GPIOA -> DDR, ARG_u8Pin); break;
				case MDIO_PORTB: CLEAR_BIT(GPIOB -> DDR, ARG_u8Pin); break;
				case MDIO_PORTC: CLEAR_BIT(GPIOC -> DDR, ARG_u8Pin); break;
				case MDIO_PORTD: CLEAR_BIT(GPIOD -> DDR, ARG_u8Pin); break;
				default: L_stderrError = E_NOK; break; /* Report an Error */
			}
		}
		else if(MDIO_INPUT_PULLUP == ARG_u8Direction)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA: CLEAR_BIT(GPIOA -> DDR, ARG_u8Pin); SET_BIT(GPIOA -> PORT, ARG_u8Pin); break;
				case MDIO_PORTB: CLEAR_BIT(GPIOB -> DDR, ARG_u8Pin); SET_BIT(GPIOB -> PORT, ARG_u8Pin); break;
				case MDIO_PORTC: CLEAR_BIT(GPIOC -> DDR, ARG_u8Pin); SET_BIT(GPIOC -> PORT, ARG_u8Pin); break;
				case MDIO_PORTD: CLEAR_BIT(GPIOD -> DDR, ARG_u8Pin); SET_BIT(GPIOD -> PORT, ARG_u8Pin); break;
				default: L_stderrError = E_NOK; break; /* Report an Error */
			}
		}
		else
		{
			/* Report an Error */
			L_stderrError = E_NOK;
		}
	}
	else
	{
		/* Report an Error */
		L_stderrError = E_NOK;
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Value)
{
	STD_error_t L_stderrError = E_OK;
	if((ARG_u8Pin>=MDIO_PIN0) && (ARG_u8Pin<=MDIO_PIN7))
	{
		if(MDIO_HIGH == ARG_u8Value)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA: SET_BIT(GPIOA -> PORT, ARG_u8Pin); break;
				case MDIO_PORTB: SET_BIT(GPIOB -> PORT, ARG_u8Pin); break;
				case MDIO_PORTC: SET_BIT(GPIOC -> PORT, ARG_u8Pin); break;
				case MDIO_PORTD: SET_BIT(GPIOD -> PORT, ARG_u8Pin); break;
				default: L_stderrError = E_NOK; break; /* Report an Error */
			}
		}
		else if(MDIO_LOW == ARG_u8Value)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA: CLEAR_BIT(GPIOA -> PORT, ARG_u8Pin); break;
				case MDIO_PORTB: CLEAR_BIT(GPIOB -> PORT, ARG_u8Pin); break;
				case MDIO_PORTC: CLEAR_BIT(GPIOC -> PORT, ARG_u8Pin); break;
				case MDIO_PORTD: CLEAR_BIT(GPIOD -> PORT, ARG_u8Pin); break;
				default: L_stderrError = E_NOK; break; /* Report an Error */
			}
		}
		else
		{
			/* Report an Error */
			L_stderrError = E_NOK;
		}
	}
	else
	{
		/* Report an Error */
		L_stderrError = E_NOK;
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrGetPinValue(u8* ARG_u8pValue, u8 ARG_u8Port, u8 ARG_u8Pin)
{
	STD_error_t L_stderrError = E_OK;
	if(NULL_POINTER==ARG_u8pValue)
	{
		L_stderrError = E_NULL_POINTER;
	}
	else if((ARG_u8Pin>=MDIO_PIN0) && (ARG_u8Pin<=MDIO_PIN7))
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: *ARG_u8pValue = GET_BIT(GPIOA -> PIN, ARG_u8Pin); break;
			case MDIO_PORTB: *ARG_u8pValue = GET_BIT(GPIOB -> PIN, ARG_u8Pin); break;
			case MDIO_PORTC: *ARG_u8pValue = GET_BIT(GPIOC -> PIN, ARG_u8Pin); break;
			case MDIO_PORTD: *ARG_u8pValue = GET_BIT(GPIOD -> PIN, ARG_u8Pin); break;
			default: L_stderrError = E_NOK; break; /* Report an Error */
		}
	}
	else
	{
		/* Report an Error */
		L_stderrError = E_NOK;
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrTogglePinValue(u8 ARG_u8Port ,u8 ARG_u8Pin)
{
	STD_error_t L_stderrError= E_OK;
	if(ARG_u8Pin>= MDIO_PIN0 && ARG_u8Pin<= MDIO_PIN7)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: TOGGLE_BIT(GPIOA->PORT ,ARG_u8Pin) ; break;
			case MDIO_PORTB: TOGGLE_BIT(GPIOB->PORT ,ARG_u8Pin) ; break;
			case MDIO_PORTC: TOGGLE_BIT(GPIOC->PORT ,ARG_u8Pin) ; break;
			case MDIO_PORTD: TOGGLE_BIT(GPIOD->PORT ,ARG_u8Pin) ; break;
			default: L_stderrError = E_NOK; break; /* report an error*/
		}	
	}
	else{
		/* Report an Error */
		L_stderrError=E_NULL_POINTER;
	}
	return L_stderrError;
}
