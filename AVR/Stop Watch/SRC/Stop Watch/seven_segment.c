/*
 * seven_segment.c
 *
 * Created: 6/21/2024 10:15:38 PM
 *  Author: Omar Mahfouz
 */ 
#define ca
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