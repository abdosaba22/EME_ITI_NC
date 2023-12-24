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
	char L_chararrDisplay[20]= "Abdalrahman ^_^";

	HLCD_voidInit();

	HLCD_voidSendString(L_chararrDisplay);
	HLCD_voidSetCur(1,0);
	HLCD_voidSendString("ITI NC1");
	while(1){
		// Application (Run )

		HLCD_voidSendCmd(HLCD_SHIFT_LEFT);
		_delay_ms(500);

	}
	return 0;
}


