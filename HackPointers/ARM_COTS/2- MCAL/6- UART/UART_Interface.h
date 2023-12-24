/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : USART 				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : September 10, 2023                 */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

#ifndef _MUSART_INTERFACE_H_
#define _MUSART_INTERFACE_H_

/* Possible options for USART_Mode */
typedef enum
{
							/*    TE RE */
	USART_MODE_ONLY_RX = 1, /* 0b 0  1  */
	USART_MODE_ONLY_TX ,	/* 0b 1  0  */
	USART_MODE_TXRX 		/* 0b 1  1  */
}USART_Mode_t;

/* Possible options for USART_Baud */
typedef enum{
	USART_BAUD_1200 = 1200,
	USART_BAUD_2400 = 2400,
	USART_BAUD_9600 = 9600,
	USART_BAUD_19200 = 19200,
	USART_BAUD_38400 = 38400,
	USART_BAUD_57600 = 57600,
	USART_BAUD_115200 = 115200,
	USART_BAUD_230400 =	230400,
	USART_BAUD_460800 = 460800,
	USART_BAUD_921600 = 921600,
	USART_BAUD_2M = 2000000,
	USART_BAUD_3M = 3000000
}USART_BaudeRate_t;

/* Possible options for USART_ParityControl */
typedef enum {
							/*   PCE  PS    */
	USART_PARITY_DISABLE=0, /* 0b 0   0		*/
	USART_PARITY_EN_EVEN=2,	/* 0b 1   0		*/
	USART_PARITY_EN_ODD  	/* 0b 1   1		*/
}USART_Parity_t;

/* Possible options for USART_WordLength */

typedef enum{
	USART_WORD_WIDTH_8BITS=0,
	USART_WORD_WIDTH_9BITS
}USART_WordWidth_t;

/* Possible options for USART_NoOfStopBits */
typedef enum{
	USART_STOPBITS_1=0,
	USART_STOPBITS_0_5,
	USART_STOPBITS_2,
	USART_STOPBITS_1_5
}USART_StopBits_t;


/* Possible options for USART_HWFlowControl */
typedef enum{
	/*                                CTSE RTSE */
	USART_HW_FLOW_CTRL_NONE = 0,/* 0 0b 0   0  	*/
	USART_HW_FLOW_CTRL_RTS, 	/* 1 0b 0   1  	*/
	USART_HW_FLOW_CTRL_CTS, 	/* 2 0b 1   0  	*/
	USART_HW_FLOW_CTRL_CTS_RTS  /* 3 0b 1   1  	*/
}USART_HWFlowControl_t;


 /* Possible options for SynchMode */
typedef enum{
	ASYNCH =0,
    SYNCH
}USART_SynchMode_t;

 /* Possible options for USARTNumber */
typedef enum{
	USART_1=0,
	USART_2,
	USART_3,
	USART_4,
	USART_5,
	USART_6
}USART_Number_t;


/* Config interrupt   */
typedef struct
{
	/* 0 or 1 */
    u8 PEIE:1; 	/* parity error */
    u8 TXEIE:1;	/* Transmit data register empty */
    u8 TCIE:1;     /* Transmission complete */
    u8 RXNEIE:1;   /* Read data register not empty */
    u8 IDLEIE:1;   /* IDLE line detected */
    u8 CTSIE:1;    /* CTS  interrupt */

} UART_IT_ENABLE_t;

 /*
 * Configuration structure for USARTx peripheral
 */
typedef struct {
	USART_Number_t	 USART_Num;
	USART_Mode_t USART_Mode;
	USART_BaudeRate_t USART_Baud;
	USART_StopBits_t USART_NoOfStopBits;	// can be removed
	USART_WordWidth_t USART_WordLength;	// can be removed
	USART_Parity_t USART_ParityControl; // can be removed
	USART_HWFlowControl_t USART_HWFlowControl; // can be removed
	USART_SynchMode_t USART_SynchMode; // can be removed

	/* in synchronous mode need to config CPOL & CPHA  */

	UART_IT_ENABLE_t  	 USART_InterruptEnable; // struct
}USART_Config_t;


/* ********************************************* */


//uint8_t USART_u8Init(USART_Handle_t *pUSARTHandle);

STD_error_t		MUSART_stderrInit (USART_Config_t *ARG_pUSARTHandle);

STD_error_t 	MUSART_stderrSendChar(USART_Number_t ARG_numUSARTNum , char ARG_charString );
STD_error_t 	MUSART_stderrSendString	(USART_Number_t ARG_numUSARTNum , const char *ARG_ccharpString );

char 			MUSART_charReceiveCharNonBlocking(USART_Number_t ARG_numUSARTNum );
char 			MUSART_charReceiveCharBlocking(USART_Number_t ARG_numUSARTNum );
STD_error_t 	MUSART_stderrReceiveStringUntil(USART_Number_t ARG_numUSARTNum , char *ARG_charpReceived, char  ARG_charTerminator);

u8 		MUSART_u8GetFlagStatus(USART_Number_t ARG_numUSARTNum, u8 ARG_u8Flag);


//STD_error_t 	MUART_stderrSetCallback(USART_Number_t ARG_numUSARTx, u8 ARG_u8InterruptSource , void(*ARG_pvoidfUserFunction)(void));


//u8 USART_u8SendData(USART_Config_t *pUSARTHandle, u8 *pTxBuffer, u32 Length);


/* using ISR */
STD_error_t 	MUSART_stderrSendData_IT	(USART_Config_t *ARG_pUSARTHandle, u8 *ARG_pu8TxBuffer , u32 ARG_u32Length);
STD_error_t 	MUSART_stderrReceiveData_IT (USART_Number_t ARG_numUSARTx, char *ARG_pcharDataReceived, void(*ARG_pvoidfUserFunction)(void));
STD_error_t 	MUSART_stderrReceiveBuffer_IT (USART_Number_t ARG_numUSARTx, char *ARG_pcharDataReceived, char ARG_charTerm, void(*ARG_pvoidfUserFunction)(void));


#endif
