/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : EPROM				                */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : September 4, 2023                  */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

#ifndef _HNVM_INTERFACE_H_
#define _HNVM_INTERFACE_H_

STD_error_t	HNVM_stderrInit(void);

void		HNVM_voidWrite(u16 ARG_u16Address, u8 ARG_u8Data);
u8			HNVM_u8Read(u16 ARG_u16Address);

#endif