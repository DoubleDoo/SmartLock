
#ifndef DEFINES_H_
#define DEFINES_H_
#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>
#include <avr/sleep.h>
#define OLED_WIDTH			128
#define OLED_HEIGHT			64
#define CPU_F				20000000UL
#define SCL_F				1250000UL
#define Skip_Flag			0xff
#define Dev_Adr				0b00111100


#endif /* DEFINES_H_ */