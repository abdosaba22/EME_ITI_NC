/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.1                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : August 8, 2023	                    */
/* ************************************************ */


#ifndef _HLCD_CONFIG_H_
#define _HLCD_CONFIG_H_

#define F_CPU     						8000000UL


#define HLCD_4BIT_MODE  			 	1
#define HLCD_8BIT_MODE					2

#define HLCD_MODE      					HLCD_4BIT_MODE


#define HLCD_DATA_PORT 					MDIO_PORTA /*Data port from D0:D7 */
#define HLCD_CTRL_PORT 					MDIO_PORTA /*Control port for RS,EN and RW */


#define HLCD_D4_PIN 					MDIO_PIN4
#define HLCD_D5_PIN 					MDIO_PIN5
#define HLCD_D6_PIN 					MDIO_PIN6
#define HLCD_D7_PIN 					MDIO_PIN7

#define HLCD_RS_PIN 					MDIO_PIN0
#define HLCD_RW_PIN 					MDIO_PIN1
#define HLCD_EN_PIN 					MDIO_PIN2


#endif
