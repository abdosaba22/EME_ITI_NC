/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: omare
 */


#include <util/delay.h>

#define F_CPU 8000000UL

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MTWI_interface.h"

#include "HLCD_interface.h"
#include "HNVM_interface.h"

int main(void)
{
	u8  L_u8Data;

	MDIO_stderrSetPinDirection(MDIO_PORTC, 0, MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTC, 1, MDIO_INPUT_PULLUP);

	HNVM_stderrInit();
	HLCD_voidInit();

	HLCD_voidSendString("Welcome");
	_delay_ms(1000);
	HLCD_voidSendCmd(0x01);
	_delay_ms(2);
	u8 c='A';
	while(1)
	{
			HNVM_voidWrite(0x00, c);
			HLCD_voidSendString("Data written: ");
			HLCD_voidSendChar(c++);
			_delay_ms(1000);
			HLCD_voidSendCmd(0x01);
			_delay_ms(500);

			L_u8Data = HNVM_u8Read(0x00);
			HLCD_voidSendString("Read Data: ");
			HLCD_voidSendChar(L_u8Data);
			_delay_ms(1000);
			HLCD_voidSendCmd(0x01);
			_delay_ms(2);
		_delay_ms(250);
		L_u8Data=0;
	}
	return 0;
}
