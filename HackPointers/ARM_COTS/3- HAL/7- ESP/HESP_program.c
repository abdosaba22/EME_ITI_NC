/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 ESP								*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 3, 2023					*/
/* Last Edit   	:	 N/A								*/
/* **************************************************** */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "HESP_interface.h"
#include "HESP_private.h"

#include "UART_Interface.h"


u8 HESP_u8Response[100] ={0};

void HESP_voidInit(void)
{
	u8 L_u8ValidFlag = 0;

	while(L_u8ValidFlag == 0)
	{
		/*Stop Echo*/
		MUSART_stderrSendString(USART_1 ,"ATE0\r\n");
		/*	Check command is done right
			ATE0 returns OK if all is okay*/
		L_u8ValidFlag = HESP_u8ValidateCmd(150);
	}
	
	L_u8ValidFlag = 0;

	while(L_u8ValidFlag == 0)
	{
		/*Set ESP station mode*/
		MUSART_stderrSendString(USART_1 ,"AT+CWMODE=1\r\n");
		/*	Check command is done right
			AT+CWMODE=1 returns OK if all is okay*/
		L_u8ValidFlag = HESP_u8ValidateCmd(150);
	}
}


u8 HESP_u8ValidateCmd(u32 ARG_u32EchoTime)
{
	u8 L_u8ValidFlag = 0;
	u8 L_u8Counter = 0;
	u32 L_u32Timeout=0;
	u8 L_u8Tempchar = 0;

	for(u8 i = 0; i < 100; i++)
	{
		HESP_u8Response[i] = 0;
	}

	/*Make sure that the MC is not receiving any more data from the ESP*/
	while (L_u8Tempchar != 255)
	{
		while(L_u32Timeout != ARG_u32EchoTime && L_u8Tempchar == 0 )
		{
			L_u8Tempchar = MUSART_charReceiveCharNonBlocking(ARG_u32EchoTime);
			L_u32Timeout ++;
		}
		
		if(L_u32Timeout == ARG_u32EchoTime ) L_u8Tempchar = 255 ;
		L_u32Timeout=0;
		HESP_u8Response[L_u8Counter] = L_u8Tempchar;
		L_u8Counter++;
	}

	/*	Deleting last element as it is always 255 for stop receiving data	*/
	HESP_u8Response[L_u8Counter-1] = 0;

	/*Strcmp returns 0 if the two strings are iqentical*/
	//L_u8ValidFlag = strcmp(Copy_u8StrCmd, HESP_u8Response);

	/* Checks if any of the received data contains the word "OK" meaning the command is done successfully*/
	for(u8 i = 0; i < L_u8Counter - 2; i ++)
	{
		if(HESP_u8Response[i] == 'O' && HESP_u8Response[i+1] == 'K')
		{
			L_u8ValidFlag = 1;
		}
	}
	return L_u8ValidFlag;
}



void HESP_WIFIConnect(void)
{
	u8 L_u8Result = 0;

	while(L_u8Result == 0)
	{
		/* stop ECHO */
		MUSART_stderrSendString(USART_1 ,"AT+CWJAP_CUR=\"AX\",\"0558817006\"\r\n");
		L_u8Result = HESP_u8ValidateCmd(10000);
	}
}

void HESP_voidSendData(void)
{
	u8 L_u8Result = 0;

	while(L_u8Result == 0)
	{
		/* set IP */
		MUSART_stderrSendString(USART_1 ,"AT+CIPSTART=\"TCP\",\"23.179.32.37\",80\r\n");
		L_u8Result = HESP_u8ValidateCmd(30000);
	}

	L_u8Result = 0;


}

u8 HESP_u8WebState(void)
{
	u8 i = 0;
	u8 L_u8Result = 0;
	u8 L_u8Tempchar;

	while(L_u8Result == 0)
	{
		/* Send */
		MUSART_stderrSendString(USART_1 ,"AT+CIPSEND=55\r\n");
		L_u8Result = HESP_u8ValidateCmd(10000);
	}
	L_u8Result = 0;
		/* get state */
	while(L_u8Result == 0)
	{
		/* Send */
		MUSART_stderrSendString(USART_1 ,"GET http://abdalrahmansaba.freetzi.com/status.txt\r\n");
		L_u8Result = HESP_u8ValidateCmd(900000);
	}
	L_u8Result = 0;

	for(i=0;i<99;i++)
	{
		/*Checking that the data recieved have IPD*/
		if(HESP_u8Response[i] == 'I' && HESP_u8Response[i+1] == 'P' && HESP_u8Response[i+2] == 'D')
		{
			/*Return data in the 6th postion after the I*/
			L_u8Tempchar = HESP_u8Response[i+6];
		}
	}
	if(	L_u8Tempchar == '1')
		L_u8Tempchar = 1;
	else if (L_u8Tempchar == '0')
		L_u8Tempchar = 0;

	return L_u8Tempchar;
}
