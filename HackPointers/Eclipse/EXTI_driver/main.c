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
#include "MEXTI_interface.h"
#include "MGIE_interface.h"

void CallBackFunc(void){
	MDIO_stderrTogglePinValue(MDIO_PORTA,MDIO_PIN0);
}


int main(void){
	// Initialization  (Run Once)

	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	//MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_OUTPUT);


	MDIO_stderrSetPinDirection(MDIO_PORTD,MDIO_PIN2,MDIO_INPUT_PULLUP);

	MEXTI_stderrInit(MEXTI_INT0,MEXTI_MODE_IOC);

	MEXTI_stderrEnable(MEXTI_INT0);
	MGIE_voidEnable();

	MEXTI_stderrCallBack(CallBackFunc,MEXTI_INT0);
	while(1){
		// Application (Run )



	}
	return 0;
}
