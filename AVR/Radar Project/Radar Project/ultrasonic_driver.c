/*
 * ultrasonic_driver.c
 *
 * Created: 8/15/2024 12:56:01 AM
 *  Author: Omar Mahfouz
 */ 

#include "DIO.h"
#include "STD_MACROS.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
void send_trigger(char port,char pin)
{
	DIO_SETPIN_DIR(port,pin,1);
	DIO_WRITE(port,pin,1);
	_delay_us(50);
	DIO_WRITE(port,pin,0);
}

unsigned short recive_data(void)
{
	unsigned short a,b,high;
	TCCR1A=0;
	SET_BIT(TIFR,ICF1);
	
	TCCR1B=0xc1;
	while(READ_BIT(TIFR,ICF1)==0);
	a=TCNT1;
	SET_BIT(TIFR,ICF1);
	TCCR1B=0x81;
	while(READ_BIT(TIFR,ICF1)==0);
	b=TCNT1;
	SET_BIT(TIFR,ICF1);
	high=b-a;
	TCCR1B=0;
	TCNT1=0;
	
	
	return high;
	
	
}





