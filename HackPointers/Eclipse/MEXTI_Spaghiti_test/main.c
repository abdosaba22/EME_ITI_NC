/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: DELL
 */

#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"


#define  MCUCR 			*((volatile u8 *)0x55)
#define ISC00  			0
#define ISC01			1
#define ISC10  			2
#define ISC11			3


#define  MCUCSR 		*((volatile u8 *)0x54)
#define ISC20			6


#define  GICR 			*((volatile u8 *)0x5B)
#define INT2  			5
#define INT0			6
#define INT1  			7


#define GIFR 			*((volatile u8 *)0x5A)
#define INTF2  			5
#define INTF0			6
#define INTF1  			7


#define SREG 			*((volatile u8 *)0x5F)
#define I  				7


void EXT_INT_INIT(void){


	SET_BIT(MCUCR,ISC00);       // MAKE INT0 with logical change
	CLEAR_BIT(MCUCR,ISC01);

	SET_BIT(MCUCR,ISC10);       // MAKE INT1 with logical change
	CLEAR_BIT(MCUCR,ISC11);

	SET_BIT(GICR,INT0);         // ENABLE INT0
	SET_BIT(GICR,INT1);         // ENABLE INT0

	SET_BIT(SREG,I);            // ENABLE THE GLOBAL INT

}

int main(void){
	// Initialization  (Run Once)
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_OUTPUT);


	MDIO_stderrSetPinDirection(MDIO_PORTD,MDIO_PIN2,MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTD,MDIO_PIN3,MDIO_INPUT_PULLUP);

	EXT_INT_INIT();
	while(1){
		// Application (Run )



	}
	return 0;
}

void __vector_1(void) __attribute__((signal)); /* This line is not prototype */
void __vector_1(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,MDIO_PIN0);
}

void __vector_2(void) __attribute__((signal)); /* This line is not prototype */
void __vector_2(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,MDIO_PIN1);
}
