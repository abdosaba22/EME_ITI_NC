/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : DIO                                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 2, 2023                     */
/* Last Edit   : N/A                                */
/* ************************************************ */

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_


#define MDIO_PORTA  				1U
#define MDIO_PORTB  				2U
#define MDIO_PORTC  				3U
#define MDIO_PORTD  				4U

/* DIO Port Direction option  */
#define MDIO_OUTPUT_PORT			0XFFU
#define MDIO_INPUT_PORT				0X00U

/* DIO Pin Direction option  */
#define MDIO_OUTPUT					1U
#define MDIO_INPUT					0U

/* DIO Value pin high ,low  */
#define MDIO_HIGH					1U
#define MDIO_LOW					0U

/* DIO pin option  */
#define MDIO_PIN0    				0U
#define MDIO_PIN1    				1U
#define MDIO_PIN2    				2U
#define MDIO_PIN3    				3U
#define MDIO_PIN4    				4U
#define MDIO_PIN5    				5U
#define MDIO_PIN6    				6U
#define MDIO_PIN7    				7U


void MDIO_voidSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction);
void MDIO_voidSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value);
u8 MDIO_u8GetPortValue(u8 ARG_u8Port);
void MDIO_voidSetPinDirection(u8 ARG_u8Port,u8 ARG_u8Pin, u8 ARG_u8Direction);
void MDIO_voidSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin , u8 ARG_u8Value);
void MDIO_voidTogglePinValue(u8 ARG_u8Port ,u8 ARG_u8Pin);
u8 MDIO_u8GetPinValue(u8 ARG_u8Port ,u8 ARG_u8Pin );
void MDIO_voidEnablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin);
void MDIO_voidDisablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin);


#endif
