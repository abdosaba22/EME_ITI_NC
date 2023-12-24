/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Scheduler			                */
/* Layer       : OS                                 */
/* Version     : 1.0                                */
/* Date        : September 5, 2023                  */
/* Last Edit   : N/A 			                    */
/* ************************************************ */


#ifndef _OS_INTERFACE_H_
#define _OS_INTERFACE_H_

#define OS_NUMBER_OF_TASKS  256

#define OS_STATE_ACTIVE		1
#define OS_STATE_SUSPENDED	0


void OS_voidStartOS(void);
/* the Task ID is the priortiy so only one func can take priority 1 or .. 255 */
STD_error_t OS_stderrCreateTask( void (*ARG_pvoidfhandler)(void), u16 ARG_u16Periodicity , u8 ARG_u8Priority , u8 ARG_u8FirstDelay);

STD_error_t OS_stderrDeleteTask( u8 ARG_u8Priority);

STD_error_t OS_stderrActivateTask( u8 ARG_u8Priority);

STD_error_t OS_stderrSuspendTask( u8 ARG_u8Priority);


#endif
