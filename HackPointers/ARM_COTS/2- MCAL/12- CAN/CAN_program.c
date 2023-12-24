/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 CAN								*/
/* MCu         	:	 Stm32F446RE						*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 2, 2023					*/
/* Last Edit   	:	 N/A								*/
/* **************************************************** */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "MCAN_interface.h"
#include "MCAN_private.h"

// Configure GPIO pins for CAN (you need to define your GPIO configuration here)
// Enable the GPIO clocks, set pins as alternate function, etc.


/* array of 3 pointers to struct Reg def */
static MCAN_REGDEF_t *MCAN_pArr[2] = {CAN1, CAN2};

STD_error_t MCAN_stderrInit(CAN_Config_t* ARG_pconfigConfig) 
{    
    STD_error_t L_stderrState = E_OK;
	
	if( NULL_POINTER != ARG_pconfigConfig)
	{
		// Configure CAN peripheral registers
		MCAN_pArr[ARG_pconfigConfig -> CanNum ] -> MCR |= CAN_MCR_INRQ; // Request initialization mode
	
		// Set the CAN configuration parameters based on the config struct
		MCAN_pArr[ARG_pconfigConfig -> CanNum ] -> BTR = ( ARG_pconfigConfig -> Prescaler << 0 ) | ( ARG_pconfigConfig -> TimeSeg1 << 16) | (ARG_pconfigConfig->TimeSeg2   << 20) | (ARG_pconfigConfig->SyncJumpWidth << 24) |
					( ARG_pconfigConfig -> TimeTriggeredMode << 2 	) | ( ARG_pconfigConfig -> AutoBusOff << 		10) | (ARG_pconfigConfig->AutoWakeUp << 11) |
					( ARG_pconfigConfig -> AutoRetransmission << 9	) | ( ARG_pconfigConfig -> ReceiveFifoLocked << 7 ) |
					( ARG_pconfigConfig -> TransmitFifoPriority << 8);
	
		// Exit initialization mode
		MCAN_pArr[ARG_pconfigConfig -> CanNum ] -> MCR &= ~CAN_MCR_INRQ;
	
		// Enable the CAN peripheral
		MCAN_pArr[ARG_pconfigConfig -> CanNum ] -> MCR |= CAN_MCR_SLEEP; // Exit sleep mode (if it was in sleep mode)
		MCAN_pArr[ARG_pconfigConfig -> CanNum ] -> MCR |= CAN_MCR_TXFP;  // Transmit FIFO priority (optional)
	}
	else
	{
		L_stderrState = E_NULL_POINTER;
	}
	
	return L_stderrState;
}


void MCAN_voidTransmit(u32 id, u32* data, u32 length)
{
	
}
void MCAN_voidReceive(u32* id, u32* data, u32* length)
{
	
}
void MCAN_voidErrorHandler(void)
{
	
}
