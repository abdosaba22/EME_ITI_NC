/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 CAN								*/
/* MCu         	:	 Stm32F446RE						*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 2, 2023					*/
/* Last Edit   	:	 N/A								*/
/* **************************************************** */

#ifndef _MCAN_PRIVATE_H_
#define _MCAN_PRIVATE_H_



/******************* bxCAN Peripheral Base Addresses ********************/ 

#define MCAN1_BASE_ADDRESS			0x40006400U
#define MCAN2_BASE_ADDRESS			0x40006800U
/**********************************************************************/


/***************** bxCAN Register Definition Structure ***************/

typedef struct 
{
   	volatile u32 MCR;     	/* Master Control Register			*/
    volatile u32 MSR;     	/* Mode Status Register             */
    volatile u32 TSR;     	/* Transmit Status Register         */
    volatile u32 RF0R;    	/* Receive FIFO 0 Register          */
    volatile u32 RF1R;    	/* Receive FIFO 1 Register          */
    volatile u32 IER;     	/* Interrupt Enable Register        */
    volatile u32 ESR;     	/* Error Status Register            */
    volatile u32 BTR;     	/* Bit Timing Register              */
	u32 	RESERVED0[88];
    /* Transmit Mailboxes	*/
    struct 
	{
        volatile u32 TIR; 	/* Transmit Mailbox Identifier Register                             */
        volatile u32 TDTR; 	/* Transmit Mailbox Data Length Control and Time Stamp Register     */
        volatile u32 TDLR; 	/* Transmit Mailbox Data Low Register                               */
        volatile u32 TDHR; 	/* Transmit Mailbox Data High Register								*/
    }TX_MAILBOX[3];
    /* Receive FIFO Mailboxes	*/
    struct
	{
        volatile u32 RIR; 	/* Receive FIFO Mailbox Identifier Register             */
        volatile u32 RDTR; 	/* Receive FIFO Mailbox Data Length Control Register    */
        volatile u32 RDLR; 	/* Receive FIFO Mailbox Data Low Register               */
        volatile u32 RDHR; 	/* Receive FIFO Mailbox Data High Register				*/
    }RX_FIFO[2];
	u32  	RESERVED1[12];
	volatile u32 FMR;     	/* Filter Master Register				*/
    volatile u32 FM1R;    	/* Filter Mode Register                 */
    u32  	RESERVED2;
	volatile u32 FS1R;    	/* Filter Scale Register                */
    u32 	RESERVED3;
	volatile u32 FFA1R;   	/* Filter FIFO Assignment Register      */
    u32 	RESERVED4;
	volatile u32 FA1R;    	/* Filter Activation Register           */
	u32 	RESERVED5[8];
    /* Filter Banks (0-27)	*/
    struct 
	{
        volatile u32 FR1; 	/* Filter Register 1    */
        volatile u32 FR2; 	/* Filter Register 2	*/
    }FILTER_BANK[28];

} MCAN_REGDEF_t;
/**********************************************************************/

/******************* bxCAN Peripheral Definition **************/

#define CAN1 			 ((MCAN_REGDEF_t*) MCAN1_BASE_ADDRESS)
#define CAN2 			 ((MCAN_REGDEF_t*) MCAN1_BASE_ADDRESS)
/**********************************************************************/



// CAN_MCR register bit positions
#define CAN_MCR_DBF_Pos           (16U) /* Debug Freeze bit								*/
#define CAN_MCR_TTCM_Pos          (7U)  /* Time Triggered Communication Mode bit        */
#define CAN_MCR_ABOM_Pos          (6U)  /* Automatic Bus-Off Management bit             */
#define CAN_MCR_AWUM_Pos          (5U)  /* Automatic Wakeup Mode bit                    */
#define CAN_MCR_NART_Pos          (4U)  /* No Automatic Retransmission bit              */
#define CAN_MCR_RFLM_Pos          (3U)  /* Receive FIFO Locked Mode bit                 */
#define CAN_MCR_TXFP_Pos          (2U)  /* Transmit FIFO Priority bit                   */
#define CAN_MCR_SLEEP_Pos         (1U)  /* Sleep Mode Request bit                       */
#define CAN_MCR_INRQ_Pos          (0U)  /* Initialization Request bit                   */
/******************************************************************************************/



#endif