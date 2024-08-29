/*
 * ultrasonic_driver.h
 *
 * Created: 8/15/2024 12:56:41 AM
 *  Author: PC
 */ 


#ifndef ULTRASONIC_DRIVER_H_
#define ULTRASONIC_DRIVER_H_

void send_trigger(char port,char pin);
unsigned short recive_data(void);



#endif /* ULTRASONIC_DRIVER_H_ */