/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: DELL
 */

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"


#define UDR           *((volatile u8*)0x2C)

#define UCSRA         *((volatile u8*)0x2B)
#define RXC             7
#define TXC             6
#define UDRE            5
#define FE              4
#define DOR             3
#define PE              2
#define U2X             1
#define MCPM            0

#define UCSRB         *((volatile u8*)0x2A)
#define RXCIE           7
#define TXCIE           6
#define UDRIE           5
#define RXEN            4
#define TXEN            3
#define UCSZ2           2
#define RXB8            1
#define TXB8            0

#define UCSRC         *((volatile u8*)0x40)
#define URSEL          7
#define UMSEL          6
#define UPM1           5
#define UPM0           4
#define USBS           3
#define UCSZ1          2
#define UCSZ0          1
#define UCPOL          0

#define UBRRH         *((volatile u8*)0x40)
#define UBRRL         *((volatile u8*)0x29)


int main(void){

	u8 L_u8DataRX=0;

	/* UART Config */
	CLEAR_BIT(UCSRB,UCSZ2);
	UCSRC = (1<<URSEL) | (3<<1) ;
	UBRRL = 51;
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);

	MDIO_stderrSetPinDirection(MDIO_PORTA,0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,1,MDIO_OUTPUT);


	while(1){

		while(GET_BIT(UCSRA,RXC)==0);
		L_u8DataRX=UDR;

		switch(L_u8DataRX)
		{
		case '0': MDIO_stderrTogglePinValue(MDIO_PORTA,0); break;
		case '1': MDIO_stderrTogglePinValue(MDIO_PORTA,1); break;
		default: break;
		}


	}
	return 0;
}
