/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 TFT									*/
/* Layer       	:	 HAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 September 28, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */

#ifndef _MTFT_INTERFACE_H_
#define _MTFT_INTERFACE_H_


void HTFT_voidInitialize(void);

void HTFT_voidDisplayImage(const u16 * Copy_Image);

void HTFT_voidFillColor(u16  Copy_u16Color);

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16  Copy_u16Color);

void HTFT_voidDrawChar(u8 x1,u8 y1,u16 CharColor, u16 BackColor, u8 charcter);

void HTFT_voidDrawString(u8 x1,u8 y1,u16 CharColor, u16 BackColor, u8 * string);



#endif