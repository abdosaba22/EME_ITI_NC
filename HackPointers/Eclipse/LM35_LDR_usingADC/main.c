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

#define LM35_CHANNEL    				MADC_SCHANNEL_ADC0  // AN0
#define LM35_RESOLUTION 				256.0
#define LM35_VREFF						5.0

#define LDR_CHANNEL  		  			MADC_SCHANNEL_ADC1  // AN0
#define LDR_RESOLUTION 					256.0
#define LDR_VREFF						5.0


u16 LM35_u16GetTemp(void)
{

        /* 19.5 m.v for level --> 5 V / 256
           we use 8-bit mode
           ADC_read return number of the level multiply it by 19.5 = V_out m.v from sens
           T c = V_out m.v / 10.00 m.v --> 10 mv/c */
		u16 L_u16ADCResult;
		f32 L_f32Volt=0;
		MADC_stderrReadADC(&L_u16ADCResult,LM35_CHANNEL);
		L_f32Volt= (f32) (L_u16ADCResult*(LM35_VREFF/LM35_RESOLUTION)); // LM35 V-out
		L_u16ADCResult= (u32) ((f32)L_f32Volt/0.01); //Temperature in C
		return L_u16ADCResult ;
}

u16 LDR_u16GetValue(void)
{

        /* 4.88 m.v for level --> 5 V / 256
           we use 8-bit mode
           ADC_read return number of the level multiply it by 19.5 = V_out m.v from sens
           T c = V_out m.v / 10.00 m.v --> 10 mv/c
           vLDR = v-in * R / (R-LDR + R)
           */

		u16 L_u16ADCResult;
		f32 L_f32Volt=0;
		MADC_stderrReadADC(&L_u16ADCResult,LDR_CHANNEL);
		L_f32Volt= (f32) (L_u16ADCResult*(LDR_VREFF/LDR_RESOLUTION)); // LM35 V-out
		L_u16ADCResult= (u32) ( (f32)(20000*L_f32Volt)/(5-L_f32Volt)); //    (f32)L_f32Volt/0.01); //Temperature in C
		return L_u16ADCResult ;
}




int main(void){
	// Initialization  (Run Once)
	//char L_charpNumString[6]="0000";
	//f32 L_f32Volt=0;
	u16 L_u16ADCResult= 0;

	MADC_stderrInit(MADC_VREF_AVCC,MADC_PRESCALER_64,MADC_ADJUST_LEFT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_INPUT_PULLUP);

	HLCD_voidInit();

	while(1){
		// Application (Run )
		//MADC_stderrReadADC(&L_u16ADCResult,MADC_SCHANNEL_ADC0);
		L_u16ADCResult=LM35_u16GetTemp();
		HLCD_voidClear();
		HLCD_voidSetCur(0,0);
		HLCD_voidSendString("Temp is:");
		HLCD_voidSendNum(L_u16ADCResult);
		HLCD_voidSendChar('C');
		_delay_ms(1200);
		//L_f32Volt = L_u16ADCResult* (5.0/256.0); // volt val conversion
		L_u16ADCResult=LDR_u16GetValue();

		HLCD_voidSetCur(1,0);
		HLCD_voidSendString("LDR is:");
		HLCD_voidSendNum(L_u16ADCResult);
		HLCD_voidSendString("Ohms");
		_delay_ms(1200);

	}
	return 0;
}

