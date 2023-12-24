/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 Serial to Parallel					*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 25, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */

#ifndef _HSTP_INTERFACE_H_
#define _HSTP_INTERFACE_H_


void HSTP_voidInit(void);
/* Synchronus Func == wait the signal clock */
void HSTP_voidSendSynchronus(u16 ARG_u8DataToSend, u8 ARG_u8NumOfECU);


#endif