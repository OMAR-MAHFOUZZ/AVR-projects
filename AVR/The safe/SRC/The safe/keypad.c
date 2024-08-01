/*
 * keypad.c
 *
 * Created: 7/22/2024 8:43:02 PM
 *  Author: Omar Mahfouz
 */ 
#include "DIO.h"
#define keypad_port 'D'
#define NOT_PRESSED  0xff
void keypad_vinit(void)
{
	DIO_SETPIN_DIR(keypad_port,0,1);
	DIO_SETPIN_DIR(keypad_port,1,1);
	DIO_SETPIN_DIR(keypad_port,2,1);	
	DIO_SETPIN_DIR(keypad_port,3,1);	
	DIO_SETPIN_DIR(keypad_port,4,0);
	DIO_SETPIN_DIR(keypad_port,5,0);
	DIO_SETPIN_DIR(keypad_port,6,0);
	DIO_SETPIN_DIR(keypad_port,7,0);
	DIO_pullup_connect(keypad_port,4,1);
	DIO_pullup_connect(keypad_port,5,1);
	DIO_pullup_connect(keypad_port,6,1);
	DIO_pullup_connect(keypad_port,7,1);
}
char keypad_checkpress(void)
{
	char arr[4][4]={{'1','2','3','-'},{'4','5','6','*'},{'7','8','9','/'},{'A','0','=','+'}};
		char row,col,x;
		char return_var=NOT_PRESSED;
		for (row=0;row<4;row++)
		{
			DIO_WRITE(keypad_port,0,1);
			DIO_WRITE(keypad_port,1,1);
			DIO_WRITE(keypad_port,2,1);
			DIO_WRITE(keypad_port,3,1);
			DIO_WRITE(keypad_port,row,0);
			for (col=0;col<4;col++)
			{
				x=DIO_READ(keypad_port,col+4);
				if (x==0)
				{
					return_var=arr[row][col];
					break;
				}
				
			}
			if (x==0)
			{
				break;
			}
	
		}
		return return_var;
}