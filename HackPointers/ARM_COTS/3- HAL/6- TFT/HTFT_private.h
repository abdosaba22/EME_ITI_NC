/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 TFT									*/
/* Layer       	:	 HAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 September 28, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */

#ifndef _MTFT_PRIVATE_H_
#define _MTFT_PRIVATE_H_


static void voidWriteCommand(u8 Copy_u8Command);

static void voidWriteData(u8 Copy_u8Data);

static void HTFT_voidBounders(u8 x1, u8 x2, u8 y1, u8 y2);

static void DrawTheColor(u16 Color);

static void HTFT_voidDrawPixel(u8 x1, u8 y1, u16  Copy_u16Color);


#endif