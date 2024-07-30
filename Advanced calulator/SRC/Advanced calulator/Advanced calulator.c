/*
 * Advanced_calulator.c
 *
 * Created: 7/25/2024 11:44:26 AM
 *  Author: PC
 */ 

#include "LCD.h"
#include "keypad.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	LCD_init();
	keypad_vinit();
	char num1[2];
	char num2[2];
	char i,opr;
	unsigned short res;
	while(1)
	{
		/***********************************************************/
			for(i=0;i<2;i++)
			{
				do
				{
					num1[i]=keypad_checkpress();
				} while (num1[i]==NOT_PRESSED);
				LCD_vsend_char(num1[i]);
				_delay_ms(200);
			}
		    if (num1[1]=='+' || num1[1]=='-' || num1[1]=='*' || num1[1]=='/' )
		    {
			    opr=num1[1];
			    for(i=0;i<2;i++)
			    {
				    do
				    {
					    num2[i]=keypad_checkpress();
				    } while (num2[i]==NOT_PRESSED);
				    LCD_vsend_char(num2[i]);
				    _delay_ms(200);
			    }
				if (num2[1]=='=')
				{
					num2[0]-=48;
					num1[0]-=48;
					switch(opr)
					{
						case '+':res=num2[0]+num1[0];
						break;
						case '-':res=num1[0]-num2[0];
						break;
						case '*':res=num1[0]*num2[0];
						break;
						case '/':res=num1[0]/num2[0];
						break;
					}
					if (res<10)
					{
						LCD_vsend_char(res+48);
					}
					else
					{
						LCD_vsend_char(res/10+48);
						LCD_vsend_char(res%10+48);
					}
				}
	/*********************************************************/
				else
				{
					num1[0]-=48;
					num2[1]=(num2[0]-48)*10+(num2[1]-48);
					switch(opr)
					{
						case '+':res=num2[1]+num1[0];
						break;
						case '-':res=num1[0]-num2[1];
						break;
						case '*':res=num1[0]*num2[1];
						break;
						case '/':res=num1[0]/num2[1];
						break;
					}
					do
					{
						opr=keypad_checkpress();
					} while (opr==NOT_PRESSED);
					LCD_vsend_char(opr);
					_delay_ms(200);
					do
					{
						if (res<10)
						{
							LCD_vsend_char(res+48);
						}
						else if(res<100)
						{
							LCD_vsend_char(res/10+48);
							LCD_vsend_char(res%10+48);
						}
						else
						{
							LCD_vsend_char(res/100+48);
							LCD_vsend_char(((res/10)-(res/100)*10)+48);
							LCD_vsend_char(res%10+48);
						}
					} while (opr!='=');
				}
	/*********************************************************/
				}	
	else
	{
		num1[1]=(num1[0]-48)*10+(num1[1]-48);
		do
		{
			opr=keypad_checkpress();
		} while (opr==NOT_PRESSED);
		LCD_vsend_char(opr);
		_delay_ms(200);
		
		for (i=0;i<2;i++)
		{
			do
			{
				num2[i]=keypad_checkpress();
			} while (num2[i]==NOT_PRESSED);
			LCD_vsend_char(num2[i]);
			_delay_ms(200);
		}	
		if (num2[1]=='=')
		{
			num2[0]-=48;
			switch(opr)
			{
				case '+':res=num2[0]+num1[1];
				break;
				case '-':res=num1[1]-num2[0];
				break;
				case '*':res=num1[1]*num2[0];
				break;
				case '/':res=num1[1]/num2[0];
				break;
			}
			if (res<10)
			{
				LCD_vsend_char(res+48);
			}
			else if(res<100)
			{
				LCD_vsend_char(res/10+48);
				LCD_vsend_char(res%10+48);
			}
			else if(res<1000)
			{
				LCD_vsend_char(res/100+48);
				LCD_vsend_char(((res/10)-(res/100)*10)+48);
				LCD_vsend_char(res%10+48);
			}
			else
			{
				LCD_vsend_char(res/1000+48);
				LCD_vsend_char((res/100)-((res/1000)*10)+48);
				LCD_vsend_char(((res/10)-(res/100)*10)+48);
				LCD_vsend_char(res%10+48);
			}			
			}
	/***********************************************************/
			else
			{
				
				num2[1]=(num2[0]-48)*10+(num2[1]-48);
				switch(opr)
				{
					case '+':res=num2[1]+num1[1];
					break;
					case '-':res=num1[1]-num2[1];
					break;
					case '*':res=num1[1]*num2[1];
					break;
					case '/':res=num1[1]/num2[1];
					break;
				}
				do
				{
					opr=keypad_checkpress();
				} while (opr==NOT_PRESSED);
				LCD_vsend_char(opr);
				_delay_ms(200);
				do
				{
					if (res<10)
					{
						LCD_vsend_char(res+48);
					}
					else if(res<100)
					{
						LCD_vsend_char(res/10+48);
						LCD_vsend_char(res%10+48);
					}
					else if(res<1000)
					{
						LCD_vsend_char(res/100+48);
						LCD_vsend_char(((res/10)-(res/100)*10)+48);
						LCD_vsend_char(res%10+48);
					}
					else
					{
						LCD_vsend_char(res/1000+48);
						LCD_vsend_char((res/100)-((res/1000)*10)+48);
						LCD_vsend_char(((res/10)-(res/100)*10)+48);
						LCD_vsend_char(res%10+48);
					}
				} while (opr!='=');
			}
		}	
		
		do
		{
			opr=keypad_checkpress();
			
		} while (opr == NOT_PRESSED);
		if (opr=='A')
		{
			LCD_clearscreen();
		}
		_delay_ms(200);
								



























		
	
	

}
}
	