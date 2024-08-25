/*
 * Motor_driver.c
 *
 * Created: 8/16/2024 8:10:39 PM
 *  Author: Omar Mahfouz
 */ 

#include "Timer_driver.h"
/*set PB3 pin as output*/
#define enable 3
void Motor_ControlSpeed(unsigned char val)
{
	Timer0_Motor_PWMsignal(val);
}
void Servo_motorAngle1(double val)
{
	
	Timer1_FastPWM_servoMotor1(val);

}
void Servo_motorAngle2(double val)
{
	
	Timer1_FastPWM_servoMotor2(val);

}