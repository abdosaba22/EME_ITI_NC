/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 Direct Mem Access					*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 1, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */


#ifndef _DMA_INTERFACE_H_
#define _DMA_INTERFACE_H_


typedef enum
{
	DMA_1,
	DMA_2
}DMA_Num_t;

typedef enum
{
	DMA_DIRECT,
	DMA_FIFO
}DMA_Mode_t;

typedef enum
{
	DMA_STREAM_0,
	DMA_STREAM_1,
	DMA_STREAM_2,
	DMA_STREAM_3,
	DMA_STREAM_4,
	DMA_STREAM_5,
	DMA_STREAM_6,
	DMA_STREAM_7,
}DMA_Stream_t;

typedef enum
{
	DMA_CHANNEL_0,
	DMA_CHANNEL_1,
	DMA_CHANNEL_2,
	DMA_CHANNEL_3,
	DMA_CHANNEL_4,
	DMA_CHANNEL_5,
	DMA_CHANNEL_6,
	DMA_CHANNEL_7
}DMA_Channel_t;

typedef enum
{
	PERIPHERAL_TO_MEMORY,
	MEMORY_TO_PERIPHERAL,
	MEMORY_TO_MEMORY
}DMA_DataDir_t;

typedef enum
{
	DMA_LOW_PR,
	DMA_MEDIUM_PR,
	DMA_HIGH_PR,
	DMA_VERY_HIGH_PR,
}DMA_StreamPriority_t;

typedef enum
{
	SINGLE_TRANSFER,
	INCR4,
	INCR8,
	INCR16
}DMA_BurstTransfer_t;

typedef enum
{
	BYTE,
	HALF_WORD,
	WORD,
}DMA_DataSize_t;

typedef enum
{
    FIEF = 0,  // FIFO error interrupt flag
    DMEIF = 2, // Direct mode error interrupt flag
    TEIF,      // Transfer error interrupt flag
    HTIF,      // Half transfer interrupt flag
    TCIF       // Transfer complete interrupt flag

} DMA_Flag_t;

typedef enum
{
	MEM_FIXED_PRPH_FIXED,
	MEM_FIXED_PRPH_INC,
	MEM_INC_PRPH_FIXED,
	MEM_INC_PRPH_INC
}DMA_IncMode_t;

typedef enum
{
	ONE_TRANSFER,
	CIRCULAR_TRANSFER
}DMA_Transfer_t;

/* current target in Double buffer mode*/
typedef enum
{
    Meomry0 = 0, // Meomry 0 (addressed by the DMA_SxM0AR pointer)
    Meomry1 = 1  // Meomry 1 (addressed by the DMA_SxM1AR pointer)
} DMA_CT_t;

typedef enum
{
	FIFO_QUARTER_FULL,
	FIFO_HALF_FULL,
	FIFO_THREE_QUARTERs_FULL,
	FIFO_FULL,
}DMA_FifoSize_t;

typedef enum
{
    DMAFlowController = 0,    // DMA Flow Controller
    PeripheralFlowController, // Peripheral Flow Controller
} DMA_FlowController_t;

typedef struct
{
    u8 TransferCompleteInterrupt; // Transfer Complete Interrupt --> ON or OFF
    u8 HalfTransferInterrupt;     // Half Transfer Interrupt     --> ON or OFF
    u8 TransferErrorInterrupt;    // Transfer Error Interrupt    --> ON or OFF
    u8 DirectModeErrorInterrupt;  // Direct Mode Error Interrupt --> ON or OFF
    //u8 FIFOErrorInterrupt;        // FIFO Error Interrupt        --> ON or OFF
} DMA_InteruptConfig_t;

typedef struct
{
	DMA_Num_t 	 			DMA_Number;
	DMA_Stream_t 			Stream_Number;
	DMA_Channel_t 			Channel;
	DMA_Mode_t 				Mode;
	DMA_DataDir_t 			DataDirection;
	DMA_StreamPriority_t 	Priority;
	DMA_BurstTransfer_t 	DataType;
	DMA_DataSize_t 			MemoryDataSize;
	DMA_DataSize_t 			PeripheralDataSize;
	DMA_IncMode_t 			MemPrphIncMode;
	DMA_Transfer_t 			TransferType; 			// Circular mode 
	DMA_FifoSize_t 			FifoThreshold;
	DMA_FlowController_t 	FlowController;           // Flow Controller
	DMA_InteruptConfig_t* 	InteruptFlagsConfig;     // Interupt Flags Config
	void (* CallBackFunc)(void);
}DMA_Config_t;

u8 DMA_u8Init(const DMA_Config_t* ARG_pDMAconfig);

void DMA_voidClearInterruptFlag(DMA_Num_t ARG_u8DMANumber, DMA_Stream_t ARG_u8StreamNumber, DMA_Flag_t ARG_u8Flag);

void DMA_voidSetStreamInteruptConfig(const DMA_Config_t *ARG_pDMAconfig);

void DMA_voidStartTransfer(const DMA_Config_t *ARG_pDMAconfig, u32 ARG_u32SourceAddress, u32 ARG_u32DestinationAddress, u16 ARG_u16DataLength);

void DMA_voidStartTransferIT(DMA_Config_t *ARG_pDMAconfig, u32 ARG_u32SourceAddress, u32 ARG_u32DestinationAddress, u16 ARG_u16DataLength);

u8 DMA_u8CheckingInterruptFlagSource(DMA_Num_t ARG_DMANumber, DMA_Stream_t ARG_StreamNumber, DMA_Flag_t ARG_u8Flag);

void DMA_voidSetCallBack(const DMA_Config_t *ARG_pDMAconfig, void (*ARG_pvoidfCallBack)(void), DMA_Flag_t ARG_u8Flag);


#endif
