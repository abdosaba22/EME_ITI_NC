/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : TWI				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 29, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MTWI_private.h"
#include "MTWI_interface.h"


static void (*MTWI_pvoidfUserFunction)(void) = NULL_POINTER ;


STD_error_t MTWI_stderrInit(u32 ARG_u32DataRate, u8 ARG_u8Prescalar)
{
	STD_error_t L_stderrStatus = E_OK ;
	switch(ARG_u8Prescalar)
	{
		case MTWI_PRESCALER_1 : TWBR = ((F_CPU/ARG_u32DataRate) - 16) / (2 * 1 ); break ;
		case MTWI_PRESCALER_4 : TWBR = ((F_CPU/ARG_u32DataRate) - 16) / (2 * 4 ); break ;
		case MTWI_PRESCALER_16: TWBR = ((F_CPU/ARG_u32DataRate) - 16) / (2 * 16); break ;
		case MTWI_PRESCALER_64: TWBR = ((F_CPU/ARG_u32DataRate) - 16) / (2 * 64); break ;
		default : L_stderrStatus = E_NOK  ; break ;
	}
	// TWBR = ( (F_CPU / ARG_u16DataRate)-16 ) /( 2* 4<<ARG_Prescaler) ;
	if(ARG_u8Prescalar<=3)
	{
	TWSR = (TWSR & 0xFC) | (ARG_u8Prescalar) ; 
	}
	else
	{
		L_stderrStatus = E_NOK ;
	}
	
	return L_stderrStatus ; 
	
}

void 		MTWI_voidEnable()
{
			SET_BIT(TWCR, TWEN);
}
void 		MTWI_voidDisable()
{
			CLEAR_BIT(TWCR, TWEN);
}

void 		MTWI_voidInterrupt()
{
			SET_BIT(TWCR, TWIE);

}
void 		MTWI_voidDisableInterrupt()
{
			CLEAR_BIT(TWCR, TWIE);

}

STD_error_t MTWI_stderrSetCallback(void(*ARG_pvoidfUserFunction)(void))
{
	STD_error_t  L_stderrStatus = E_OK ; 
	if(ARG_pvoidfUserFunction== NULL_POINTER)
	{
		MTWI_pvoidfUserFunction = ARG_pvoidfUserFunction;
	}
	else
	{
		L_stderrStatus = E_NOK ; 
	}
	return L_stderrStatus ; 
}

void 		MTWI_voidSendStartCondition(void)
{
			TWCR = (TWCR & (0x5F)) | (1<< TWINT) | (1<< TWSTA) ;
}
void 		MTWI_voidSendStopCondition(void)
{
			TWCR = (TWCR & (0x6F)) | (1<< TWINT) | (1<< TWSTO) ;
}


void 		MTWI_voidEnableAck(void)
{
			SET_BIT(TWCR,TWEA);
}
void 		MTWI_voidDisableAck(void)
{
			CLEAR_BIT(TWCR,TWEA);
}

void 		MTWI_voidEnableGeneralCall(void)
{
			SET_BIT(TWAR, TWGCE);
}
void 		MTWI_voidDisableGeneralCall(void)
{
			CLEAR_BIT(TWAR, TWGCE);
}

void 		MTWI_voidSetSlaveAddress(u8 ARG_u8SlaveAddress)
{
			TWAR = (TWAR & 0x01)  | (ARG_u8SlaveAddress << 1 ) ; 
}

MTWI_status_t	MTWI_twistatusCheckStatus(void)
{
		return (TWSR & TWS_MASK) ; 
}

void 		MTWI_voidFlagPolling(void)
{
			while(!GET_BIT(TWCR, TWINT));
}
void 		MTWI_voidClearFlag(void)
{
			TWCR = (TWCR & 0x4F) | (1<<TWINT); // set bit
}

void 		MTWI_voidLoadTWDR(u8 ARG_u8Data)
{
			TWDR = ARG_u8Data ; 
}
char 		MTWI_charReadTWDR(void)
{
			return TWDR ; 
}

void 		MTWI_voidSendChar(u8 ARG_u8SlaveAddress, char ARG_charChar)
{
	
		MTWI_voidSendStartCondition();	
		MTWI_voidFlagPolling();
		if(MTWI_STATUS_MASTER_START_CONDITION == MTWI_twistatusCheckStatus())
		{
			/* we want to load the slave address + the read/write bit so we take the slave address which is 7 bit */
			MTWI_voidLoadTWDR(((ARG_u8SlaveAddress<<1) & (0xFE)) | (0x00)); /*  sheft always shift with 0 there is no need to clear bit 0 */
			MTWI_voidClearFlag();
			MTWI_voidFlagPolling();
			/*after sending the slave address with the read/write bit we check the status*/
			if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
				{
					MTWI_voidLoadTWDR(ARG_charChar);
					MTWI_voidClearFlag();
					MTWI_voidFlagPolling();
					if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
					{
						MTWI_voidSendStopCondition();
					}
				}
		}
		else
		{
			
		}
		
		
}
void 		MTWI_voidSendMultiple(u8 ARG_u8SlaveAddress, const char* ARG_cchar)
{	
		u16 L_u16Counter = 0 ;
		MTWI_voidSendStartCondition();	
		MTWI_voidFlagPolling();
		if(MTWI_STATUS_MASTER_START_CONDITION == MTWI_twistatusCheckStatus())
		{
			/*Load the twdr before clearing the flag because once you clear the flag the data in twdr is sent */
			MTWI_voidLoadTWDR(((ARG_u8SlaveAddress<<1) & (0xFE)) | (0x00));
			MTWI_voidClearFlag();
			MTWI_voidFlagPolling();
			/*after sending the slave address with the read/write bit we check the status*/
			if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
			{
				do
				{
					MTWI_voidLoadTWDR(ARG_cchar[L_u16Counter]);
					MTWI_voidClearFlag();
					MTWI_voidFlagPolling();
					L_u16Counter++;
				}while((MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus()) && (ARG_cchar[L_u16Counter]!= '\0'));

				MTWI_voidSendStopCondition();
			}
	
		}	
		else
		{
			
		}
		
}
char		MTWI_charSlaveRecieve(void)
{
		u8 L_u8Data = 0 ;
		MTWI_voidFlagPolling();
		if(MTWI_STATUS_SLAVE_RX_SLA_W_ACK == MTWI_twistatusCheckStatus())
		{
			MTWI_voidClearFlag();
			MTWI_voidFlagPolling();
			if(MTWI_STATUS_SLAVE_RX_SLA_W_DATA_ACK == MTWI_twistatusCheckStatus())
			{
				L_u8Data = MTWI_charReadTWDR (); 
				MTWI_voidClearFlag();
				MTWI_voidFlagPolling();
				if(MTWI_STATUS_SLAVE_RX_STOP_RSTART == MTWI_twistatusCheckStatus())
				{
					MTWI_voidClearFlag();
				}
				
			}
		}
		return L_u8Data ; 
} 
