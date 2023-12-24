/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : MEXTI                              */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 12, 2023                    */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

#ifndef _MEXTI_INTERFACE_H_
#define _MEXTI_INTERFACE_H_


#define MEXTI_MODE_LOW		    			0U
#define MEXTI_MODE_IOC			    		1U
#define MEXTI_MODE_FALLING    				2U
#define MEXTI_MODE_RISING		   			3U

#define MEXTI_INT0							0U
#define MEXTI_INT1							1U
#define MEXTI_INT2							2U

STD_error_t MEXTI_stderrInit(u8 ARG_u8InterruptNo,u8 ARG_u8SenseMode);
STD_error_t MEXTI_stderrCallBack(void (*ARG_pvoidUserFunction)(void), u8 ARG_u8InterruptNo );
STD_error_t MEXTI_stderrEnable(u8 ARG_u8InterruptNo);
STD_error_t MEXTI_stderrDisable(u8 ARG_u8InterruptNo);

#endif
