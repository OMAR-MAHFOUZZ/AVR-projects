/*
 * Advanced_Tempreture_meter.c
 *
 * Created: 8/4/2024 3:28:45 PM
 *  Author: PC
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"



int main(void)
{
	ADC_vinit();
	LCD_init();
	unsigned short tempreture,volt;
	LCD_send_string("temp=");
    while(1)
    {
        volt=(2.56*1000*ADC_u16Read())/1024;
		if (volt>1500)
		{
			tempreture=(volt-1500)/10;
			LCD_move_cursor(1,6);
			if (tempreture<10)
			{
				LCD_vsend_char(tempreture+48);
				LCD_vsend_char(0xdf);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
			else
			{
				LCD_vsend_char(tempreture/10+48);
				LCD_vsend_char(tempreture%10+48);
				LCD_vsend_char(0xdf);
				LCD_vsend_char('C');
			}
		}
		else
		{
			tempreture=(1500-volt)/10;
			LCD_move_cursor(1,6);
			if (tempreture<10)
			{
				LCD_vsend_char('-');
				LCD_vsend_char(tempreture+48);
				LCD_vsend_char(0xdf);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
			else
			{
				LCD_vsend_char('-');
				LCD_vsend_char(tempreture/10+48);
				LCD_vsend_char(tempreture%10+48);
				LCD_vsend_char(0xdf);
				LCD_vsend_char('C');
								
			}
			
		}
		
		
		 
    }
}