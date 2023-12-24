/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Scheduler			                */
/* Layer       : OS                                 */
/* Version     : 1.0                                */
/* Date        : September 5, 2023                  */
/* Last Edit   : N/A 			                    */
/* ************************************************ */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MSYSTICK_interface.h"

#include "OS_private.h"
#include "OS_interface.h"

task_t OS_sysTasks[OS_NUMBER_OF_TASKS] ={0};
u16 OS_pu16TaskPeriodicity[OS_NUMBER_OF_TASKS] ;

static volatile u32 OS_u32TickCount =0;


/*
	F=8Mh, need Systick = 1 ms 
	so choose prescaler 64 the tick time will be 8us
	then use CTC mode with OCR = 125 tick then 1 O.V
	take 1 ms 
*/
static void OS_voidScheduler(void)
{
	u8 L_u8i;
	for(L_u8i = 0; L_u8i< OS_NUMBER_OF_TASKS; L_u8i++)
	{
		if(OS_STATE_ACTIVE == OS_sysTasks[L_u8i].State)
		{
			if( 0 == OS_pu16TaskPeriodicity[L_u8i] )
			{
				OS_sysTasks[L_u8i].TaskHandler();
				OS_pu16TaskPeriodicity[L_u8i] = OS_sysTasks[L_u8i].Periodicity;
			}
			else
			{
				OS_pu16TaskPeriodicity[L_u8i]--;
			}	
		}
		else
		{
			/* Do nothing Misra */
		}
	}

}

void OS_voidStartOS(void)
{
	MSTK_stderrInit(MSTK_CLOCKSRC_AHB_8);
	/* Tick every 1ms */
	MSTK_stderrDelayms_IT(OS_voidScheduler,1,MSTK_PERIOD_INTERVAL);
}

/* the Task ID is the priortiy so only one func can take priority 1 or .. 255 */
STD_error_t OS_stderrCreateTask( void (*ARG_pvoidfhandler)(void), u16 ARG_u16Periodicity , u8 ARG_u8Priority , u8 ARG_u8FirstDelay)
{
	STD_error_t L_stderrState=E_OK;
	if(NULL_POINTER != ARG_pvoidfhandler)
	{
		/* task not overwrite another task in array OS_sysTasks */
		if( (ARG_u8Priority < OS_NUMBER_OF_TASKS) && (NULL_POINTER == OS_sysTasks[ARG_u8Priority].TaskHandler) )
		{
			OS_sysTasks[ARG_u8Priority].TaskHandler= ARG_pvoidfhandler;
			OS_sysTasks[ARG_u8Priority].Periodicity= ARG_u16Periodicity;
			OS_sysTasks[ARG_u8Priority].State= OS_STATE_SUSPENDED;
			OS_pu16TaskPeriodicity[ARG_u8Priority] = ARG_u8FirstDelay;
		}
		else
		{
			L_stderrState=E_NOK;
		}
	}
	else
	{
		L_stderrState=E_NULL_POINTER;
	}
	
	return L_stderrState;
}

STD_error_t OS_stderrDeleteTask( u8 ARG_u8Priority)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_u8Priority < OS_NUMBER_OF_TASKS)
	{
		if(NULL_POINTER != OS_sysTasks[ARG_u8Priority].TaskHandler)
		{
			/* delete task */
			OS_sysTasks[ARG_u8Priority].TaskHandler= NULL_POINTER;
			OS_sysTasks[ARG_u8Priority].Periodicity= 0;
			OS_sysTasks[ARG_u8Priority].State= OS_STATE_SUSPENDED;
			
		}
		else
		{
			L_stderrState=E_NOK; /* empty*/
		}
	}
	else
	{
		L_stderrState=E_NOK;
	}
	
	return L_stderrState;
}

STD_error_t OS_stderrActivateTask( u8 ARG_u8Priority)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_u8Priority < OS_NUMBER_OF_TASKS)
	{
		if(NULL_POINTER != OS_sysTasks[ARG_u8Priority].TaskHandler)
		{
			OS_sysTasks[ARG_u8Priority].State= OS_STATE_ACTIVE;
		}
		else
		{
			L_stderrState=E_NOK; /* empty*/
		}
	}
	else
	{
		L_stderrState=E_NOK;
	}
	
	return L_stderrState;
	
}

STD_error_t OS_stderrSuspendTask( u8 ARG_u8Priority)
{
	STD_error_t L_stderrState=E_OK;
	if(ARG_u8Priority < OS_NUMBER_OF_TASKS)
	{
		if(NULL_POINTER != OS_sysTasks[ARG_u8Priority].TaskHandler)
		{
			OS_sysTasks[ARG_u8Priority].State= OS_STATE_SUSPENDED;
		}
		else
		{
			L_stderrState=E_NOK; /* empty*/
		}
	}
	else
	{
		L_stderrState=E_NOK;
	}
	
	return L_stderrState;
	
}
