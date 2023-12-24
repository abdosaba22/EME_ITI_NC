/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Timers				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 17, 2023                    */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

#ifndef _MTIM_INTERFACE_H_
#define _MTIM_INTERFACE_H_

#define MTIM_TIMER0							0
#define MTIM_TIMER1							1
#define MTIM_TIMER2							2

#define MTIM_CS_NO_CLOCK 					0
#define MTIM_CS_PRESCALER_1 				1
#define MTIM_CS_PRESCALER_8 				2
#define MTIM_CS_PRESCALER_64 				3
#define MTIM_CS_PRESCALER_256 				4
#define MTIM_CS_PRESCALER_1024 				5
#define MTIM_CS_T0_FALLING 					6
#define MTIM_CS_T0_RISING 					7

#define MTIM_MODE_NORMAL					0
#define MTIM_MODE_CTC						1
#define MTIM_MODE_FASTPWM					2
#define MTIM_MODE_PHASECORRECTPWM			3

#define MTIM_HWPIN_DISCONNECTED				0
#define MTIM_HWPIN_TOGGLE					1
#define MTIM_HWPIN_CLEAR					2
#define MTIM_HWPIN_SET						3
#define MTIM_HWPIN_NONINVERTING_PWM			2
#define MTIM_HWPIN_INEVERING_PWM			3

#define MTIM_INTERRUPT_T0_OVF				0
#define MTIM_INTERRUPT_T0_OCM				1


/* make sure F_CPU is defined */
#ifndef F_CPU 
#define F_CPU 		8000000UL
#warning F_CPU is not defined. Assuming 8MHz clock.
#endif

STD_error_t MTIM_stderrInit(u8 ARG_u8TimerNo,u8 ARG_u8ClockSource,u8 ARG_u8u8Mode ,u8 ARG_u8HWPinMode);
void MTIM_voidForceOutputCompare(void);
STD_error_t MTIM_stderrEnableInterrupt(u8 ARG_u8InterruptSource);
STD_error_t MTIM_stderrDisableInterrupt(u8 ARG_u8InterruptSource);
STD_error_t MTIM_stderrSetCallBack(void(*ARG_pvoidfUserFunction)(void), u8 ARG_u8InterruptSource);
STD_error_t MTIM_stderrStartTimer(u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrStopTimer(u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrSetOCR(u8 ARG_u8TimerNo,u16 ARG_u16OCRValue);
STD_error_t MTIM_stderrTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay);

#endif
