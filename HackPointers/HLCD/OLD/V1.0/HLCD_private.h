/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : N/A			                    */
/* ************************************************ */


#ifndef _HLCD_PRIVATE_H_
#define _HLCD_PRIVATE_H_


/* Macros needed */
#define HLCD_DATA_PORT_INIT()						MDIO_stderrSetPortDirection(HLCD_DATA_PORT,0xFF)
#define HLCD_CTRL_INIT(X) 							MDIO_stderrSetPinDirection(HLCD_CTRL_PORT, X ,MDIO_OUTPUT)
#define HLCD_SEND_DATA_PORT(X)						MDIO_stderrSetPortValue(HLCD_DATA_PORT , X)
#define HLCD_RS(X) 									MDIO_stderrSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, X)
#define HLCD_EN(X) 									MDIO_stderrSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, X)
#define HLCD_RW(X) 									MDIO_stderrSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, X)


#endif
