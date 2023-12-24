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
#include "MTIM_interface.h"
#include "MGIE_interface.h"

#include "OS_private.h"
#include "OS_interface.h"

task_t OS_sysTasks[OS_NUMBER_OF_TASKS] ={0};

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
	OS_u32TickCount++;
	for(L_u8i = 0; L_u8i< OS_NUMBER_OF_TASKS; L_u8i++)
	{
		if(OS_STATE_ACTIVE == OS_sysTasks[L_u8i].State)
		{
			if( 0==(OS_u32TickCount%OS_sysTasks[L_u8i].Periodicity) )
			{
				OS_sysTasks[L_u8i].TaskHandler();
			}	
		}
	}

}

void OS_voidStartOS(void)
{
	MTIM_stderrInit(MTIM_TIMER0, MTIM_CS_PRESCALER_64, u8 MTIM_MODE_T0T1_CTC ,MTIM_HWPIN_T0_DISCONNECTED)
	MTIM_stderrSetOCR(MTIM_TIMER0,125);
	MTIM_stderrSetCallBack(MTIM_INTERRUPT_T0_OCM, OS_voidScheduler );
	MTIM_stderrEnableInterrupt(MTIM_INTERRUPT_T0_OCM);
	MGIE_voidEnableGI();
	MTIM_stderrStartTimer(MTIM_TIMER0);	
}
/* the Task ID is the priortiy so only one func can take priority 1 or .. 255 */
STD_error_t OS_stderrCreateTask( void (*ARG_pvoidfhandler)(void), u16 ARG_u16Periodicity , u8 ARG_u8Priority)
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
