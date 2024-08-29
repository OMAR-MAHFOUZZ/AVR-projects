/*
 * Radar_Project.c
 *
 * Created: 8/29/2024 1:03:54 AM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "Motor_driver.h"
#include "ultrasonic_driver.h"
int main(void)
{
	LCD_init();
	DIO_SETPIN_DIR('B',0,1);
	signed char angle;
	unsigned short high , distance;
    while(1)
    {

         for (angle=-30;angle<=60;angle++)
         {
			 
			 TCNT1=0;
			 //_delay_ms(50);
			 servo_degree(angle);
			 _delay_ms(30);
			 send_trigger('D',0);
			 high=recive_data();
			 distance=(high*34600)/(F_CPU * 2);
			 if (distance<=50)
			 {
				 DIO_WRITE('B',0,1);
				 LCD_move_cursor(1,1);
				 LCD_send_string("obstacle ");
				 
			 }
			 else
			 {
				 DIO_WRITE('B',0,0);
				 LCD_move_cursor(1,1);
				 LCD_send_string("clean way");
			 }	 
         }
		
		for (angle=60;angle>=-30;angle--)
		{
			TCNT1=0;
			//_delay_ms(50);
			servo_degree(angle);
			_delay_ms(30);
			send_trigger('D',0);
			high=recive_data();
			distance=(high*34600)/(F_CPU * 2);
			if (distance<=50)
			{
				DIO_WRITE('B',0,1);
				LCD_move_cursor(1,1);
				LCD_send_string("obstacle ");
				
			}
			else
			{
				DIO_WRITE('B',0,0);
				 LCD_move_cursor(1,1);
				 LCD_send_string("clean way");
			}
		} 
    }
}