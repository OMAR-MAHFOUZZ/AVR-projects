/*
 * Elevator_project.c
 *
 * Created: 7/28/2024 2:50:16 PM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "keypad.h"
#include "seven_segment.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	LCD_init();
	keypad_vinit();
	seven_seg_init_BCD('B','H');
	char counter=0;
	char current_floor,i;
    while(1)
    {
		LCD_send_string("floor number?");
		do 
		{
			current_floor=keypad_checkpress();
		} while (current_floor == 0xff);
		_delay_ms(200);
		LCD_vsend_char(current_floor);
		_delay_ms(1000);
		LCD_clearscreen();
		current_floor-=48;
		if (current_floor>counter)
		{
			LCD_send_string("up to floor:");
			LCD_vsend_char(current_floor+48);
			_delay_ms(2000);
			LCD_clearscreen();
			for(i=counter;i<=(current_floor);i++)
			{	
				LCD_move_cursor(1,1);
				LCD_send_string("current floor:");
				LCD_vsend_char(counter+48);
				seven_seg_write_BCD('B',counter,'H');
				_delay_ms(1000);
				counter++;
			}	
			counter=current_floor;
			LCD_move_cursor(1,1);
			LCD_send_string("reach to floor:");
			LCD_vsend_char(current_floor+48);
			_delay_ms(2000);
			LCD_clearscreen();
		}					
		else
		{
				LCD_send_string("down to floor:");
				LCD_vsend_char(current_floor+48);
				_delay_ms(2000);
				LCD_clearscreen();
				for(i=counter;i>=(current_floor);i--)
				{
				LCD_move_cursor(1,1);
				LCD_send_string("current floor");
				LCD_vsend_char(counter+48);
				seven_seg_write_BCD('B',counter,'H');
				counter--;
				_delay_ms(1000);
				}
				counter=current_floor;
				LCD_move_cursor(1,1);
				LCD_send_string("reach to floor:");
				LCD_vsend_char(current_floor+48);
				_delay_ms(2000);
				LCD_clearscreen();
								
		}	

	}
}