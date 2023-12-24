/* ************************************* */
/* Author      : Abd-alrahman Amin       */
/* SWC         : DIO                     */
/* Layer       : MCAL                    */
/* Version     : 1.0                     */
/* Date        : August 2, 2023          */
/* Last Edit   : N/A                     */
/* ************************************* */

/* library include */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* swc include */
#include "MDIO_private.h"
#include "MDIO_interface.h"

void MDIO_voidSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction)
{
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:
			GPIOA->DDR = ARG_u8Direction;
		break;
		case MDIO_PORTB: GPIOB->DDR = ARG_u8Direction;
		break;
		case MDIO_PORTC: GPIOC->DDR = ARG_u8Direction;
		break;
		case MDIO_PORTD: GPIOD->DDR = ARG_u8Direction;
		break;
		default: break; /* report error*/
		
	}
}

void MDIO_voidSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value){
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT = ARG_u8Value; break;
		case MDIO_PORTB:GPIOB->PORT = ARG_u8Value; break;
		case MDIO_PORTC:GPIOC->PORT = ARG_u8Value; break;
		case MDIO_PORTD:GPIOD->PORT = ARG_u8Value; break;
		default: break; /* report error*/
		
	}
}

u8 MDIO_u8GetPortValue(u8 ARG_u8Port){
	u8 L_u8PortValueReturn=0;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: L_u8PortValueReturn = GPIOA->PIN; break;
	    case MDIO_PORTB: L_u8PortValueReturn = GPIOA->PIN; break;
        case MDIO_PORTC: L_u8PortValueReturn = GPIOA->PIN; break;
        case MDIO_PORTD: L_u8PortValueReturn = GPIOA->PIN; break;
		default: break;  /* report error*/
	}
	return L_u8PortValueReturn;
}	

void MDIO_voidSetPinDirection(u8 ARG_u8Port,u8 ARG_u8Pin, u8 ARG_u8Direction)
{
	
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
		default: break; /* report error*/
		
	}
}

void MDIO_voidSetPinValue(u8 ARG_u8Port,u8 ARG_u8Pin,u8 ARG_u8Value)
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
		default: break; /* report error*/
		
	}
}

u8 MDIO_u8GetPinValue(u8 ARG_u8Port,u8 ARG_u8Pin)
{
	u8 L_u8PinValueReturn=0;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: L_u8PinValueReturn = ( (GPIOA->PIN)>>ARG_u8Pin ) & 1 ; break;
	    case MDIO_PORTB: L_u8PinValueReturn = ( (GPIOB->PIN)>>ARG_u8Pin ) & 1 ; break;
        case MDIO_PORTC: L_u8PinValueReturn = ( (GPIOC->PIN)>>ARG_u8Pin ) & 1 ; break;
        case MDIO_PORTD: L_u8PinValueReturn = ( (GPIOD->PIN)>>ARG_u8Pin ) & 1 ; break;
		default: break;  /* report error*/
	}
	return L_u8PinValueReturn;
}

void MDIO_voidTogglePinValue(u8 ARG_u8Port ,u8 ARG_u8Pin)
{
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT ^= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTB:GPIOB->PORT ^= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTC:GPIOC->PORT ^= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTD:GPIOD->PORT ^= (1<<ARG_u8Pin) ; break;
		default: break; /* report error*/
		
	}
}

void MDIO_voidEnablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin)
{
	/* Set bit */
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT |= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTB:GPIOB->PORT |= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTC:GPIOC->PORT |= (1<<ARG_u8Pin) ; break;
		case MDIO_PORTD:GPIOD->PORT |= (1<<ARG_u8Pin) ; break;
		default: break; /* report error*/
		
	}
}
void MDIO_voidDisablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin)
{
	/* Clear bit */
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT &= ~(1<<ARG_u8Pin) ; break;
		case MDIO_PORTB:GPIOB->PORT &= ~(1<<ARG_u8Pin) ; break;
		case MDIO_PORTC:GPIOC->PORT &= ~(1<<ARG_u8Pin) ; break;
		case MDIO_PORTD:GPIOD->PORT &= ~(1<<ARG_u8Pin) ; break;
		default: break; /* report error*/
		
	}
}
