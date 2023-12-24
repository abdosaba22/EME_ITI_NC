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


#define HKPD_PORT  MDIO_PORTC

char HKPD_charKeypad[4][4]={
		{'1','2','3','A'}, 	/*  ROW0  */
		{'4','5','6','B'},	/*  ROW1  */
		{'7','8','9','C'},	/*  ROW2  */
		{'*','0','#','D'}	/*  ROW3  */
};



char HKPD_charGetKey(void);


int main(void){
	// Initialization  (Run Once)
	char L_charptrPassword[5]={'1','2','3','4'};
	char L_charptrEnteredPassword[5]={0};
	u8 L_u8i=0;
	u8 L_u8FlagPass=0,L_u8kpdcounter=0;
	HLCD_voidInit();
	HLCD_voidSetCur(0,1);
	HLCD_voidSendString("HELLO NC_G1 ^_^");
	_delay_ms(2000);
	HLCD_voidClear();

	while(1){
		// Application (Run )
		L_u8kpdcounter=0;

		while(L_u8kpdcounter<4)
		{
			L_u8FlagPass=0;
			HLCD_voidSetCur(0,1);
			HLCD_voidSendString("Enter_Password:");
			HLCD_voidSetCur(1,2);
			for (L_u8i=0;L_u8i<4;L_u8i++)
			{
				L_charptrEnteredPassword[L_u8i]= HKPD_charGetKey();
				HLCD_voidSendChar('*');
				_delay_ms(300);
			}

			for( L_u8i=0;L_u8i<4;L_u8i++){
				if(L_charptrEnteredPassword[L_u8i]!=L_charptrPassword[L_u8i]){ L_u8FlagPass=1;}
			}
			if(0==L_u8FlagPass ){
				HLCD_voidClear();
				HLCD_voidSetCur(0,2);
				HLCD_voidSendString("Locker Opened");
				_delay_ms(3000);
				HLCD_voidClear();
			}
			else if(1==L_u8FlagPass ) {
				HLCD_voidClear();
				HLCD_voidSetCur(0,2);
				HLCD_voidSendString("Wrong Password");
				_delay_ms(1500);
				HLCD_voidClear();
			}
			L_u8kpdcounter++;
		}
		if(4==L_u8kpdcounter){
			HLCD_voidClear();
			HLCD_voidSetCur(0,0);
			HLCD_voidSendString("Maximum attempts reached");
			HLCD_voidSetCur(1,3);
			HLCD_voidSendString("Try after 5-S");
			_delay_ms(5000);
			HLCD_voidClear();
		}
			//HLCD_voidSendChar(HKPD_charGetKey());
			//_delay_ms(1000);

	}
	return 0;
}



char HKPD_charGetKey(void){
	u8 L_u8Row,L_u8Col;
	//	COLs   OP from PC4-PC7  , ROWs IP from PC0-PC3
	MDIO_stderrSetPortDirection(HKPD_PORT,0xF0);
	//	COLs   OP value: 0000   , ROWs IP PULLUP 1111
	MDIO_stderrSetPortValue(HKPD_PORT,0x0F);

	do{
		MDIO_stderrGetPortValue(&L_u8Row,HKPD_PORT);
		L_u8Row = (~L_u8Row) & 0x0F; // row value inverted 1 be 0  then read only 4-LS bits
	}while(0==L_u8Row); // polling

	MDIO_stderrSetPortDirection(HKPD_PORT,0x0F);
	MDIO_stderrSetPortValue(HKPD_PORT,0xF0);

	MDIO_stderrGetPortValue(&L_u8Col,HKPD_PORT );

	L_u8Col = ((~L_u8Col) & 0xF0) >>4; // Cols value inverted 1 be 0  then read only 4-MS bits and shift right by 4 to start from b0


	switch(L_u8Row){
	case 1: L_u8Row=0;break;
	case 2: L_u8Row=1;break;
	case 4: L_u8Row=2;break;
	case 8:	L_u8Row=3;break;
	}
	switch(L_u8Col){
	case 1: L_u8Col=0;break;
	case 2: L_u8Col=1;break;
	case 4: L_u8Col=2;break;
	case 8:	L_u8Col=3;break;
	}


	return HKPD_charKeypad[L_u8Row][L_u8Col];
}

