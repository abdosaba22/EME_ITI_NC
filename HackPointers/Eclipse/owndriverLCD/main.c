/*
 * CoolerSystemApp.c
 *
 * Created: 12/10/2021 10:31:23 AM
 * Author : Abd-Alrahman Saba
 */ 

#include "header.h"
#include "LCD.h"


int main(void)
{	
    LCD_init();
    CLRBIT(PORTA,1);
    LCD_write_string("hello");
    while (1) 
    {

    }

}

