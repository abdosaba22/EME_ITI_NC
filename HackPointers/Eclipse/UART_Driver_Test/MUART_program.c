/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : UART				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 24, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "MUART_private.h"
#include "MUART_interface.h"


void (*MUART_pvoidfUserFunctionRxC)(void) = NULL_POINTER;
void (*MUART_pvoidfUserFunctionTxC)(void) = NULL_POINTER;
void (*MUART_pvoidfUserFunctionUDREmpty)(void) = NULL_POINTER;

STD_error_t MUART_stderrInit(u32 ARG_u32BaudRate, u8 ARG_u8DataBits, u8 ARG_u8Parity , u8 ARG_u8StopBits)
{
	STD_error_t L_stderrState = E_OK;	
	if( ((ARG_u8DataBits <=3)||(7==ARG_u8DataBits )) && ( (0==ARG_u8Parity)||(32==ARG_u8Parity)||(48==ARG_u8Parity) ) && ((8==ARG_u8StopBits)||(0==ARG_u8StopBits))  )
	{
		u16 L_u16UBRR = (F_CPU/ (16 * ARG_u32BaudRate)) - 1 ; /* Calc the value needed to generate the needed baud rate */
		UBRRL = (u8 ) L_u16UBRR;  /* write the 8-LSB in UBRRL */
		UBRRH = (u8 )(L_u16UBRR >> 8) & 0x0F; /* write the 4-MSB in UBRRH and URSEL = 0  in the same cycle */ 
		/* URSEL =1 to choose UCSRC ,then write 2-LSB of DATASIZE UCSZ0, Parity , StopBits */
		UCSRC = (1 << URSEL) | ( (UCSRC & 0xC1) | ((ARG_u8DataBits & 0x03) << UCSZ0) )  | ARG_u8Parity | ARG_u8StopBits   ; 
		
		UCSRB = (UCSRB & 0xFB) | (ARG_u8DataBits & 0x04) ; /* write the 3rd bit in DATASIZE in bit UCSZ2 */ 
	}
	else
	{
		L_stderrState = E_NOK;
	}
	return L_stderrState;
}

void MUART_voidEnableTX(void){
	SET_BIT(UCSRB,TXEN);
}
void MUART_voidDisableTX(void){
	//MUART_voidTxFlagPolling();
	CLEAR_BIT(UCSRB,TXEN);
}

void MUART_voidEnableRX(void)
{
	SET_BIT(UCSRB,RXEN);
}
void MUART_voidDisableRX(void)
{
	MUART_voidRXFlagPolling();
	CLEAR_BIT(UCSRB,RXEN);
}

void MUART_voidTxFlagPolling(void)
{
	while(!GET_BIT(UCSRA, TXC));
}
void MUART_voidRXFlagPolling(void)
{
	while(!GET_BIT(UCSRA,RXC));
}
void MUART_voidUDREFlagPolling(void)
{
	while(!GET_BIT(UCSRA,UDRE));
}

void MUART_voidSendChar(char ARG_charChar)
{
	MUART_voidUDREFlagPolling();
	UDR =ARG_charChar;
	
}
void MUART_voidSendString(const char* ARG_charpString)
{
	u32 Lu32i=0;
	do{
		MUART_voidSendChar(ARG_charpString[Lu32i]);
		Lu32i++;
	}while(ARG_charpString[Lu32i] !='\0');
	
}

char MUART_charReceiveChar(){
	MUART_voidRXFlagPolling();
	return UDR;
}

void MUART_voidReceiveStringUntil(char* ARG_charpString , char ARG_charTerminator)
{
	u32 Lu32i=0;
	// do
	// {
		// ARG_charpString[Lu32i]=MUART_voidRecieveChar();
		// Lu32i++;
	// }while(ARG_charpString[Lu32i-1]!=ARG_charTerminator);
	// ARG_charpString[Lu32i-1] = '\0';
	
	while(ARG_charpString[Lu32i] !=ARG_charTerminator){
		ARG_charpString[Lu32i] = MUART_charReceiveChar();
		Lu32i++;
	}
	ARG_charpString[Lu32i]='\0';	
}

STD_error_t MUART_stderrEnableInterrupt(u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8InterruptSource <8 && ARG_u8InterruptSource > 4)
	{
		SET_BIT(UCSRB, ARG_u8InterruptSource);	
	}
	else
	{
		L_stderrStatus = E_NOK ;	
	} 
	return L_stderrStatus ;		
}

STD_error_t MUART_stderrDisableInterrupt(u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrStatus = E_OK ;
	if(ARG_u8InterruptSource <8 && ARG_u8InterruptSource > 4)
	{
		CLEAR_BIT(UCSRB, ARG_u8InterruptSource);	
	}
	else
	{
		L_stderrStatus = E_NOK ;	
	} 
	return L_stderrStatus ;
}

STD_error_t MUART_stderrSetCallback(void(*ARG_pvoidfUserFunction)(void),u8 ARG_u8InterruptSource)
{	
	STD_error_t L_stderrStatus = E_OK ; 
	switch(ARG_u8InterruptSource)
	{
		case MUART_INTERRUPT_RXC		: MUART_pvoidfUserFunctionRxC  = ARG_pvoidfUserFunction ; break ; 
		case MUART_INTERRUPT_TXC		: MUART_pvoidfUserFunctionTxC  = ARG_pvoidfUserFunction ; break ; 
		case MUART_INTERRUPT_UDR_EMPTY  : MUART_pvoidfUserFunctionUDREmpty = ARG_pvoidfUserFunction ; break ;
		default : L_stderrStatus = E_NOK ; break ;  
	}

	return L_stderrStatus ;	
}





void __vector_13(void) __attribute__ ((signal));
void __vector_13(void) 
{
	(*MUART_pvoidfUserFunctionRxC)();
}
void __vector_14(void) __attribute__ ((signal));
void __vector_14(void) 

{
	(*MUART_pvoidfUserFunctionTxC)();

}
void __vector_15(void) __attribute__ ((signal));
void __vector_15(void) 
{
	(*MUART_pvoidfUserFunctionUDREmpty)();

}
