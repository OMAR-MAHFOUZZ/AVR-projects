/*
 * led_module.c
 *
 * Created: 6/18/2024 7:19:52 PM
 *  Author: omar mahfouz
 */ 
#include "DIO.h"
void led_init(char port , char pin)
{
	DIO_SETPIN_DIR(port,pin,1);
}

void led_on(char port,char pin)
{
	DIO_WRITE(port , pin , 1);
}

void led_off(char port , char pin )
{
	DIO_WRITE(port,pin,0);
}
void led_tog(char port , char pin)
{
	DIO_TOGGLE_BIT(port,pin);
}
char led_read(char port , char pin)
{
	int val =DIO_READ(port,pin);
	return val;
}