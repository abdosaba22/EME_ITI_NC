/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 Direct Mem Access					*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 1, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "DMA_Interface.h"
#include "DMA_Private.h"


/* Array Of Pointers To Functions To Hold The Address Of The Call Back Function */
static void (*DMA1_PTR[Streams_Num][Interrupts_Num])(void) = {NULL_POINTER};
static void (*DMA2_PTR[Streams_Num][Interrupts_Num])(void) = {NULL_POINTER};
/* Array Of Pointers To DMA Registers */
static DMA_RegDef_t *DMA[2] = {DMA1, DMA2};

STD_error_t DMA_stderrInit(const DMA_Config_t* ARG_pDMAconfig)
{
	STD_error_t L_stderrState = E_OK;
	if( ARG_pDMAconfig == NULL_POINTER )
	{
		L_stderrState=E_NULL_PONTER;
	}
	else
	{
		/* Channel Selection */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(ThreeBitMask << CHSEL); //25
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->Channel) << CHSEL);

		/*Setting Channel Priority*/
		//DMA_SetStreamPriority(ARG_pDMAconfig);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(TwoBitMask << PL); //16
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->Priority) << PL);
		
		/*Choose mode of DMA*/
		switch(ARG_pDMAconfig->Mode)
		{
			case DMA_DIRECT: 
				DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].FCR &= ~(1<<DMDIS); break;
			case DMA_FIFO:
				DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].FCR |= (1<<DMDIS);
				/*choose the FIFO Threshold*/
				DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].FCR &= ~(TwoBitMask << FTH);
				DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].FCR |= ARG_pDMAconfig->FifoThreshold;
				/*Choose data transfer type*/
				DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(FourBitMask << PBURST);
				DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->DataType)<<PBURST) | ((ARG_pDMAconfig->DataType)<<MBURST);
			break;
			default: L_stderrState = E_NOK;
		}
		
		/* Setting memory data size */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(TwoBitMask << MSIZE);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->MemoryDataSize) << MSIZE);

		/* Setting Periphral data size */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(TwoBitMask << PSIZE);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->PeripheralDataSize) << PSIZE);

		/* Setting memory & Periphral increment mode */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(TwoBitMask << PINC);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->MemPrphIncMode) << PINC);   // 4 bits for ( PINC | MINC ) --> 0b XXXX

		/* Setting data transfer Mode Circular Mode  */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(OneBitMask << CIRC);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->TransferType) << CIRC);
		
		/* Setting data transfer direction */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(TwoBitMask << DIR);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->DataDirection) << DIR);

		/* Seting peripheral flow controller */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(OneBitMask << PFCTRL);
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->FlowController) << PFCTRL);
		
	}
	return L_stderrState;

}
	
void DMA_voidClearInterruptFlag(DMA_Num_t ARG_u8DMANumber, DMA_Stream_t ARG_u8StreamNumber, DMA_Flag_t ARG_u8Flag)
{
	/* Local Variable To Hold Register Number */
	u8 Local_u8RegNum = (ARG_u8StreamNumber) / 2;  // u16_arr[4]  -->  0 2 3 4 5  
	u8 Local_u8BitNum = ( (ARG_u8StreamNumber % 2 )*6) + ARG_u8Flag ;  // 6 or 0 + f ,,, u16_arr[4]  -->  0 2 3 4 5 

	/* Clearing Interrupt Flag Of A Given Stream */
	DMA[ARG_u8DMANumber]->IFCR[Local_u8RegNum] |= (1 << Local_u8BitNum);
}

void DMA_voidSetStreamInteruptConfig(const DMA_Config_t *ARG_pDMAconfig)
{
	/* Configuring DMA Interrupts */
	/* Clearing Interrupts Bits */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~(FourBitMask << DMEIE);
	/* Setting Direct Mode Error Interrupt  */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->InteruptFlagsConfig->DirectModeErrorInterrupt) << DMEIE);
	/* Setting Transfer Error Interrupt */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->InteruptFlagsConfig->TransferErrorInterrupt) << TEIE);
	/* Setting Half Transfer Interrupt */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->InteruptFlagsConfig->HalfTransferInterrupt) << HTIE);
	/* Setting Transfer Complete Interrupt */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((ARG_pDMAconfig->InteruptFlagsConfig->TransferCompleteInterrupt) << TCIE);
}
void DMA_voidStartTransfer(const DMA_Config_t *ARG_pDMAconfig, u32 ARG_u32SourceAddress, u32 ARG_u32DestinationAddress, u16 ARG_u16DataLength)
{
	if (ARG_pDMAconfig->DataDirection == MEMORY_TO_MEMORY || ARG_pDMAconfig->DataDirection == PERIPHERAL_TO_MEMORY)
	{
		/* Setting Source Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].PAR = ARG_u32SourceAddress;
		/* Setting Destination Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].M0AR = ARG_u32DestinationAddress;
	}
	else if (ARG_pDMAconfig->DataDirection == MEMORY_TO_PERIPHERAL)
	{
		/* Setting Source Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].M0AR = ARG_u32SourceAddress;
		/* Setting Destination Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].PAR = ARG_u32DestinationAddress;
	}
	/* Setting Data Length */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].NDTR = ARG_u16DataLength;
	/* Enabling Stream */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~((OneBitMask) << EN);
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((OneBitMask) << EN);
	/* Waiting For Transfer Complete Flag */
	while (DMA_u8CheckingInterruptFlagSource(ARG_pDMAconfig->DMA_Number, ARG_pDMAconfig->Stream_Number, TCIF) == 0);
	
}

void DMA_voidStartTransferIT(DMA_Config_t *ARG_pDMAconfig, u32 ARG_u32SourceAddress, u32 ARG_u32DestinationAddress, u32 ARG_u16DataLength)
{
	if (ARG_pDMAconfig->DataDirection == MEMORY_TO_MEMORY || ARG_pDMAconfig->DataDirection == PERIPHERAL_TO_MEMORY)
	{
		/* Setting Source Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].PAR = ARG_u32SourceAddress;
		/* Setting Destination Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].M0AR = ARG_u32DestinationAddress;
	}
	else if (ARG_pDMAconfig->DataDirection == MEMORY_TO_PERIPHERAL)
	{
		/* Setting Source Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].M0AR = ARG_u32SourceAddress;
		/* Setting Destination Address */
		DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].PAR = ARG_u32DestinationAddress;
	}
	/* Setting Data Length */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].NDTR = ARG_u16DataLength;
	/* Configuring DMA Interrupts */
	DMA_voidSetStreamInteruptConfig(ARG_pDMAconfig);
	/* Enabling Stream */
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR &= ~((OneBitMask) << EN);
	DMA[ARG_pDMAconfig->DMA_Number]->Stream[ARG_pDMAconfig->Stream_Number].CR |= ((OneBitMask) << EN);
}

u8 DMA_u8CheckingInterruptFlagSource(DMA_Num_t ARG_DMANumber, DMA_Stream_t ARG_StreamNumber, DMA_Flag_t ARG_u8Flag)
{
	u8 Local_u8FlagSource = 0;
	/* Local Variable To Hold Register Number */
	u8 Local_u8RegNum = (ARG_StreamNumber) / 2;  // u16_arr[4]  -->  0 2 3 4 5  
	u8 Local_u8BitNum = ( (ARG_StreamNumber)*6) + ARG_u8Flag ;  // 6 or 0 + f ,,, u16_arr[4]  -->  0 2 3 4 5  
	/* Checking Interrupt Flag Source*/
	Local_u8FlagSource = (DMA[ARG_DMANumber]->ISR[Local_u8RegNum] >> (Local_u8BitNum)) & 1; 
	return Local_u8FlagSource;
}

void DMA_voidSetCallBack(const DMA_Config_t *ARG_pDMAconfig, void (*ARG_pvoidfCallBack)(void), DMA_Flag_t ARG_u8Flag)
{
	if ( DMA_1==ARG_pDMAconfig->DMA_Number)
	{
		DMA1_PTR[ARG_pDMAconfig->Stream_Number][ARG_u8Flag] = ARG_pvoidfCallBack;
	}
	else if ( DMA_2==ARG_pDMAconfig->DMA_Number )
	{
		DMA2_PTR[ARG_pDMAconfig->Stream_Number][ARG_u8Flag] = ARG_pvoidfCallBack;
	}
}


void DMA1_Stream0_IRQHandler(void)
{
	/* Checking Interrupt Flag Source*/
	/* Transfer Complete */
	if (DMA_u8CheckingInterruptFlagSource(DMA_1, DMA_STREAM_0, TCIF))
	{
		/* Clearing Interrupt Flag */
		DMA_voidClearInterruptFlag(DMA_1, DMA_STREAM_0, TCIF);
		/* Calling Callback Function */
		DMA1_PTR[DMA_STREAM_0][TCIF]();
	}
	/* Half Transfer Complete */
	else if (DMA_u8CheckingInterruptFlagSource(DMA_1, DMA_STREAM_0, HTIF))
	{
		/* Clearing Interrupt Flag */
		DMA_voidClearInterruptFlag(DMA_1, DMA_STREAM_0, HTIF);
		/* Calling Callback Function */
		DMA1_PTR[DMA_STREAM_0][HTIF]();
	}
	/* Transfer Error */
	else if (DMA_u8CheckingInterruptFlagSource(DMA_1, DMA_STREAM_0, TEIF))
	{
		/* Clearing Interrupt Flag */
		DMA_voidClearInterruptFlag(DMA_1, DMA_STREAM_0, TEIF);
		/* Calling Callback Function */
		DMA1_PTR[DMA_STREAM_0][TEIF]();
	}
	/* FIFO Error */
	else if (DMA_u8CheckingInterruptFlagSource(DMA_1, DMA_STREAM_0, FIEF))
	{
		/* Clearing Interrupt Flag */
		DMA_voidClearInterruptFlag(DMA_1, DMA_STREAM_0, FIEF);
		/* Calling Callback Function */
		DMA1_PTR[DMA_STREAM_0][FIEF]();
	}
	/* Direct Mode Error */
	else if (DMA_u8CheckingInterruptFlagSource(DMA_1, DMA_STREAM_0, DMEIF))
	{
		/* Clearing Interrupt Flag */
		DMA_voidClearInterruptFlag(DMA_1, DMA_STREAM_0, DMEIF);
		/* Calling Callback Function */
		DMA1_PTR[DMA_STREAM_0][DMEIF]();
	}
}

/* DMA1 Stream 1 --> 7 */

