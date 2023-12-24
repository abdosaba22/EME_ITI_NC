/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 Flash Program and erase controller		*/
/* Layer       	:	 MCAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 October 4, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC includes */
#include "MFPEC_private.h"
#include "MFPEC_interface.h"
// #include "MFPEC_config.h"


void MFPEC_voidFlashUnlock(void)
{
	if(1 ==  ((FPEC -> CR >> LOCK_BIT ) & 1)  )
	{
		FPEC->KEYR = FPEC_KEY1;
		FPEC->KEYR = FPEC_KEY2;
		
	}
	else { /* Do nothing */}
	
}

void MFPEC_voidFlashLock(void)
{
	FPEC -> CR |= 1<<LOCK_BIT;
}

STD_error_t MFPEC_stderrFlashMassErase(void)
{
	STD_error_t L_stderrState = E_OK;
	
	/*Unlock flash to start process*/
	MFPEC_voidFlashUnlock();

	/*Disable all interrupts to avoid errors*/
	__asm volatile ("cpsid i" : : : "memory");

	/*Wait if there is a current process using Flash*/
	while(GET_BIT(FPEC->SR,BSY_FLAG) == 1);

	/*Set word size to be 32 bit, Choose sector Number & choose sector erase */
	FPEC->CR = ( FPEC->CR & 0xFFFFFC80) | ( 0b10 <<PSIZE_BIT) | ( ARG_secSectorNum << SNB_BIT_0 ) | (1 << SER_BIT ) ;

	/*erase Flags*/
	FPEC->SR |= ( 0x1F <<WRPERR_FLAG);

	/*Start erase opreation*/
	SET_BIT(FPEC->CR,STRT_BIT);

	/*Wait if there is a current process using Flash*/
	while(GET_BIT(FPEC->SR,BSY_FLAG)==1);

	/*Enable Interrupts again*/
	__asm volatile ("cpsie i" : : : "memory");

	/*Lock Flash again*/
	MFPEC_voidFlashLock();

	
	return L_stderrState;
}

STD_error_t MFPEC_stderrFlashEraseSector(MFPEC_SECTORS_t ARG_secSectorNum)
{
	STD_error_t L_stderrState = E_OK;
	
	if(ARG_secSectorNum <= MFPEC_SECTOR_5)
	{
		/*Unlock flash to start process*/
		MFPEC_voidFlashUnlock();

		/*Disable all interrupts to avoid errors*/
		__asm volatile ("cpsid i" : : : "memory");

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(FPEC->SR,BSY_FLAG) == 1);

		/*Set word size to be 32 bit, Choose sector Number & choose sector erase */
		FPEC->CR = ( FPEC->CR & 0xFFFFFC80) | ( 0b10 <<PSIZE_BIT) | ( ARG_secSectorNum << SNB_BIT_0 ) | (1 << SER_BIT ) ;

		/*erase Flags*/
		FPEC->SR |= ( 0x1F <<WRPERR_FLAG);

		/*Start erase opreation*/
		SET_BIT(FPEC->CR,STRT_BIT);

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(FPEC->SR,BSY_FLAG)==1);

		/*Enable Interrupts again*/
		__asm volatile ("cpsie i" : : : "memory");

		/*Lock Flash again*/
		MFPEC_voidFlashLock();

	}
	else
	{
		L_stderrState = E_NOK;
	}
	
	return L_stderrState;
}

STD_error_t MFPEC_stderrFlashWrite(u32* ARG_pu32Data, u32 ARG_u32Address,u32 ARG_u32Length )
{
	STD_error_t L_stderrState = E_OK;
	
	if(ARG_u32Address <= MFLASH_SECTOR_5_END)
	{

		/*Unlock flash to start process*/
		MFlash_u8Unlock();

		/*Disable all interrupts to avoid errors*/
		__asm volatile ("cpsid i" : : : "memory");

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(FPEC->SR,BSY_FLAG)==1);

		/*Set word size to be 32 bit*/
		CLEAR_BIT(FPEC->CR,8);
		SET_BIT(FPEC->CR,9);

		/*erase Flags*/
		FPEC->SR |= ( 0x1F <<WRPERR_FLAG);

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(FPEC->SR,BSY_FLAG)==1);


		/*start program mode*/
		SET_BIT(FPEC->CR,PG_BIT);
		
		u32 L_u32I ; /* iterator var */
		/*Write Data*/
		for ( L_u32I = 0; L_u32I < ARG_u32Length; ++L_u32I) 
		{
			*(u32 *)(ARG_u32Address+ L_u32I*4) = Ptr_u32Data[ L_u32I ];
			/*Wait if there is a current process using Flash*/
			while(GET_BIT(FPEC->SR,BSY_FLAG)==1);
		}

		/*Stop program mode*/
		CLEAR_BIT( FPEC->CR, PG_BIT);

		/*Enable Interrupts again*/
		__asm volatile ("cpsie i" : : : "memory");

		/*Lock Flash again*/
		MFPEC_voidFlashLock();

	}
	else
	{
		L_stderrState = E_NOK;
	}
	
	return L_stderrState;
}
