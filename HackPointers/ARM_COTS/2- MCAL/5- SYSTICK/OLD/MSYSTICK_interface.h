/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 SysTick							*/
/* MCu         	:	 Stm32F401CCU6						*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 19, 2023					*/
/* Last Edit   	:	 N/A			   					*/
/* **************************************************** */

#ifndef _MSYSTICK_INTERFACE_H_
#define _MSYSTICK_INTERFACE_H_


STD_error_t MSTK_stderrInit(u8 ARG_u8ClockSrc);

STD_error_t MSTK_stderrDelayms_IT(void (*ARG_pvoidfuncUserFunction)(void), u16 ARG_u16Delay, u8 ARG_u8Periodic);

u32 MSTK_u32Millis(void);

void MSTK_voidDelayms(u16 ARG_u16Delay);

void MSTK_voidDelayus(u32 ARG_u32Delayus);

void MSTK_voidStop(void);


#define MSTK_CLOCKSRC_AHB_8			  	0U
#define MSTK_CLOCKSRC_AHB  			  	1U

#define MSTK_SINGLE_INTERVAL			0U
#define MSTK_PERIOD_INTERVAL			1U


#endif