/*
 * Motor_driver.c
 *
 * Created: 8/16/2024 8:10:39 PM
 *  Author: PC
 */ 

#include "Timer_driver.h"
/*set PB3 pin as output*/
#define enable 3
void Motor_ControlSpeed(unsigned char val)
{
	Timer0_Motor_PWMsignal(val);
}
void servo_degree(signed char degree)
{
	double value;
	if(-90<=degree<0)
	{
		value=((0.5/90)*(90+degree))+1;
	}
	else if(0<=degree<=90)
	{
		value=((0.5/90)*degree)+1.5;
	}
	timer1_wave_fastPWM(value);
}