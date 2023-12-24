
/*
 * LCD.h
 *
 * Created: 12/4/2021 2:48:24 PM
 *  Author: Abd-Alrahman Saba
 */ 
#ifndef LCD_H_
#define LCD_H_

#include "header.h" 
#define LCD_PORT_INIT() DDRB |= 0b11110000;\
	DDRA|=0b00000111;

#define RS(x) if(x == 1) SETBIT(PORTA,0); else CLRBIT(PORTA,0);
#define EN(x) if(x == 1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define D4(x) if(x == 1) SETBIT(PORTB,4); else CLRBIT(PORTB,4);
#define D5(x) if(x == 1) SETBIT(PORTB,5); else CLRBIT(PORTB,5);
#define D6(x) if(x == 1) SETBIT(PORTB,6); else CLRBIT(PORTB,6);
#define D7(x) if(x == 1) SETBIT(PORTB,7); else CLRBIT(PORTB,7);

void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_char(uint8_t);
void LCD_write_num(uint16_t);
void LCD_write_string(uint8_t *);

#endif
