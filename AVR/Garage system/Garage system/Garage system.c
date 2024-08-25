/*
 * Garage_system.c
 *
 * Created: 8/24/2024 3:38:50 PM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "STD_MACROS.h"
#include "Motor_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{	
	char flag=0,counter=0;
	LCD_init();
	/*input pins for IR sensor*/
	CLR_BIT(DDRB,1);
	CLR_BIT(DDRB,0);
    while(1)
    {

		do
		{
					LCD_move_cursor(1,2);
					LCD_vsend_char(counter+48);
					LCD_send_string("cars in garage");
					if (counter==3)
					{
							LCD_clearscreen();
							LCD_send_string("garage is full");
							_delay_ms(2000);
							LCD_clearscreen();
					}
					
						if ((READ_BIT(PINB,0)==1) && flag==0)
						 {
							counter++;
							Servo_motorAngle1(180);
							_delay_ms(1000);
							Servo_motorAngle1(90);
							flag=1;
						 }
						if (READ_BIT(PINB,0)==0)
						{
							flag=0;
						}
							
		}while(flag==1);	
		do 
		{
			LCD_move_cursor(1,2);
			LCD_vsend_char(counter+48);
			LCD_send_string("cars in garage");
			if (counter==0 )
			{
				LCD_clearscreen();
				LCD_send_string("there are");
				LCD_move_cursor(2,1);
				LCD_send_string("no cars");
				_delay_ms(2000);
				LCD_clearscreen();
			}
			
			
			 if ((READ_BIT(PINB,1)==1) && flag==0)
			 {
				 counter--;
				 Servo_motorAngle2(180);
				 _delay_ms(1000);
				 Servo_motorAngle2(90);
				 flag=1;		 
			 }
			 if (READ_BIT(PINB,1)==0)
			 {
				 flag=0;
			 }
						 
		} while (flag==1);
    }
}