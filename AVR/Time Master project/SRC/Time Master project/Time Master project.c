/*
 * Time_Master_project.c
 *
 * Created: 8/16/2024 10:46:29 PM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer Master functions.h"
#include "seven_segment.h"
#include "LCD.h"
#include "keypad.h"
#include "Timer_driver.h"
#include "push button.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define seg_port	'B'
#define seg_control  'C'
#define button_port  'B'
#define button_pin    4
#define BUZZER_port  'B'
#define BUZZER_pin    5
volatile unsigned char seconds_counter=0;
unsigned char minutes_counter,hours_counter,date_day,date_month,date_year;
unsigned char flag=0,i,minutes_counter_alarm,hours_counter_alarm,seconds_counter_alarm;
int main(void)
{
	unsigned char choice=0;
	LCD_init();
	keypad_vinit();
	timer2_ovf_init_interrupt();
	seven_seg_init_BCD(seg_port,'L');//L for low nipple
	DIO_SETPIN_DIR(seg_control,0,1);
	DIO_SETPIN_DIR(seg_control,1,1);
	DIO_SETPIN_DIR(seg_control,2,1);
	DIO_SETPIN_DIR(seg_control,3,1);
	DIO_SETPIN_DIR(seg_control,4,1);
	DIO_SETPIN_DIR(seg_control,5,1);
	DIO_SETPIN_DIR(button_port,button_pin,0);
	DIO_SETPIN_DIR(BUZZER_port,BUZZER_pin,1);
	LCD_send_string("1)watch 2)date");
	LCD_move_cursor(2,1);
	LCD_send_string("3)Alarm");
	
    while(1)
    {
		choice=keypad_checkpress();
		if (choice!=NOT_PRESSED)
		{
			_delay_ms(250);
			 switch (choice)
			 {
				 case '1':set_watch();
						break;
				 case '2':set_date();
						break;
				 case '3':set_alarm();
						flag=1;
						break; 	
				 default:break;
			 }
		}
       
//*********************************************************	

	if (seconds_counter==seconds_counter_alarm && minutes_counter==minutes_counter_alarm && seconds_counter_alarm==seconds_counter && flag==1)
	{
		for(i=0;i<4;i++)
		{
		DIO_WRITE(BUZZER_port,BUZZER_pin,1);
		_delay_ms(500);
		DIO_WRITE(BUZZER_port,BUZZER_pin,0);
		_delay_ms(500);			
		}
	}
//*********************************************************		
		if (pushbutt_read(button_port,button_pin)==1)
		{
				do 
				{
				
					DIO_WRITE(seg_control,0,0);
					DIO_WRITE(seg_control,1,0);
					DIO_WRITE(seg_control,2,0);
					DIO_WRITE(seg_control,3,0);
					DIO_WRITE(seg_control,4,0);
					DIO_WRITE(seg_control,5,0);
					DIO_WRITE(seg_control,0,1);
					seven_seg_write_BCD(seg_port,date_day%10,'L');
					_delay_ms(5);
					DIO_WRITE(seg_control,0,0);
					DIO_WRITE(seg_control,1,1);
					seven_seg_write_BCD(seg_port,date_day/10,'L');
					_delay_ms(5);
					DIO_WRITE(seg_control,1,0);
					DIO_WRITE(seg_control,2,1);
					seven_seg_write_BCD(seg_port,date_month%10,'L');
					_delay_ms(5);
					DIO_WRITE(seg_control,2,0);
					DIO_WRITE(seg_control,3,1);
					seven_seg_write_BCD(seg_port,date_month/10,'L');
					_delay_ms(5);
					DIO_WRITE(seg_control,3,0);
					DIO_WRITE(seg_control,4,1);
					seven_seg_write_BCD(seg_port,date_year%10,'L');
					_delay_ms(5);
					DIO_WRITE(seg_control,4,0);
					DIO_WRITE(seg_control,5,1);
					seven_seg_write_BCD(seg_port,date_year/10,'L');
					_delay_ms(5);
				} while (pushbutt_read(button_port,button_pin)==1);
		}
//*********************************************************
		else
			{
			DIO_WRITE(seg_control,0,0);
			DIO_WRITE(seg_control,1,0);
			DIO_WRITE(seg_control,2,0);
			DIO_WRITE(seg_control,3,0);
			DIO_WRITE(seg_control,4,0);
			DIO_WRITE(seg_control,5,0);
			DIO_WRITE(seg_control,0,1);
			seven_seg_write_BCD(seg_port,seconds_counter%10,'L');
			_delay_ms(5);
			DIO_WRITE(seg_control,0,0);
			DIO_WRITE(seg_control,1,1);
			seven_seg_write_BCD(seg_port,seconds_counter/10,'L');
			_delay_ms(5);
			DIO_WRITE(seg_control,1,0);
			DIO_WRITE(seg_control,2,1);
			seven_seg_write_BCD(seg_port,minutes_counter%10,'L');
			_delay_ms(5);
			DIO_WRITE(seg_control,2,0);
			DIO_WRITE(seg_control,3,1);
			seven_seg_write_BCD(seg_port,minutes_counter/10,'L');
			_delay_ms(5);
			DIO_WRITE(seg_control,3,0);
			DIO_WRITE(seg_control,4,1);
			seven_seg_write_BCD(seg_port,hours_counter%10,'L');
			_delay_ms(5);
			DIO_WRITE(seg_control,4,0);
			DIO_WRITE(seg_control,5,1);
			seven_seg_write_BCD(seg_port,hours_counter/10,'L');
			_delay_ms(5);
		}			
		if (seconds_counter>=60)
		{
			seconds_counter=0;
			minutes_counter++;
		}
		if (minutes_counter>=60)
		{
			minutes_counter=0;
			hours_counter++;
		}
		if (hours_counter>24)
		{
			hours_counter=0;
			date_day++;
		}
		if (date_day>30)
		{
			date_day=0;
			date_month++;
		}
		if (date_month>12)
		{
			date_month=0;
			date_year++;
		}
//****************************************		
		
		
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;	
}