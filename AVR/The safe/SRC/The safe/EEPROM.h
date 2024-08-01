/*
 * EEPROM.h
 *
 * Created: 7/24/2024 10:20:23 PM
 *  Author: PC
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_vwrite(unsigned short address, char data);
unsigned char EEPROM_u8read(unsigned short address);


#endif /* EEPROM_H_ */