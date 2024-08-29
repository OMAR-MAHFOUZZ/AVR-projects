/*
 * Timer_driver.c
 *
 * Created: 8/8/2024 2:16:08 PM
 *  Author:Omar Mahfouz
 */ 
#include "STD_MACROS.h"
#include <avr/interrupt.h>
void Timer0_normal_Vinit(void)
{
	/*CLR WGM00 WGM01 bits in TccR0 to be in normal mode*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	/*set timer clock prescaler 1024 101*/
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	//SET_BIT(TCCR0,CS02);
	
	/*TCNT0 value for 10ms we need 256-n(79)*/
	
	
	sei();
	SET_BIT(TIMSK,TOIE0);
}
void timer0_ctc_Vinit(void)
{
	/*set  WGM01 bits in TccR0 to be in ctc mode*/
	SET_BIT(TCCR0,WGM01);
	/*set timer clock prescaler 1024 101*/
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	
	/*OCR0 value for 10ms */
	OCR0=79;
	
	sei();
	SET_BIT(TIMSK,OCF0);
	
}

void Timer0_wave_nonpwm(void)
{
	
	/*set  WGM01 bits in TccR0 to be in ctc mode*/
	SET_BIT(TCCR0,WGM01);
	/*set bit 3 as output pin*/
	 SET_BIT(DDRB,3);
	 /*OCR0 value for 10ms */
	 OCR0=64;
	 /*set timer clock prescaler 1024 101*/
	 SET_BIT(TCCR0,CS00);
	 CLR_BIT(TCCR0,CS01);
	 SET_BIT(TCCR0,CS02);
    /*set toggle to pin oc0*/
	SET_BIT(TCCR0,COM00);
}
void Timer0_wave_fastpwm(void)
{
	/*SEt WGM00 WGM01 to be in fast pwm mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*set PB3 as out put*/
	SET_BIT(DDRB,3);
	/*set OCR0 value*/
	OCR0=64;
	/*set clock prescaler 1024*/
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*SET COM0:1*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

void Timer0_wave_phasecorrect(void)
{
	/*SEt WGM00 WGM01 to be in fast pwm mode*/
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*set PB3 as out put*/
	SET_BIT(DDRB,3);
	/*set OCR0 value*/
	OCR0=64;		
	/*set clock prescaler 1024*/
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*SET COM0:1*/
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);	
}

void Timer0_Motor_PWMsignal(unsigned char val)
{
	/*SEt WGM00 WGM01 to be in fast pwm mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*set PB3 as out put*/
	SET_BIT(DDRB,3);
	/*set OCR0 value*/
	OCR0=val;
	/*set clock prescaler 1024*/
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*SET COM0:1 clear OC0 on comapre match*/
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
/*void Timer1_FastPWM_servoMotor(signed char degree)
{
	double value;
	/*set WGM11 WGM12 WGM13
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/*set OCR1A output
	SET_BIT(DDRD,5);
	ICR1=19999;
	
	if(-90<=degree<0)
	{
		value=((0.5/90)*(90+degree))+1;
	}
	else if(0<=degree<=90)
	{
		value=((0.5/90)*degree)+1.5;
	}

	OCR1A=value;
	/*set clock prescaler 8
	SET_BIT(TCCR1B,CS11);
	/*SET COM0:1
	SET_BIT(TCCR1A,COM1A1);
	
}*/
void timer1_wave_fastPWM(double value)
{
	/* set OC0 as output pin */
	SET_BIT(DDRD,5);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */

	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS11);
		ICR1=19999;
		OCR1A=(value*1000)-1;
}
