
/*
 * header.h
 *
 * Created: 12/4/2021 2:48:04 PM
 *  Author: Abd-Alrahman Saba
 */ 
#ifndef HEADER_H_ 
#define HEADER_H_
 
#include <avr/io.h>   // include all register addresses
#define F_CPU 8000000UL // set the frequency
#include <util/delay.h> // this header include all delay function 
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt


#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#endif 
