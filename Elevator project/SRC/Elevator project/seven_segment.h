/*
 * seven_segment.h
 *
 * Created: 6/21/2024 10:20:22 PM
 *  Author: PC
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

void seven_seg_write(char port,char number);
void seven_seg_init(char port);
void seven_seg_init_BCD(char port ,char choose);
void seven_seg_write_BCD(char port , char val ,char choose);
#endif /* SEVEN_SEGMENT_H_ */