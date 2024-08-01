/*
 * The_safe.c
 *
 * Created: 7/24/2024 10:10:04 PM
 *  Author: Omar Mahfouz
 */ 

#include "LCD.h"
#include "keypad.h"
#include "EEPROM.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#define  STATUS_ADDRESS 0x20
#define  FIRST_ADDRESS 0x22
#define  SECOND_ADDRESS 0x23
#define  THIRD_ADDRESS 0x24
#define  FOURTH_ADDRESS 0x25
#define  MAX_TRIES 2
int main(void)
{

	char arr[4];
	char x=NOT_PRESSED;
	char flag=0,i;
	char tries=MAX_TRIES;
	LCD_init();
	keypad_vinit();
    while(1)
    {
		if (EEPROM_u8read(STATUS_ADDRESS)==NOT_PRESSED)
		{
			
			LCD_send_string("set pass:");
			for (i=0;i<=3;i++)
			{
				do 
				{	
					x=keypad_checkpress();
				} while (x==NOT_PRESSED);
				LCD_vsend_char(x);
				_delay_ms(500);
				LCD_vsend_cmd(0x10);
				LCD_vsend_char('*');
				_delay_ms(500);
				EEPROM_vwrite(FIRST_ADDRESS+i,x);
				
			}			
			EEPROM_vwrite(STATUS_ADDRESS,0x00);
		}
		
		while(flag==0)
		{
			arr[0]=arr[1]=arr[2]=arr[3]=NOT_PRESSED;
			LCD_clearscreen();
			LCD_send_string("check pass:");
			for (i=0;i<=3;i++)
			{
				do 
				{
					arr[i]=keypad_checkpress();
				} while (arr[i]==NOT_PRESSED);
				LCD_vsend_char(arr[i]);
				_delay_ms(500);
				LCD_vsend_cmd(0x10);
				LCD_vsend_char('*');
			}
			if (arr[0]==EEPROM_u8read(FIRST_ADDRESS) && arr[1]==EEPROM_u8read(SECOND_ADDRESS) && arr[2]==EEPROM_u8read(THIRD_ADDRESS) && arr[3]==EEPROM_u8read(FOURTH_ADDRESS))
			{
				LCD_clearscreen();
				LCD_send_string("correct pass");
				LCD_move_cursor(2,1);
				LCD_send_string("safe open");
				flag=1;
			}
			else
			{
				tries--;
				if (tries>0)
				{
					LCD_clearscreen();
					LCD_send_string("Wrong password");
					_delay_ms(1000);
					LCD_move_cursor(2,1);
					LCD_send_string("tries left:");
					LCD_vsend_char(tries+48);
					_delay_ms(1000);
				}
				else
				{
					LCD_clearscreen();
					LCD_send_string("Wrong password");
					_delay_ms(1000);
					LCD_move_cursor(2,1);
					LCD_send_string("safe close");
					_delay_ms(1000);
					flag=1;
				}
			}
			
		}
	}	

}