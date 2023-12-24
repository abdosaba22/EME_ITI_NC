/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : WDT				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 23, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

#ifndef _MWDT_INTERFACE_H_
#define _MWDT_INTERFACE_H_

/* #define WDP2_WDP1_WDP0_16K_3V0_MS 			0b000
#define WDP2_WDP1_WDP0_32K_3V0_MS 			0b001
#define WDP2_WDP1_WDP0_64K_3V0_MS 			0b010
#define WDP2_WDP1_WDP0_128K_3V0_MS 			0b011
#define WDP2_WDP1_WDP0_256K_3V0_MS 			0b100
#define WDP2_WDP1_WDP0_512K_3V0_MS 			0b101
#define WDP2_WDP1_WDP0_1024K_3V0_MS 		0b110
#define WDP2_WDP1_WDP0_2048K_3V0_MS 		0b111 */

#define MWDT_5V_16_3_5V0_MS 			0b000
#define MWDT_5V_32_5_MS 				0b001
#define MWDT_5V_65_MS 					0b010
#define MWDT_5V_0_13_S 					0b011
#define MWDT_5V_0_26_S	 				0b100
#define MWDT_5V_0_52_S	 				0b101
#define MWDT_5V_1_S 					0b110
#define MWDT_5V_2_1_S 					0b111


STD_error_t MWDT_stderrInit(u8 ARG_u8Prescaler);
void MWDT_voidEnable(void);
void MWDT_voidDisable(void);
void MWDT_voidReset(void);

#endif
