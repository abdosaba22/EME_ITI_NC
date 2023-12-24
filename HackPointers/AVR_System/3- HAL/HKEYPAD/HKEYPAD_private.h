/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : KEYPAD                             */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : August 9, 2023                     */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

#ifndef _HKPD_PRIVATE_H_
#define _HKPD_PRIVATE_H_


#define HKPD_COL_NUM 						4
#define HKPD_ROW_NUM 						4

#define HKPD_ROW0(x) 						MDIO_stderrSetPinValue(HKPD_ROW_PORT,HKPD_ROW0_PIN,x)
#define HKPD_ROW1(x) 						MDIO_stderrSetPinValue(HKPD_ROW_PORT,HKPD_ROW1_PIN,x)
#define HKPD_ROW2(x) 						MDIO_stderrSetPinValue(HKPD_ROW_PORT,HKPD_ROW2_PIN,x)
#define HKPD_ROW3(x) 						MDIO_stderrSetPinValue(HKPD_ROW_PORT,HKPD_ROW3_PIN,x)

#define HKPD_COL0(x) 						GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP4_PIN,x)
#define HKPD_COL1(x) 						GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP5_PIN,x)
#define HKPD_COL2(x) 						GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP6_PIN,x)
#define HKPD_COL3(x) 						GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP7_PIN,x)




#endif