/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Timers				                */
/* Layer       : MCAL                               */
/* Version     : 1.1                                */
/* Date        : August 17, 2023                    */
/* Last Edit   : August 20, 2023                    */
/* ************************************************ */

#ifndef _MTIM_INTERFACE_H_
#define _MTIM_INTERFACE_H_

#define MTIM_TIMER0											0
#define MTIM_TIMER1											1
#define MTIM_TIMER2											2

#define MTIM_CS_NO_CLOCK 									0
#define MTIM_CS_PRESCALER_1 								1
#define MTIM_CS_PRESCALER_8 								2
#define MTIM_CS_PRESCALER_64 								3
#define MTIM_CS_PRESCALER_256 								4
#define MTIM_CS_PRESCALER_1024 								5
#define MTIM_CS_T0_FALLING 									6
#define MTIM_CS_T0_RISING 									7
				
#define MTIM_MODE_T0_NORMAL									0
#define MTIM_MODE_T0_CTC									1
#define MTIM_MODE_T0_FASTPWM								2
#define MTIM_MODE_T0_PHASECORRECTPWM						3

#define MTIM_HWPIN_T0_DISCONNECTED							0
#define MTIM_HWPIN_T0_TOGGLE								1
#define MTIM_HWPIN_T0_CLEAR									2
#define MTIM_HWPIN_T0_SET									3
#define MTIM_HWPIN_T0_NONINVERTING_PWM						2
#define MTIM_HWPIN_T0_INEVERING_PWM							3
//TIMSK 				
#define MTIM_INTERRUPT_T0_OVF								0
#define MTIM_INTERRUPT_T0_OCM								1
#define MTIM_INTERRUPT_T1_OVF								2
#define MTIM_INTERRUPT_T1_OCMA								3
#define MTIM_INTERRUPT_T1_OCMB								4
#define MTIM_INTERRUPT_T1_ICU								5
#define MTIM_INTERRUPT_T2_OVF								6
#define MTIM_INTERRUPT_T2_OCM								7

#define MTIM_MODE_T1_NORMAL           			   			0
#define MTIM_MODE_T1_PHASECORRECTPWM_8BIT     	   			1
#define MTIM_MODE_T1_PHASECORRECTPWM_9BIT     	   			2
#define MTIM_MODE_T1_PHASECORRECTPWM_10BIT    	   			3
#define MTIM_MODE_T1_CTC_OCR1A        	   					4
#define MTIM_MODE_T1_FASTPWM_8BIT   	   					5
#define MTIM_MODE_T1_FASTPWM_9BIT   	   					6
#define MTIM_MODE_T1_FASTPWM_10BIT  	   					7
#define MTIM_MODE_T1_PHASEFREQCORRECTPWM_ICR1      	   	    8
#define MTIM_MODE_T1_PHASEFREQCORRECTPWM_OCR1A     	   	    9
#define MTIM_MODE_T1_PHASECORRECTPWM_ICR1      	   		    10
#define MTIM_MODE_T1_PHASECORRECTPWM_OCR1A     	   		    11
#define MTIM_MODE_T1_CTC_ICR1         	   					12
#define MTIM_MODE_T1_FASTPWM_ICR1    	   					14
#define MTIM_MODE_T1_FASTPWM_OCR1A   	   					15

#define MTIM_HWPIN_T1_OC1ADISCON_OC1B_DISCON              0b0000
#define MTIM_HWPIN_T1_OC1ADISCON_OC1B_TOGGLE              0b0001
#define MTIM_HWPIN_T1_OC1ADISCON_OC1B_CLEAR               0b0010
#define MTIM_HWPIN_T1_OC1ADISCON_OC1B_SET                 0b0011

#define MTIM_HWPIN_T1_OC1ATOG_OC1B_DISCON                 0b0100
#define MTIM_HWPIN_T1_OC1ATOG_OC1B_TOGGLE                 0b0101
#define MTIM_HWPIN_T1_OC1ATOG_OC1B_CLEAR                  0b0110
#define MTIM_HWPIN_T1_OC1ATOG_OC1B_SET                    0b0111

#define MTIM_HWPIN_T1_OC1ACLEAR_OC1B_DISCON               0b1000
#define MTIM_HWPIN_T1_OC1ACLEAR_OC1B_TOGGLE               0b1001
#define MTIM_HWPIN_T1_OC1ACLEAR_OC1B_CLEAR                0b1010
#define MTIM_HWPIN_T1_OC1ACLEAR_OC1B_SET                  0b1011

#define MTIM_HWPIN_T1_OC1ASET_OC1B_DISCON                 0b1100
#define MTIM_HWPIN_T1_OC1ASET_OC1B_TOGGLE                 0b1101
#define MTIM_HWPIN_T1_OC1ASET_OC1B_CLEAR                  0b1110
#define MTIM_HWPIN_T1_OC1ASET_OC1B_SET                    0b1111


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
STD_error_t MTIM_stderrGetTimerValue(u16* ARG_u16TimerValue, u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrSetTimerValue(u8 ARG_u8TimerNo, u16 ARG_u16TimerValue);
STD_error_t MTIM_stderrSetOCR(u8 ARG_u8TimerNo,u16 ARG_u16OCRValue);
STD_error_t MTIM_stderrTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay);

#endif
