#include "Defines.h"
#include "Images.h"
#include "TWI.h"
#include "OLED.h"







TWI wire;
OLED oled(wire);
bool pss=false;


class Menu_Element
{
	protected:
	int pointer;
	
	public:
	virtual void Default();
	virtual void refresh();
	virtual void close();
	virtual void next();
	virtual void previous();
	virtual void choise();
	virtual void back();
	virtual void animate();
	virtual void actions();
	
}; 
#define MAIN_MENU_POINER_COUNT 2
#define MAIN_MENU_IMG_X 50
#define MAIN_MENU_IMG_Y 2

class Main_Menu:public Menu_Element
{
	protected:
	int pointer=0;
	public:
	Main_Menu()
	{
		Default();
		actions();
	};
	
    void Default() override
    {
		oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X-20,MAIN_MENU_IMG_Y+1,1,16,lt);
		oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X+56,MAIN_MENU_IMG_Y+1,1,16,rt);
    };
	
    void refresh() override
	{
		
		
	};
	
	void close()override
	{
		oled.OLED_Bufer_Clear();
	};
	
	void next()override
	{
		pointer++;
		if(pointer>MAIN_MENU_POINER_COUNT) pointer=0;
		actions();
	};
	
	void previous()override
	{
		pointer--;
		if(pointer<0) pointer=MAIN_MENU_POINER_COUNT;
		actions();
	};
	
	void choise()override
	{
		switch(pointer)
		{
			case 0:
			{
				close();
				break;
			}
			case 1:
			{
				close();
				break;
			}
			case 2:
			{
				close();
				break;
			}
		}
	};
	
	void back()override
	{
		
		
	};
	
	void animate()override
	{
		
		
	};
	
	void actions()override
	{
		switch(pointer)
		{
			case 0:
			{
				oled.OLED_Clear_Bufer_part(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32);
				oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32,lock);
				break;
			}
			case 1:
			{
				oled.OLED_Clear_Bufer_part(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32);
				oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32,gear);
				break;
			}
			case 2:
			{
				oled.OLED_Clear_Bufer_part(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32);
				oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32,info);
				break;
			}	
		}
	};
	
};

#define PASSWORD_MENU_POINER_COUNT 4
#define PASSWORD_MENU_SIMVOLS_COUNT 11
#define PASSWORD_MENU_IMG_X_0 12
#define PASSWORD_MENU_IMG_X_1 36
#define PASSWORD_MENU_IMG_X_2 60
#define PASSWORD_MENU_IMG_X_3 84
#define PASSWORD_MENU_IMG_X_4 108
#define PASSWORD_MENU_IMG_Y 2

class Password_Menu:public Menu_Element
{
	protected:
	int pointer=0;
	int symbol_pointer=0;
	int x[5]={PASSWORD_MENU_IMG_X_0,PASSWORD_MENU_IMG_X_1,PASSWORD_MENU_IMG_X_2,PASSWORD_MENU_IMG_X_3,PASSWORD_MENU_IMG_X_4};
	int y=PASSWORD_MENU_IMG_Y;
	public:
	Password_Menu()
	{
		Default();
		actions();
	};
	
	void Default() override
	{
		oled.OLED_Write_To_Bufer(x[0],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[1],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[2],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[3],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[4],y+1,1,8,line);
	};
	
	void refresh() override
	{
		
		
	};
	
	void close()override
	{
		oled.OLED_Bufer_Clear();
	};
	
	void next()override
	{
		symbol_pointer++;
		if(symbol_pointer>PASSWORD_MENU_SIMVOLS_COUNT) symbol_pointer=0;
		actions();
	};
	
	void previous()override
	{
		symbol_pointer--;
		if(symbol_pointer<0) symbol_pointer=PASSWORD_MENU_SIMVOLS_COUNT;
		actions();
	};
	
	void choise()override
	{
		switch(symbol_pointer)
		{
			case 0:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 1:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 2:
			{
	    			 pointer++;
	    			 for(int i=0;i<pointer;i++)
	    			 {
		    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
		    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
	    			 }
	    			 break;
			}
			case 3:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 4:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 5:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 6:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 7:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 8:
			{
    			 pointer++;
    			 for(int i=0;i<pointer;i++)
    			 {
	    			 oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
	    			 oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
    			 }
    			 break;
			}
			case 9:
			{
    			 pointer++;
				for(int i=0;i<pointer;i++)
				{
					oled.OLED_Clear_Bufer_part(x[i],y+2,1,8);
					oled.OLED_Clear_Bufer_part(x[i],y-1,1,8);
				}
				break;
			}
			case 10:
			{
				 back();
				break;
			}
		}
		     if(pointer>PASSWORD_MENU_POINER_COUNT) close();
			 symbol_pointer=0;
			 actions();	 
		
	};
	
	void back()override
	{
		oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
		oled.OLED_Clear_Bufer_part(x[pointer],y+2,1,8);
		oled.OLED_Clear_Bufer_part(x[pointer],y-1,1,8);
		pointer--;
		if(pointer<0) close();
		else actions();	
	};
	
	void animate()override
	{
		
		
	};
	
	void actions()override
	{
		switch(symbol_pointer)
		{
			case 0:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,zero);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 1:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,one);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 2:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,two);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 3:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,three);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 4:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,four);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 5:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,five);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 6:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,six);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 7:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,seven);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 8:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,eight);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 9:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,nine);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
			case 10:
			{
				oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
				oled.OLED_Write_To_Bufer(x[pointer],y,1,8,arrow);
				oled.OLED_Write_To_Bufer(x[pointer],y+2,1,8,downn);
				oled.OLED_Write_To_Bufer(x[pointer],y-1,1,8,upp);
				break;
			}
		}
	};
	
};



//Password_Menu passw_menu;
Main_Menu menu;
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
	//	if(!pss)passw.up();
		//else passww.up();
		menu.previous();
		//passw_menu.previous();
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
	//	if(!pss)passw.down();
		//else passww.down();
		menu.next();
		//passw_menu.next();
	}
	else if(!btn0  & !btn3 & btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,four);
		//if(!pss)passw.forward();
	//	else passww.forward();
	menu.back();
		
	}
	else if(!btn1 & !btn2 & !btn12 & btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,five);
	//	if(!pss)passw.back();
	//	else passww.back();
	//passw_menu.choise();
		
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

