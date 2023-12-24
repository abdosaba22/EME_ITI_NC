/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : N/A			                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

#include <util/delay.h>

/* MCAL Includes */
#include "MDIO_interface.h"

/* SWC includes */
#include "HLCD_private.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"


void HLCD_voidInit(void){
	
	/* init direction */
	HLCD_DATA_PORT_INIT();
	HLCD_CTRL_INIT(HLCD_RS_PIN);
	HLCD_CTRL_INIT(HLCD_RW_PIN);
	HLCD_CTRL_INIT(HLCD_EN_PIN);
	
	HLCD_voidSendCmd(HLCD_FUNCTION_SET);
	_delay_us(50);
	HLCD_voidSendCmd(HLCD_ENTRY_MODE_SET);
	_delay_us(50);
	HLCD_voidSendCmd(HLCD_DISPLAY_ON);
	_delay_us(50);
	HLCD_voidSendCmd(HLCD_CLEAR_DISPLAY);
	_delay_ms(2);
	
}

void HLCD_voidSendCmd(u8 ARG_u8Cmd){

	HLCD_RS(MDIO_LOW);
	HLCD_RW(MDIO_LOW);
	HLCD_EN(MDIO_LOW);
	HLCD_EN(MDIO_HIGH);

	HLCD_SEND_DATA_PORT(ARG_u8Cmd);	
	_delay_us(2);
	HLCD_EN(MDIO_LOW);
	
}

void HLCD_voidSendChar(char ARG_charChar){
	
	HLCD_RS(MDIO_HIGH);
	HLCD_RW(MDIO_LOW);
	HLCD_EN(MDIO_LOW);
	HLCD_EN(MDIO_HIGH);

	HLCD_SEND_DATA_PORT(ARG_charChar);	
	_delay_us(2);
	HLCD_EN(MDIO_LOW);
	
}

void HLCD_voidSendNum(u16 ARG_u16Number){
	if (0 == ARG_u16Number ) 
	{
		HLCD_voidSendChar('0');
	}
	else{
		u8 L_u8arrNum[6]; 
		s8	L_s8Iterator=0;
		//save every digit of num in our array separately
		for(;ARG_u16Number!=0;L_s8Iterator++)
		{
			L_u8arrNum[L_s8Iterator]=(ARG_u16Number%10) +'0';
			ARG_u16Number/=10;
		}
		L_s8Iterator--;
		while(L_s8Iterator!=-1){
			HLCD_voidSendChar(L_u8arrNum[L_s8Iterator]);
			L_s8Iterator--;
		}	
	}
}

void HLCD_voidSendString(const char *ARG_charptrString){
	
	if(ARG_charptrString != NULL_POINTER )
	{	
		u8 L_u8Iterator =0;
		do{
			HLCD_voidSendChar(ARG_charptrString[L_u8Iterator]);
			L_u8Iterator++;
		}while(ARG_charptrString[L_u8Iterator]!='\0');
		
		/* for(;ARG_charptrString[L_u8Iterator]!='\0';L_u8Iterator++){
			LCD_voidSendChar(ARG_charptrString[L_u8Iterator]);
		 }*/
	}
	else{
		/* return NULL_POINTER_ERROR */
	}
}

void HLCD_voidSetCur(u8 ARG_u8Row, u8 ARG_u8Col)
{
    u8 L_u8Temp= ( HLCD_START_LINE_1 | (ARG_u8Col ) | (ARG_u8Row<<6) );

    HLCD_voidSendCmd(L_u8Temp);
    _delay_ms(1);

}


void HLCD_voidClear(void)
{
	HLCD_voidSendCmd(HLCD_CLEAR_DISPLAY);
	_delay_ms(1);
}
