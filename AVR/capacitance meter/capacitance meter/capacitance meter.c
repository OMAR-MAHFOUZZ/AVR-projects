/*
 * capacitance_meter.c
 *
 * Created: 8/8/2024 8:53:21 PM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ADC.h"
#include "LCD.h"
#include "Timer_driver.h"
#include "STD_MACROS.h"
#define RESISTOR (10000.0)
volatile unsigned long counter1=0;
unsigned long time,start_time;
float capacitance;

int main(void)
{
	
	LCD_init();
	ADC_vinit();
	timer0_ctc_Vinit();
	LCD_move_cursor(1,4);
	LCD_send_string("capacitance");
	LCD_move_cursor(2,7);
	LCD_send_string("meter");
	_delay_ms(1000);
	LCD_clearscreen();
	
    while(1)
    {
		SET_BIT(DDRA,5);
		CLR_BIT(DDRA,4);
		DIO_WRITE('A',5,1);
		start_time=counter1;
		while(ADC_u16Read()<648);
			time=counter1-start_time;		
			capacitance=((time/RESISTOR)*1000);			
			if (capacitance>=1)
			{
				LCD_clearscreen();
				LCD_send_string("cap=");
				if (capacitance<10)
				{
					LCD_vsend_char((unsigned short)capacitance+48);
				}
				
				else if (capacitance<99)
				{
					LCD_vsend_char((unsigned short)capacitance/10+48);
					LCD_vsend_char((unsigned short)capacitance%10+48);
				}
				else
				{
					LCD_vsend_char((unsigned short)capacitance/100+48);
					LCD_vsend_char(((unsigned short)capacitance/10)-(((unsigned short)capacitance/100)*10)+48);
					LCD_vsend_char((unsigned short)capacitance%10+48);

				}
				
				LCD_send_string("uF");
				_delay_ms(2000);
			}	
			else
			{
				LCD_clearscreen();
				LCD_send_string("Out of range");
				_delay_ms(2000);
			}		
			DIO_WRITE('A',5,0);
			CLR_BIT(DDRA,5);
			SET_BIT(DDRA,4);
			DIO_WRITE('A',4,0);
			while(ADC_u16Read()>0);
    }
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
}