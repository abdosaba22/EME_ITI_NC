/*
 * main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: user
 */

#define F_CPU     						8000000UL

#include "LBIT_math.h"
#include "LSTD_types.h"
#include <util/delay.h>

#include "MDIO_interface.h"
#include "MTIM_Interface.h"
#include "MADC_interface.h"
#include "MEXTI_interface.h"
#include "MGIE_interface.h"

#include "HLCD_interface.h"


void Step1(void);
void Step2(void);
void Step3(void);

u8  G_u8Ready=0;
u16 G_u16Ton;
u16 G_u16Toff;
u16 G_u16Period;
u16	G_u16Frequency;
u8  G_u8DutyCycle;

int main (void)
{
	/* Initialization  (Run Once)  */
	u16 L_ADCValue=0;
	/* PWM0 pin */
	MDIO_stderrSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);

	MADC_stderrInit(MADC_VREF_AVCC,MADC_PRESCALER_2,MADC_ADJUST_LEFT);
	MADC_voidEnableADC();
	MTIM_stderrInit(MTIM_TIMER0, MTIM_CS_PRESCALER_256,MTIM_MODE_T0_PHASECORRECTPWM,MTIM_HWPIN_T0_NONINVERTING_PWM);
	MTIM_stderrStartTimer(MTIM_TIMER0);

	HLCD_voidInit();

	HLCD_voidSetCur(0,0);
	HLCD_voidSendString("Freq: ");
	HLCD_voidSetCur(1,0);
	HLCD_voidSendString("Duty: ");

	MTIM_stderrInit(MTIM_TIMER1, MTIM_CS_PRESCALER_8,MTIM_MODE_T1_NORMAL,MTIM_HWPIN_T1_OC1ADISCON_OC1B_DISCON);

	MEXTI_stderrInit(MEXTI_INT0, MEXTI_MODE_RISING);
	MEXTI_stderrCallBack(Step1, MEXTI_INT0);
	MEXTI_stderrEnable(MEXTI_INT0);

	MGIE_voidEnableGI();

	while(1)
	{
		MADC_stderrReadADC(&L_ADCValue,MADC_SCHANNEL_ADC0);
		MTIM_stderrSetOCR(MTIM_TIMER0,L_ADCValue);

		if(1==G_u8Ready)
		{
			G_u16Frequency = ( 1.0/(f32)(G_u16Period/1000) ) * 1000 ; // convert period to Sec then 1.0/(Period/1000) == (1.0/Period)*1000
			G_u8DutyCycle = ((f32)G_u16Ton/G_u16Period) * 100;
			HLCD_voidSetCur(0,6);
			HLCD_voidSendString("        ");
			HLCD_voidSetCur(0,6);
			HLCD_voidSendNum(G_u16Frequency);
			HLCD_voidSendString("Hz.");
			HLCD_voidSetCur(1,6);
			HLCD_voidSendString("       ");
			HLCD_voidSetCur(1,6);
			HLCD_voidSendNum(G_u8DutyCycle);
			HLCD_voidSendChar('%');
		}
		_delay_ms(1000);
	}
	return 0 ;
}

void Step1(void)
{
	MTIM_stderrStartTimer(MTIM_TIMER1);
	MEXTI_stderrInit(MEXTI_INT0, MEXTI_MODE_FALLING);
	MEXTI_stderrCallBack(Step2, MEXTI_INT0);
}
void Step2(void)
{
	MTIM_stderrGetTimerValue(&G_u16Ton, MTIM_TIMER1);
	//MTIM_stderrSetTimerValue(MTIM_TIMER1, 0x0000);
	MEXTI_stderrInit(MEXTI_INT0, MEXTI_MODE_RISING);
	MEXTI_stderrCallBack(Step3, MEXTI_INT0);
	G_u8Ready=0;
}
void Step3(void){
//	MTIM_stderrGetTimerValue(&G_u16Toff, MTIM_TIMER1);
	MTIM_stderrGetTimerValue(&G_u16Period, MTIM_TIMER1);
	MTIM_stderrSetTimerValue(MTIM_TIMER1, 0x0000);
	MTIM_stderrStopTimer(MTIM_TIMER1);
	MEXTI_stderrCallBack(Step1, MEXTI_INT0);
	G_u8Ready=1;
}


