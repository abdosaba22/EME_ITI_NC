/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: DELL
 */





#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"

#include "MDIO_interface.h"


int main(void){

    // Initialization  (Run Once)
	s8 i=0;
	u8 L_u8P0Value=1; //

	for(i=0;i<8;i++){
		MDIO_stderrSetPinDirection(MDIO_PORTA,i,MDIO_OUTPUT);
	}
	MDIO_stderrSetPinDirection(MDIO_PORTB,MDIO_PIN0,MDIO_INPUT_PULLUP);

	while(1){
		// Application (Run )
		MDIO_stderrGetPinValue(&L_u8P0Value,MDIO_PORTB,MDIO_PIN0);

		if(0==L_u8P0Value){

			for(i=0;i<8;i++){
				MDIO_stderrSetPinValue(MDIO_PORTA,i,MDIO_HIGH);
				_delay_ms(800);
				MDIO_stderrSetPinValue(MDIO_PORTA,i,MDIO_LOW);
			}
		}
		else if(1==L_u8P0Value){

			for(i=7;i>=0;i--){
				MDIO_stderrSetPinValue(MDIO_PORTA,i,MDIO_HIGH);
				_delay_ms(800);
				MDIO_stderrSetPinValue(MDIO_PORTA,i,MDIO_LOW);
			}
		}

	}
	return 0;
}


