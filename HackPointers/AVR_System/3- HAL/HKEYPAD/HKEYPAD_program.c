/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : KEYPAD                             */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : August 9, 2023                     */
/* Last Edit   : N/A 			                    */
/* ************************************************ */
/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MDIO_private.h"
#include "MDIO_interface.h"


const char HKPD_charKeypad[HKPD_ROW_NUM][HKPD_COL_NUM]= HKPD_ARR_VAL;

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


/* 

void KEYPAD_init(void){
        for(uint8_t i=0; i< NUMOF_LCDPINS;i++){

		GPIO_u8PinInit(KEYPAD_arr[i].port,KEYPAD_arr[i].pin,KEYPAD_arr[i].mode);

	}
       // Enable internal pull-up resistors for PORTD

}

uint8_t KEYPAD_read(void){
uint8_t i,VAL=1;

//portd=0xFF;
//TRISD |= (1 << 7); // Set RD7 as input (button)
KP0(1);KP1(1);KP2(1);KP3(1);
for(i = 0; i < 4;i++)
      {
          switch(i){
                  case 0: KP0(0);KP1(1);KP2(1);KP3(1); break;
                  case 1: KP0(1);KP1(0);KP2(1);KP3(1); break;
                  case 2: KP0(1);KP1(1);KP2(0);KP3(1); break;
                  case 3: KP0(1);KP1(1);KP2(1);KP3(0); break;
        }
        if (KP4(&VAL)&& VAL==0) return keypad_matrix[0 + i*4];
        if (KP5(&VAL)&& VAL==0) return keypad_matrix[1 + i*4];
        if (KP6(&VAL)&& VAL==0) return keypad_matrix[2 + i*4];
        if (KP7(&VAL)&& VAL==0) return keypad_matrix[3 + i*4];


      }
          return 0;


} */