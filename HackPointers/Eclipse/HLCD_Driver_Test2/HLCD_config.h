/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : N/A			                    */
/* ************************************************ */


#ifndef _HLCD_CONFIG_H_
#define _HLCD_CONFIG_H_

#define F_CPU     						8000000UL

#define HLCD_DATA_PORT 					MDIO_PORTA /*Data port from D0:D7 */
#define HLCD_CTRL_PORT 					MDIO_PORTB /*Control port for RS,EN and RW */

#define HLCD_RS_PIN 					MDIO_PIN0
#define HLCD_RW_PIN 					MDIO_PIN1
#define HLCD_EN_PIN 					MDIO_PIN2


#endif