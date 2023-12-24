/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: DELL
 */


#include "LBIT_math.h"
#include "LSTD_types.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "MDIO_interface.h"
#include "MSPI_Interface.h"

#define MSPI_PORT				                         MDIO_PORTB
#define MSPI_SS1											3
#define MSPI_SS2											4
#define MSPI_MOSI											5
#define MSPI_MISO											6
#define MSPI_SCK											7


int main(void)
{
	u8 L_u8Data = 0;
	u8 L_u8Button1=1,L_u8Button2=1,L_u8Button3=1,L_u8SS1=1,L_u8SS2=1;

	MDIO_stderrSetPinDirection(MDIO_PORTA, 0 , MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTA, 1 , MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTA, 2 , MDIO_INPUT_PULLUP);

	MDIO_stderrSetPinDirection(MDIO_PORTA, 3 , MDIO_INPUT_PULLUP);
	MDIO_stderrSetPinDirection(MDIO_PORTA, 4 , MDIO_INPUT_PULLUP);


	MDIO_stderrSetPinDirection(MSPI_PORT, MSPI_SS1  , MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MSPI_PORT, MSPI_SS2 , MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MSPI_PORT, MSPI_MOSI, MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MSPI_PORT, MSPI_SCK , MDIO_OUTPUT);

	MDIO_stderrSetPinDirection(MDIO_PORTA, 7, MDIO_OUTPUT);

	MSPI_stderrInit(MSPI_MODE_MASTER, MSPI_POLPHA_NONINVERTING_LEADING, MSPI_RATE_FOSC_4 , MSPI_DATA_MSB);
	MSPI_voidEnableSPI();
	MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_HIGH);
	MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_HIGH);

	while(1)
	{
		//MSPI_charTranceive(0);

		MDIO_stderrGetPinValue(&L_u8Button1, MDIO_PORTA, 0);
		MDIO_stderrGetPinValue(&L_u8Button2, MDIO_PORTA, 1);
		MDIO_stderrGetPinValue(&L_u8Button3, MDIO_PORTA, 2);

		if(0==L_u8Button1)
		{
			MDIO_stderrGetPinValue(&L_u8SS1, MDIO_PORTA, 3);
			MDIO_stderrGetPinValue(&L_u8SS2, MDIO_PORTA, 4);
//			if(L_u8SS1==0 && L_u8SS1==0 ){
//				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_LOW);
//				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_LOW);
//			}
			 if(L_u8SS1==0){
				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_LOW);
			}
			else
			{
				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_LOW);
			}
			 L_u8Data=MSPI_charTranceive('1');

		}
		else if(0==L_u8Button2)
		{
			MDIO_stderrGetPinValue(&L_u8SS1, MDIO_PORTA, 3);
			MDIO_stderrGetPinValue(&L_u8SS2, MDIO_PORTA, 4);
//			if(L_u8SS1==0 && L_u8SS1==0 ){
//				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_LOW);
//				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_LOW);
//			}
			if(L_u8SS1==0){
				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_LOW);
			}
			else
			{
				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_LOW);
			}
			L_u8Data=MSPI_charTranceive('2');
		}
		else if(0==L_u8Button3)
		{
			MDIO_stderrGetPinValue(&L_u8SS1, MDIO_PORTA, 3);
			MDIO_stderrGetPinValue(&L_u8SS2, MDIO_PORTA, 4);
//			if(L_u8SS1==0 && L_u8SS1==0 ){
//				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_LOW);
//				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_LOW);
//			}
			 if(L_u8SS1==0){
				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_LOW);
			}
			else
			{
				MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_LOW);
			}
			 L_u8Data=MSPI_charTranceive('3');
		}
		if(L_u8Data=='5' ){MDIO_stderrTogglePinValue(MDIO_PORTA,7);}

		MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS1, MDIO_HIGH);
		MDIO_stderrSetPinValue(MDIO_PORTB,MSPI_SS2, MDIO_HIGH);
		_delay_ms(300);
	}
	return 0;
}

