/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: DELL
 */
#include "LBIT_math.h"
#include "LSTD_types.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "MDIO_interface.h"
#include "HLCD_interface.h"

#define SPCR 		*((volatile u8 *) 0x2D)
#define SPIE		7
#define SPE			6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0


#define SPSR 		*((volatile u8 *) 0x2E)
#define SPIF		7
#define WCOL		6
#define SPI2X		0


#define SPDR 		*((volatile u8 *) 0x2F)


#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7


int main(void)
{
	u8 L_u8Data = 0;
	MDIO_stderrSetPinDirection(MDIO_PORTD, 0 , MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTD, 1 , MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTD, 2 , MDIO_OUTPUT);

	MDIO_stderrSetPinDirection(MDIO_PORTB, MISO, MDIO_OUTPUT);

	CLEAR_BIT(SPCR , DORD);
	CLEAR_BIT(SPCR, MSTR);
	CLEAR_BIT(SPCR, CPOL);
	CLEAR_BIT(SPCR, CPHA);
	SET_BIT(SPCR, SPE); /* Enable */

	HLCD_voidInit();

	HLCD_voidSendString("*_*");
	_delay_ms(500);
	HLCD_voidClear();
	while(1)
	{
		while(!GET_BIT(SPSR, SPIF));
		L_u8Data=SPDR;
		switch(L_u8Data)
		{
		case '1': MDIO_stderrTogglePinValue(MDIO_PORTD,0);  break;
		case '2': MDIO_stderrTogglePinValue(MDIO_PORTD,1);  break;
		case '3': MDIO_stderrTogglePinValue(MDIO_PORTD,2);  break;
		default: break;
		}
		HLCD_voidSetCur(0,0);
		HLCD_voidSendString("Received Data:");
		HLCD_voidSendChar(L_u8Data);

	}
	return 0;
}
