/*
 * LCD_DRIVER.c
 *
 * Created: 7/24/2024 12:32:55 PM
 *  Author: PC
 */ 

#define eight_bit_mode
#define CURSOR_DISPLAY 0x0c
#include "LCD.h"
#define F_CPU	8000000UL
#include <util/delay.h>
void LCD_vsend_char(char data)
{
	#if defined	eight_bit_mode
{
	DIO_write_port(PORT_DATA,data);
	DIO_WRITE(PORT_CONTROL,RS,1);
	enable();
}
	#elif defined four_bit_mode
	{
		
	
	DIO_write_High_nipple(PORT_DATA,data>>4);
	DIO_WRITE(PORT_CONTROL,RS,1);
	enable();
	DIO_write_High_nipple(PORT_DATA,data);
	DIO_WRITE(PORT_CONTROL,RS,1);
	enable();	
	}
	#endif
	_delay_ms(1);
}	
void LCD_vsend_cmd(char cmd)
{
	#if defined	eight_bit_mode
{
	DIO_write_port(PORT_DATA,cmd);
	DIO_WRITE(PORT_CONTROL,RS,0);
	enable();
}
	#elif defined four_bit_mode
	{
	DIO_write_High_nipple(PORT_DATA,cmd>>4);
	DIO_WRITE(PORT_CONTROL,RS,0);
	enable();
	DIO_write_High_nipple(PORT_DATA,cmd);
	DIO_WRITE(PORT_CONTROL,RS,0);
	enable();
	}	
	#endif
	_delay_ms(1);
}
void LCD_init(void)
{
	_delay_ms(200);	
	#if defined eight_bit_mode
	{
		
	
	DIO_SETPORT_DIR(PORT_DATA,0xff);
	DIO_SETPIN_DIR(PORT_CONTROL,EN,1);
	DIO_SETPIN_DIR(PORT_CONTROL,RS,1);	
	DIO_SETPIN_DIR(PORT_CONTROL,RW,1);	
	DIO_WRITE(PORT_CONTROL,RW,0);
	LCD_vsend_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_DISPLAY);
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vsend_cmd(ENTRY_MODE);
	_delay_ms(1);
	}
#elif defined four_bit_mode
{
	DIO_SET_high_nipple(PORT_DATA);
	DIO_SETPIN_DIR(PORT_CONTROL,EN,1);
	DIO_SETPIN_DIR(PORT_CONTROL,RS,1);
	DIO_SETPIN_DIR(PORT_CONTROL,RW,1);
	DIO_WRITE(PORT_CONTROL,RW,0);
	LCD_vsend_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_vsend_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_DISPLAY);
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vsend_cmd(ENTRY_MODE);
	_delay_ms(1);		
}	
	#endif
	
}
void LCD_move_cursor(char row,char col)
{
	char cmd;
	if (row<1 || row>2 || col<1 || col>16)
	{
		cmd=0x80;
	}
	else if(row==1)
	{
		cmd=0x80+col-1;
	}
	else
	{
		cmd=0xc0+col-1;
	}
	LCD_vsend_cmd(cmd);
}
void LCD_clearscreen(void)
{
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_send_string(char *ptr)
{
	while(*ptr != 0)
	{
		LCD_vsend_char(*ptr);
		ptr++;
	}
}
void  enable(void)
{
	DIO_WRITE(PORT_CONTROL,EN,1);
	_delay_ms(2);
	DIO_WRITE(PORT_CONTROL,EN,0);
	_delay_ms(2);

}