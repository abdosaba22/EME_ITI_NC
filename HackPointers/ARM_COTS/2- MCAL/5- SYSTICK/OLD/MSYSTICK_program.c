/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 SysTick							*/
/* MCu         	:	 Stm32F401CCU6						*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 19, 2023					*/
/* Last Edit   	:	 N/A			   					*/
/* **************************************************** */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "MSYSTICK_interface.h"
#include "MSYSTICK_private.h"
/******************/
u8 G_u8TickClock;
/**************/
static void (*G_pvoidCallBackFunc)(void);
/*************/
u32 G_u32TimeInms; /* used in func Milles */

static volatile u8 G_u8CountMode = MSTK_SINGLE_INTERVAL;

STD_error_t MSTK_stderrInit(u8 ARG_u8ClockSrc)
{	
	STD_error_t L_stderrState = E_OK;
	if( ARG_u8ClockSrc <=1 )
	{
		/* Disable Counter & Clear 3-LSB */
		SYSTICK->CSR &= ~(0x07<<MSTK_BIT_ENABLE);
		/* Choose Clock Source */
		
		SYSTICK->CSR |= (ARG_u8ClockSrc << MSTK_BIT_CLKSOURCE) ;
		
		SYSTICK->CVR=0;
		
		/*	clk in Mhz we have 2 option AHB / 8 or AHB 
		 *	0->AHB/8 **** 1-> AHB  	
		 *	div by 8 like >>3 so XOR the value 0 or 1 
		 *	then we will use 0 option to div by 8 
		 *	1.0/( 16 >> (3*(0^1)) )  --> 1.0/(16>>3) --> 1/2 = 0.5us
		 */
		G_u8TickClock = (u8) ( AHB_CLK >> (3 *(ARG_u8ClockSrc^1)) ); /* in Mhz */
		
	}
	else
	{
		L_stderrState = E_NOK;
	}
	
	return L_stderrState;
}

STD_error_t MSTK_stderrDelayms_IT(void (*ARG_pvoidfuncUserFunction)(void), u16 ARG_u16Delay, u8 ARG_u8Periodic)
{	
	STD_error_t L_stderrState = E_OK;

	if(ARG_pvoidfuncUserFunction != NULL_POINTER )
	{
		G_pvoidCallBackFunc= ARG_pvoidfuncUserFunction;
	
		SYSTICK->RVR= (ARG_u16Delay*TMS_TUS)*G_u8TickClock;/* Load the value of Delay */
	
		SYSTICK-> CSR |= 0x03 ;/* Enable Counter & Interrupt request */
		
		G_u8CountMode = ARG_u8Periodic;
	}
	else
	{
		L_stderrState = E_NULL_POINTER;
	}

	return L_stderrState;	
}

u32 MSTK_u32Millis(void)
{
	return G_u32TimeInms;
}

void MSTK_voidDelayms(u16 ARG_u16Delay)
{	
	SYSTICK->RVR= 2000000;
	SYSTICK->RVR= (u32)((ARG_u16Delay*TMS_TUS)*G_u8TickClock) ;/* Load the value of Delay */
	
	SYSTICK-> CSR|= 1;/* Enable Counter*/
	
	while( ( ( (SYSTICK->CSR )>>16 ) &1) == 0);/* Busy waiting until Counter is zero*/
	
	MSTK_voidStop();
}

void MSTK_voidDelayus(u32 ARG_u32Delayus)
{
	SYSTICK->RVR=ARG_u32Delayus *G_u8TickClock ;/* Load the value of Delay */
	
	SYSTICK->CSR |= 1;/* Enable Counter*/
	
	while( ( ( (SYSTICK->CSR )>>16 ) &1) == 0);/* Busy waiting until Counter is zero*/
	
	MSTK_voidStop();
}
void MSTK_voidStop(void)
{
	SYSTICK->CSR &= ~(3<<0);/* Disable Counter & Disable Interrupt */
	
	SYSTICK->RVR = 0;
	SYSTICK->CVR = 0;
}

void SysTick_Handler(void)
{
	
	if (G_u8CountMode == MSTK_SINGLE_INTERVAL)
	{
		MSTK_voidStop();
	}
	else
	{
		/*MISRA*/
	}
	/* Callback notification */
	G_pvoidCallBackFunc();
	
	G_u32TimeInms++; /* used for return n of ms */
	
	/* wtite any value in VAL Clear interrupt flag */
	SYSTICK->CVR = 0;

}
