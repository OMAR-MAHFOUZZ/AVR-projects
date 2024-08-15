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
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
	/*OCR0 value for 10ms */
	OCR0=125;
	
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
void timer2_ovf_init_interrupt(void)
{
	
	SET_BIT(ASSR,AS2);
	//set clock prescaler to 128 
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	
	sei();
	SET_BIT(TIMSK,TOIE2);
	
	
	
}