/*
 * OLED.h
 *
 * Created: 19.04.2019 21:22:08
 *  Author: dima8
 */ 


#ifndef OLED_H_
#define OLED_H_
#include "Defines.h"
#include "TWI.h"


class OLED
{
	private:
	uint8_t  oled_bufer[(OLED_HEIGHT/8)*OLED_WIDTH];
	TWI wire;
	public:
	OLED(TWI _wire);
	void OLED_Command(int command);
	void OLED_Data(int data);
	void OLED_Write_Bufer();
	void OLED_Bufer_Clear();
	void OLED_Clear_Bufer_part(int x,int y,int width,int height);
	void OLED_Write_To_Bufer(int x,int y,int width,int height,uint8_t* img);
};


#endif /* OLED_H_ */