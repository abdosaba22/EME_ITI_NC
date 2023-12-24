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
	u8 L_u8Button1=1,L_u8Button2=1,L_u8Button3=1;
	MDIO_stderrSetPinDirection(MDIO_PORTA, 0 , MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTA, 1 , MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTA, 2 , MDIO_INPUT_PULLUP);

	MDIO_stderrSetPinDirection(MDIO_PORTB, SS, MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTB, MOSI, MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTB, SCK , MDIO_OUTPUT);

	MDIO_stderrSetPinDirection(MDIO_PORTB, 7, MDIO_OUTPUT);
	CLEAR_BIT(SPCR , DORD);
	SET_BIT(SPCR, MSTR);
	CLEAR_BIT(SPCR, CPOL);
	CLEAR_BIT(SPCR, CPHA);

	CLEAR_BIT(SPCR, SPR1);
	SET_BIT(SPCR, SPR0);
	SET_BIT(SPCR, SPE); /* Enable */

	while(1)
	{
		MDIO_stderrGetPinValue(&L_u8Button1, MDIO_PORTA, 0);
		MDIO_stderrGetPinValue(&L_u8Button2, MDIO_PORTA, 1);
		MDIO_stderrGetPinValue(&L_u8Button3, MDIO_PORTA, 2);


		if(0==L_u8Button1)
		{
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_LOW);
			SPDR = '1';
			while(!GET_BIT(SPSR, SPIF));
			L_u8Data=SPDR ; // to clear flag
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_HIGH);
			_delay_ms(100);
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_LOW);
			while(!GET_BIT(SPSR, SPIF));
			L_u8Data=SPDR ; // to clear flag
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_HIGH);
			if(L_u8Data=='2') MDIO_stderrTogglePinValue(MDIO_PORTA,7);
			_delay_ms(400);
		}
		else if(0==L_u8Button2)
		{
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_LOW);
			SPDR = '2';
			while(!GET_BIT(SPSR, SPIF));
			L_u8Data=SPDR ; // to clear flag
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_HIGH);
		}
		else if(0==L_u8Button3)
		{
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_LOW);
			SPDR = '3';
			while(!GET_BIT(SPSR, SPIF));
			L_u8Data=SPDR ; // to clear flag
			MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_HIGH);
		}
		MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_LOW);
		while(!GET_BIT(SPSR, SPIF));
		L_u8Data=SPDR ; // to clear flag
		MDIO_stderrSetPinValue(MDIO_PORTB,SS, MDIO_HIGH);
		if(L_u8Data=='1') MDIO_stderrTogglePinValue(MDIO_PORTA,7);
		_delay_ms(400);
	}
	return 0;
}
