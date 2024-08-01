/*
 * seven_segment.c
 *
 * Created: 6/21/2024 10:15:38 PM
 *  Author: Omar Mahfouz
 */ 
#define ca
#include "STD_MACROS.h"
#include "DIO.h"
void seven_seg_init(char port)
{
	DIO_SETPORT_DIR(port,0xFF);
}

void seven_seg_write(char port,char number)
{
	#ifdef cc
		unsigned char arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7d,0x47,0x7F,0x6F};
	#else 
		unsigned char arr[]={~0x3F,~0x06,~0x5b,~0x4F,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
	#endif
	
	DIO_write_port(port,arr[number]);
}
void seven_seg_init_BCD(char port ,char choose)
{
	switch(choose)
	{
		case 'H':
		case 'h':
		DIO_SETPIN_DIR(port,4,1);
		DIO_SETPIN_DIR(port,5,1);
		DIO_SETPIN_DIR(port,6,1);
		DIO_SETPIN_DIR(port,7,1);
		break;
		case 'L':
		case 'l':
		DIO_SETPIN_DIR(port,0,1);
		DIO_SETPIN_DIR(port,1,1);
		DIO_SETPIN_DIR(port,2,1);
		DIO_SETPIN_DIR(port,3,1);
		break;
		default:break;

	}
	
}
void seven_seg_write_BCD(char port , char val ,char choose)
{
	switch(choose)
	{
		case 'H':
		case 'h':
		DIO_WRITE(port,4,READ_BIT(val,0));
		DIO_WRITE(port,5,READ_BIT(val,1));
		DIO_WRITE(port,6,READ_BIT(val,2));
		DIO_WRITE(port,7,READ_BIT(val,3));
		break;
		
		case 'L':
		case 'l':
			DIO_WRITE(port,0,READ_BIT(val,0));
			DIO_WRITE(port,1,READ_BIT(val,1));
			DIO_WRITE(port,2,READ_BIT(val,2));
			DIO_WRITE(port,3,READ_BIT(val,3));
			break;
			
		default:break;

	}
	
	
}