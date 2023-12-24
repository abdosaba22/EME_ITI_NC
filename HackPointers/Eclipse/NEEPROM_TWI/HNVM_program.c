/* ************************************************ */
/* Author      : Mohamed Hassan                     */
/* SWC         : EEPROM                             */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : September 3, 2023                  */
/* Last Edit   : N/A                                */
/* ***************************************************/


#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MTWI_interface.h"
#include "HNVM_interface.h"
#include "HNVM_private.h"
#include "HNVM_configure.h"




STD_error_t HNVM_stderrInit(void)
{

STD_error_t L_stderrstate = E_OK;	
 L_stderrstate = MTWI_stderrInit(HNVM_BIT_RATE,HNVM_PRESCALER);
 MTWI_voidEnable();
	
	return L_stderrstate;
}

void HNVM_voidWrite(u16 ARG_u16Address,u8 ARG_u8Data)
{
	        u8 L_u8SlaveAddress , L_u8Block;
			L_u8Block = ARG_u16Address >> 8;
			L_u8SlaveAddress = (0b1010000) | (L_u8Block) ;  // 1010 fixed bits and 0 for A2 and last two bits for A1 A2 which choose the block
	        MTWI_voidSendStartCondition();
			MTWI_voidFlagPolling();
			if( MTWI_STATUS_MASTER_START_CONDITION == MTWI_twistatusCheckStatus())
			{
				MTWI_voidLoadTWDR((( L_u8SlaveAddress << 1) & (0xFE)) | (0));
				MTWI_voidClearFlag();
				MTWI_voidFlagPolling();
				if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == 	MTWI_twistatusCheckStatus())
				{
					MTWI_voidLoadTWDR((u8)ARG_u16Address);
					MTWI_voidClearFlag();
				    MTWI_voidFlagPolling();
					if(MTWI_STATUS_MASTER_TX_DATA_ACK == 	MTWI_twistatusCheckStatus())
					{
						  MTWI_voidLoadTWDR(ARG_u8Data);
					      MTWI_voidClearFlag();
				          MTWI_voidFlagPolling();
						if(MTWI_STATUS_MASTER_TX_DATA_ACK == 	MTWI_twistatusCheckStatus())
					    {
					  	    MTWI_voidSendStopCondition();
					    }

					}
				}
			}
			
			
	
}

u8   HNVM_u8Read(u16 ARG_u16Address)
{
	
	        u8 L_u8SlaveAddress , L_u8Block , L_u8Data=0;
			L_u8Block = ARG_u16Address >> 8;
			L_u8SlaveAddress = (0b1010000) | (L_u8Block) ;  // 1010 fixed bits and 0 for A2 and last two bits for A1 A2 which choose the block
	        MTWI_voidSendStartCondition();
			MTWI_voidFlagPolling();
			if(MTWI_STATUS_MASTER_START_CONDITION == 	MTWI_twistatusCheckStatus())
			{
				MTWI_voidLoadTWDR((( L_u8SlaveAddress << 1) & (0xFE)) | (0));
				MTWI_voidClearFlag();
				MTWI_voidFlagPolling();
				if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == 	MTWI_twistatusCheckStatus())
				{
					MTWI_voidLoadTWDR((u8)ARG_u16Address);
					MTWI_voidClearFlag();
				    MTWI_voidFlagPolling();
					if(MTWI_STATUS_MASTER_TX_DATA_ACK == 	MTWI_twistatusCheckStatus())
					{
						 MTWI_voidSendStartCondition();
			             MTWI_voidFlagPolling();
						if(MTWI_STATUS_MASTER_RSTART_CONDITION  == 	MTWI_twistatusCheckStatus())
		            	{
		            		MTWI_voidLoadTWDR((( L_u8SlaveAddress << 1) & (0xFE)) | (1));
		            		MTWI_voidClearFlag();
		            		MTWI_voidFlagPolling();
							 if(MTWI_STATUS_MASTER_RX_SLA_R_ACK == 	MTWI_twistatusCheckStatus())
				             {
				            	
				            	MTWI_voidClearFlag();
				                MTWI_voidFlagPolling();
								if(MTWI_STATUS_MASTER_RX_DATA_NACK == 	MTWI_twistatusCheckStatus())
					            {   // we did not enable ACK for master so by default he will send NACK if we enabled ACK it will sent ACK
									L_u8Data = MTWI_charReadTWDR ();
					  	            MTWI_voidSendStopCondition();
					            }
							 }
						
						}
						
					  
					}	
				}
				
			}
			
			
	
	
	return L_u8Data ;
}

