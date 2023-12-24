/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : DIO                                */
/* Layer       : MCAL                               */
/* Version     : 1.1                                */
/* Date        : August 2, 2023                     */
/* Last Edit   : August 3, 2023                     */
/* ************************************************ */

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_


/* use enum instead  */

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
#define MDIO_INPUT_PULLUP			2U

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


STD_error_t MDIO_stderrSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction);
STD_error_t MDIO_stderrSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value);
STD_error_t MDIO_stderrGetPortValue(u8* ARG_u8PValue,u8 ARG_u8Port);

STD_error_t MDIO_stderrSetPinDirection(u8 ARG_u8Port,u8 ARG_u8Pin, u8 ARG_u8Direction);
STD_error_t MDIO_stderrSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin , u8 ARG_u8Value);
STD_error_t MDIO_stderrTogglePinValue(u8 ARG_u8Port ,u8 ARG_u8Pin);
STD_error_t MDIO_stderrGetPinValue(u8* ARG_u8PValue ,u8 ARG_u8Port ,u8 ARG_u8Pin );

STD_error_t MDIO_stderrEnablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin);
STD_error_t MDIO_stderrDisablePullUP(u8 ARG_u8Port ,u8 ARG_u8Pin);


#endif
