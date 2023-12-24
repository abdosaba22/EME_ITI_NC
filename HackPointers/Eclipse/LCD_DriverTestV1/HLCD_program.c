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
#include "HLCD_config.h"
#include "HLCD_private.h"
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

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : send a specific command to LCD
* Parameters   : uint8_t: the value of command
* Return value : void
*****************************************************************************/

void HLCD_voidSendCmd(u8 ARG_u8Cmd){

	HLCD_RS(MDIO_LOW);
	HLCD_RW(MDIO_LOW);
	HLCD_EN(MDIO_LOW);
	HLCD_EN(MDIO_HIGH);

	HLCD_SEND_DATA_PORT(ARG_u8Cmd);	
	_delay_us(2);
	HLCD_EN(MDIO_LOW);
	
}
/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : write a char (by ascii) on LCD
* Parameters   : uint8_t: the value of ascii of the char
* Return value : void
*****************************************************************************/

void HLCD_voidSendData(u8 ARG_u8Data){
	
	HLCD_RS(MDIO_HIGH);
	HLCD_RW(MDIO_LOW);
	HLCD_EN(MDIO_LOW);
	HLCD_EN(MDIO_HIGH);

	HLCD_SEND_DATA_PORT(ARG_u8Data);	
	_delay_us(2);
	HLCD_EN(MDIO_LOW);
	
}
/************************************************************************
* Function Name: LCD_write_num
* Purpose      : display a specific number on LCD
* Parameters   : uint16_t: 5 digit number or less
* Return value : void
*************************************************************************/
void HLCD_voidSendNum(u16 ARG_u16Number){
	if (0 == ARG_u16Number ) 
	{
		HLCD_voidSendData('0');
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
			HLCD_voidSendData(L_u8arrNum[L_s8Iterator]);
			L_s8Iterator--;
		}	
	}
}

void HLCD_voidSendString(char *ARG_chararrString){
	uint8_t L_s8Iterator =0;
	for(;ARG_chararrString[L_s8Iterator]!='\0';L_s8Iterator++){
		HLCD_voidSendData(ARG_chararrString[L_s8Iterator]);
	}
}
void HLCD_voidSetCur(u8 ARG_u8Row, u8 ARG_u8Col)
{
    switch (ARG_u8Row)
    {
        case 0:
            ARG_u8Col |= HLCD_START_LINE_1;
            break;
        case 1:
            ARG_u8Col |= HLCD_START_LINE_2;
            break;
    }

    HLCD_voidSendCmd(ARG_u8Col);
    _delay_ms(2);

}

void HLCD_voidClear(void)
{
	HLCD_voidSendCmd(HLCD_CLEAR_DISPLAY);
	_delay_ms(2);
}
