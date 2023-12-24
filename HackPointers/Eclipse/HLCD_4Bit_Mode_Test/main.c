/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: DELL
 */
#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"

#include "MDIO_interface.h"

#include "HLCD_interface.h"



int main(void){
	// Initialization  (Run Once)

	HLCD_voidInit();

_delay_ms(5000);
	HLCD_voidSetCur(0,0);

	HLCD_voidSendString("Ahmed Walid");
	//unsigned char i=0;
//MDIO_stderrSetPortValue(MDIO_PORTA,0x00);

	while(1){
		// Application (Run )
		//HLCD_voidSendChar(0x0F);
		//HLCD_voidSetCur(0,i);
		//i++;
	}
	return 0;
}

