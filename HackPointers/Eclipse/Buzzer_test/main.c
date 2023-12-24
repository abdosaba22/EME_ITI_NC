/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: DELL
 */


#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"

#include "MDIO_interface.h"

//#include "HLCD_interface.h"



int main(void){
	// Initialization  (Run Once)

	//HLCD_voidInit();
//_delay_ms(5000);
	//HLCD_voidSetCur(0,0);
	//HLCD_voidSendString("^_^");
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN2,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN3,MDIO_OUTPUT);
	//	_delay_ms(1000);
//	MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN7,MDIO_HIGH);
//	_delay_ms(500);
	MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_HIGH);
	MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);
	MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN2,MDIO_LOW);
	MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN3,MDIO_LOW);
	_delay_ms(200);
	while(1){
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_HIGH);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN2,MDIO_LOW);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN3,MDIO_LOW);

		_delay_ms(300);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_HIGH);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN2,MDIO_LOW);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN3,MDIO_LOW);
		_delay_ms(300);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
		MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);
	    MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN2,MDIO_HIGH);
	    MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN3,MDIO_LOW);
	    _delay_ms(300);
	    MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
	    MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);
	    MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN2,MDIO_LOW);
	    MDIO_stderrSetPinValue(MDIO_PORTA,MDIO_PIN3,MDIO_HIGH);
	   _delay_ms(300);
	}
	  return 0;
}
