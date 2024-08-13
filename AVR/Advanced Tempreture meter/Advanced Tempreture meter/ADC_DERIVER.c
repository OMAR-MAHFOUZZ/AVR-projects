/*
 * ADC_DERIVER.c
 *
 * Created: 8/1/2024 6:39:40 PM
 *  Author: Omar Mahfouz
 */ 
#include <avr/io.h>
#include "STD_MACROS.h"
void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0);//configure V_ref
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);//enable ADC
	/*choose ADC pin*/
	CLR_BIT(ADMUX,MUX0);
	CLR_BIT(ADMUX,MUX1);
	CLR_BIT(ADMUX,MUX2);
	CLR_BIT(ADMUX,MUX3);
	SET_BIT(ADMUX,MUX4);
	/*adjust ADC clk*/
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}

unsigned short ADC_u16Read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA,ADSC);//start conversion
	while(READ_BIT(ADCSRA,ADSC)==1);
	SET_BIT(ADCSRA,ADIF);//clear flag bit
	read_val=ADCL;
	read_val |=(ADCH<<8);
	return read_val;
}