/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: DELL
 */

#define F_CPU 8000000UL
#include  <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MWDT_interface.h"


int main (void){

	MDIO_stderrSetPinDirection(MDIO_PORTB,1,MDIO_OUTPUT);
		MDIO_stderrSetPinValue(MDIO_PORTB,1,MDIO_HIGH);
		_delay_ms(500);
		MDIO_stderrSetPinValue(MDIO_PORTB,1,MDIO_LOW);
		MWDT_stderrInit(MWDT_5V_2_1_S);
		MWDT_voidEnable();
		_delay_ms(500);
		MWDT_voidDisable();

	while(1);
	return 0;
}
