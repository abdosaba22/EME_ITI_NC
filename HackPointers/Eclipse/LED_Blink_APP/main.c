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




int main(void){
	char flag = 0; /* used to start count or stop */
	int Last_num=0,i ;
				// 0         1          2        3
	int arrSSD[11]={0b0111111,0b0000110,0b01011011,0b1001111,
			0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};

	/* SSD Init */
	DDRB=0xFF;
	PORTB=0x00;
	/* DDRA & use PULL UP  */
	DDRA=0x00;
	PORTA=0x0F;

	while(1)
	{

		/* Loop for counter */
		while(flag==1){
			// Last_num used to save the last elem in stop
			for(i=Last_num;i<10;i++){
				Last_num=0;
				/* SW1 pressed stop */
				if(0==GIT_BIT(PINA,0)){
					flag=0 ; /* flag counter  */
					Last_num=i;
					while(0==GIT_BIT(PINA,0)); //stuck while SW3 is pressed
					break;
				}
				/*SW2 pressed reset */
				else if(0==GIT_BIT(PINA,1)){
					i=0;
					while(0==GIT_BIT(PINA,1)); //stuck while SW3 is pressed
				}
				/* writ the number on SSD*/
				PORTB=arrSSD[i];
				_delay_ms(500);
			}
		}
		/*SW3 start*/
		if(0==GIT_BIT(PINA,2)){
			while(0==GIT_BIT(PINA,2)); // stuck while SW3 is pressed
			flag=1;
		}


	}

}
