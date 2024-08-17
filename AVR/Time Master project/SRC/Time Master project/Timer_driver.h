/*
 * Timer_driver.h
 *
 * Created: 8/8/2024 2:16:27 PM
 *  Author: PC
 */ 


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_
void timer1_ctc_init(void);
void timer1_ovf_init(void);
void timer2_ovf_init_interrupt(void);
void Timer0_normal_Vinit(void);
void Timer0_wave_nonpwm(void);
void timer0_ctc_Vinit(void);
#endif /* TIMER_DRIVER_H_ */