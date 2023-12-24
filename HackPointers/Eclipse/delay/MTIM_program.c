/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Timers				                */
/* Layer       : MCAL                               */
/* Version     : 1.1                                */
/* Date        : August 17, 2023                    */
/* Last Edit   : August 20, 2023                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "MTIM_private.h"
#include "MTIM_interface.h"
// Variables
static u8 MTIM_u8Timer0Clock;
static u8 MTIM_u8Timer1Clock;
static u8 MTIM_u8Timer2Clock;

volatile static u16 MTIM_u16Timer0OVFCount;
volatile static u8  MTIM_u8Timer0Preload;

volatile static u16 MTIM_u16Timer1OVFCount;
volatile static u16 MTIM_u16Timer1Preload;

volatile static u16 MTIM_u16Timer2OVFCount;
volatile static u8 MTIM_u8Timer2Preload;

void (*MTIM_pvoidfUserFunctionT0OVF)(void)=NULL_POINTER;
void (*MTIM_pvoidfUserFunctionT0OCM)(void)=NULL_POINTER;

STD_error_t MTIM_stderrInit(u8 ARG_u8TimerNo,u8 ARG_u8ClockSource,u8 ARG_u8u8Mode ,u8 ARG_u8HWPinMode)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_u8TimerNo<=2 &&ARG_u8ClockSource<=7 && ARG_u8u8Mode<=3 && ARG_u8HWPinMode<=3)
	{
		switch(ARG_u8TimerNo)
		{
			case MTIM_TIMER0:
				switch(ARG_u8u8Mode)
				{
					case MTIM_MODE_T0T2_NORMAL:
						CLEAR_BIT(TCCR0,WGM01);
						CLEAR_BIT(TCCR0,WGM00);
					break;
					case MTIM_MODE_T0T2_CTC:
						SET_BIT(TCCR0,WGM01);
						CLEAR_BIT(TCCR0,WGM00);
					break;
					case MTIM_MODE_T0T2_FASTPWM:
						SET_BIT(TCCR0,WGM01);
						SET_BIT(TCCR0,WGM00);
					break;
					case MTIM_MODE_T0T2_PHASECORRECTPWM:
						SET_BIT(TCCR0,WGM00);
						CLEAR_BIT(TCCR0,WGM01);
					break;
					default: L_stderrState=E_NOK; break;
				}
				TCCR0 = (TCCR0 & 0xCF) | (ARG_u8HWPinMode<<4);
				MTIM_u8Timer0Clock = ARG_u8ClockSource; /* assign it to global var*/
			break;
			case MTIM_TIMER1:
				TCCR1A =( TCCR1A & 0xFC) | ( ARG_u8u8Mode & 0x03 );
				TCCR1B =( TCCR1B & 0xE7) | ( ARG_u8u8Mode & 0x0C );	
				/* switch(ARG_u8u8Mode)
				{
					case MTIM_MODE_T1_NORMAL:
						CLEAR_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						CLEAR_BIT(TCCR1B,WGM12);
						CLEAR_BIT(TCCR1B,WGM13);
					break;
					default: L_stderrState=E_NOK; break;
				} */
				
				TCCR1A = (TCCR1A&0x0F) | (ARG_u8HWPinMode<<4);
				MTIM_u8Timer1Clock = ARG_u8ClockSource; /* assign it to global var*/
			break;
			case MTIM_TIMER2: 
				switch(ARG_u8u8Mode)
				{
					case MTIM_MODE_T0T2_NORMAL:
						CLEAR_BIT(TCCR0,WGM01);
						CLEAR_BIT(TCCR0,WGM00);
					break;
					case MTIM_MODE_T0T2_CTC:
						SET_BIT(TCCR0,WGM01);
						CLEAR_BIT(TCCR0,WGM00);
					break;
					case MTIM_MODE_T0T2_FASTPWM:
						SET_BIT(TCCR0,WGM01);
						SET_BIT(TCCR0,WGM00);
					break;
					case MTIM_MODE_T0T2_PHASECORRECTPWM:
						SET_BIT(TCCR0,WGM00);
						CLEAR_BIT(TCCR0,WGM01);
					break;
					default: L_stderrState=E_NOK; break;
				}
				TCCR2 = (TCCR2&0xCF) | (ARG_u8HWPinMode<<4);
				MTIM_u8Timer2Clock = ARG_u8ClockSource; /* assign it to global var*/
			break;
			default: L_stderrState=E_NOK; break;
		}
	}
	else
	{
		L_stderrState=E_NOK;
	}

	return L_stderrState;
}

void MTIM_voidForceOutputCompare(void)
{
	SET_BIT(TCCR0,FOC0);
}

STD_error_t MTIM_stderrEnableInterrupt(u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_u8InterruptSource<=7)
	{
		SET_BIT(TIMSK, ARG_u8InterruptSource);
	}
	else
	{
		L_stderrState=E_NOK;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrDisableInterrupt(u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_u8InterruptSource<=7)
	{
		CLEAR_BIT(TIMSK, ARG_u8InterruptSource);
	}
	else
	{
		L_stderrState=E_NOK;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrSetCallBack(void(*ARG_pvoidfUserFunction)(void), u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_pvoidfUserFunction!=NULL_POINTER )
	{
		switch(ARG_u8InterruptSource)
		{
			case MTIM_INTERRUPT_T0_OVF:	MTIM_pvoidfUserFunctionT0OVF=ARG_pvoidfUserFunction; break;
			case MTIM_INTERRUPT_T0_OCM:	MTIM_pvoidfUserFunctionT0OCM=ARG_pvoidfUserFunction; break;
			default: L_stderrState=E_NOK; break;
		}
	}
	else
	{
		L_stderrState=E_NULL_POINTER;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrStartTimer(u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrState=E_OK;
	switch(ARG_u8TimerNo)
	{
		case MTIM_TIMER0: TCCR0  = (TCCR0 & 0xF8)  | MTIM_u8Timer0Clock; break;
		case MTIM_TIMER1: TCCR1B = (TCCR1B & 0xF8) | MTIM_u8Timer1Clock; break;
		case MTIM_TIMER2: break;
		default: L_stderrState=E_NOK; break;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrStopTimer(u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrState=E_OK;
	switch(ARG_u8TimerNo)
	{
		case MTIM_TIMER0: TCCR0  = (TCCR0 & 0xF8)  | MTIM_CS_NO_CLOCK; break;
		case MTIM_TIMER1: TCCR1B = (TCCR1B & 0xF8) | MTIM_CS_NO_CLOCK; break;
		case MTIM_TIMER2: break;
		default: L_stderrState=E_NOK; break;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrSetOCR(u8 ARG_u8TimerNo,u16 ARG_u16OCRValue)
{
	STD_error_t L_stderrState=E_OK;
	switch(ARG_u8TimerNo)
	{
		case MTIM_TIMER0:	OCR0 = ARG_u16OCRValue; break;
		case MTIM_TIMER1: break;
		case MTIM_TIMER2: break;
		default: L_stderrState=E_NOK; break;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrGetTimerValue(u16* ARG_u16TimerValue, u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrState=E_OK;
	switch(ARG_u8TimerNo)
	{
		case MTIM_TIMER0:	*ARG_u16TimerValue = TCNT0; break;
		case MTIM_TIMER1: 	*ARG_u16TimerValue = TCNT1; break;
		case MTIM_TIMER2: break;
		default: L_stderrState=E_NOK; break;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrSetTimerValue(u8 ARG_u8TimerNo, u16 ARG_u16TimerValue)
{
	STD_error_t L_stderrState=E_OK;
	switch(ARG_u8TimerNo)
	{
		case MTIM_TIMER0:	TCNT0 = ARG_u16TimerValue; break;
		case MTIM_TIMER1: 	TCNT1 = ARG_u16TimerValue; break;
		case MTIM_TIMER2: break;
		default: L_stderrState=E_NOK; break;
	}

	return L_stderrState;
}

STD_error_t MTIM_stderrTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay)
{
	STD_error_t L_stderrState=E_OK;
	f32 L_f32TickTime,L_f32OVFTime;
	u16 L_u16Prscaler;
	switch(ARG_u8TimerNo){
		case MTIM_TIMER0:
			switch(MTIM_u8Timer0Clock){
				case MTIM_CS_PRESCALER_1 	:L_u16Prscaler = 1; break;
				case MTIM_CS_PRESCALER_8 	:L_u16Prscaler = 8; break;
				case MTIM_CS_PRESCALER_64 	:L_u16Prscaler = 64; break;
				case MTIM_CS_PRESCALER_256 	:L_u16Prscaler = 256; break;
				case MTIM_CS_PRESCALER_1024 :L_u16Prscaler = 1024; break;
				default: L_stderrState=E_NOK; break;
			}
			L_f32TickTime = (f32)L_u16Prscaler/ F_CPU;
			L_f32OVFTime = L_f32TickTime * 256;
			MTIM_u16Timer0OVFCount = ((f32)ARG_u32Delay/1000) / L_f32OVFTime;
			MTIM_u8Timer0Preload = 256 - ((ARG_u32Delay / 1000) % (u32)L_f32OVFTime);
			TCNT0= MTIM_u8Timer0Preload;
		break;
		case MTIM_TIMER1:
			switch(MTIM_u8Timer1Clock){
				case MTIM_CS_PRESCALER_1 	:L_u16Prscaler = 1; break;
				case MTIM_CS_PRESCALER_8 	:L_u16Prscaler = 8; break;
				case MTIM_CS_PRESCALER_64 	:L_u16Prscaler = 64; break;
				case MTIM_CS_PRESCALER_256 	:L_u16Prscaler = 256; break;
				case MTIM_CS_PRESCALER_1024 :L_u16Prscaler = 1024; break;
				default: L_stderrState=E_NOK; break;
			}
			L_f32TickTime = (f32)L_u16Prscaler/ F_CPU;
			L_f32OVFTime = L_f32TickTime * 65535;
			MTIM_u16Timer1OVFCount = ((f32)ARG_u32Delay/1000) / L_f32OVFTime;
			MTIM_u16Timer1Preload = 65535 - ((ARG_u32Delay / 1000) % (u32)L_f32OVFTime);
			TCNT1= MTIM_u16Timer1Preload;
		break;
		case MTIM_TIMER2: break;
		default: L_stderrState=E_NOK; break;
	}

	return L_stderrState;

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(NULL_POINTER != MTIM_pvoidfUserFunctionT0OVF)
	{
		(*MTIM_pvoidfUserFunctionT0OCM)();
	}
	else
	{
		/* do nothing */
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){

	if(NULL_POINTER != MTIM_pvoidfUserFunctionT0OVF)
	{
		volatile static u16 L_u16OVFCounter = 0;
		L_u16OVFCounter++;
		if(L_u16OVFCounter==(MTIM_u16Timer0OVFCount+1))
		{
			L_u16OVFCounter =0;
			TCNT0=MTIM_u8Timer0Preload;
			(*MTIM_pvoidfUserFunctionT0OVF)();
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}

}

