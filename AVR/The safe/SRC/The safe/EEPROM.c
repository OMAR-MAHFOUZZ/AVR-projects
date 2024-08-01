/*
 * EEPROM.c
 *
 * Created: 7/24/2024 10:15:43 PM
 *  Author: Omar Mahfouz
 */ 
#include "STD_MACROS.h"
#include <avr/io.h>
void EEPROM_vwrite(unsigned short address, char data)
{
	EEARL=(char)address;
	EEARH=(char)address>>8;
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	
	
	while(READ_BIT(EECR,EEWE)==1);
	
	
}

unsigned char EEPROM_u8read(unsigned short address)
{
	EEARL=(char)address;
	EEARH=(char)address>>8;
	SET_BIT(EECR,EERE);
	return EEDR;
	
	
} 