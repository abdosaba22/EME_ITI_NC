/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: DELL
 */

#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "HLCD_interface.h"


void floatToString(f32 num, char* str);

int main(void){
	// Initialization  (Run Once)
	char L_charpNumString[6]="0000";
	f32 L_f32Volt=0;
	u16 L_u16ADCResult= 0;

	MADC_stderrInit(MADC_VREF_AVCC,MADC_PRESCALER_64,MADC_ADJUST_LEFT);

	HLCD_voidInit();

	while(1){
		// Application (Run )
		MADC_stderrReadADC(&L_u16ADCResult,MADC_SCHANNEL_ADC0);
		//MDIO_stderrSetPortValue(MDIO_PORTB,L_u16ADCResult);
		HLCD_voidClear();
		HLCD_voidSetCur(0,0);
		HLCD_voidSendString("ADCR:");
		HLCD_voidSendNum(L_u16ADCResult);
		//_delay_ms(1000);
		L_f32Volt = L_u16ADCResult* (5.0/256.0); // volt val conversion
		floatToString(L_f32Volt,L_charpNumString); // convert float to string
		HLCD_voidSetCur(1,1);
		HLCD_voidSendString("Volt is:");
		HLCD_voidSendString(L_charpNumString);
		HLCD_voidSendChar('V');
//		if (L_u16ADCResult >=4 ) {MDIO_stderrSetPortValue(MDIO_PORTB,0x00); MDIO_stderrSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_HIGH); }
//		else if (L_u16ADCResult >=3 ) {MDIO_stderrSetPortValue(MDIO_PORTB,0x00); MDIO_stderrSetPinValue(MDIO_PORTB,MDIO_PIN1,MDIO_HIGH); }
//		else if (L_u16ADCResult >=2 ) {MDIO_stderrSetPortValue(MDIO_PORTB,0x00); MDIO_stderrSetPinValue(MDIO_PORTB,MDIO_PIN2,MDIO_HIGH); }
//		else {MDIO_stderrSetPortValue(MDIO_PORTB,0x00); MDIO_stderrSetPinValue(MDIO_PORTB,MDIO_PIN3,MDIO_HIGH); }

		_delay_ms(1500);



	}
	return 0;
}


void floatToString(f32 num, char* str) {
	*str++='0';
	*str='.';

    u8 L_u8Part = (u8)num;
    u8 L_u8fractionalPart = (u8) 100*(num - L_u8Part);
    u8 L_s8Iterator ;

    // Move pointer to the end of the string
    while (*str != '\0') {
    	str++;
    }
    str--;



    // Convert fractional part to string with the given precision
    for ( L_s8Iterator = 0; L_s8Iterator < 2; L_s8Iterator++) {
    	*str=(L_u8fractionalPart%10) +'0';
    	L_u8fractionalPart/=10;
    	str--;
    }

    // Add decimal point
    *str = '.';
    str--;
    for(;L_u8Part!=0;str--)
    {
    	*str=(L_u8Part%10) +'0';
    	L_u8Part/=10;
    }

}
