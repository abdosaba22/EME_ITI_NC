/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : TWI				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 29, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

#ifndef _MTWI_INTERFACE_H_
#define _MTWI_INTERFACE_H_

typedef enum
{
	START_ACK              = 0x08, /* start has been sent */
	REP_START_ACK          = 0x10, /* repeated start */
	SLAVE_ADD_AND_WR_ACK   = 0x18, /* Master transmit ( slave address + Write request ) ACK */
	SLAVE_ADD_AND_RD_ACK   = 0x40, /* Master transmit ( slave address + Read request ) ACK */
	MSTR_WR_BYTE_ACK       = 0x28, /* Master transmit data ACK */
	MSTR_RD_BYTE_WITH_ACK  = 0x50, /* Master received data with ACK */
	MSTR_RD_BYTE_WITH_NACK = 0x58, /* Master received data with not ACK */
	SLAVE_ADD_RCVD_RD_REQ  = 0xA8, /* means that slave address is received with read request */
	SLAVE_ADD_RCVD_WR_REQ  = 0x60, /* means that slave address is received with write request */
	SLAVE_DATA_RECEIVED    = 0x80, /* means that a byte is received */
	SLAVE_BYTE_TRANSMITTED = 0xB8, /* means that the written byte is transmitted */

}MTWI_status_t;


typedef enum
{
	NoError,
	NullPtrErr,
	StartCondErr,
	RepStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MstrWriteByteWithAckErr,
	MstrReadByteWithAck
	
}TWI_ErrorStatus_t;


STD_error_t MTWI_stderrInit(u16 ARG_u16DataRate, u8 ARG_Prescaler);
void MTWI_voidEnable(void);
void MTWI_voidDisable(void);

void MTWI_voidEnableInterrupt(void);
void MTWI_voidDisableInterrupt(void);

STD_error_t MTWI_stderrSetCallback(void (*ARG_pvoidfUserFunction)(void) );

void MTWI_voidEnableAck(void);
void MTWI_voidDisableAck(void);

void MTWI_voidEnableGeneralCall(void);
void MTWI_voidDisableGeneralCall(void);

void MTWI_voidSetSlaveAddress(u8 ARG_u8SlaveAddress);

MTWI_status_t MTWI_twistatusCheckStatus(void);

void MTWI_voidFlagPolling(void);
void MTWI_voidClearFlag(void);


TWI_ErrorStatus_t TWI_SendStartCondition(void);

TWI_ErrorStatus_t TWI_SendRepeatedStart(void);

TWI_ErrorStatus_t TWI_SendSlaveAdressWithWrite(uint8 Copy_u8SlaveAddress);

TWI_ErrorStatus_t TWI_SendSlaveAdressWithRead(uint8 Copy_u8SlaveAddress);

TWI_ErrorStatus_t TWI_MstrWriteDataByte(uint8 Copy_u8DataByte);

TWI_ErrorStatus_t TWI_MstrReadDataByte(uint8* Copy_u8DataByte);

TWI_ErrorStatus TWI_twierrSlaveReadDataByte( u8 * ARG_pu8DataReceived );

void TWI_SendStopCondition(void);

#endif