/*
 * main.c
 *
 *  Created on: Aug 2, 2023
 *      Author: DELL
 */

#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"

#include "MDIO_interface.h"


int main(void){

    // Initialization  (Run Once)
	MDIO_voidSetPortDirection( MDIO_PORTA,MDIO_OUTPUT_PORT );
	MDIO_voidSetPinDirection(MDIO_PORTB,MDIO_PIN2,MDIO_INPUT); /* SW1 */
	MDIO_voidEnablePullUP(MDIO_PORTB,MDIO_PIN2); /* SW1 Pull UP */
	MDIO_voidSetPinDirection(MDIO_PORTB,MDIO_PIN4,MDIO_OUTPUT); /* led */

	MDIO_voidSetPinValue(MDIO_PORTB,MDIO_PIN4,MDIO_HIGH);

	while(1){
		// Application (Run )

		/*
		MDIO_voidSetPortValue( MDIO_PORTA,0xFF );
		_delay_ms(1000);
		MDIO_voidSetPortValue( MDIO_PORTA,0x00 );
		_delay_ms(1000);

		 */

		if(0 == MDIO_u8GetPinValue(MDIO_PORTB,MDIO_PIN2)){

			/* button pressed */
			MDIO_voidTogglePinValue(MDIO_PORTB,MDIO_PIN4);  /* Toggle led */
			while(0 == MDIO_u8GetPinValue(MDIO_PORTB,MDIO_PIN2));  /*Stuck while button pressed*/
		}
		else{
			 /*Do nothing*/
		}


	}
	return 0;
}
