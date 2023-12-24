/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *
 */



#define F_CPU 8000000UL

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MTIM_interface.h"
#include "MGIE_interface.h"

void OS_voidTaskToggleLED1(void);

int main(void)
{
	MDIO_stderrSetPinDirection(MDIO_PORTA,0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,1,MDIO_OUTPUT);
	MTIM_stderrInit(MTIM_TIMER0, MTIM_CS_PRESCALER_64, MTIM_MODE_CTC ,MTIM_HWPIN_DISCONNECTED);
	MTIM_stderrSetOCR(MTIM_TIMER0,124);
	MTIM_stderrSetCallBack(OS_voidTaskToggleLED1,  MTIM_INTERRUPT_T0_OCM );
	MTIM_stderrEnableInterrupt(MTIM_INTERRUPT_T0_OCM);
	MGIE_voidEnableGI();
	MTIM_stderrStartTimer(MTIM_TIMER0);
//	MDIO_stderrTogglePinValue(MDIO_PORTA,0);
	while(1);
	return 0;
}
void OS_voidTaskToggleLED1(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,0);
}
