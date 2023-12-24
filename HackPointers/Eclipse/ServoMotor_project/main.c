/*
 * main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: user
 */

#define F_CPU     						8000000UL

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"
#include "MTIM_Interface.h"
#include "MADC_interface.h"



int main (void)
{
	/* Initialization  (Run Once)  */
	u8 L_ADCValue=0;
	u8 L_OCRValue=0;
	/* PWM0 pin */
	MDIO_stderrSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);

	MADC_stderrInit(MADC_VREF_AVCC,MADC_PRESCALER_4,MADC_ADJUST_LEFT);
	MADC_voidEnableADC();

	MTIM_stderrInit(MTIM_TIMER0, MTIM_CS_PRESCALER_256,MTIM_MODE_PHASECORRECTPWM,MTIM_HWPIN_NONINVERTING_PWM);
	MTIM_stderrStartTimer(MTIM_TIMER0);

	while(1)
	{
		MADC_stderrReadADC((u16*)&L_ADCValue,MADC_SCHANNEL_ADC0);
		L_OCRValue = (((f32)L_ADCValue*15)/255) + 16 ;
		MTIM_stderrSetOCR(MTIM_TIMER0,L_OCRValue);

	}
	return 0 ;
}


