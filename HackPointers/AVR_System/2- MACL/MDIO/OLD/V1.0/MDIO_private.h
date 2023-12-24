/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : DIO                                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 2, 2023                     */
/* Last Edit   : N/A                                */
/* ************************************************ */

#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

typedef struct{
	const u8	PIN;
	u8 			DDR;
	u8 			PORT;
}GPIO_t;

#define GPIOD  			( (volatile GPIO_t *) (0x30) )
#define GPIOC  			( (volatile GPIO_t *) (0x33) )
#define GPIOB  			( (volatile GPIO_t *) (0x36) )
#define GPIOA  			( (volatile GPIO_t *) (0x39) )


#endif