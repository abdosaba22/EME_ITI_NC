/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.1                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : August 8, 2023	                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

#include <util/delay.h>

/* MCAL Includes */
#include "MDIO_interface.h"

/* SWC includes */
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"

void HLCD_voidInit(void){
	/* 8 bit mode init code  */
	#if HLCD_MODE == HLCD_8BIT_MODE
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
	/* 4 bit mode init */
	#elif HLCD_MODE == HLCD_4BIT_MODE
	/* init direction */

	HLCD_CTRL_INIT(HLCD_RS_PIN);
	HLCD_CTRL_INIT(HLCD_RW_PIN);
	HLCD_CTRL_INIT(HLCD_EN_PIN);

	HLCD_DATA_INIT(HLCD_D4_PIN);
	HLCD_DATA_INIT(HLCD_D5_PIN);
	HLCD_DATA_INIT(HLCD_D6_PIN);
	HLCD_DATA_INIT(HLCD_D7_PIN);


	_delay_ms(40) ;

	HLCD_voidSendCmd(HLCD_INIT);//send most first
	_delay_ms(5);
	HLCD_voidSendCmd(HLCD_ENABLE_4BIT_MODE);//send most first
	_delay_us(100);
	HLCD_voidSendCmd(0x28);//send most first
	_delay_us(100);
	HLCD_voidSendCmd(0x0C);
		_delay_us(200);


	HLCD_voidSendCmd(0x06);
	HLCD_voidSendCmd(0x0F);
	HLCD_voidSendCmd(0x01);
	_delay_ms(2);

	#endif

}

void HLCD_voidSendCmd(u8 ARG_u8Cmd){
	
	HLCD_RS(MDIO_LOW);
	HLCD_RW(MDIO_LOW);
	HLCD_EN(MDIO_LOW);
	
	/* 8 - bit mode */	
	#if HLCD_MODE == HLCD_8BIT_MODE

	HLCD_SEND_DATA_PORT(ARG_u8Cmd);	
	HLCD_EN(MDIO_HIGH);
	_delay_us(20);
	HLCD_EN(MDIO_LOW);
	
	/* 4 - bit mode */
	#elif HLCD_MODE == HLCD_4BIT_MODE

	/* send 4-MS bits  */
	HLCD_D4( GET_BIT(ARG_u8Cmd,4) +1);  /*if bit is 0 or 1 increment it by 1 cause MDIO driver #MDIO_HIGH is 2 low is 1  */
	HLCD_D5( GET_BIT(ARG_u8Cmd,5) +1);	/* we can change the macro in MDIO_driver but we don't need to define macro with 0 */
	HLCD_D6( GET_BIT(ARG_u8Cmd,6) +1);
	HLCD_D7( GET_BIT(ARG_u8Cmd,7) +1);

	HLCD_EN(MDIO_HIGH);
	_delay_us(10);
	HLCD_EN(MDIO_LOW);
	_delay_us(100);

	/* send 4-LS bits  */
	HLCD_D4( GET_BIT(ARG_u8Cmd,0)+1 );
	HLCD_D5( GET_BIT(ARG_u8Cmd,1)+1 );
	HLCD_D6( GET_BIT(ARG_u8Cmd,2)+1 );
	HLCD_D7( GET_BIT(ARG_u8Cmd,3)+1 );

	HLCD_EN(MDIO_HIGH);
	_delay_us(10);
	HLCD_EN(MDIO_LOW);
	_delay_us(100);
	#endif
}

void HLCD_voidSendChar(char ARG_charChar){
	HLCD_RS(MDIO_HIGH);
	HLCD_RW(MDIO_LOW);
	HLCD_EN(MDIO_LOW);
	
	/* 8 - bit mode */	
	#if HLCD_MODE == HLCD_8BIT_MODE

	HLCD_SEND_DATA_PORT(ARG_charChar);	
	HLCD_EN(MDIO_HIGH);
	_delay_us(20);
	HLCD_EN(MDIO_LOW);
	
	/* 4 - bit mode */
	#elif HLCD_MODE == HLCD_4BIT_MODE

	/* send 4-MS bits  */
	HLCD_D4( GET_BIT(ARG_charChar,4)+1 );
	HLCD_D5( GET_BIT(ARG_charChar,5)+1 );
	HLCD_D6( GET_BIT(ARG_charChar,6)+1 );
	HLCD_D7( GET_BIT(ARG_charChar,7)+1 );

	HLCD_EN(MDIO_HIGH);
	_delay_us(10);
	HLCD_EN(MDIO_LOW);
	_delay_us(100);

	/* send 4-LS bits  */
	HLCD_D4( GET_BIT(ARG_charChar,0)+1 );
	HLCD_D5( GET_BIT(ARG_charChar,1)+1 );
	HLCD_D6( GET_BIT(ARG_charChar,2)+1 );
	HLCD_D7( GET_BIT(ARG_charChar,3)+1 );

	HLCD_EN(MDIO_HIGH);
	_delay_us(10);
	HLCD_EN(MDIO_LOW);
	_delay_us(100);
	#endif	
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
    u8 L_u8Temp=HLCD_START_LINE_1 | (ARG_u8Col ) | (ARG_u8Row<<6);

    HLCD_voidSendCmd(L_u8Temp);
    _delay_ms(1);
    /*  another way */

    /* 	switch (ARG_u8Row)
        {
            case 0:
                ARG_u8Col |= HLCD_START_LINE_1;
                break;
            case 1:
                ARG_u8Col |= HLCD_START_LINE_2;
                break;
        }
     */
}

void HLCD_voidClear(void)
{
	HLCD_voidSendCmd(HLCD_CLEAR_DISPLAY);
	_delay_ms(1);
}
