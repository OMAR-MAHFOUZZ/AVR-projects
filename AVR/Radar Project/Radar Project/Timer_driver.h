/*
 * Timer_driver.h
 *
 * Created: 8/8/2024 2:16:27 PM
 *  Author: PC
 */ 


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_
void timer1_wave_fastPWM(double value);
//void Timer1_FastPWM_servoMotor(double val);
void Timer0_Motor_PWMsignal(unsigned char val);
void Timer0_normal_Vinit(void);
void Timer0_wave_nonpwm(void);
void timer0_ctc_Vinit(void);
#endif /* TIMER_DRIVER_H_ */