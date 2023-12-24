/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: DELL
 */


#define F_CPU 		8000000UL
#include <util/delay.h>

#include "LSTD_types.h"

#include "MDIO_interface.h"

#define LCD_DATA_PORT 	MDIO_PORTA
#define LCD_CTRL_PORT 	MDIO_PORTB

#define LCD_RS_PIN 	0
#define LCD_RW_PIN 	1
#define LCD_EN_PIN 	2

void LCD_init(void);
void LCD_sendCmd(u8 ARG_u8Cmd);
void LCD_sendData(u8 ARG_u8Data);

int main(void){
	// Initialization  (Run Once)

	int i=0;
	char arr [20]= "7ADEDA *_*";

	LCD_init();

	do{
		LCD_sendData(arr[i]);
		i++;
	}while(arr[i]!='\0');

	while(1){
		// Application (Run )



	}
	return 0;
}

void LCD_init(void){

	MDIO_stderrSetPortDirection(LCD_DATA_PORT,0xFF);
	MDIO_stderrSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN ,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN ,MDIO_OUTPUT);
	MDIO_stderrSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN ,MDIO_OUTPUT);

	LCD_sendCmd(0x3c);
	_delay_us(50);
	LCD_sendCmd(0x06);
	_delay_us(50);
	LCD_sendCmd(0x0F);
	_delay_us(50);
	LCD_sendCmd(0x01);
	_delay_us(50);
	_delay_ms(2);
}

void LCD_sendData(u8 ARG_u8Data)
{
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN,MDIO_HIGH);
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN,MDIO_LOW);


	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN,MDIO_LOW);
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN,MDIO_HIGH);
	MDIO_stderrSetPortValue(LCD_DATA_PORT,ARG_u8Data);
	_delay_us(2);
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN,MDIO_LOW);
}

void LCD_sendCmd(u8 ARG_u8Cmd)
{
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN,MDIO_LOW);
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN,MDIO_LOW);


	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN,MDIO_LOW);
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN,MDIO_HIGH);
	MDIO_stderrSetPortValue(LCD_DATA_PORT,ARG_u8Cmd);
	_delay_us(2);
	MDIO_stderrSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN,MDIO_LOW);
}
