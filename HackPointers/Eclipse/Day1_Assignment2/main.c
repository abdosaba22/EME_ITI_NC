/*
 * main.c
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */



/* define Crystal 8Mhz */
#define F_CPU 			8000000UL


#include <avr/io.h>
#include <util/delay.h>
#include "bit_math.h"

#define DIP_SW_0          	    (GIT_BIT(PORTB,0))
#define DIP_SW_1          	    (GIT_BIT(PORTB,1)<<1)
#define DIP_SW_2          	    (GIT_BIT(PORTB,2)<<2)
#define DIP_SW_VAL          	~(DIP_SW_0 | DIP_SW_1 | DIP_SW_2)


int main(void){
	int j=0,i ;		// 0         1          2        3
	/* LED Direction */
	DDRA=0xFF;
	PORTA=0x00;

	DDRB=0x0F;
	PORTB=0x0F; /*PULL UP */

	while(1)
	{

		switch(DIP_SW_VAL){
		case 0:
			/* Flashing animation */
			PORTA = 0xFF;
			_delay_ms(500);
			PORTA = 0x00;
			break;

		case 1:
			/* Shift left  */

			for(i=0;i<8;i++){
				SIT_BIT(PORTA,i);
				_delay_ms(250);
				CLEAR_BIT(PORTA,i);
			}
			break;

		case 2:
			/* shift Right */
			for(i=7;i>=0;i--){
				SIT_BIT(PORTA,i);
				_delay_ms(250);
				CLEAR_BIT(PORTA,i);
			}
			break;

		case 3:
			/* Converging animation */
			for(j=7,i=0;i<4;i++,j--){
				SIT_BIT(PORTA,i);
				SIT_BIT(PORTA,j);
				_delay_ms(500);
				CLEAR_BIT(PORTA,i);
				CLEAR_BIT(PORTA,j);
			}
			break;

		case 4:
			/* Diverging animation */
			for(j=3,i=4;i<8;i++,j--){
				SIT_BIT(PORTA,i);
				SIT_BIT(PORTA,j);
				_delay_ms(500);
				CLEAR_BIT(PORTA,i);
				CLEAR_BIT(PORTA,j);
			}
			break;

		case 5:
			/* Ping pong animation */
			for(j=7,i=0;i<8 ;){

				SIT_BIT(PORTA,i);
				_delay_ms(500);
				CLEAR_BIT(PORTA,i);
				if(i==4)break;
				else if(i<4){i=j+i; j=i-j; i=i-j; j++; }
				else if (i>4){ i=j+i; j=i-j; i=i-j; j--;
				}

			}
			break;

		case 6:
			/* Incrementing (Snake effect) animation */
			for(i=0;i<8;i++){
				SIT_BIT(PORTA,i);
				_delay_ms(250);
				CLEAR_BIT(PORTA,i);
			}
			for(i=7;i>=0;i--){
				SIT_BIT(PORTA,i);
				_delay_ms(250);
				CLEAR_BIT(PORTA,i);
			}

			break;

		case 7:
			/* Converging animation */
			for(j=7,i=0;i<4;i++,j--){
				SIT_BIT(PORTA,i);
				SIT_BIT(PORTA,j);
				_delay_ms(500);
				CLEAR_BIT(PORTA,i);
				CLEAR_BIT(PORTA,j);
			}
			for(j=3,i=4;i<8;i++,j--){
				SIT_BIT(PORTA,i);
				SIT_BIT(PORTA,j);
				_delay_ms(500);
				CLEAR_BIT(PORTA,i);
				CLEAR_BIT(PORTA,j);
			}

			break;

		}

	}


}
