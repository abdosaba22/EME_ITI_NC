/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : UART				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 24, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

#ifndef _MUART_INTERFACE_H_
#define _MUART_INTERFACE_H_

 
#define MUART_DATABITS_5            	0
#define MUART_DATABITS_6				1
#define MUART_DATABITS_7				2
#define MUART_DATABITS_8				3
#define MUART_DATABITS_9				7

#define MUART_PARITY_NONE				(0<<4)
#define MUART_PARITY_EVEN				(2<<4)
#define MUART_PARITY_ODD				(3<<4)

#define MUART_STOPBITS_1				(0<<3)
#define MUART_STOPBITS_2				(1<<3)


#define MUART_INTERRUPT_RXC		        7
#define MUART_INTERRUPT_TXC		        6
#define MUART_INTERRUPT_UDR_EMPTY       5



STD_error_t MUART_stderrInit(u32 ARG_u32BaudRate, u8 ARG_u8DataBits, u8 ARG_u8Parity , u8 ARG_u8StopBits);

void MUART_voidEnableTX(void);
void MUART_voidDisableTX(void);
void MUART_voidEnableRX(void);
void MUART_voidDisableRX(void);

void MUART_voidTxFlagPolling(void);
void MUART_voidRXFlagPolling(void);
void MUART_voidUDREFlagPolling(void);

void MUART_voidSendChar(char ARG_charChar);
void MUART_voidSendString(const char* ARG_charpString);

char MUART_charReceiveChar();
void MUART_voidReceiveStringUntil(char* ARG_charpString , char ARG_charTerminator);

STD_error_t MUART_stderrEnableInterrupt(u8 ARG_u8InterruptSource);
STD_error_t MUART_stderrDisableInterrupt(u8 ARG_u8InterruptSource);
STD_error_t MUART_stderrSetCallback(void(*ARG_pvoidfUserFunction)(void),u8 ARG_u8InterruptSource);

#endif
