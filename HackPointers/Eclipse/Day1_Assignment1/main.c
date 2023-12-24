/*
 * main.c
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */

#define F_CPU 			8000000UL


#include <avr/io.h>
#include <util/delay.h>
#include "bit_math.h"


#define GREEN_LED  				0 // pinA0
#define YELLOW_LED  			1 // pinA1
#define RED_LED  				2 // pinA2

#define GREEN_DEL  				9
#define YELLOW_DEL  			2
#define RED_DEL  				9
/* 7-segment values */
int arrSSD[11]={0b0111111,0b0000110,0b01011011,0b1001111,
			0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};


/*
 *  Function used to print the delay time
 *  in 7-Segment Display and turn on the led
 *  for the same delay then turn off
 */

void counterDisplay(int copy_delay,int LED){

	SIT_BIT(PORTA,LED);
	for(;copy_delay>=0;copy_delay--){

		PORTB=arrSSD[copy_delay];
		_delay_ms(1000);

	}
	CLEAR_BIT(PORTA,LED);

}


int main(void){
	//int j=0,i ;		// 0         1          2        3


	DDRA=0xFF;  // out led PORTA 0 , 1 , 2 , 3

	DDRB=0xFF; // 7-segment DDRB
	PORTB=0x00;


	while(1){

		counterDisplay(GREEN_DEL,GREEN_LED);
		counterDisplay(YELLOW_DEL,YELLOW_LED);
		counterDisplay(RED_DEL,RED_LED);
		counterDisplay(YELLOW_DEL,YELLOW_LED);

	}

}
