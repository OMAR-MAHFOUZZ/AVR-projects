/*
 * push_button.c
 *
 * Created: 6/18/2024 8:34:04 PM
 *  Author: PC
 */ 
#include "DIO.h"
void pushbutt_inti(char port , char pin)
{
	DIO_SETPIN_DIR(port,pin,0);
}
char pushbutt_read(char port , char pin )
{
	char val;
	val=DIO_READ(port,pin);
	return val;
}