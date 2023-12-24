/* **************************************************** */
/* Author      	:	 Abd-alrahman Amin					*/
/* SWC         	:	 Direct Mem Access					*/
/* Layer       	:	 MCAL              					*/
/* Version     	:	 1.0               					*/
/* Date        	:	 October 1, 2023					*/
/* Last Edit   	:	 N/A 								*/
/* **************************************************** */

#ifndef _DMA_PRIVATE_H_
#define _DMA_PRIVATE_H_



/*************************** DMA Base Addresses ***************************/
#define DMA1_BASE_ADDRESS		0x40026000UL

#define DMA2_BASE_ADDRESS		0x40026400UL
/**********************************************************************************/


/************************** DMA Register Definition Structure ***********************/

typedef struct
{
	volatile u32 CR;				 /*DMA stream x configuration register*/
	volatile u32 NDTR;              /*DMA stream x number of data register*/
	volatile u32 PAR;               /*DMA stream x peripheral address register*/
	volatile u32 M0AR;              /*DMA stream x memory 0 address register*/
	volatile u32 M1AR;              /*DMA stream x memory 1 address register*/
	volatile u32 FCR;               /*DMA stream x FIFO control register*/
}Stream_RegDef_t;

typedef struct
{
	volatile u16 ISR[4];	   /* uint16_t of 4 elem */		   	 /*DMA low interrupt status register*/ 
	volatile u16 IFCR[4];     /* uint16_t of 4 elem */             /*DMA low interrupt flag clear register*/
	//volatile uint32_t LISR;	 		   	 /*DMA low interrupt status register*/ 
	//volatile uint32_t HISR;                /*DMA high interrupt status register*/
	//volatile uint32_t LIFCR;               /*DMA low interrupt flag clear register*/
	//volatile uint32_t HIFCR;               /*DMA high interrupt flag clear register*/
	volatile Stream_RegDef_t Stream[8];
}DMA_RegDef_t;
 
/**********************************************************************************/ 

/***************************** DMA Peripheral Definitions **************************/
#define DMA1					((DMA_RegDef_t*)DMA1_BASE_ADDRESS)	
#define DMA2					((DMA_RegDef_t*)DMA2_BASE_ADDRESS)	

/********************************************************************************/


/***************** Private enums and defines ***************/

#define STREAMS_NUM    8
#define CHANNELS_NUM   8
#define INTERRUPTS_NUM 6

typedef enum
{
  EN = 0,      // DMA stream enable
  DMEIE,   // Direct mode error interrupt enable
  TEIE ,    // Transfer error interrupt enable
  HTIE ,    // Half transfer interrupt enable
  TCIE ,    // Transfer complete interrupt enable
  PFCTRL,  // Peripheral flow controller
  DIR ,    // Data transfer direction
  CIRC = 8,    // Circular mode
  PINC  ,  // Peripheral increment mode
  MINC  ,  // Memory increment mode
  PSIZE ,  // Peripheral data size
  MSIZE = 13,  // Memory data size
  PINCOS = 15, // Peripheral increment offset size
  PL = 16,     // Priority level
  DBM = 18,    // Double buffer mode  HINT: This bit can be written only if EN = 0
  CT = 19,     // Current target (only in double buffer mode) HINT: This bit can be written only if EN = 0
  PBURST = 21, // Peripheral burst transfer configuration
  MBURST = 23, // Memory burst transfer configuration
  CHSEL = 25,  // Channel selection
} DMA_SCR_BITS_t;

#define NDT  		0 // Number of data items to transfer
//#define PA_R  		0 // Peripheral address
#define M0A  		0 // Memory 0 address
#define M1A  		0 // Memory 0 address

#define FTH  		0   // FIFO threshold selection
#define DMDIS 		2 // Direct mode disable
#define FS 			3    // FIFO status
#define FEIE 		7  // FIFO error interrupt enable

#define FourBitMask	 		0b1111
#define ThreeBitMask	 	0b111
#define TwoBitMask	 		0b11
#define OneBitMask	 		0b1


#endif
