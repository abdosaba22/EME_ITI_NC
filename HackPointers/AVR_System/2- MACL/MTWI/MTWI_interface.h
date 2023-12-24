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
	MTWI_STATUS_MASTER_START_CONDITION             = 0x08,
	MTWI_STATUS_MASTER_RSTART_CONDITION            = 0x10,
	MTWI_STATUS_MASTER_TX_SLA_W_ACK                = 0x18,
	MTWI_STATUS_MASTER_TX_SLA_W_NACK               = 0x20,
	MTWI_STATUS_MASTER_TX_DATA_ACK                 = 0x28,
	MTWI_STATUS_MASTER_TX_DATA_NACK                = 0x30,
	MTWI_STATUS_MASTER_TX_SLA_W_OR_DATA_LOST_ARB   = 0x38,
	MTWI_STATUS_MASTER_RX_SLA_R_OR_NACK_LOST_ARB   = 0x38,
	MTWI_STATUS_MASTER_RX_SLA_R_ACK                = 0x40,
	MTWI_STATUS_MASTER_RX_SLA_R_NACK               = 0x48,
	MTWI_STATUS_MASTER_RX_DATA_ACK                 = 0x50,
	MTWI_STATUS_MASTER_RX_DATA_NACK                = 0x58,
	MTWI_STATUS_SLAVE_RX_SLA_W_ACK                 = 0x60,
	MTWI_STATUS_SLAVE_RX_SLA_W_ACK_LOST_ARB        = 0x68,
	MTWI_STATUS_SLAVE_RX_GENERAL_CALL_ACK          = 0x70,
	MTWI_STATUS_SLAVE_RX_GENERAL_CALL_ACK_LOST_ARB = 0x78,
	MTWI_STATUS_SLAVE_RX_SLA_W_DATA_ACK            = 0x80,
	MTWI_STATUS_SLAVE_RX_SLA_W_DATA_NACK           = 0x88,
	MTWI_STATUS_SLAVE_RX_GENERAL_CALL_DATA_ACK     = 0x90,
	MTWI_STATUS_SLAVE_RX_GENERAL_CALL_DATA_NACK    = 0x98,
	MTWI_STATUS_SLAVE_RX_STOP_RSTART               = 0xA0,
	MTWI_STATUS_SLAVE_TX_SLA_R_ACK                 = 0xA8,
	MTWI_STATUS_SLAVE_TX_SLA_R_ACK_LOST_ARB        = 0xB0,
	MTWI_STATUS_SLAVE_TX_DATA_ACK                  = 0xB8,
	MTWI_STATUS_SLAVE_TX_DATA_NACK                 = 0xC0,
	MTWI_STATUS_SLAVE_TX_LAST_DATA_ACK             = 0xC8,
	MTWI_STATUS_NO_RELEVANT_STATE                  = 0xF8,
	MTWI_STATUS_BUS_ERROR_ILLEGAL_START_STOP       = 0x00,
}MTWI_status_t;

#define MTWI_PRESCALER_1			0
#define MTWI_PRESCALER_4			1
#define MTWI_PRESCALER_16			2
#define MTWI_PRESCALER_64			3



STD_error_t MTWI_stderrInit(u16 ARG_u16DataRate, u8 ARG_Prescaler);
void MTWI_voidEnable(void);
void MTWI_voidDisable(void);

void MTWI_voidEnableInterrupt(void);
void MTWI_voidDisableInterrupt(void);

STD_error_t MTWI_stderrSetCallback(void (*ARG_pvoidfUserFunction)(void) );

void MTWI_voidSendStartCondition(void);
void MTWI_voidSendStopCondition(void);

void MTWI_voidEnableAck(void);
void MTWI_voidDisableAck(void);

void MTWI_voidEnableGeneralCall(void);
void MTWI_voidDisableGeneralCall(void);

void MTWI_voidSetSlaveAddress(u8 ARG_u8SlaveAddress);

MTWI_status_t MTWI_twistatusCheckStatus(void);

void MTWI_voidFlagPolling(void);
void MTWI_voidClearFlag(void);

void MTWI_voidLoadTWDR(u8 ARG_u8Data);
char MTWI_voidReadTWDR(void);


void MTWI_voidSendChar(u8 ARG_u8SlaveAddress, char ARG_charChar);
void MTWI_voidSendMultipleChar(u8 ARG_u8SlaveAddress,const char* ARG_ccharpChar);

char MTWI_charSlaveReceive(void); 



#endif