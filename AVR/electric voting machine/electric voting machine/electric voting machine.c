/*
 * electric_voting_machine.c
 *
 * Created: 7/24/2024 6:10:52 PM
 *  Author: Omar Mahfouz
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "push button.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	LCD_init();
	pushbutt_inti('B',4);
	pushbutt_inti('B',5);
	pushbutt_inti('B',6);
	pushbutt_inti('B',7);
	
	LCD_send_string("A=0");
	LCD_move_cursor(1,12);
	LCD_send_string("B=0");
	LCD_move_cursor(2,1);
	LCD_send_string("C=0");
	LCD_move_cursor(2,12);
	LCD_send_string("D=0");
	char counter1=0;
	char counter2=0;
	char counter3=0;
	char counter4=0;
    while(1)
    {
        if (pushbutt_read('B',4)==1)
        {
			counter1++;
			if (counter1<10)
			{
				LCD_move_cursor(1,3);
				LCD_vsend_char(counter1+48);
			}
			else
			{
				LCD_move_cursor(1,3);
				LCD_vsend_char(counter1/10+48);
				LCD_vsend_char(counter1%10+48);
			}

        }
		else if (pushbutt_read('B',5)==1)
		{
			counter2++;
			if (counter2<10)
			{
				LCD_move_cursor(1,14);
				LCD_vsend_char(counter2+48);
			}
			else
			{
				LCD_move_cursor(1,14);
				LCD_vsend_char(counter2/10+48);
				LCD_vsend_char(counter2%10+48);
			}

		}
		else if (pushbutt_read('B',6)==1)
		{
			counter3++;
			if (counter3<10)
			{
				LCD_move_cursor(2,3);
				LCD_vsend_char(counter3+48);
			}
			else
			{
				LCD_move_cursor(2,3);
				LCD_vsend_char(counter3/10+48);
				LCD_vsend_char(counter3%10+48);
			}

		}
		else if (pushbutt_read('B',7)==1)
		{
			counter4++;
			if (counter4<10)
			{
				LCD_move_cursor(2,14);
				LCD_vsend_char(counter4+48);
			}
			else
			{
				LCD_move_cursor(2,14);
				LCD_vsend_char(counter4/10+48);
				LCD_vsend_char(counter4%10+48);
			}

		}
		
		_delay_ms(200);
		
    }
}