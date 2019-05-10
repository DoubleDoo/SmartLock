#include "Defines.h"
#include "Images.h"
#include "TWI.h"
#include "OLED.h"
#define CPU_F				20000000UL


TWI wire;
OLED oled(wire);
bool Main_Menu_Status=true;
bool Password_Menu_Status=false;
bool Settings_Menu_Status=false;
bool Info_Menu_Status=false;

bool User_Info_Status=false;
bool Device_Info_Status=false;
bool User_Add_Status=false;
bool Reset_Status=false;
bool Brightness_Status=false;
bool Waiting_Status=false;

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
				Main_Menu_Status=false;
				Info_Menu_Status=true;
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


#define SETTINGS_MENU_POINER_COUNT 3
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

#define INFO_MENU_POINER_COUNT 2
#define INFO_MENU_IMG_X_0 24
#define INFO_MENU_IMG_X_1 32
#define INFO_MENU_IMG_X_2 54
#define INFO_MENU_IMG_Y 4

class Info_menu:public Menu_Element
{
	protected:
	int pointer=0;
	int x[3]={ INFO_MENU_IMG_X_0, INFO_MENU_IMG_X_1, INFO_MENU_IMG_X_2};
	int y= INFO_MENU_IMG_Y;
	public:
	Info_menu()
	{

	};
	
	void Default() override
	{
		oled.OLED_Write_To_Bufer(56,y+2,2,8,downwd);
		oled.OLED_Write_To_Bufer(56,y-2,2,8,upwd);
	};
	
	void refresh() override
	{
		Default();
		actions();
	};
	
	void close()override
	{
		pointer=0;
		Info_Menu_Status=false;
		Main_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()override
	{
		pointer++;
		if(pointer>INFO_MENU_POINER_COUNT) pointer=0;
		actions();
	};
	
	void previous()override
	{
		pointer--;
		if(pointer<0) pointer=INFO_MENU_POINER_COUNT;
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
		if(Info_Menu_Status){
			switch(pointer)
			{
				case 0:
				{
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer]+0,y,1,8,D);
					oled.OLED_Write_To_Bufer(x[pointer]+8,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+16,y,1,8,V);
					oled.OLED_Write_To_Bufer(x[pointer]+24,y,1,8,I);
					oled.OLED_Write_To_Bufer(x[pointer]+32,y,1,8,C);
					oled.OLED_Write_To_Bufer(x[pointer]+40,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+56,y,1,8,I);
					oled.OLED_Write_To_Bufer(x[pointer]+64,y,1,8,N);
					oled.OLED_Write_To_Bufer(x[pointer]+72,y,1,8,F);
					oled.OLED_Write_To_Bufer(x[pointer]+80,y,1,8,O);

					break;
				}
				case 1:
				{
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer]+0,y,1,8,U);
					oled.OLED_Write_To_Bufer(x[pointer]+8,y,1,8,S);
					oled.OLED_Write_To_Bufer(x[pointer]+16,y,1,8,E);
					oled.OLED_Write_To_Bufer(x[pointer]+24,y,1,8,R);
					oled.OLED_Write_To_Bufer(x[pointer]+40,y,1,8,I);
					oled.OLED_Write_To_Bufer(x[pointer]+48,y,1,8,N);
					oled.OLED_Write_To_Bufer(x[pointer]+56,y,1,8,F);
					oled.OLED_Write_To_Bufer(x[pointer]+64,y,1,8,O);
					break;
				}
				case 2:
				{
					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[pointer],y,2,8,backk);
					break;
				}
			}
		}
	};
	
};

Info_menu inf_menu;
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
	if(!(PINA&0b00000100)&!btn2 )
	{
		
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,one);
		btn2=true;
	}
	
	if(!(PINA&0b00001000)&!btn3 )
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,two);
		btn3=true;
	}
	if(!(PINA&0b00010000)&!btn0 )
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,three);
		btn0=true;
	}
	if(!(PINA&0b00100000)&!btn1 )
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,four);
		btn1=true;
	}
	_delay_ms(500);
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
		else if (Info_Menu_Status)
		{
			inf_menu.previous();
			//sett_menu.refresh();
		}
		else if (User_Info_Status)
		{
		//	.refresh();
		}
		else if (Device_Info_Status)
		{
		//	.refresh();
		}
		else if (User_Add_Status)
		{
		//	.refresh();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			//	.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}

	}
	else if(!btn0 & btn1 & !btn2 & !btn3 & !btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,one);
		if (Password_Menu_Status)
		{

		}
		else if (Main_Menu_Status)
		{

		}
		else if (Settings_Menu_Status)
		{

		}	
		else if (Info_Menu_Status)
		{

		}
		else if (User_Info_Status)
		{
			//	.refresh();
		}
		else if (Device_Info_Status)
		{
			//	.refresh();
		}
		else if (User_Add_Status)
		{
			//	.refresh();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			//	.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}
		if(!locked)
		{
			PORTD = 0b10000000;
			_delay_ms(15000);
			PORTD = 0b00000000;
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
		else if (Info_Menu_Status)
		{

		}
		else if (User_Info_Status)
		{
			//	.refresh();
		}
		else if (Device_Info_Status)
		{
			//	.refresh();
		}
		else if (User_Add_Status)
		{
			//	.refresh();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			//	.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}
		
		if(!locked)
		{
			PORTD = 0b10000000;
			_delay_ms(15000);
			PORTD = 0b00000000;
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
		else if (Info_Menu_Status)
		{
			inf_menu.next();
		}
		else if (User_Info_Status)
		{
			//	.refresh();
		}
		else if (Device_Info_Status)
		{
			//	.refresh();
		}
		else if (User_Add_Status)
		{
			//	.refresh();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			//	.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}

	}
	else if(!btn0  & !btn3 & btn12 & !btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,four);
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
	else if (Info_Menu_Status)
	{

	}
	else if (User_Info_Status)
	{
		//	.refresh();
	}
	else if (Device_Info_Status)
	{
		//	.refresh();
	}
	else if (User_Add_Status)
	{
		//	.refresh();
	}
	else if (Reset_Status)
	{
		//	.refresh();
	}
	else if (Brightness_Status)
	{
		//	.refresh();
	}
	else if (Waiting_Status)
	{
		//	.refresh();
	}
		if(!locked)
		{
			PORTD = 0b10000000;
			_delay_ms(15000);
			PORTD = 0b00000000;
		}
	}
	else if(!btn1 & !btn2 & !btn12 & btn03)
	{
		oled.OLED_Clear_Bufer_part(0,0,1,8);
		oled.OLED_Write_To_Bufer(0,0,1,8,five);
		
		
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
		else if (Info_Menu_Status)
		{
			inf_menu.choise();
			//sett_menu.refresh();
		}
		else if (User_Info_Status)
		{
			//	.refresh();
		}
		else if (Device_Info_Status)
		{
			//	.refresh();
		}
		else if (User_Add_Status)
		{
			//	.refresh();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			//	.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
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

void asciitoimg(int x,int y,int w,int h,uint8_t data)
{
	if (data==0x41) 
	oled.OLED_Write_To_Bufer(x,y,w,h,A);
	else if (data==0x42)
	oled.OLED_Write_To_Bufer(x,y,w,h,B);
	else if (data==0x43)
	oled.OLED_Write_To_Bufer(x,y,w,h,C);
	else if (data==0x44)
	oled.OLED_Write_To_Bufer(x,y,w,h,D);
	else if (data==0x45)
	oled.OLED_Write_To_Bufer(x,y,w,h,E);
	else if (data==0x46)
	oled.OLED_Write_To_Bufer(x,y,w,h,F);
	else if (data==0x47)
	oled.OLED_Write_To_Bufer(x,y,w,h,G);
	else if (data==0x48)
	oled.OLED_Write_To_Bufer(x,y,w,h,H);
	else if (data==0x49)
	oled.OLED_Write_To_Bufer(x,y,w,h,I);
	else if (data==0x4A)
	oled.OLED_Write_To_Bufer(x,y,w,h,J);
	else if (data==0x4B)
	oled.OLED_Write_To_Bufer(x,y,w,h,K);
	else if (data==0x4C)
	oled.OLED_Write_To_Bufer(x,y,w,h,L);
	else if (data==0x4D)
	oled.OLED_Write_To_Bufer(x,y,w,h,M);
	else if (data==0x4E)
	oled.OLED_Write_To_Bufer(x,y,w,h,N);
	else if (data==0x4F)
	oled.OLED_Write_To_Bufer(x,y,w,h,O);
	else if (data==0x50)
	oled.OLED_Write_To_Bufer(x,y,w,h,P);
	else if (data==0x51)
	oled.OLED_Write_To_Bufer(x,y,w,h,Q);
	else if (data==0x52)
	oled.OLED_Write_To_Bufer(x,y,w,h,R);
	else if (data==0x53)
	oled.OLED_Write_To_Bufer(x,y,w,h,S);
	else if (data==0x54)
	oled.OLED_Write_To_Bufer(x,y,w,h,T);
	else if (data==0x55)
	oled.OLED_Write_To_Bufer(x,y,w,h,U);
	else if (data==0x56)
	oled.OLED_Write_To_Bufer(x,y,w,h,V);
	else if (data==0x57)
	oled.OLED_Write_To_Bufer(x,y,w,h,W);
	else if (data==0x58)
	oled.OLED_Write_To_Bufer(x,y,w,h,X);
	else if (data==0x59)
	oled.OLED_Write_To_Bufer(x,y,w,h,Y);
	else if (data==0x5A)
	oled.OLED_Write_To_Bufer(x,y,w,h,Z);
	else if (data==0x30)
	oled.OLED_Write_To_Bufer(x,y,w,h,zero);
	else if (data==0x31)
	oled.OLED_Write_To_Bufer(x,y,w,h,one);
	else if (data==0x32)
	oled.OLED_Write_To_Bufer(x,y,w,h,two);
	else if (data==0x33)
	oled.OLED_Write_To_Bufer(x,y,w,h,three);
	else if (data==0x34)
	oled.OLED_Write_To_Bufer(x,y,w,h,four);
	else if (data==0x35)
	oled.OLED_Write_To_Bufer(x,y,w,h,five);
	else if (data==0x36)
	oled.OLED_Write_To_Bufer(x,y,w,h,six);
	else if (data==0x37)
	oled.OLED_Write_To_Bufer(x,y,w,h,seven);
	else if (data==0x38)
	oled.OLED_Write_To_Bufer(x,y,w,h,eight);
	else if (data==0x39)
	oled.OLED_Write_To_Bufer(x,y,w,h,nine);
	
	else if (data>>4==0)
	oled.OLED_Write_To_Bufer(x,y,w,h,NL);
	else oled.OLED_Write_To_Bufer(x,y,w,h,what);
}


void USART_Init()
{
	UBRR0L = 16;      
	UBRR0H = 16 >> 8; 
	UCSR0B |=(1<<RXEN0)|(1<<RXCIE0)|(1<<TXEN0);      
	UCSR0C = (0<<USBS0) | (1<<UCSZ00)| (1<<UCSZ01)| (0<<UCSZ02);
}



void send_Uart(const char c)
{
	while(!(UCSR0A&(1<<UDRE0))) 
	{}
	UDR0 = c;
}

void send_Uart_str(const char *s)
{
	while (*s != 0) send_Uart(*s++);
}


uint8_t data_in[100];
bool read=false;
int count=0;
/*
ISR (USART0_RX_vect)
{
	while(!(UCSR0A&(1<<RXC0))) {};
	UCSR0B |=(0<<RXEN0)|(0<<RXCIE0);
	data_in[count] = UDR0;
		read=true;
		count++;
	UCSR0B |=(1<<RXEN0)|(1<<RXCIE0); 


}

 ISR (TIMER0_COMPA_vect)
 {
	PORTD=0b10000000;
	 

 }
*/
int main(void){
sei();

		oled.OLED_Write_Bufer();
		DDRA = 0xff;  
		PORTA= 0x00;
		DDRD = 0b10000000;
		//PORTD = 0b00000000;
		PCMSK0=0b00111100;
		PCICR|=0b00000001;
	//	OCR0A=0b00010000;
	//	TCCR0A |= (3<<CS00);
		
		USART_Init();
		_delay_ms(1000);
		_delay_ms(1000);	
		send_Uart_str("AT");
		send_Uart((char)13);
		_delay_ms(1000);
		send_Uart_str("AT+CMGF=1");
		//readSerial();
		send_Uart((char)13);
		_delay_ms(1000);
		send_Uart_str("AT+CMGS=\"89260755725\"");
		send_Uart((char)13);
		_delay_ms(1000);
		send_Uart_str("STARTED, READY TO CONTROLL");
		_delay_ms(1000);
		send_Uart((char)26);
		_delay_ms(1000);
	//	send_Uart_str("AT+CNMI=1,2,0,0,0");
	//	send_Uart((char)13);
	//			_delay_ms(1000);
	//			send_Uart_str("AT");
	//			send_Uart((char)13);
	while(1)
	{
		/*
		if (read == true) {
		 for(int j=0;j<count;j++)
		 {
		 oled.OLED_Clear_Bufer_part((j)*8,1,1,8);
		 asciitoimg((j)*8,1,1,8,data_in[j]);
		 }
		 count=0;
		 read = false;
		}*/
		sei();
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
		else if (Info_Menu_Status)
		{
			inf_menu.refresh();
		}
		else if (User_Info_Status)
		{
		//	.refresh();
		}
		else if (Device_Info_Status)
		{
		//	.refresh();
		}
		else if (User_Add_Status)
		{
		//	.refresh();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			//	.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}

		batary.refresh();
		oled.OLED_Write_To_Bufer(80,0,2,8,Net3);
		oled.OLED_Write_Bufer();
	}
}
