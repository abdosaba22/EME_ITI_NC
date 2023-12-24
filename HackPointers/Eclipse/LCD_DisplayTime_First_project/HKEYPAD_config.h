/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : KEYPAD                             */
/* Layer       : HAL                                */
/* Version     : 1.0                                */
/* Date        : August 9, 2023                     */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

#ifndef HKPD_CONFIG_H
#define HKPD_CONFIG_H

#define HKPD_PORT  						MDIO_PORTC
#define HKPD_ROW_PORT  					MDIO_PORTC
#define HKPD_COL_PORT  					MDIO_PORTC


#define HKPD_ROW0_PIN 					MDIO_PIN0
#define HKPD_ROW1_PIN 					MDIO_PIN1
#define HKPD_ROW2_PIN 					MDIO_PIN2
#define HKPD_ROW3_PIN 					MDIO_PIN3

#define HKPD_COL0_PIN 					MDIO_PIN4
#define HKPD_COL1_PIN 					MDIO_PIN5
#define HKPD_COL2_PIN 					MDIO_PIN6
#define HKPD_COL3_PIN 					MDIO_PIN7

#define HKPD_ARR_VAL			{{'7','8','9','A'},{'4','5','6','B'},{'1','2','3','C'},{'*','0','#','D'}}


 // char HKPD_charKeypad[4][4]={
		// {'1','2','3','A'}, 	/*  ROW0  */
		// {'4','5','6','B'},	/*  ROW1  */
		// {'7','8','9','C'},	/*  ROW2  */
		// {'*','0','#','D'}	/*  ROW3  */
// }; 

#endif
