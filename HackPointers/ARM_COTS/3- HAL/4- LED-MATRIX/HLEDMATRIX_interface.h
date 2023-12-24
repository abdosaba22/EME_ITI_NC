/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 LED Matrix							*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 21, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */

#ifndef _HLEDMATRIX_INTERFACE_H_
#define _HLEDMATRIX_INTERFACE_H_


void HLEDMRX_voidInit(void);

void HLEDMRX_voidDisplay(u8 * ARG_pu8Data);

void HLEDMRX_voidDisplayScroll(u8 *Copy_u8BigData);

void HLEDMRX_voidDisplayOnce2(u8 *Copy_u8Data2);

void HLEDMRX_voidDisplayPlayer(u8 *Copy_u8PlayerData, u8 *Copy_u8BallData);

void HLEDMRX_voidDisplayBall(u8 *Copy_u8DBallData);

#endif
