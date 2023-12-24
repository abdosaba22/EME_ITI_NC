
/*
 * LCD.c
 *
 * Created: 12/4/2021 2:48:45 PM
 *  Author: Abd-Alrahman Saba
 */ 

#include "LCD.h"
/*****************************************************************************
* Function Name: LCD_init
* Purpose      : initialize LCD - enable mode 4-bit mode - enable both lines - cursor off
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void){
	LCD_PORT_INIT();
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2); //enable 4-bit mode 
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01);//to clear LCD 
	LCD_write_command(0x06);//make cursor increment to right 
	LCD_write_command(0x0C);//turn on the display
 	_delay_ms(20);
}

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : send a specific command to LCD
* Parameters   : uint8_t: the value of command
* Return value : void
*****************************************************************************/

void LCD_write_command(uint8_t com){
	
	// send last 4 bits in com after enable command
	RS(0);
	D4(READBIT(com,4));
	D5(READBIT(com,5));
	D6(READBIT(com,6));
	D7(READBIT(com,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	// send first 4 bits in com after enable command 
	D4(READBIT(com,0));
	D5(READBIT(com,1));
	D6(READBIT(com,2));
	D7(READBIT(com,3));
	EN(1);
	_delay_ms(1);
	EN(0);	
	_delay_ms(1);
	
}
/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : write a char (by ascii) on LCD
* Parameters   : uint8_t: the value of ascii of the char
* Return value : void
*****************************************************************************/

void LCD_write_char(uint8_t data){
	// send last 4 bits in com after enable command
	RS(1);
	D4(READBIT(data,4));
	D5(READBIT(data,5));
	D6(READBIT(data,6));
	D7(READBIT(data,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	// send first 4 bits in com after enable command
	D4(READBIT(data,0));
	D5(READBIT(data,1));
	D6(READBIT(data,2));
	D7(READBIT(data,3));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
}
/************************************************************************
* Function Name: LCD_write_num
* Purpose      : display a specific number on LCD
* Parameters   : uint16_t: 5 digit number or less
* Return value : void
*************************************************************************/

void LCD_write_num(uint16_t num){
	if (num ==0) {LCD_write_char('0');return;}	 
	uint8_t n[5]; int8_t i=0;
	//save every digit of num in our array separately  
	for(;num!=0;i++)
	{
		n[i]=(num%10) +'0';
		num/=10;
	}
	i--;
	while(i!=-1){
		LCD_write_char(n[i]);
		i--;
	}
}
/*****************************************************************************
* Function Name: LCD_write_string
* Purpose      : display a specific string on LCD
* Parameters   : uint8_t*: array of string which must end with null
* Return value : void
*****************************************************************************/

void LCD_write_string(uint8_t *str){
	uint8_t i =0;
	for(;str[i]!='\0';i++){
		LCD_write_char(str[i]);
	}
}

	