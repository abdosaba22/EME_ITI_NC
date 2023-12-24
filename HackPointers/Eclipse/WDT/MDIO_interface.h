/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : DIO                                */
/* Layer       : MCAL                               */
/* Version     : 1.2                                */
/* Date        : August 3, 2023                     */
/* Last Edit   : August 4, 2023                     */
/* ************************************************ */


#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_


#define MDIO_PORTA					1U
#define MDIO_PORTB					2U
#define MDIO_PORTC					3U
#define MDIO_PORTD					4U

#define MDIO_OUTPUT					1U
#define MDIO_INPUT					2U
#define MDIO_INPUT_PULLUP			3U
 
#define MDIO_LOW					1U
#define MDIO_HIGH					2U

/* DIO pin option  */
#define MDIO_PIN0    				0U
#define MDIO_PIN1    				1U
#define MDIO_PIN2    				2U
#define MDIO_PIN3    				3U
#define MDIO_PIN4    				4U
#define MDIO_PIN5    				5U
#define MDIO_PIN6    				6U
#define MDIO_PIN7    				7U


/* Port Access */
STD_error_t MDIO_stderrSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction);
STD_error_t MDIO_stderrSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value);
STD_error_t	MDIO_stderrGetPortValue(u8* ARG_u8pValue, u8 ARG_u8Port);

/* Pin Access */
STD_error_t MDIO_stderrSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction);
STD_error_t MDIO_stderrSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Value);
STD_error_t MDIO_stderrGetPinValue(u8* ARG_u8pValue, u8 ARG_u8Port, u8 ARG_u8Pin);
STD_error_t MDIO_stderrTogglePinValue(u8 ARG_u8Port ,u8 ARG_u8Pin);


#endif
