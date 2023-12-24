/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 Flash Program and erase controller		*/
/* Layer       	:	 MCAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 October 4, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */


#ifndef _MFPEC_INTERFACE_H_
#define _MFPEC_INTERFACE_H_

STD_error_t MFPEC_stderrFlashMassErase(void);

STD_error_t MFPEC_stderrFlashEraseSector(MFPEC_SECTORS_t ARG_secSectorNum);

STD_error_t MFPEC_stderrFlashWrite(u32* ARG_pu32Data, u32 ARG_u32Address,u32 ARG_u32Length );


typedef enum 
{
	MFPEC_SECTOR_0,
    MFPEC_SECTOR_1,
    MFPEC_SECTOR_2,
    MFPEC_SECTOR_3,
    MFPEC_SECTOR_4,
	MFPEC_SECTOR_5,
	
}MFPEC_SECTORS_t;


#define MFLASH_SECTOR_1_BEGIN 				0x08004000U
#define MFLASH_SECTOR_1_END   				0x08007FFFU

#define MFLASH_SECTOR_5_BEGIN 				0x08020000U	 /* Sector at address 0x08020000  */
#define MFLASH_SECTOR_5_END 				0x0803FFFFU	 /* Sector end address 0x0803FFFF  */





#endif
