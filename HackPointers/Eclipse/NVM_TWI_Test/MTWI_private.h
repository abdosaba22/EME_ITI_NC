/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : TWI				                */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 29, 2023                    */
/* Last Edit   : N/A		   	                    */
/* ************************************************ */

#ifndef _MTWI_PRIVATE_H_
#define _MTWI_PRIVATE_H_

#define TWDR	   				*((volatile u8*)0x23)  // TWDR Two-wire Serial Interface Data Register address
		
#define TWAR	   				*((volatile u8*)0x22)  // TWAR Two-wire Serial Interface Address Register address
// Bit positions for TWAR register
#define TWA0 					1  // Bit 1
#define TWGCE  				0  // Bit 0


#define TWSR					 	*((volatile u8*)0x21)   // TWSR Two-wire Serial Interface Status Register address (0x21)
// Bit positions for TWSR register
#define TWS3 					3  
#define TWPS1 					1  
#define TWPS0 					0

	
#define TWBR					 	*((volatile u8*)0x20)   // TWBR Two-wire Serial Interface Bit Rate Register address (0x20)

#define TWCR					 	*((volatile u8*)0x56)   // TWCR Two-wire Serial Interface Control Register address (0x56)
// Bit positions for TWCR register
#define TWINT 					7   
#define TWEA  					6   
#define TWSTA 					5   
#define TWSTO 					4   
#define TWWC  					3   
#define TWEN  					2   
#define TWIE  					0   

#define TWS_MASK				0xF8


#endif
