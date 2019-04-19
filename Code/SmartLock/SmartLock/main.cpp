#include "Defines.h"
#include "Images.h"
#include "TWI.h"
#include "OLED.h"







TWI wire;
OLED oled(wire);

bool pss=false;

class password_scene
{
	protected:
	int pointer=0;
	int imgnum=0;
	int xcoord[5]={12,36,60,84,108};
	int ycoord=4;
	public:
	password_scene()
	{
		if(pss){
		write_default();
		variants(xcoord[pointer],ycoord);
		}
	}
	
	void write_default()
	{
		oled.OLED_Write_To_Bufer(xcoord[0],ycoord+1,1,8,line);
		oled.OLED_Write_To_Bufer(xcoord[1],ycoord+1,1,8,line);
		oled.OLED_Write_To_Bufer(xcoord[2],ycoord+1,1,8,line);
		oled.OLED_Write_To_Bufer(xcoord[3],ycoord+1,1,8,line);
		oled.OLED_Write_To_Bufer(xcoord[4],ycoord+1,1,8,line);
		oled.OLED_Write_To_Bufer(xcoord[pointer],ycoord+2,1,8,downn);
		oled.OLED_Write_To_Bufer(xcoord[pointer],ycoord-1,1,8,upp);
	}
	
	void  clear_others()
	{
				oled.OLED_Clear_Bufer_part(xcoord[pointer-1],ycoord+2,1,8);
				oled.OLED_Clear_Bufer_part(xcoord[pointer-1],ycoord-1,1,8);
	}
	
	void up()
	{
		write_default();
		imgnum++;
		if (imgnum>10) imgnum=0;
		variants(xcoord[pointer],ycoord);
	}
	
	void down()
	{
		write_default();
		imgnum--;
		if (imgnum<0) imgnum=10;
		variants(xcoord[pointer],ycoord);
	}
	
	void back()
	{
		write_default();
		pointer--;
		if(pointer<0)pointer=0;
		if (pointer>=0)
		{
			
			write_default();
			variants(xcoord[pointer],ycoord);
			oled.OLED_Clear_Bufer_part(xcoord[pointer+1],ycoord+2,1,8);
			oled.OLED_Clear_Bufer_part(xcoord[pointer+1],ycoord-1,1,8);
		}
	}
	
	void forward()
	{
		write_default();
		pointer++;
		if(pointer>4)pointer=4;
		if (pointer<5)
		{ 
			write_default();
			variants(xcoord[pointer],ycoord);
		}
		oled.OLED_Clear_Bufer_part(xcoord[pointer-1],ycoord+2,1,8);
		oled.OLED_Clear_Bufer_part(xcoord[pointer-1],ycoord-1,1,8);
	}
	
	void variants(int x,int y)
	{
		switch(imgnum)
		{
			case 0:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,zero);
				break;
			}
			case 1:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,one);
				break;
			}
			case 2:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,two);
				break;
			}
			case 3:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,three);
				break;
			}
			case 4:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,four);
				break;
			}
			case 5:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,five);
				break;
			}
			case 6:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,six);
				break;
			}
			case 7:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,seven);
				break;
			}
			case 8:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,eight);
				break;
			}
			case 9:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,nine);
				break;
			}
			case 10:
			{
				oled.OLED_Clear_Bufer_part(x,y,1,8);
				oled.OLED_Write_To_Bufer(x,y,1,8,arrow);
				break;
			}
			
		}
		
	}
	
};

class main_menu_scene
{
	protected:
	int pointer=0;
	int imgnum=0;
	int xcoord=49;
	int ycoord=2;
	public:
	main_menu_scene()
	{
		
		write_default();
		variants(xcoord,ycoord);
		
	}
	
	void write_default()
	{
		oled.OLED_Write_To_Bufer(xcoord-20,ycoord+1,1,16,lt);
		oled.OLED_Write_To_Bufer(xcoord+52,ycoord+1,1,16,rt);
	}
	
	void  clear_others()
	{

	}
	
	void up()
	{
		imgnum++;
		if (imgnum>2) imgnum=0;
		variants(xcoord,ycoord);
	}
	
	void down()
	{
		imgnum--;
		if (imgnum<0) imgnum=2;
		variants(xcoord,ycoord);
	}
	
	void back()
	{
		pointer--;
		if(pointer<0)pointer=2;
			write_default();
			variants(xcoord,ycoord);
	}
	
	void forward()
	{
		switch(imgnum)
		{
			case 0:
			{
				oled.OLED_Bufer_Clear();
				pss=true;
			
				break;
			}
			case 1:
			{

				break;
			}
			case 2:
			{

				break;
			}
		}
	}
	
	void variants(int x,int y)
	{
		switch(imgnum)
		{
			case 0:
			{
				oled.OLED_Clear_Bufer_part(x,y,4,32);
				oled.OLED_Write_To_Bufer(x,y,4,32,gear);
				break;
			}
			case 1:
			{
				oled.OLED_Clear_Bufer_part(x,y,4,32);
				oled.OLED_Write_To_Bufer(x,y,4,32,lock);
				break;
			}
			case 2:
			{
				oled.OLED_Clear_Bufer_part(x,y,4,32);
				oled.OLED_Write_To_Bufer(x,y,4,32,unlock);
				break;
			}

			
		}
		
	}
	
};


password_scene passww;
main_menu_scene passw;
bool btn0=false;
bool btn1=false;
bool btn2=false;
bool btn3=false;
bool btn03=false;
bool btn12=false;

ISR(PCINT0_vect)
{
    cli();
	if(PINA==0b00000100&!btn0 )
	{
		btn0=true;
	}
	if(PINA==0b00001000&!btn1 )
	{
		btn1=true;
	}
	if(PINA==0b00010000&!btn2 )
	{
		btn2=true;
	}
	if(PINA==0b00100000&!btn3 )
	{
		btn3=true;
	}
	if(PINA==0b00011000&!btn03)
	{
		btn03=true;
	}
	if(PINA==0b00100100&!btn12)
	{
		btn12=true;
	}
	sei();

}


void check()
{
	if(btn0 & !btn1 & !btn2 & btn3) btn03=true;
	if(!btn0 & btn1 & btn2 & !btn3) btn12=true;
	
	if(btn0 & !btn1 & !btn2 & !btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,zero);
		if(!pss)passw.up();
		else passww.up();
	}
	else if(!btn0 & btn1 & !btn2 & !btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,one);
		
	}
	else if(!btn0 & !btn1 & btn2 & !btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,two);
		
	}
	else if(!btn0 & !btn1 & !btn2 & btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,three);
		if(!pss)passw.down();
		else passww.down();
		
	}
	else if(!btn0  & !btn3 & btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,four);
		if(!pss)passw.forward();
		else passww.forward();
		
	}
	else if(!btn1 & !btn2 & !btn12 & btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,five);
		if(!pss)passw.back();
		else passww.back();
		
	}
		btn0=false;
		btn1=false;
		btn2=false;
		btn3=false;
		btn03=false;
		btn12=false;
	
}



class Batary
{
private:
int curlvl;
public:
Batary()
{
	DDRB=0x00;
	PORTB=0x0F;	
	refreshlvl();
	printlvltoOLEDbufer();
}

void refreshlvl()
{
	int kf=0;
	if((PINB>>0)&0b00000001==1) kf++;
	if((PINB>>1)&0b00000001==1) kf++;
	if((PINB>>2)&0b00000001==1) kf++;
	if((PINB>>3)&0b00000001==1) kf++;
	curlvl=kf;
}

void printlvltoOLEDbufer()
{
	if(curlvl==0) oled.OLED_Write_To_Bufer(96,0,4,8,batary5);
	if(curlvl==1) oled.OLED_Write_To_Bufer(96,0,4,8,batary4);
	if(curlvl==2) oled.OLED_Write_To_Bufer(96,0,4,8,batary3);
	if(curlvl==3) oled.OLED_Write_To_Bufer(96,0,4,8,batary2);
	if(curlvl==4) oled.OLED_Write_To_Bufer(96,0,4,8,batary1);
}

void refresh()
{
	refreshlvl();
	printlvltoOLEDbufer();
}
	
};

Batary batary;


int main(void){
	
		//TWI wire;
		//OLED oled(wire);
		//oled.OLED_Write_Bufer();
		//_delay_ms(1000);
		//oled.OLED_Write_To_Bufer(0,0,0b11111111);
		
//		oled.OLED_Write_To_Bufer(0,2,4,32,gear);
//		oled.OLED_Write_To_Bufer(33,2,4,32,lock);
//		oled.OLED_Write_To_Bufer(80,2,4,32,unlock);
		//oled.OLED_Write_To_Bufer(0,5,4,8,batary2);
		//oled.OLED_Write_To_Bufer(40,5,4,8,batary5);
		//oled.OLED_Write_To_Bufer(80,5,2,8,Net0);
		//oled.OLED_Write_To_Bufer(100,5,2,8,Net4);
		
		//	oled. OLED_Write_To_Bufer(0,0b11111111);
		//oled.OLED_Write_Bufer();
		//oled.oled_bufer[1]=0b11111111;
		//oled.OLED_Clear_Bufer_part(0,0,1,8);
		/*
		oled.OLED_Write_To_Bufer(12,5,1,8,line);
		oled.OLED_Write_To_Bufer(36,5,1,8,line);
		oled.OLED_Write_To_Bufer(60,5,1,8,line);
		oled.OLED_Write_To_Bufer(84,5,1,8,line);
		oled.OLED_Write_To_Bufer(108,5,1,8,line);
		
	//	oled.OLED_Write_To_Bufer(12,3,1,8,up);
	/	oled.OLED_Write_To_Bufer(36,3,1,8,up);
		oled.OLED_Write_To_Bufer(60,3,1,8,up);
		oled.OLED_Write_To_Bufer(84,3,1,8,up);
		oled.OLED_Write_To_Bufer(108,3,1,8,up);
		
		oled.OLED_Write_To_Bufer(12,6,1,8,down);
		oled.OLED_Write_To_Bufer(36,6,1,8,down);
		oled.OLED_Write_To_Bufer(60,6,1,8,down);
		oled.OLED_Write_To_Bufer(84,6,1,8,down);
		oled.OLED_Write_To_Bufer(108,6,1,8,down);
		
		oled.OLED_Write_To_Bufer(12,4,1,8,one);
		oled.OLED_Write_To_Bufer(36,4,1,8,two);
		oled.OLED_Write_To_Bufer(60,4,1,8,zero);
		oled.OLED_Write_To_Bufer(84,4,1,8,arrow);
		*/
		
		//oled.OLED_Clear_Bufer_part(0,0,1,8);
		//oled.OLED_Write_To_Bufer(2,2,1,8,arrow);
		oled.OLED_Write_Bufer();
		//Interupts

	DDRA = 0x00;
		PORTA=0x00;
		PCMSK0=0b00111100;
		PCICR|=0b00000001;
		sei();
		//
		//DDRD|=0b10000000;
		/*
		DDRB=0x00;
		PORTB=0x0F;
		int kf=0;
				if((PINB>>0)&0b00000001==1)kf++;
				if((PINB>>1)&0b00000001==1)kf++;
				if((PINB>>2)&0b00000001==1)kf++;
				if((PINB>>3)&0b00000001==1)kf++;
				if(kf==0) oled.OLED_Write_To_Bufer(96,0,4,8,batary5);
				if(kf==1) oled.OLED_Write_To_Bufer(96,0,4,8,batary4);
				if(kf==2) oled.OLED_Write_To_Bufer(96,0,4,8,batary3);
				if(kf==3) oled.OLED_Write_To_Bufer(96,0,4,8,batary2);
				if(kf==4) oled.OLED_Write_To_Bufer(96,0,4,8,batary1);
				oled.OLED_Write_Bufer();
				oled.writenumber(4-kf);
						oled.writenumber((PINB>>0)&0b00000001);
		oled.writenumber((PINB>>1)&0b00000001);
		oled.writenumber((PINB>>2)&0b00000001);
		oled.writenumber((PINB>>3)&0b00000001);*/
	while(1)
	{
		
	 batary.refresh();
	 oled.OLED_Write_To_Bufer(80,0,2,8,Net0);
	// oled.OLED_Write_To_Bufer(1,1,1,8,zero);
	// oled.OLED_Write_To_Bufer(9,1,1,8,two);
	// oled.OLED_Write_To_Bufer(17,1,1,8,nine);
	 oled.OLED_Write_Bufer();
	 //_delay_ms(1000);
	 
	// _delay_ms(100);
     check();
	}
}

