/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 LED Matrix							*/
/* Layer       	:	 HAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 September 21, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MSYSTICK_interface.h"
#include "MGPIO_interface.h"
#include "HLEDMATRIX_interface.h"
#include "HLEDMATRIX_private.h"
#include "HLEDMATRIX_config.h"

/* use array to save pins config Row,COL Pins */
static u8 L_pu8PinsArr[16] = {
			/* ROW pins*/
			HLEDMAT_ROW_0      		,
			HLEDMAT_ROW_1      		,
			HLEDMAT_ROW_2      		,
			HLEDMAT_ROW_3      		,
			HLEDMAT_ROW_4      		,
			HLEDMAT_ROW_5      		,
			HLEDMAT_ROW_6      		,
			HLEDMAT_ROW_7      		,
			/* Col pins*/
			HLEDMAT_COL_0      		,
			HLEDMAT_COL_1      		,
			HLEDMAT_COL_2      		,
			HLEDMAT_COL_3      		,
			HLEDMAT_COL_4      		,
			HLEDMAT_COL_5      		,
			HLEDMAT_COL_6      		,
			HLEDMAT_COL_7      		
};

void HLEDMRX_voidInit(void)
{
	u8 L_u8Iteration;
	
	/* Config pins in for loop we will assign the pin */
	MGPIO_CONFIG_t L_configLedMatrix = {
		.Port=HLEDMAT_ROW_PORT, 
		.Mode=OUTPUT,
		.Speed=LOW,
		.OutputType= PUSH_PULL,
		.PullType= NOPULL,
	};
		/* Config the ROW pins  */
	for( L_u8Iteration = 0 ; L_u8Iteration < 8 ;L_u8Iteration++)
	{
		L_configLedMatrix.Pin = L_pu8PinsArr[L_u8Iteration];
		MGPIO_stderrPinConfig(&L_configLedMatrix);
	}
	/* Assign the PORT for COL */
	L_configLedMatrix.Port = HLEDMAT_COL_PORT;
	/* Config the COL pins  */
	for( /* L_u8Iteration start from 8 */ ; L_u8Iteration < 16 ;L_u8Iteration++)
	{
		L_configLedMatrix.Pin = L_pu8PinsArr[L_u8Iteration];
		MGPIO_stderrPinConfig(&L_configLedMatrix);
	}
	
}

void HLEDMRX_voidDisplay(u8 *ARG_pu8Data)
{
	u8 L_u8Iteration ;
	while(1)
	{
		
		for( L_u8Iteration = 0; L_u8Iteration < 8 ; L_u8Iteration++)
		{
			/* disable all col */
			DisableAllCols();
			SetRowValues(ARG_pu8Data[L_u8Iteration]);
			/* enable col-i+8- */
			MGPIO_stderrSetPinValue( HLEDMAT_COL_PORT, L_pu8PinsArr[L_u8Iteration+8], PIN_LOW);
			MSTK_voidBusyDelay(5000);  // 2.5 mSec
		}
	}
	
}

void HLEDMRX_voidDisplayOnce(u8 *ARG_pu8Data, u8 ARG_u8ScrollCounter)
{
	u8 L_u8Iteration ,L_u8i;
	for(L_u8i = 0 ; L_u8i < 12 ; L_u8i++)
	{
		
		for( L_u8Iteration = 0; L_u8Iteration < 8 ; L_u8Iteration++)
		{
			/* disable all col */
			DisableAllCols();
			SetRowValues(ARG_pu8Data[ARG_u8ScrollCounter+L_u8Iteration]);
			/* enable col-i+8- */
			MGPIO_stderrSetPinValue( HLEDMAT_COL_PORT, L_pu8PinsArr[L_u8Iteration+8], PIN_LOW);
			MSTK_voidSetBusyWait(5000);  // 2.5 mSec
		}
	}

}

void HLEDMRX_voidDisplayOnce2(u8 *ARG_pu8Data)
{
	u8 L_u8Iteration ,L_u8i;
	
	for(L_u8i = 0 ; L_u8i < 6 ; L_u8i++)
	{
	
		for( L_u8Iteration = 0; L_u8Iteration < 8 ; L_u8Iteration++)
		{
			/* disable all col */
			DisableAllCols();
			SetRowValues(ARG_pu8Data[L_u8Iteration]);
			/* enable col-i- */
			MGPIO_voidSetPinValue( HLEDMAT_COL_PORT, L_pu8PinsArr[L_u8Iteration+8], PIN_LOW);
			MSTK_voidSetBusyWait(5000);  // 2.5 mSec
		}
	
	}

}

void HLEDMRX_voidDisplayScroll(u8 *ARG_pu8BigData)
{
	u8 L_u8ArraySize = ArraySize1 - 7;
	u8 L_u8i ;
	while(1)
	{
		for(L_u8i = 0 ; L_u8i < L_u8ArraySize ; L_u8i++)
		{
			HLEDMRX_voidDisplayOnce(ARG_pu8BigData, L_u8i);
			MSTK_voidSetBusyWait(60000); // 3 ms
		}
		
	}
}

void HLEDMRX_voidDisplayPlayer(u8 *ARG_u8PlayerData, u8 *ARG_u8BallData)
{
	while(1)
	{
		HLEDMRX_voidDisplayOnce(ARG_u8PlayerData, 0);
		HLEDMRX_voidDisplayBall(ARG_u8BallData);

	}
}

void HLEDMRX_voidDisplayBall(u8 *ARG_pu8DBallData)
{

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(192);
	/* enable col-6- */
	MGPIO_voidSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(160);
	/* enable col-6- */
	MGPIO_voidSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(144);
	/* enable col-6- */
	MGPIO_voidSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(136);
	/* enable col-6- */
	MGPIO_voidSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(144);
	/* enable col-6- */
	MGPIO_voidSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(160);
	/* enable col-6- */
	MGPIO_stderrSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

	DisableAllCols();
	SetRowValues(192);
	/* enable col-6- */
	MGPIO_voidSetPinValue(HLEDMAT_COL_PORT, HLEDMAT_COL_6, PIN_LOW);
	MSTK_voidSetBusyWait(5000);  // 2.5 mSec

	HLEDMRX_voidDisplayOnce2(ARG_pu8DBallData);

}

void DisableAllCols(void)
{
	u8 L_u8Iteration ;
	/* disable all col */
	for( L_u8Iteration = 8; L_u8Iteration < 16 ; L_u8Iteration++)
	{
		MGPIO_stderrSetPinValue(	HLEDMAT_COL_PORT, /* COLs PORT */
									L_pu8PinsArr[L_u8Iteration], /* get Row pin value from arr */
									PIN_HIGH ); /* HIGH */
	}

}

void SetRowValues(u8 ARG_u8Value)
{
	u8 L_u8Iteration ;
	for( L_u8Iteration = 0; L_u8Iteration < 8 ; L_u8Iteration++)
	{
		MGPIO_stderrSetPinValue(	HLEDMAT_ROW_PORT, /* ROWs PORT */
									L_pu8PinsArr[L_u8Iteration], /* get Row pin value from arr */
									GET_BIT(ARG_u8Value,L_u8Iteration) ); /* pass bit[i] of  data */
	}
	
}
