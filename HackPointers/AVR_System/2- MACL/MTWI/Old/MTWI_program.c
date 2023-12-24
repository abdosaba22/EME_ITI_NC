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

static void (*pvoidfUserCallbackF)(void);


STD_error_t MTWI_stderrInit(u16 ARG_u16DataRate, u8 ARG_Prescaler)
{
	STD_error_t L_stderrState=E_OK;
	
	if(ARG_Prescaler <= 3)
	{
		switch(ARG_Prescaler)
		{
			case MTWI_PRESCALER_1 :	TWBR= ( (F_CPU / ARG_u16DataRate)-16 ) /( 2* 1)  break;
			case MTWI_PRESCALER_4 :	TWBR= ( (F_CPU / ARG_u16DataRate)-16 ) /( 2* 4)  break;
			case MTWI_PRESCALER_16:	TWBR= ( (F_CPU / ARG_u16DataRate)-16 ) /( 2* 16) break;
			case MTWI_PRESCALER_64:	TWBR= ( (F_CPU / ARG_u16DataRate)-16 ) /( 2* 64) break;
			default : L_stderrState=E_NOK; break;
		}
		// TWBR = ( (F_CPU / ARG_u16DataRate)-16 ) /( 2* 4<<ARG_Prescaler) ; 
		TWSR = ( TWSR & 0xFC ) | (ARG_Prescaler);
	}
	else 
	{
		L_stderrState=E_NOK;
	}
	return L_stderrState;
	
}

void MTWI_voidEnable(void)
{
	//set bit
	SET_BIT(TWCR,TWCR_TWEN);
}
void MTWI_voidDisable(void)
{
	// clear bit
	CLEAR_BIT(TWCR,TWCR_TWEN);
}

void MTWI_voidEnableInterrupt(void)
{
	SET_BIT(TWCR,TWCR_TWIE);
}
void MTWI_voidDisableInterrupt(void)
{
	CLEAR_BIT(TWCR,TWCR_TWIE);
}

void MTWI_voidEnableAck(void)
{
	SET_BIT(TWCR,TWCR_TWEA);
}
void MTWI_voidDisableAck(void)
{
	CLEAR_BIT(TWCR,TWCR_TWEA);
}

void MTWI_voidEnableGeneralCall(void)
{
	SET_BIT(TWAR,TWAR_TWGCE);
}
void MTWI_voidDisableGeneralCall(void)
{
	CLEAR_BIT(TWAR,TWAR_TWGCE);
}

void MTWI_voidSetSlaveAddress(u8 ARG_u8SlaveAddress)
{
	/* assign the device address */
	TWAR = (TWAR & 0x01) | (ARG_u8SlaveAddress << 1);  
}

MTWI_status_t MTWI_twistatusCheckStatus(void)
{
	return (TWSR & STATUS_BITS_MASK); // return TWI Status only 5-MSB in TWSR 
}

STD_error_t MTWI_stderrSetCallback(void (*ARG_pvoidfUserFunction)(void) )
{
	STD_error_t L_stderrState=E_OK;
	// assign call back func if not NULL
	if( NULL_POINTER == pvoidfUserCallbackF)
	{
		pvoidfUserCallbackF = ARG_pvoidfUserFunction;
	}
	else
	{
		L_stderrState=E_NULL_POINTER;
	}
	return L_stderrState;
}

void MTWI_voidFlagPolling(void)
{
	/* Wait Until the TWINT Flag is Raised Again */
	while( 0==GET_BIT( TWCR , TWCR_TWINT ) ) ;
}
void MTWI_voidClearFlag(void)
{
	SET_BIT(TWCR,TWCR_TWINT);
}

TWI_ErrorStatus_t TWI_twierrSendStartCondition(void)
{
	TWI_ErrorStatus_t L_twierrError = NoError;

	/*Set start condition bit*/
	SET_BIT(TWCR, TWCR_TWSTA);

	MTWI_voidClearFlag();
	MTWI_voidFlagPolling();

	/*Check the status of the bus*/
	if( MTWI_twistatusCheckStatus()!= START_ACK)
	{
		L_twierrError = StartCondErr;
	}
	else
	{
		/*Do nothing*/
	}

	return L_twierrError;
}

TWI_ErrorStatus_t TWI_twierrSendRepeatedStart(void)
{
	TWI_ErrorStatus_t L_twierrError = NoError;

	/*Set start condition bit*/
	SET_BIT(TWCR, TWCR_TWSTA);

	MTWI_voidClearFlag();
	MTWI_voidFlagPolling();

	/*Check the status of the bus*/
	if(MTWI_twistatusCheckStatus()!= REP_START_ACK)
	{
		L_twierrError = RepStartErr;
	}
	else
	{
		/*Do nothing*/
	}

	return L_twierrError;
}

TWI_ErrorStatus_t TWI_twierrSendSlaveAdressWithWrite(uint8 ARG_u8SlaveAddress)
{
	TWI_ErrorStatus_t L_twierrError = NoError;

	/*Set the slave address into the data register*/
	TWDR = ARG_u8SlaveAddress << 1u ;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	MTWI_voidClearFlag();
	MTWI_voidFlagPolling();
	
	/*Check the status of the bus*/
	if(MTWI_twistatusCheckStatus()!= SLAVE_ADD_AND_WR_ACK)
	{
		L_twierrError = SlaveAddressWithWriteErr;
	}
	else
	{
		/*Do nothing*/
	}

	return L_twierrError;

}

TWI_ErrorStatus_t TWI_twierrSendSlaveAdressWithRead(uint8 ARG_u8SlaveAddress)
{
	TWI_ErrorStatus_t L_twierrError = NoError;

	/*Set the slave address into the data register*/
	TWDR = (ARG_u8SlaveAddress << 1u) | 1 ;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	MTWI_voidClearFlag();
	MTWI_voidFlagPolling();
	
	/*Check the status of the bus*/
	if(MTWI_twistatusCheckStatus()!= SLAVE_ADD_AND_RD_ACK)
	{
		L_twierrError = SlaveAddressWithReadErr;
	}
	else
	{
		/*Do nothing*/
	}

	return L_twierrError;

}

TWI_ErrorStatus_t TWI_twierrMstrWriteDataByte(uint8 ARG_u8Data )
{
	TWI_ErrorStatus_t L_twierrError = NoError;

	/*Put the data byte on the bus*/
	TWDR = ARG_u8Data ;

	MTWI_voidClearFlag();
	MTWI_voidFlagPolling();
	
	/*Check the status of the bus*/
	if(MTWI_twistatusCheckStatus()!= MSTR_WR_BYTE_ACK)
	{
		L_twierrError = MstrWriteByteWithAckErr;
	}
	else
	{
		/*Do nothing*/
	}

	return L_twierrError;
}

TWI_ErrorStatus_t TWI_twierrMstrReadDataByte(uint8_t* ARG_u8Data )
{
	TWI_ErrorStatus_t L_twierrError = NoError;

	if(ARG_u8Data != NULL_POINTER)
	{
		MTWI_voidClearFlag();
		MTWI_voidFlagPolling();

		/*Check the status of the bus*/
		if(MTWI_twistatusCheckStatus() != MSTR_RD_BYTE_WITH_ACK)
		{
			L_twierrError = MstrReadByteWithAck;
		}
		else
		{
			/*Read the data sent from slave*/
			*ARG_u8Data = TWDR;
		}
	}
	else
	{
		L_twierrError = NullPtrErr;
	}

	return L_twierrError;
}


TWI_ErrorStatus TWI_twierrSlaveReadDataByte( u8 * ARG_pu8DataReceived )
{
	TWI_ErrorStatus Local_ErrorStatus = NoError ;

	MTWI_voidClearFlag();
	MTWI_voidFlagPolling();
	
	if( MTWI_twistatusCheckStatus() != SLAVE_DATA_RECEIVED )
	{
		Local_ErrorStatus = SlaveReadByteError ;
	}
	else
	{
		*ARG_pu8DataReceived = TWDR ;
	}
	
	return Local_ErrorStatus ;
}

void TWI_voidSendStopCondition(void)
{
	/*Set the stop condition bit*/
	SET_BIT(TWCR, TWCR_TWSTO);

	/*Clear interrupt flag to enable previous action to happen*/
	SET_BIT(TWCR, TWCR_TWINT);
}