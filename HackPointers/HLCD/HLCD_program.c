/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.1                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : August 8, 2023	                    */
/* ************************************************ */

/* Library Includes */
#include <stdint.h>
#include "BITMATH.h"

#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

/* SWC includes */
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"


*****************************************************************************/
static LCD_Config LDC_arr[6]={
	{HLCD_DATA_PORT,LCD_D4PIN},{HLCD_DATA_PORT,LCD_D5PIN},{HLCD_DATA_PORT,LCD_D6PIN},{HLCD_DATA_PORT,LCD_D7PIN},{HLCD_CTRL_PORT,HLCD_RS_PIN},{HLCD_CTRL_PORT,HLCD_RS_PIN}
};


void HLCD_voidInit(void)
{
		// init direction pin 
	for(uint8_t i=0; i< NUMOF_LCDPINS;i++)
	{
		GPIO_u8PinInit(LDC_arr[i].port,LDC_arr[i].pin,GPO_PUSH_PULL_02_MHZ);
	}

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

void HLCD_voidSendCmd(uint8_t ARG_u8Cmd){
	
	HLCD_RS(PIN_LOW);
	HLCD_EN(PIN_LOW);
	
	/* 4 - bit mode */
	
	/* send 4-MS bits  */
	HLCD_D4( GET_BIT(ARG_u8Cmd,4) ;  /*if bit is 0 or 1 increment it by 1 cause MDIO driver #MDIO_HIGH is 2 low is 1  */
	HLCD_D5( GET_BIT(ARG_u8Cmd,5) ;	/* we can change the macro in MDIO_driver but we don't need to define macro with 0 */
	HLCD_D6( GET_BIT(ARG_u8Cmd,6) ;
	HLCD_D7( GET_BIT(ARG_u8Cmd,7) ;

	HLCD_EN(PIN_HIGH);
	_delay_us(10);
	HLCD_EN(PIN_LOW);
	_delay_us(100);

	/* send 4-LS bits  */
	HLCD_D4( GET_BIT(ARG_u8Cmd,0) );
	HLCD_D5( GET_BIT(ARG_u8Cmd,1) );
	HLCD_D6( GET_BIT(ARG_u8Cmd,2) );
	HLCD_D7( GET_BIT(ARG_u8Cmd,3) );

	HLCD_EN(PIN_HIGH);
	_delay_us(10);
	HLCD_EN(PIN_LOW);
	_delay_us(100);
}

void HLCD_voidSendChar(char ARG_charChar){
	HLCD_RS(PIN_HIGH);
	HLCD_EN(PIN_LOW);
	
	/* send 4-MS bits  */
	HLCD_D4( GET_BIT(ARG_charChar,4) );
	HLCD_D5( GET_BIT(ARG_charChar,5) );
	HLCD_D6( GET_BIT(ARG_charChar,6) );
	HLCD_D7( GET_BIT(ARG_charChar,7) );

	HLCD_EN(PIN_HIGH);
	_delay_us(10);
	HLCD_EN(PIN_LOW);
	_delay_us(100);

	/* send 4-LS bits  */
	HLCD_D4( GET_BIT(ARG_charChar,0) );
	HLCD_D5( GET_BIT(ARG_charChar,1) );
	HLCD_D6( GET_BIT(ARG_charChar,2) );
	HLCD_D7( GET_BIT(ARG_charChar,3) );

	HLCD_EN(PIN_HIGH);
	_delay_us(10);
	HLCD_EN(PIN_LOW);
	_delay_us(100);
	#endif	
}

void HLCD_voidSendNum(uint16_t ARG_u16Number){
	if (0 == ARG_u16Number ) 
	{
		HLCD_voidSendChar('0');
	}
	else{
		uint8_t L_u8arrNum[6]; 
		int8_t	L_s8Iterator=0;
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
		uint8_t L_u8Iterator =0;
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
    uint8_t L_u8Temp=HLCD_START_LINE_1 | (ARG_u8Col ) | (ARG_u8Row<<6);

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
