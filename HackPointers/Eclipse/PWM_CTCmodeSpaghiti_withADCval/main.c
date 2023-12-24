/*
 * main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: user
 */

#define F_CPU     						8000000UL

#include "LBIT_math.h"
#include "LSTD_types.h"
//#include <util/delay.h>

//#include "MGIE_Interface.h"
#include "MDIO_interface.h"
#include "MTIM_Interface.h"
#include "MADC_interface.h"


//void GenerateFrequency(void);

int main (void)
{
	/* Initialization  (Run Once)  */
	u16 L_ADCValue=0;

//	MDIO_stderrSetPinDirection(MDIO_PORTC,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);

	MADC_stderrInit(MADC_VREF_AVCC,MADC_PRESCALER_2,MADC_ADJUST_LEFT);
	MADC_voidEnableADC();

	MTIM_stderrInit(MTIM_TIMER0, MTIM_CS_PRESCALER_8,MTIM_MODE_FASTPWM,MTIM_HWPIN_NONINVERTING_PWM);
//	MTIM_stderrSetCallBack(&GenerateFrequency, MTIM_INTERRUPT_T0_OCM);

//	MTIM_stderrEnableInterrupt(MTIM_INTERRUPT_T0_OCM);
//	MGIE_voidEnableGI();
	MTIM_stderrStartTimer(MTIM_TIMER0);

	while(1)
	{
		MADC_stderrReadADC(&L_ADCValue,MADC_SCHANNEL_ADC0);
		MTIM_stderrSetOCR(MTIM_TIMER0,L_ADCValue);

	}
	return 0 ;
}

//void GenerateFrequency(void){
//	MDIO_stderrTogglePinValue(MDIO_PORTC,MDIO_PIN0);
//}

