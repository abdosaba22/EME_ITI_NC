/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 CAN								*/
/* MCu         	:	 Stm32F446RE						*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 2, 2023					*/
/* Last Edit   	:	 N/A								*/
/* **************************************************** */

#ifndef _MCAN_INTERFACE_H_
#define _MCAN_INTERFACE_H_



/** CAN_Activation  CAN Activation **/
#define DISABLE			 0
#define ENABLE 			 1

/** @defgroup CAN_identifier_type CAN Identifier Type **/
#define CAN_ID_STD                  ((uint32)(0x0))  /*!< Standard Id */
#define CAN_ID_EXT                  ((uint32)(0x4))  /*!< Extended Id */

/** @defgroup CAN_remote_transmission_request CAN Remote Transmission Request **/
#define CAN_RTR_DATA                ((uint32)(0x0))  /*!< Data frame   */
#define CAN_RTR_REMOTE              ((uint32)(0x2))  /*!< Remote frame */

#define CAN_RTR_REMOTEFLAG          ((uint32)(0x1))  /*!< Remote flag   */


/** @defgroup CAN_receive_FIFO_number CAN Receive FIFO Number **/
#define CAN_RX_FIFO0                ((uint32)(0x0))  /*!< CAN receive FIFO 0 */
#define CAN_RX_FIFO1                ((uint32)(0x1))  /*!< CAN receive FIFO 1 */

/** @defgroup CAN_filter_FIFO CAN Filter FIFO **/
#define CAN_FILTER_FIFO0            ((uint32)(0x0))  /*!< Filter FIFO 0 assignment for filter x */
#define CAN_FILTER_FIFO1            ((uint32)(0x1))  /*!< Filter FIFO 1 assignment for filter x */

/** @defgroup CAN_filter_mode CAN Filter Mode **/
#define CAN_FILTERMODE_IDMASK       ((uint32)(0x0))  /*!< Identifier mask mode */
#define CAN_FILTERMODE_IDLIST       ((uint32)(0x1))  /*!< Identifier list mode */

/** @defgroup CAN_filter_scale CAN Filter Scale */
#define CAN_FILTERSCALE_16BIT       ((uint32)(0x0))  /*!< Two 16-bit filters */
#define CAN_FILTERSCALE_32BIT       ((uint32)(0x1))  /*!< One 32-bit filter  */

/** @defgroup CAN_IRQn **/
#define CAN_TX_IRQn			19 /* CAN TX Interrupts*/
#define CAN_RX0_IRQn		20 /* CAN RX0 (FIFO_0) Interrupts */
#define CAN_RX1_IRQn		21 /* CAN RX1 (FIFO_1) Interrupts */
#define CAN_SCE_IRQn		22 /* CAN SCE (Status Change Error) Interrupts */


typedef enum {
    CAN_NUM1,
    CAN_NUM2,
} MCAN_Num_t;


typedef enum {
    CAN_Mode_Normal = 0,
    CAN_Mode_Loopback = 1,
    // Add other mode options as needed
} CAN_ModeTypeDef;


typedef enum {
    CAN_TimeTriggerMode_Disabled = 0,
    CAN_TimeTriggerMode_Enabled = 1,
    // Add other time-triggered mode options as needed
} CAN_TimeTriggerModeTypeDef;


// Bit values for each bit for MCR REG 
#define MCAN_MCR_DBF               (0x1U << CAN_MCR_DBF_Pos)
#define MCAN_MCR_TTCM              (0x1U << CAN_MCR_TTCM_Pos)
#define MCAN_MCR_ABOM              (0x1U << CAN_MCR_ABOM_Pos)
#define MCAN_MCR_AWUM              (0x1U << CAN_MCR_AWUM_Pos)
#define MCAN_MCR_NART              (0x1U << CAN_MCR_NART_Pos)
#define MCAN_MCR_RFLM              (0x1U << CAN_MCR_RFLM_Pos)
#define MCAN_MCR_TXFP              (0x1U << CAN_MCR_TXFP_Pos)
#define MCAN_MCR_SLEEP             (0x1U << CAN_MCR_SLEEP_Pos)
#define MCAN_MCR_INRQ              (0x1U << CAN_MCR_INRQ_Pos)




/* 5000 bitrate */

/* struct configuration of CAN */
typedef struct 
{
    MCAN_Num_t	CanNum;			/* CAN number 										*/
	u32 Bitrate;  				/* CAN bitrate 			                            */
    u8	Mode;       			/* CAN operating mode (e.g., normal, loopback)      */
    u8	TimeSeg1;   			/* Time segment 1                                   */
    u8	TimeSeg2;   			/* Time segment 2                                   */
    u8	SyncJumpWidth; 			/* Synchronization Jump Width                       */
    u8	TimeTriggeredMode; 		/* Time-Triggered Communication Mode                */
    u8	AutoBusOff; 			/* Automatic Bus-Off Management                     */
    u8	AutoWakeUp; 			/* Automatic Wakeup Mode                            */
    u8	AutoRetransmission; 	/* Automatic Retransmission                         */
    u8	ReceiveFifoLocked;  	/* Receive FIFO Locked Mode                         */
    u8	TransmitFifoPriority; 	/* Transmit FIFO Priority							*/

} CAN_Config_t;



/* Function prototypes for your custom CAN driver	*/
STD_error_t MCAN_stderrInit(CAN_Config_t* ARG_pconfigConfig);
void MCAN_voidTransmit(u32 id, u32* data, u32 length);
void MCAN_voidReceive(u32* id, u32* data, u32* length);
void MCAN_voidErrorHandler(void);



#endif