/*
 * LCD.h
 *
 * Created: 7/24/2024 12:33:09 PM
 *  Author: PC
 */ 


#ifndef LCD_H_
#define LCD_H_

#define CLR_SCREEN	0x01
//#define CURSOR_DISPLAY 0x0E
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define FOUR_BITS	0x28
#define EIGHT_BITS	0x38
#define EN	0
#define RS	1
#define RW	2
#define PORT_DATA	'A'
#define PORT_CONTROL 'A'
void LCD_vsend_char(char data);
void LCD_vsend_cmd(char cmd);
void LCD_init(void);
void LCD_move_cursor(char row,char col);
void LCD_clearscreen(void);
void LCD_clearscreen(void);
void LCD_send_string(char *ptr);
void enable(void);


#endif /* LCD_H_ */