/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: DELL
 */

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"
#include "MUART_interface.h"

int main(void){

	u8 L_u8DataRX=0;
	MUART_stderrInit((u32)9600,MUART_DATABITS_8, MUART_PARITY_NONE, MUART_STOPBITS_1);
	MUART_voidEnableRX();

	while(1){

		MUART_voidRXFlagPolling();
		L_u8DataRX=MUART_charReceiveChar();

		switch(L_u8DataRX)
		{
		case '0': MDIO_stderrTogglePinValue(MDIO_PORTA,0); break;
		case '1': MDIO_stderrTogglePinValue(MDIO_PORTA,1); break;
		default: break;
		}


	}
	return 0;
}
