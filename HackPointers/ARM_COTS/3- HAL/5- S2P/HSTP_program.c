/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 Serial to Parallel					*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 25, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC includes */
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"

#include "HSTP_interface.h"
#include "HSTP_private.h"
#include "HSTP_config.h"

void HSTP_voidInit(void)
{
	/* Config pins of STP */
	MGPIO_CONFIG_t L_configSTP_Pins = {
		.Port=HSTP_PORT, 
		.Pin = HSTP_SERIAL_DATA_PIN,
		.Mode=OUTPUT,
		.Speed=LOW,
		.OutputType= PUSH_PULL,
		.PullType= NOPULL,
	};
	MGPIO_stderrPinConfig(&L_configSTP_Pins);
	L_configSTP_Pins.Pin = HSTP_SHIFT_CLOCK_PIN; /* reAssign the Pin */
	MGPIO_stderrPinConfig(&L_configSTP_Pins);
	L_configSTP_Pins.Pin = HSTP_STORE_DATA_PIN; /* reAssign the Pin */
	MGPIO_stderrPinConfig(&L_configSTP_Pins);
	
}


void HSTP_voidSendSynchronus(u16 ARG_u8DataToSend, u8 ARG_u8NumOfECU)
{
	
	/* send bit by bit starting from MSb (Most S bit) */
	s8 L_s8Counter = (ARG_u8NumOfECU * 8) - 1;
	u8 L_u8Bit;
	
	for( ; Local_s8Counter >= 0; Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(ARG_u8DataToSend,Local_s8Counter);
		
		MGPIO_voidSetPinValue(HSTP_PORT, HSTP_SERIAL_DATA_PIN, Local_u8Bit);
		
		/* Send PULSE to Shift Clock */
		MGPIO_voidSetPinValue(HSTP_PORT, HSTP_SHIFT_CLOCK_PIN, GPIO_HIGH);
		MSTK_voidSetBusyWait(2);
		MGPIO_voidSetPinValue(HSTP_PORT, HSTP_SHIFT_CLOCK_PIN, GPIO_LOW);
		MSTK_voidSetBusyWait(2);
	}
	
	/* Send PULSE to Storge Clock */
	MGPIO_voidSetPinValue(HSTP_PORT, HSTP_STORE_DATA_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(2);
	MGPIO_voidSetPinValue(HSTP_PORT, HSTP_STORE_DATA_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2);
}