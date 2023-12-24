/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : DIO                                */
/* Layer       : MCAL                               */
/* Version     : 1.1                                */
/* Date        : August 2, 2023                     */
/* Last Edit   : August 3, 2023                     */
/* ************************************************ */

/* library include */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* swc include */
#include "MDIO_private.h"
#include "MDIO_interface.h"

STD_error_t MDIO_stderrSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction)
{
	STD_error_t L_stderrError= E_OK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: GPIOA->DDR = ARG_u8Direction; break;
		case MDIO_PORTB: GPIOB->DDR = ARG_u8Direction; break;
		case MDIO_PORTC: GPIOC->DDR = ARG_u8Direction; break;
		case MDIO_PORTD: GPIOD->DDR = ARG_u8Direction; break;
		default: L_stderrError = E_NOK; break; /* reporrt error*/
		
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value)
{
	STD_error_t L_stderrError= E_OK;	
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT = ARG_u8Value; break;
		case MDIO_PORTB:GPIOB->PORT = ARG_u8Value; break;
		case MDIO_PORTC:GPIOC->PORT = ARG_u8Value; break;
		case MDIO_PORTD:GPIOD->PORT = ARG_u8Value; break;
		default: L_stderrError = E_NOK; break; /* reporrt error*/

	}
	return L_stderrError;
}

STD_error_t MDIO_stderrGetPortValue(u8* ARG_u8PValue, u8 ARG_u8Port)
{
	STD_error_t L_stderrError= E_OK;
	if(NULL_POINTER!=ARG_u8PValue)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: *ARG_u8PValue = GPIOA->PIN; break;
			case MDIO_PORTB: *ARG_u8PValue = GPIOA->PIN; break;
			case MDIO_PORTC: *ARG_u8PValue = GPIOA->PIN; break;
			case MDIO_PORTD: *ARG_u8PValue = GPIOA->PIN; break;
			default: L_stderrError = E_NOK; break; /* reporrt error*/
		}
	}
	else{
		L_stderrError=E_NULL_POINTER;
	}	
	return L_stderrError;
}

STD_error_t MDIO_stderrSetPinDirection(u8 ARG_u8Port,u8 ARG_u8Pin, u8 ARG_u8Direction)
{
	STD_error_t L_stderrError= E_OK;	
	u8 L_u8EnablPullUP=0; /* this flag used to enable PULL UP or Disable */
	
	if(ARG_u8Pin>= MDIO_PIN0 && ARG_u8Pin<= MDIO_PIN7 && ARG_u8Direction>= MDIO_INPUT && ARG_u8Direction<= MDIO_INPUT_PULLUP)
	{
		/* OK No error  */
		if(MDIO_INPUT_PULLUP==ARG_u8Direction)
		{
			/* this for flag of INPUT_PULLUP */
			L_u8EnablPullUP=1;
			ARG_u8Direction=MDIO_INPUT;/* assign it for value INPUT */
		}
		else{ /* do nothing */ }
		
		/* Set direction for PINX using DDRX */
		switch(ARG_u8Port)
		{
			case MDIO_PORTA:
				GPIOA->DDR &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOA->DDR |= (ARG_u8Direction<<ARG_u8Pin); /* assign the Direction */
			break;
			case MDIO_PORTB:
				GPIOB->DDR &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOB->DDR |= (ARG_u8Direction<<ARG_u8Pin); /* assign the Direction */
			break;
			case MDIO_PORTC:
				GPIOD->DDR &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOD->DDR |= (ARG_u8Direction<<ARG_u8Pin); /* assign the Direction */
			break;
			case MDIO_PORTD:
				GPIOD->DDR &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOD->DDR |= (ARG_u8Direction<<ARG_u8Pin); /* assign the Direction */
			break;
			default: L_stderrError = E_NOK; break; /* report an error*/
		}		
		//check flag of PULLUP 
		if(1==L_u8EnablPullUP)
		{
			/* Enable PULL UP */
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:GPIOA->PORT |= (1<<ARG_u8Pin) ; break;
				case MDIO_PORTB:GPIOB->PORT |= (1<<ARG_u8Pin) ; break;
				case MDIO_PORTC:GPIOC->PORT |= (1<<ARG_u8Pin) ; break;
				case MDIO_PORTD:GPIOD->PORT |= (1<<ARG_u8Pin) ; break;
				default: L_stderrError = E_NOK; break; /* reporrt an error*/
				
			}
		}
		else{ /* do nothing */ }

	}
	else{
		L_stderrError = E_NOK;
	}

	return L_stderrError;
}

STD_error_t MDIO_stderrSetPinValue(u8 ARG_u8Port,u8 ARG_u8Pin,u8 ARG_u8Value)
{
	STD_error_t L_stderrError= E_OK;
	if(ARG_u8Pin>= MDIO_PIN0 && ARG_u8Pin<= MDIO_PIN7 && ARG_u8Value<= MDIO_HIGH && ARG_u8Value>= MDIO_LOW)
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA:
				GPIOA->PORT &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOA->PORT |= (ARG_u8Value<<ARG_u8Pin); /* assign the Direction */
			break;
			case MDIO_PORTB:
				GPIOB->PORT &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOB->PORT |= (ARG_u8Value<<ARG_u8Pin); /* assign the Direction */
			break;
			case MDIO_PORTC:
				GPIOD->PORT &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOD->PORT |= (ARG_u8Value<<ARG_u8Pin); /* assign the Direction */
			break;
			case MDIO_PORTD:
				GPIOD->PORT &= ~(1<<ARG_u8Pin); /* Clear bit*/
				GPIOD->PORT |= (ARG_u8Value<<ARG_u8Pin); /* assign the Direction */
			break;
			default: L_stderrError = E_NOK; break; /* report an error*/
			
		}
	}
	else{
		L_stderrError = E_NOK;
	}	
	return L_stderrError;
}

STD_error_t MDIO_stderrGetPinValue(u8* ARG_u8PValue ,u8 ARG_u8Port ,u8 ARG_u8Pin )
{
	STD_error_t L_stderrError= E_OK;
	if(NULL_POINTER!=ARG_u8PValue )
	{	
		if(ARG_u8Pin>= MDIO_PIN0 && ARG_u8Pin<= MDIO_PIN7)
		{	
			switch(ARG_u8Port)
			{
				case MDIO_PORTA: *ARG_u8PValue = ( (GPIOA->PIN)>>ARG_u8Pin ) & 1 ; break;
				case MDIO_PORTB: *ARG_u8PValue = ( (GPIOB->PIN)>>ARG_u8Pin ) & 1 ; break;
				case MDIO_PORTC: *ARG_u8PValue = ( (GPIOC->PIN)>>ARG_u8Pin ) & 1 ; break;
				case MDIO_PORTD: *ARG_u8PValue = ( (GPIOD->PIN)>>ARG_u8Pin ) & 1 ; break;
				default: L_stderrError = E_NOK; break; /* report an error*/
			}
		}
		else{
			L_stderrError = E_NOK;
		}
	}
	else{
		L_stderrError=E_NULL_POINTER;
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
			case MDIO_PORTA:GPIOA->PORT ^= (1<<ARG_u8Pin) ; break;
			case MDIO_PORTB:GPIOB->PORT ^= (1<<ARG_u8Pin) ; break;
			case MDIO_PORTC:GPIOC->PORT ^= (1<<ARG_u8Pin) ; break;
			case MDIO_PORTD:GPIOD->PORT ^= (1<<ARG_u8Pin) ; break;
			default: L_stderrError = E_NOK; break; /* report an error*/
		}	
	}
	else{
		L_stderrError=E_NULL_POINTER;
	}
	return L_stderrError;
}



/* will not be used*/

STD_error_t MDIO_stderrEnablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin)
{
	STD_error_t L_stderrError= E_OK;
	/* Set bit */
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT |= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTB:GPIOB->PORT |= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTC:GPIOC->PORT |= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTD:GPIOD->PORT |= (1<<ARG_u8Pin) ; break;
		default: L_stderrError = E_NOK; break; /* reporrt an error*/
		
	}
	return L_stderrError;
}

STD_error_t MDIO_stderrDisablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin)
{
	STD_error_t L_stderrError= E_OK;
	/* Clear bit */
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT &= ~(1<<ARG_u8Pin) ; break;
		case MDIO_PORTB:GPIOB->PORT &= ~(1<<ARG_u8Pin) ; break;
		case MDIO_PORTC:GPIOC->PORT &= ~(1<<ARG_u8Pin) ; break;
		case MDIO_PORTD:GPIOD->PORT &= ~(1<<ARG_u8Pin) ; break;
		default: L_stderrError = E_NOK; break; /* reporrt an error*/
		
	}
	return L_stderrError;
}
