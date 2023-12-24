/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: user
 */


#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MGIE_Interface.h"
#include "MDIO_interface.h"
#include "MTIM_Interface.h"

void Toggle_Led(void);
int main (void)
{

	MDIO_stderrSetPinDirection(MDIO_PORTA,0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,1,MDIO_OUTPUT);
	MTIM_stderrInit(MTIM_TIMER0, MTIM_CS_PRESCALER_1024,MTIM_MODE_NORMAL,MTIM_HWPIN_DISCONNECTED);
	MTIM_stderrSetCallBack(&Toggle_Led, MTIM_INTERRUPT_T0_OVF);
	MTIM_stderrEnableInterrupt(MTIM_INTERRUPT_T0_OVF);
	MGIE_voidEnable();
	MTIM_stderrTimerDelay(MTIM_TIMER0, 1000);
	MTIM_stderrStartTimer(MTIM_TIMER0);


	while(1)
	{

	}
	return 0 ;
}


void Toggle_Led(void)
{
	static u8 x = 0 ;
	if(x==0)
	{
		MDIO_stderrSetPinValue(MDIO_PORTA, 1 , MDIO_HIGH);
		MDIO_stderrSetPinValue(MDIO_PORTA, 0 , MDIO_LOW);
		x = 1 ;

	}
	else if(x==1)
	{
		MDIO_stderrSetPinValue(MDIO_PORTA, 0 , MDIO_HIGH);
		MDIO_stderrSetPinValue(MDIO_PORTA, 1 , MDIO_LOW);
		x=0 ;

	}

}
