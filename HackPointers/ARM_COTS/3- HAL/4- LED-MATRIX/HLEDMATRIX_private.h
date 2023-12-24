/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 LED Matrix							*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 21, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */

#ifndef _HLEDMATRIX_PRIVATE_H_
#define _HLEDMATRIX_PRIVATE_H_

void DisableAllCols(void);

void SetRowValues(u8 Copy_u8Value);

void HLEDMRX_voidDisplayOnce(u8 *ARG_pu8Data, u8 ARG_u8ScrollCounter);


#endif
