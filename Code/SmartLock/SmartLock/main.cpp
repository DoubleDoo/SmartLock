#include "Defines.h"
#include "Images.h"
#include "TWI.h"
#include "OLED.h"

TWI wire;
OLED oled(wire);
bool Main_Menu_Status=true;
bool Password_Menu_Status=false;
bool Settings_Menu_Status=false;
bool locked=false;

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

	};
	
    void Default() override
    {
		oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X-20,MAIN_MENU_IMG_Y+1,1,16,lt);
		oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X+56,MAIN_MENU_IMG_Y+1,1,16,rt);
    };
	
    void refresh() override
	{
		//oled.OLED_Bufer_Clear();
		Default();
		actions();
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
			    Main_Menu_Status=false;
				Password_Menu_Status=true;
				close();
				break;
			}
			case 1:
			{
				Main_Menu_Status=false;
				Settings_Menu_Status=true;
				close();
				break;
			}
			case 2:
			{
				//close();
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
				if(locked) oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32,unlock);
				else oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32,lock);
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
#define PASSWORD_MENU_SIMVOLS_COUNT 10
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
				//oled.OLED_Bufer_Clear();
				Default();
				actions();
	};
	
	void close()override
	{
		pointer=0;
		Password_Menu_Status=false;
		Main_Menu_Status=true;
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
		     if(pointer>PASSWORD_MENU_POINER_COUNT) {
				 
				Main_Menu_Status=true;
				Password_Menu_Status=false;
				close();
				 }
			 else
			 {
				 symbol_pointer=0;
				 actions();	 
			 }
		
		
	};
	
	void back()override
	{
		oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
		oled.OLED_Clear_Bufer_part(x[pointer],y+2,1,8);
		oled.OLED_Clear_Bufer_part(x[pointer],y-1,1,8);
		pointer--;
		if(pointer<0) 
		{
			Password_Menu_Status=false;
		    Main_Menu_Status=true;
				 close();
				 pointer=0;
		}
		else actions();	
	};
	
	void animate()override
	{
		
		
	};
	
	void actions()override
	{
		if(Password_Menu_Status){
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
		}
	};
	
};


#define SETTINGS_MENU_POINER_COUNT 4
#define SETTINGS_MENU_IMG_X_0 8
#define SETTINGS_MENU_IMG_X_1 16
#define SETTINGS_MENU_IMG_X_2 28
#define SETTINGS_MENU_IMG_X_3 56
#define SETTINGS_MENU_IMG_Y 4



class Settings_Menu:public Menu_Element
{
	protected:
	int pointer=0;
	int x[4]={SETTINGS_MENU_IMG_X_0,SETTINGS_MENU_IMG_X_1,SETTINGS_MENU_IMG_X_2,SETTINGS_MENU_IMG_X_3};
	int y=SETTINGS_MENU_IMG_Y;
	public:
	Settings_Menu()
	{

	};
	
	void Default() override
	{
		oled.OLED_Write_To_Bufer(56,y+2,2,8,downwd);
		oled.OLED_Write_To_Bufer(56,y-2,2,8,upwd);
	};
	
	void refresh() override
	{
		//oled.OLED_Bufer_Clear();
		Default();
		actions();
	};
	
	void close()override
	{
		pointer=0;
		Settings_Menu_Status=false;
		Main_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()override
	{
		pointer++;
		if(pointer>SETTINGS_MENU_POINER_COUNT) pointer=0;
		actions();
	};
	
	void previous()override
	{
		pointer--;
		if(pointer<0) pointer=SETTINGS_MENU_POINER_COUNT;
		actions();		
	};
	
	void choise()override
	{
		switch(pointer)
		{
			case 0:
			{
				
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
			case 3:
			{
				back();
				break;
			}
		}
	};
	
	void back()override
	{
		close();
	    pointer=0;
	};
	
	void animate()override
	{
		
		
	};
	
	void actions()override
	{
		if(Settings_Menu_Status){
			switch(pointer)
			{
				case 0:
				{
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer]+0,y,1,8,S);
					oled.OLED_Write_To_Bufer(x[pointer]+8,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+16,y,1,8,T);
					oled.OLED_Write_To_Bufer(x[pointer]+32,y,1,8,B);
					oled.OLED_Write_To_Bufer(x[pointer]+40,y,1,8,R);
					oled.OLED_Write_To_Bufer(x[pointer]+48,y,1,8,I);
					oled.OLED_Write_To_Bufer(x[pointer]+56,y,1,8,G);
					oled.OLED_Write_To_Bufer(x[pointer]+64,y,1,8,H);
					oled.OLED_Write_To_Bufer(x[pointer]+72,y,1,8,T);
					oled.OLED_Write_To_Bufer(x[pointer]+80,y,1,8,N);
					oled.OLED_Write_To_Bufer(x[pointer]+88,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+96,y,1,8,S);
					oled.OLED_Write_To_Bufer(x[pointer]+104,y,1,8,S);
					break;
				}
				case 1:
				{
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer]+0,y,1,8,R);
					oled.OLED_Write_To_Bufer(x[pointer]+8,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+16,y,1,8,S);
					oled.OLED_Write_To_Bufer(x[pointer]+24,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+32,y,1,8,T);
					oled.OLED_Write_To_Bufer(x[pointer]+48,y,1,8,D);
					oled.OLED_Write_To_Bufer(x[pointer]+56,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+64,y,1,8,V);
					oled.OLED_Write_To_Bufer(x[pointer]+72,y,1,8,I);
					oled.OLED_Write_To_Bufer(x[pointer]+80,y,1,8,C);
					oled.OLED_Write_To_Bufer(x[pointer]+88,y,1,8,E);
					break;
				}
				case 2:
				{
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer]+0,y,1,8,A);
					oled.OLED_Write_To_Bufer(x[pointer]+8,y,1,8,D);
					oled.OLED_Write_To_Bufer(x[pointer]+16,y,1,8,D);
					oled.OLED_Write_To_Bufer(x[pointer]+32,y,1,8,O);
					oled.OLED_Write_To_Bufer(x[pointer]+40,y,1,8,W);
					oled.OLED_Write_To_Bufer(x[pointer]+48,y,1,8,N);
					oled.OLED_Write_To_Bufer(x[pointer]+56,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+64,y,1,8,R);
					break;
				}
				case 3:
				{
					//oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer],y,2,8,backk);
					break;
				}
			}
		}
	};
	
};

//Info_menu inf_menu;
Settings_Menu sett_menu;
Password_Menu passw_menu;
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
		if (Password_Menu_Status)
		{
			passw_menu.previous();
			//passw_menu.refresh();
		}
		else if (Main_Menu_Status)
		{
			menu.previous();
			//menu.refresh();
		}
		else if (Settings_Menu_Status)
		{
			sett_menu.previous();
			//sett_menu.refresh();
		}
	}
	else if(!btn0 & btn1 & !btn2 & !btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,one);
		if (Password_Menu_Status)
		{
			passw_menu.choise();
			//passw_menu.refresh();
		}
		else if (Main_Menu_Status)
		{
			menu.choise();
			//menu.refresh();
		}
		else if (Settings_Menu_Status)
		{
			sett_menu.choise();
			//sett_menu.refresh();
		}
		
	}
	else if(!btn0 & !btn1 & btn2 & !btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,two);
		if (Password_Menu_Status)
		{

		}
		else if (Main_Menu_Status)
		{
			
			
		}
		else if (Settings_Menu_Status)
		{


		}
	}
	else if(!btn0 & !btn1 & !btn2 & btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,three);
		if (Password_Menu_Status)
		{
			passw_menu.next();
			//passw_menu.refresh();
		}
		else if (Main_Menu_Status)
		{
			menu.next();
			//menu.refresh();
		}
		else if (Settings_Menu_Status)
		{
			sett_menu.next();
			//sett_menu.refresh();
		}
	}
	else if(!btn0  & !btn3 & btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,four);
		if (Password_Menu_Status)
		{
			
		}
		else if (Main_Menu_Status)
		{
			
		}
		else if (Settings_Menu_Status)
		{


		}
	}
	else if(!btn1 & !btn2 & !btn12 & btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,five);
		if (Password_Menu_Status)
		{
			//passw_menu.choise();
			//passw_menu.refresh();
		}
		else if (Main_Menu_Status)
		{
			//menu.choise();
			//menu.refresh();
		}
		else if (Settings_Menu_Status)
		{
			//sett_menu.choise();
			//sett_menu.refresh();
		}
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
	PORTB=0xFF;	
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
		oled.OLED_Write_Bufer();
		//menu.refresh();

		DDRA = 0x00;
		PORTA=0x00;
		PCMSK0=0b00111100;
		PCICR|=0b00000001;
		sei();
	while(1)
	{
		check();
		if (Password_Menu_Status)
		{
			passw_menu.refresh();
		}
		else if (Main_Menu_Status)
		{
			menu.refresh();
		}
		else if (Settings_Menu_Status)
		{
			sett_menu.refresh();
		}
		batary.refresh();
		oled.OLED_Write_To_Bufer(80,0,2,8,Net0);
		oled.OLED_Write_Bufer();
	}
}

