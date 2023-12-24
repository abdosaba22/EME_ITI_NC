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

#include "OS_interface.h"

void OS_voidTaskToggleLED1(void);
void OS_voidTaskToggleLED2(void);
void OS_voidTaskToggleLED3(void);
void OS_voidTaskToggleLED4(void);

void LEDSinit(void);

int main(void)
{
	LEDSinit();

	OS_stderrCreateTask(OS_voidTaskToggleLED1, 500 , 0);
	OS_stderrCreateTask(OS_voidTaskToggleLED2, 500 , 1);
	OS_stderrCreateTask(OS_voidTaskToggleLED3, 1000, 2);
	OS_stderrCreateTask(OS_voidTaskToggleLED4, 1000, 3);

	OS_stderrActivateTask(0);
	OS_stderrActivateTask(1);
	OS_stderrActivateTask(2);
	OS_stderrActivateTask(3);

	OS_voidStartOS();

	while(1);
	return 0;
}

void LEDSinit(void)
{
	MDIO_stderrSetPinDirection(MDIO_PORTA,0,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,1,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,2,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(MDIO_PORTA,3,MDIO_OUTPUT);
}
void OS_voidTaskToggleLED1(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,0);
}
void OS_voidTaskToggleLED2(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,1);
}

void OS_voidTaskToggleLED3(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,2);
}
void OS_voidTaskToggleLED4(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTA,3);
}
