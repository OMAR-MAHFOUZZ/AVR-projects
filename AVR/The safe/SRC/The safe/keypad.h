/*
 * keypad.h
 *
 * Created: 7/22/2024 8:43:16 PM
 *  Author: PC
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

void keypad_vinit(void);
#define NOT_PRESSED  0xff
char keypad_checkpress(void);

#endif /* KEYPAD_H_ */