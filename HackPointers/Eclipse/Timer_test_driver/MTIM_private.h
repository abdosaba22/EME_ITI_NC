/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : Timers				                */
/* Layer       : MCAL                               */
/* Version     : 1.1                                */
/* Date        : August 17, 2023                    */
/* Last Edit   : August 20, 2023                    */
/* ************************************************ */

#ifndef _MTIM0_PRIVATE_H_
#define _MTIM0_PRIVATE_H_


/* Register Addresses Timer0 */
#define TCNT0  		 	*((volatile u8*) 0x52)

#define TCCR0   		*((volatile u8*) 0x53)
/* Bit Positions in TCCR0 */
#define FOC0    		7
#define WGM00   		6
#define COM01   		5
#define COM00   		4
#define WGM01   		3
#define CS02    		2
#define CS01    		1
#define CS00    		0

#define TIFR    		*((volatile u8*) 0x58)
/* Bit Positions in TIFR */
#define OCF2    		7
#define TOV2    		6
#define ICF1    		5
#define OCF1A   		4
#define OCF1B   		3
#define TOV1    		2
#define OCF0    		1
#define TOV0    		0

#define TIMSK  			*((volatile u8*) 0x59)
/* Bit Positions in TIMSK */
#define OCIE2   		7
#define TOIE2   		6
#define TICIE1  		5
#define OCIE1A  		4
#define OCIE1B  		3
#define TOIE1   		2
#define OCIE0   		1
#define TOIE0   		0

#define OCR0 			*((volatile u8*) 0x5C)


/* Register Addresses Timer1 */

#define TCCR1A    		*((volatile u8*) 0x4F)
/* Bit Positions in TCCR1A */
#define COM1A1    		7
#define COM1A0    		6
#define COM1B1    		5
#define COM1B0    		4
#define FOC1A     		3
#define FOC1B     		2
#define WGM11     		1
#define WGM10     		0

#define TCCR1B    		*((volatile u8*) 0x4E)
/* Bit Positions in TCCR1B */
#define ICNC1     		7
#define ICES1     		6
#define WGM13     		4
#define WGM12     		3
#define CS12      		2
#define CS11      		1
#define CS10      		0

#define TCNT1H    		*((volatile u8 *) 0x4D)
#define TCNT1L    		*((volatile u8 *) 0x4C)
// TCNT1 		
#define TCNT1     		*((volatile u16 *) 0x4C)
		
				
#define OCR1AH    		*((volatile u8 *) 0x4B)
#define OCR1AL    		*((volatile u8 *) 0x4A)
//OCR1A 		                          
#define OCR1A     		*((volatile u16*) 0x4A)
		
		
#define OCR1BH    		*((volatile u8 *) 0x49)
#define OCR1BL    		*((volatile u8 *) 0x48)
// OCR1B		
#define OCR1B     		*((volatile u16*) 0x48)
		
		
#define ICR1H     		*((volatile u8 *) 0x47)
#define ICR1L     		*((volatile u8 *) 0x46)
// ICR1		                              
#define ICR1     		*((volatile u16*) 0x46)

/* Register Addresses Timer2 */

#define TCCR2           *((volatile u8*) 0x45 )
#define FOC2            7
#define WGM20           6
#define COM21           5
#define COM20           4
#define WGM21           3
#define CS22            2
#define CS21            1
#define CS20            0

#define TCNT2           (*(volatile u8*)(0x44))

#define OCR2            (*(volatile u8*)(0x43))


#define ASSR_ADDRESS    (*(volatile u8*)(0x42))
#define AS2             7
#define TCN2UB          2
#define OCR2UB          1
#define TCR2UB          0



#endif




