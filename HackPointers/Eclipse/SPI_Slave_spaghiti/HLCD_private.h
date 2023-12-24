/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.1                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : August 8, 2023	                    */
/* ************************************************ */


#ifndef _HLCD_PRIVATE_H_
#define _HLCD_PRIVATE_H_


/* include config */


/* Macros needed */
#define HLCD_DATA_PORT_INIT()						MDIO_stderrSetPortDirection(HLCD_DATA_PORT,0xFF)
#define HLCD_CTRL_INIT(X) 							MDIO_stderrSetPinDirection(HLCD_CTRL_PORT, X ,MDIO_OUTPUT)
#define HLCD_DATA_INIT(X) 							MDIO_stderrSetPinDirection(HLCD_DATA_PORT, X ,MDIO_OUTPUT)
#define HLCD_SEND_DATA_PORT(X)						MDIO_stderrSetPortValue(HLCD_DATA_PORT , X)


#define HLCD_RS(X) 									MDIO_stderrSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, X)
#define HLCD_EN(X) 									MDIO_stderrSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, X)
#define HLCD_RW(X) 									MDIO_stderrSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, X)

#define HLCD_D4(X) 									MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, X)
#define HLCD_D5(X) 									MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, X)
#define HLCD_D6(X) 									MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, X)
#define HLCD_D7(X) 									MDIO_stderrSetPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, X)


#endif
