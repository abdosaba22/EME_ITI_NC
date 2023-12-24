/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 ESP								*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 3, 2023					*/
/* Last Edit   	:	 N/A								*/
/* **************************************************** */

#ifndef _HESP_INTERFACE_H_
#define _HESP_INTERFACE_H_

void HESP_voidInit(void);

u8 HESP_u8ValidateCmd(u32 EchoTime);

void HESP_WIFIConnect(void);

void HESP_voidSendData(void);

u8 HESP_u8WebState(void);

#endif