/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MGPIO_interface.h"
#include "HLED_Private.h"
#include "HLED_Interface.h"


void HLED_voidInit(const LED_t * LED_Config)
{
	MGPIO_stderrPinConfig(&LED_Config->LedPin);
	switch(LED_Config->conn_type)
	{
	case LED_SourceConnnec	: MGPIO_stderrSetPinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin,PIN_LOW); break; /* turn off led*/
	case LED_SinkConnec  	: MGPIO_stderrSetPinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin,PIN_HIGH); break;  /* turn off led*/
	default: break;
	}

}

void HLED_voidTurnOn(const LED_t * LED_Config)
{
	switch(LED_Config->conn_type)
	{
	case LED_SourceConnnec	: MGPIO_stderrSetPinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin,PIN_HIGH); break;
	case LED_SinkConnec  	: MGPIO_stderrSetPinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin,PIN_LOW); break;
	default: break;
	}

}

void HLED_voidTurnOff(const LED_t * LED_Config)
{
	switch(LED_Config->conn_type)
	{
	case LED_SourceConnnec	: MGPIO_stderrSetPinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin,PIN_LOW); break; /* turn off led*/
	case LED_SinkConnec  	: MGPIO_stderrSetPinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin,PIN_HIGH); break;  /* turn off led*/
	default: break;
	}
}

void HLED_voidToggle(const LED_t * LED_Config)
{
	MGPIO_stderrTogglePinValue(LED_Config->LedPin.Port,LED_Config->LedPin.Pin);
}
