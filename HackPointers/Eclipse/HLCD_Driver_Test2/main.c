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
	s8 L_s8Iterator=0;
	char L_charptrDisplay[20]= "Abdalrahman";
	// Arabic char ح
//	char L_charptrNewChar1[7]={
//			0b01111,
//			0b10011,
//			0b00100,
//			0b01000,
//			0b10000,
//			0b01001,
//			0b00111
//	};
	// Arabic char سـ
		char L_charptrNewChar2[8]={
				0b00000,
				0b00001,
				0b00101,
				0b10101,
				0b11111,
				0b00000,
				0b00000,
				0b00000

		};
		// سـ    ـبـ
		char L_charptrNewChar3[8]={
				0b00000,
				0b00000,
				0b01000,
				0b01000,
				0b11111,
				0b00000,
				0b01000,
				0b00000
		};
		// سـ    ـبـ  ـع
		char L_charptrNewChar4[8]={
				0b00000,
				0b01110,
				0b01010,
				0b00100,
				0b01111,
				0b10000,
				0b10000,
				0b01111
		};


	HLCD_voidInit();

	HLCD_voidSendString(L_charptrDisplay);

	HLCD_voidSendCmd(HLCD_CGRAM_ADD); /* Set CGRAM Address 0x40*/

	for(L_s8Iterator=0;L_s8Iterator<8;L_s8Iterator++){
		HLCD_voidSendChar(L_charptrNewChar4[L_s8Iterator]);
	}
	//_delay_us(1);
	//HLCD_voidSendCmd(HLCD_CGRAM_ADD); /* Set CGRAM Address 0x40*/
	for(L_s8Iterator=0;L_s8Iterator<8;L_s8Iterator++){
		HLCD_voidSendChar(L_charptrNewChar3[L_s8Iterator]);
	}
	//_delay_us(1);
	//HLCD_voidSendCmd(HLCD_CGRAM_ADD); /* Set CGRAM Address 0x40*/
	for(L_s8Iterator=0;L_s8Iterator<8;L_s8Iterator++){
		HLCD_voidSendChar(L_charptrNewChar2[L_s8Iterator]);
	}
	//_delay_us(1);

	HLCD_voidSetCur(0,12);
	HLCD_voidSendChar(0);
	HLCD_voidSendChar(1);
	HLCD_voidSendChar(2);
	//HLCD_voidSendChar(3);
	_delay_ms(10);
	HLCD_voidSetCur(1,0);
	HLCD_voidSendString(" ITI NC1 ^_*");

	L_s8Iterator=15;
	while(1){
		// Application (Run )
		if(L_s8Iterator >=0){
			HLCD_voidSendCmd(HLCD_SHIFT_LEFT);
		}
		else{
			HLCD_voidSendCmd(HLCD_SHIFT_RIGHT);
		}
		_delay_ms(300);
		if(L_s8Iterator==-15) L_s8Iterator=15;
		L_s8Iterator--;

	}
	return 0;
}


