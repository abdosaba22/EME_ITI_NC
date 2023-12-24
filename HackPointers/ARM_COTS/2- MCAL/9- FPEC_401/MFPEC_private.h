/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 Flash Program and erase controller		*/
/* Layer       	:	 MCAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 October 4, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */


#ifndef _MFPEC_PRIVATE_H_
#define _MFPEC_PRIVATE_H_

/******************* FPEC Peripheral Base Addresses ********************/ 

#define MFPEC_BASE_ADDRESS				0x40023C00U
 

typedef enum 
{
    PG_BIT   		,    // Bit 0
    SER_BIT   		,    // Bit 1
    MER_BIT   		,    // Bit 2
    SNB_BIT_0  		,    // Bit 3
    PSIZE_BIT = 8	,	 // BIT 8
	STRT_BIT  = 16	,    // Bit 16
	EOPIE_BIT = 24	,  // Bit 10
    ERRIE_BIT 		,  // Bit 10
    LOCK_BIT = 31	,    // Bit 31

} MFPEC_CRBITS_t;

typedef enum 
{
    EOP_FLAG ,
    OPERR_FLAG,
	WRPERR_FLAG = 4,
	PGAERR_FLAG ,
	PGPERR_FLAG ,
	PGSERR_FLAG ,
	RDERR_FLAG	,
	BSY_FLAG = 16,
} MFPEC_SRBITS_t;


/************************** FPEC Register Definition Structure ***********************/
typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}MFPEC_RegDef_t;


#define FPEC 			((MFPEC_RegDef_t*)MFPEC_BASE_ADDRESS)



/******************* Private Defines ****************************/

#define FPEC_KEY1		0x45670123U
#define FPEC_KEY2		0xCDEF89ABU

#define FLASH_BASE		0x08000000U

#define MFLASH_SECTOR_1_BEGIN		0x08004000
#define MFLASH_SECTOR_1_END   		0x08007FFF

#define MFLASH_SECTOR_5_BEGIN 		0x08020000U	 
#define MFLASH_SECTOR_5_END 		0x0803FFFFU	 


/****************************************************************/		

STD_error_t MFPEC_stderrFlashUnlock(void);

STD_error_t MFPEC_stderrFlashLock(void);


#endif
