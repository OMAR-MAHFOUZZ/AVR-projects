/*
 * Stop Watch.c
 *
 * Created: 8/15/2024 9:30:49 PM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "keypad.h"
#include "seven_segment.h"
#include "led.h"
#include "Timer_driver.h"
#define F_CPU 8000000UL
#define seg_port 'B'
#define seg_control 'C'
#include <util/delay.h>
volatile unsigned char seconds_counter=0,led_counter=0;
unsigned char minutes_counter,hours_counter,flag;
int main(void)
{
	LCD_init();
	keypad_vinit();
	seven_seg_init(seg_port);
	DIO_SETPIN_DIR(seg_control,0,1);
	DIO_SETPIN_DIR(seg_control,1,1);
	DIO_SETPIN_DIR(seg_control,2,1);
	DIO_SETPIN_DIR(seg_control,3,1);
	led_init(seg_control,4);
	led_init(seg_control,5);
	timer2_ovf_init_interrupt();
	timer0_ctc_Vinit();
	led_on(seg_control,4);
	led_on(seg_control,5);
    while(1)
    {
		if (led_counter>=125)
		{
			led_tog(seg_control,4);
			led_tog(seg_control,5);
			led_counter=0;
		}
		if (flag==0)
		{
			DIO_WRITE(seg_control,0,0);
		DIO_WRITE(seg_control,1,0);
		DIO_WRITE(seg_control,2,0);
		DIO_WRITE(seg_control,3,0);
		_delay_ms(5);
		DIO_WRITE(seg_control,0,1);
		seven_seg_write(seg_port,seconds_counter%10);
		_delay_ms(5);
		DIO_WRITE(seg_control,0,0);
		DIO_WRITE(seg_control,1,1);
		seven_seg_write(seg_port,seconds_counter/10);
		_delay_ms(5);
		//**********************
		DIO_WRITE(seg_control,1,0);
		DIO_WRITE(seg_control,2,1);
		seven_seg_write(seg_port,minutes_counter%10);
		_delay_ms(5);
		DIO_WRITE(seg_control,2,0);
		DIO_WRITE(seg_control,3,1);
		seven_seg_write(seg_port,minutes_counter/10);
		_delay_ms(5);
		//**********************
		}
		else
		{
			DIO_WRITE(seg_control,0,0);
		DIO_WRITE(seg_control,1,0);
		DIO_WRITE(seg_control,2,0);
		DIO_WRITE(seg_control,3,0);
		_delay_ms(5);
		DIO_WRITE(seg_control,0,1);
		seven_seg_write(seg_port,minutes_counter%10);
		_delay_ms(5);
		DIO_WRITE(seg_control,0,0);
		DIO_WRITE(seg_control,1,1);
		seven_seg_write(seg_port,minutes_counter/10);
		_delay_ms(5);
		//**********************
		DIO_WRITE(seg_control,1,0);
		DIO_WRITE(seg_control,2,1);
		seven_seg_write(seg_port,hours_counter%10);
		_delay_ms(5);
		DIO_WRITE(seg_control,2,0);
		DIO_WRITE(seg_control,3,1);
		seven_seg_write(seg_port,hours_counter/10);
		_delay_ms(5);
		//**********************
		}
		
		if(seconds_counter>=60)
		{
			minutes_counter++;
			seconds_counter=0;
		}
		if (minutes_counter>=60)
		{
			flag=1;
			minutes_counter=0;
			hours_counter++;
		}
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;

}
ISR(TIMER0_COMP_vect)
{
	led_counter++;
}