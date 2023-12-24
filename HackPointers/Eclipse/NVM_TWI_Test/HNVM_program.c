/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : EPROM				                */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : September 4, 2023                  */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MTWI_interface.h"
#include "HNVM_interface.h"
#include "HNVM_private.h"
#include "HNVM_config.h"







STD_error_t	HNVM_stderrInit(void)
{
	STD_error_t L_stderrStatus = E_OK ;
	L_stderrStatus =MTWI_stderrInit(HNVM_BIT_RATE,HNVM_PRESCALER);
	MTWI_voidEnable();
	return L_stderrStatus;
}

void		HNVM_voidWrite(u16 ARG_u16Address, u8 ARG_u8Data)
{
	u8 L_u8SlaveAddress = (HNVM_FIXED_ADDRESS) | (HNVM_A2_CONNECTION<< 2 ) | (u8)(ARG_u16Address>>8);
	MTWI_voidSendStartCondition();
	MTWI_voidFlagPolling();
	if(MTWI_STATUS_MASTER_START_CONDITION == MTWI_twistatusCheckStatus())
	{
		MTWI_voidLoadTWDR( (L_u8SlaveAddress<<1) );
		MTWI_voidClearFlag();
		MTWI_voidFlagPolling();
		if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
	   	{
			MTWI_voidLoadTWDR( (u8)ARG_u16Address );
			MTWI_voidClearFlag();
			MTWI_voidFlagPolling();
			if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
			{
				MTWI_voidLoadTWDR(ARG_u8Data);
				MTWI_voidClearFlag();
				MTWI_voidFlagPolling();
				if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
				{
					MTWI_voidSendStopCondition();
				}
			}

		}

	}
	
}

u8			HNVM_u8Read(u16 ARG_u16Address)
{


	u8 L_u8Data ;
	u8 L_u8SlaveAddress = (HNVM_FIXED_ADDRESS) | (HNVM_A2_CONNECTION<< 2 ) | (u8)(ARG_u16Address>>8);
	MTWI_voidSendStartCondition();
	MTWI_voidFlagPolling();
	if(MTWI_STATUS_MASTER_START_CONDITION == MTWI_twistatusCheckStatus())
	{
		MTWI_voidLoadTWDR( (L_u8SlaveAddress<<1) );
		MTWI_voidClearFlag();
		MTWI_voidFlagPolling();
		if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
	   	{
			MTWI_voidLoadTWDR( (u8)ARG_u16Address );
			MTWI_voidClearFlag();
			MTWI_voidFlagPolling();
			if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
			{
				MTWI_voidSendStartCondition();
				MTWI_voidFlagPolling();
				if(MTWI_STATUS_MASTER_RSTART_CONDITION == MTWI_twistatusCheckStatus())
				{
					MTWI_voidLoadTWDR(  ((L_u8SlaveAddress<<1) | 1u)  ); /* SLA + R */
					MTWI_voidClearFlag();
					MTWI_voidFlagPolling();
					if(MTWI_STATUS_MASTER_RX_SLA_R_ACK == MTWI_twistatusCheckStatus())
					{
						MTWI_voidClearFlag();
						MTWI_voidFlagPolling();
						if(MTWI_STATUS_MASTER_RX_DATA_NACK == MTWI_twistatusCheckStatus() )
						{
							L_u8Data = MTWI_charReadTWDR();
 							MTWI_voidSendStopCondition();
						}

					}

				}
				
			}

		}
	
	}
	return L_u8Data;
}
