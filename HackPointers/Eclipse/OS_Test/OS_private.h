/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Scheduler			                */
/* Layer       : OS                                 */
/* Version     : 1.0                                */
/* Date        : September 5, 2023                  */
/* Last Edit   : N/A 			                    */
/* ************************************************ */
#ifndef _OS_PRIVATE_H_
#define _OS_PRIVATE_H_

typedef struct 
{
	void (* TaskHandler)(void);
	u16 Periodicity;
	u8 State;
}task_t;

#endif
