/*
 * DIO.h
 *
 * Created: 6/17/2024 6:26:07 PM
 *  Author: omar mahfouz
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_SETPIN_DIR(char port,char pin , char dir);
void DIO_WRITE(char port,char pin , char val);
void DIO_TOGGLE_BIT(char port , char pin );
char DIO_READ(char port , char pin );
void DIO_SETPORT_DIR(char port, char dir);
void DIO_TOGGLE_PORT(char port);
void DIO_SET_high_nipple(char choice);
void DIO_write_High_nipple(char port,char val);


#endif /* DIO_H_ */