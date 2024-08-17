/*
 * TIme_master_functions.c
 *
 * Created: 8/17/2024 3:04:20 AM
 *  Author: Omar Mahfouz
 */ 
#include "keypad.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
extern volatile unsigned char seconds_counter;
extern unsigned char minutes_counter,hours_counter,date_day,date_month,date_year;
extern unsigned char minutes_counter_alarm,hours_counter_alarm,seconds_counter_alarm;
unsigned char x[2],i;
void set_watch(void)
{
	LCD_clearscreen();
	LCD_send_string("set Hours:");
	
	for(i=0;i<2;i++)
	{	
		do 
		{
			x[i]=keypad_checkpress();	
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}	
	_delay_ms(500);
	hours_counter=((x[0]-48)*10)+(x[1]-48);

//*********************************************	
	LCD_clearscreen();
	LCD_send_string("set Minutes:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	minutes_counter=((x[0]-48)*10)+(x[1]-48);

//*********************************************	
	LCD_clearscreen();
	LCD_send_string("set Seconds:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	seconds_counter=((x[0]-48)*10)+(x[1]-48);
	LCD_clearscreen();
		LCD_send_string("1)watch 2)date");
		LCD_move_cursor(2,1);
		LCD_send_string("3)Alarm");

}
void set_date(void)
{
	LCD_clearscreen();
	LCD_send_string("set day:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	date_day=((x[0]-48)*10)+(x[1]-48);
//*********************************************	
	LCD_clearscreen();
	LCD_send_string("set month:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	date_month=((x[0]-48)*10)+(x[1]-48);

//*********************************************	
	LCD_clearscreen();
	LCD_send_string("set year:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	date_year=((x[0]-48)*10)+(x[1]-48);
	LCD_clearscreen();
		LCD_send_string("1)watch 2)date");
		LCD_move_cursor(2,1);
		LCD_send_string("3)Alarm");

}
void set_alarm(void)
{
	LCD_clearscreen();
	LCD_send_string("set Hours:");
	
	for(i=0;i<2;i++)
	{	
		do 
		{
			x[i]=keypad_checkpress();	
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}	
	_delay_ms(500);
	hours_counter_alarm=((x[0]-48)*10)+(x[1]-48);

//*********************************************	
	LCD_clearscreen();
	LCD_send_string("set Minutes:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	minutes_counter_alarm=((x[0]-48)*10)+(x[1]-48);

//*********************************************	
	LCD_clearscreen();
	LCD_send_string("set Seconds:");
	for(i=0;i<2;i++)
	{
		do
		{
			x[i]=keypad_checkpress();
		} while (x[i]==NOT_PRESSED);
		_delay_ms(250);
		LCD_vsend_char(x[i]);
	}
	_delay_ms(500);
	seconds_counter_alarm=((x[0]-48)*10)+(x[1]-48);
	LCD_clearscreen();
		LCD_send_string("1)watch 2)date");
		LCD_move_cursor(2,1);
		LCD_send_string("3)Alarm");
}