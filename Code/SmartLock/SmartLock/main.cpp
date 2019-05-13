#include "Defines.h"
#include "Images.h"
#include "TWI.h"
#include "OLED.h"
#include <avr/eeprom.h>


int brigtnesslvl=1;
TWI wire;
OLED oled(wire,brigtnesslvl*25);
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

bool locktimer=false;

bool locked=false;

bool dream=false;
bool dreamreset=false;

bool newdevice=false;

char* owner_number="89260755725";

uint8_t password[5]={0,0,0,0,0};
uint8_t passwin[5]={0,0,0,0,0};



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

class Main_Menu
{
	protected:
	int pointer=0;
	public:
	Main_Menu()
	{

	};
	
    void Default() 
    {
		oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X-28,MAIN_MENU_IMG_Y+1,1,16,lt);
		oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X+52,MAIN_MENU_IMG_Y+1,1,16,rt);
    };
	
    void refresh()
	{
		//oled.OLED_Bufer_Clear();
		Default();
		actions();
	};
	
	void close()
	{
		oled.OLED_Bufer_Clear();

	};
	
	void next()
	{
		pointer++;
		if(pointer>MAIN_MENU_POINER_COUNT) pointer=0;
		actions();
	};
	
	void previous()
	{
		pointer--;
		if(pointer<0) pointer=MAIN_MENU_POINER_COUNT;
		actions();
	};
	
	void choise()
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
	
	void back()
	{
		
		
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
	{
		switch(pointer)
		{
			case 0:
			{
				oled.OLED_Clear_Bufer_part(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32);
				if(!locked) oled.OLED_Write_To_Bufer(MAIN_MENU_IMG_X,MAIN_MENU_IMG_Y,4,32,unlock);
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
#define PASSWORD_MENU_IMG_Y 3



class Password_Menu
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
	
	void Default() 
	{
		oled.OLED_Write_To_Bufer(x[0],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[1],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[2],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[3],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[4],y+1,1,8,line);
	};
	
	void refresh() 
	{
				//oled.OLED_Bufer_Clear();
				Default();
				actions();
	};
	
	void close()
	{
		pointer=0;
		symbol_pointer=0;
		Password_Menu_Status=false;
		Main_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		symbol_pointer++;
		if(symbol_pointer>PASSWORD_MENU_SIMVOLS_COUNT) symbol_pointer=0;
		actions();
	};
	
	void previous()
	{
		symbol_pointer--;
		if(symbol_pointer<0) symbol_pointer=PASSWORD_MENU_SIMVOLS_COUNT;
		actions();
	};
	
	void choise()
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
					 passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
						  passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
					  passwin[pointer-1]=symbol_pointer;
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
					 passwin[pointer-1]=symbol_pointer;
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
				if(!locked)
				{
					password[0]=passwin[0];
					password[1]=passwin[1];
					password[2]=passwin[2];
					password[3]=passwin[3];
					password[4]=passwin[4];
					passwin[0]=0;
					passwin[1]=0;
					passwin[2]=0;
					passwin[3]=0;
					passwin[4]=0;
					locked=!locked;
				}
				else
				{
					if((password[0]==passwin[0])&(password[1]==passwin[1])&(password[2]==passwin[2])&(password[3]==passwin[3])&(password[4]==passwin[4]))
					locked=!locked;
				}
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
	
	void back()
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
	
	void animate()
	{
		
		
	};
	
	void actions()
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



class Settings_Menu
{
	protected:
	int pointer=0;
	int x[4]={SETTINGS_MENU_IMG_X_0,SETTINGS_MENU_IMG_X_1,SETTINGS_MENU_IMG_X_2,SETTINGS_MENU_IMG_X_3};
	int y=SETTINGS_MENU_IMG_Y;
	public:
	Settings_Menu()
	{

	};
	
	void Default() 
	{
		oled.OLED_Write_To_Bufer(56,y+2,2,8,downwd);
		oled.OLED_Write_To_Bufer(56,y-2,2,8,upwd);
	};
	
	void refresh() 
	{
		//oled.OLED_Bufer_Clear();
		Default();
		actions();
	};
	
	void close()
	{
		pointer=0;
		Settings_Menu_Status=false;
		Main_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		pointer++;
		if(pointer>SETTINGS_MENU_POINER_COUNT) pointer=0;
		actions();
	};
	
	void previous()
	{
		pointer--;
		if(pointer<0) pointer=SETTINGS_MENU_POINER_COUNT;
		actions();		
	};
	
	void choise()
	{
		switch(pointer)
		{
			case 0:
			{
			    Settings_Menu_Status=false;
			    Brightness_Status=true;
			    //close();
				oled.OLED_Bufer_Clear();
			    break;
			}
			case 1:
			{
				Settings_Menu_Status=false;
				Reset_Status=true;
				//close();
				oled.OLED_Bufer_Clear();
				break;
			}
			case 2:
			{
				Settings_Menu_Status=false;
				User_Add_Status=true;
				oled.OLED_Bufer_Clear();
				break;
			}
			case 3:
			{
				back();
				break;
			}
		}
	};
	
	void back()
	{
		close();
	    pointer=0;
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
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

class Info_menu
{
	protected:
	int pointer=0;
	int x[3]={ INFO_MENU_IMG_X_0, INFO_MENU_IMG_X_1, INFO_MENU_IMG_X_2};
	int y= INFO_MENU_IMG_Y;
	public:
	Info_menu()
	{

	};
	
	void Default() 
	{
		oled.OLED_Write_To_Bufer(56,y+2,2,8,downwd);
		oled.OLED_Write_To_Bufer(56,y-2,2,8,upwd);
	};
	
	void refresh() 
	{
		Default();
		actions();
	};
	
	void close()
	{
		pointer=0;
		Info_Menu_Status=false;
		Main_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		pointer++;
		if(pointer>INFO_MENU_POINER_COUNT) pointer=0;
		actions();
	};
	
	void previous()
	{
		pointer--;
		if(pointer<0) pointer=INFO_MENU_POINER_COUNT;
		actions();
	};
	
	void choise()
	{
		switch(pointer)
		{
			case 0:
			{
				 Info_Menu_Status=false;
				 Device_Info_Status=true;
				 //close();
				 oled.OLED_Bufer_Clear();
				break;
			}
			case 1:
			{
				 Info_Menu_Status=false;
				 User_Info_Status=true;
				 //close();
				 oled.OLED_Bufer_Clear();
				break;
			}
			case 2:
			{
				back();
				break;
			}
		}
	};
	
	void back()
	{
		close();
		pointer=0;
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
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

#define US_INFO_POINER_COUNT 4
#define US_INFO_IMG_X_0 8
#define US_INFO_IMG_X_1 44
#define US_INFO_IMG_X_2 8
#define US_INFO_IMG_X_3 20
#define US_INFO_IMG_Y 2

class User_Info
{
	protected:
	int pointer=0;
	int x[4]={ US_INFO_IMG_X_0, US_INFO_IMG_X_1, US_INFO_IMG_X_2,US_INFO_IMG_X_3};
	int y= US_INFO_IMG_Y;
	public:
	User_Info()
	{

	};
	
	void Default() 
	{
		
	};
	
	void refresh() 
	{
		Default();
		actions();
	};
	
	void close()
	{
		pointer=0;
		User_Info_Status=false;
		Info_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		 close();
		actions();
	};
	
	void previous()
	{
		 close();
		actions();
	};
	
	void choise()
	{
		 close();
	};
	
	void back()
	{
		close();
		pointer=0;
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
	{
		if(User_Info_Status){

					oled.OLED_Clear_Bufer_part(0,y,16,8);
					oled.OLED_Write_To_Bufer(x[0]+0,y,1,8,U);
					oled.OLED_Write_To_Bufer(x[0]+8,y,1,8,J);
					oled.OLED_Write_To_Bufer(x[0]+16,y,1,8,N);
					oled.OLED_Write_To_Bufer(x[0]+24,y,1,8,O);
					oled.OLED_Write_To_Bufer(x[0]+32,y,1,8,B);
					oled.OLED_Write_To_Bufer(x[0]+40,y,1,8,U);
					oled.OLED_Write_To_Bufer(x[0]+48,y,1,8,T);
					oled.OLED_Write_To_Bufer(x[0]+56,y,1,8,O);
					oled.OLED_Write_To_Bufer(x[0]+64,y,1,8,V);
					oled.OLED_Write_To_Bufer(x[0]+72,y,1,8,S);
					oled.OLED_Write_To_Bufer(x[0]+80,y,1,8,K);
					oled.OLED_Write_To_Bufer(x[0]+88,y,1,8,A);
					oled.OLED_Write_To_Bufer(x[0]+96,y,1,8,Y);
					oled.OLED_Write_To_Bufer(x[0]+104,y,1,8,A);


					oled.OLED_Clear_Bufer_part(0,y+1,16,8);
					oled.OLED_Write_To_Bufer(x[1]+0,y+1,1,8,six);
					oled.OLED_Write_To_Bufer(x[1]+8,y+1,1,8,six);
					oled.OLED_Write_To_Bufer(x[1]+24,y+1,1,8,six);
					oled.OLED_Write_To_Bufer(x[1]+32,y+1,1,8,nine);

					
					oled.OLED_Clear_Bufer_part(0,y+2,16,8);
					oled.OLED_Write_To_Bufer(x[2]+0,y+2,1,8,D);
					oled.OLED_Write_To_Bufer(x[2]+8,y+2,1,8,M);
					oled.OLED_Write_To_Bufer(x[2]+16,y+2,1,8,I);
					oled.OLED_Write_To_Bufer(x[2]+24,y+2,1,8,T);
					oled.OLED_Write_To_Bufer(x[2]+32,y+2,1,8,R);
					oled.OLED_Write_To_Bufer(x[2]+40,y+2,1,8,Y);
					oled.OLED_Write_To_Bufer(x[2]+56,y+2,1,8,D);
					oled.OLED_Write_To_Bufer(x[2]+64,y+2,1,8,U);
					oled.OLED_Write_To_Bufer(x[2]+72,y+2,1,8,B);
					oled.OLED_Write_To_Bufer(x[2]+80,y+2,1,8,I);
					oled.OLED_Write_To_Bufer(x[2]+88,y+2,1,8,N);
					oled.OLED_Write_To_Bufer(x[2]+96,y+2,1,8,A);
					
					oled.OLED_Clear_Bufer_part(0,y+3,16,8);
					oled.OLED_Write_To_Bufer(x[3]+0,y+3,1,8,eight);
					oled.OLED_Write_To_Bufer(x[3]+8,y+3,1,8,nine);
					oled.OLED_Write_To_Bufer(x[3]+16,y+3,1,8,two);
					oled.OLED_Write_To_Bufer(x[3]+24,y+3,1,8,six);
					oled.OLED_Write_To_Bufer(x[3]+32,y+3,1,8,zero);
					oled.OLED_Write_To_Bufer(x[3]+40,y+3,1,8,seven);
					oled.OLED_Write_To_Bufer(x[3]+48,y+3,1,8,five);
					oled.OLED_Write_To_Bufer(x[3]+56,y+3,1,8,five);
					oled.OLED_Write_To_Bufer(x[3]+64,y+3,1,8,seven);
					oled.OLED_Write_To_Bufer(x[3]+72,y+3,1,8,two);
					oled.OLED_Write_To_Bufer(x[3]+80,y+3,1,8,five);

			}
	};
	
};


#define DV_INFO_POINER_COUNT 0
#define DV_INFO_IMG_X_0 0
#define DV_INFO_IMG_X_1 32
#define DV_INFO_IMG_Y 2

class Device_info:public Menu_Element
{
	protected:
	int x[2]={ DV_INFO_IMG_X_0, DV_INFO_IMG_X_1};
	int y= DV_INFO_IMG_Y;
	public:
	Device_info()
	{

	};
	
	void Default() 
	{
		
	};
	
	void refresh() 
	{
		Default();
		actions();
	};
	
	void close()
	{
		pointer=0;
		Device_Info_Status=false;
		Info_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		close();
	};
	
	void previous()
	{
		close();
	};
	
	void choise()
	{
		close();
	};
	
	void back()
	{
		close();
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
	{
		if(Device_Info_Status){

			oled.OLED_Clear_Bufer_part(0,y,16,8);
			oled.OLED_Write_To_Bufer(x[0]+0,y,1,8,S);
			oled.OLED_Write_To_Bufer(x[0]+8,y,1,8,O);
			oled.OLED_Write_To_Bufer(x[0]+16,y,1,8,F);
			oled.OLED_Write_To_Bufer(x[0]+24,y,1,8,T);
			oled.OLED_Write_To_Bufer(x[0]+32,y,1,8,W);
			oled.OLED_Write_To_Bufer(x[0]+40,y,1,8,A);
			oled.OLED_Write_To_Bufer(x[0]+48,y,1,8,R);
			oled.OLED_Write_To_Bufer(x[0]+56,y,1,8,E);
			oled.OLED_Write_To_Bufer(x[0]+72,y,1,8,V);
			oled.OLED_Write_To_Bufer(x[0]+80,y,1,8,E);
			oled.OLED_Write_To_Bufer(x[0]+88,y,1,8,R);
			oled.OLED_Write_To_Bufer(x[0]+96,y,1,8,S);
			oled.OLED_Write_To_Bufer(x[0]+104,y,1,8,I);
			oled.OLED_Write_To_Bufer(x[0]+112,y,1,8,O);
			oled.OLED_Write_To_Bufer(x[0]+120,y,1,8,N);
			
			oled.OLED_Clear_Bufer_part(0,y+1,16,8);
			oled.OLED_Write_To_Bufer(x[1]+0,y+1,1,8,zero);
			oled.OLED_Write_To_Bufer(x[1]+8,y+1,1,8,dot);
			oled.OLED_Write_To_Bufer(x[1]+16,y+1,1,8,one);
			oled.OLED_Write_To_Bufer(x[1]+32,y+1,1,8,B);
			oled.OLED_Write_To_Bufer(x[1]+40,y+1,1,8,E);
			oled.OLED_Write_To_Bufer(x[1]+48,y+1,1,8,T);
			oled.OLED_Write_To_Bufer(x[1]+56,y+1,1,8,A);
		}
	};
	
};


#define BRGTNS_SETTINGS_MENU_POINER_COUNT 10
#define BRGTNS_SETTINGS_MENU_IMG_X_0 0
#define BRGTNS_SETTINGS_MENU_IMG_X_1 112
#define BRGTNS_SETTINGS_MENU_IMG_X_2 8
#define BRGTNS_SETTINGS_MENU_IMG_X_3 20
#define BRGTNS_SETTINGS_MENU_IMG_Y 3



class Bright_set
{
	protected:
	int pointer=0;
	int x[4]={BRGTNS_SETTINGS_MENU_IMG_X_0,BRGTNS_SETTINGS_MENU_IMG_X_1,BRGTNS_SETTINGS_MENU_IMG_X_2,BRGTNS_SETTINGS_MENU_IMG_X_3};
	int y=BRGTNS_SETTINGS_MENU_IMG_Y;
	public:
	Bright_set()
	{
		pointer= brigtnesslvl;
	};
	
	void Default() 
	{
		pointer= brigtnesslvl;
		oled.OLED_Write_To_Bufer(BRGTNS_SETTINGS_MENU_IMG_X_0,y+1,1,16,lt);
		oled.OLED_Write_To_Bufer(BRGTNS_SETTINGS_MENU_IMG_X_1,y+1,1,16,rt);
	};
	
	void refresh() 
	{
		//oled.OLED_Bufer_Clear();
		Default();
		actions();
	};
	
	void close()
	{
		pointer=0;
		Settings_Menu_Status=true;
		Brightness_Status=false;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		pointer++;
		if(pointer>BRGTNS_SETTINGS_MENU_POINER_COUNT+1) pointer=BRGTNS_SETTINGS_MENU_POINER_COUNT+1;
		actions();
		brigtnesslvl=pointer;
	};
	
	void previous()
	{
		pointer--;
		if(pointer<1) pointer=1;
		actions();
		brigtnesslvl=pointer;
	};
	
	void choise()
	{
		brigtnesslvl=pointer;
		asm("JMP 0");

		close();
	};
	
	void back()
	{
		close();
		pointer=0;
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
	{
		oled.OLED_Clear_Bufer_part(0,y-1,16,8);
		oled.OLED_Write_To_Bufer(x[2]+0,y-1,1,8,S);
		oled.OLED_Write_To_Bufer(x[2]+8,y-1,1,8,E);
		oled.OLED_Write_To_Bufer(x[2]+16,y-1,1,8,T);
		oled.OLED_Write_To_Bufer(x[2]+32,y-1,1,8,B);
		oled.OLED_Write_To_Bufer(x[2]+40,y-1,1,8,R);
		oled.OLED_Write_To_Bufer(x[2]+48,y-1,1,8,I);
		oled.OLED_Write_To_Bufer(x[2]+56,y-1,1,8,G);
		oled.OLED_Write_To_Bufer(x[2]+64,y-1,1,8,H);
		oled.OLED_Write_To_Bufer(x[2]+72,y-1,1,8,T);
		oled.OLED_Write_To_Bufer(x[2]+80,y-1,1,8,N);
		oled.OLED_Write_To_Bufer(x[2]+88,y-1,1,8,E);
		oled.OLED_Write_To_Bufer(x[2]+96,y-1,1,8,S);
		oled.OLED_Write_To_Bufer(x[2]+104,y-1,1,8,S);
		if(Brightness_Status){
			switch(pointer)
			{
				case 0:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
				}
				case 1:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					break;
				}
				case 2:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					break;
				}
				case 3:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);


					break;
				}
				case 4:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);

					break;
				}
				case 5:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+32,y+1,1,16,dfull);

					break;
				}
				case 6:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+32,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+40,y+1,1,16,dfull);

					break;
				}
				case 7:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+32,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+40,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+48,y+1,1,16,dfull);
					break;
				}
				case 8:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+32,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+40,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+48,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+56,y+1,1,16,dfull);
					break;
				}
				case 9:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+32,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+40,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+48,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+56,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+64,y+1,1,16,dfull);
					break;
				}
				case 10:
				{
					oled.OLED_Clear_Bufer_part(x[3],y+1,10,16);
					oled.OLED_Write_To_Bufer(x[3]+0,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+8,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+16,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+24,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+32,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+40,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+48,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+56,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+64,y+1,1,16,dfull);
					oled.OLED_Write_To_Bufer(x[3]+72,y+1,1,16,dfull);
					break;
				}				
				

				
			}
		}
	};
	
};


#define DR_POINER_COUNT 0
#define DR_IMG_X_0 12
#define DR_IMG_X_1 0
#define DR_IMG_X_2 104
#define DR_IMG_Y 2

class Device_reset
{
	protected:
	int x[3]={ DR_IMG_X_0, DR_IMG_X_1,DR_IMG_X_2};
	int y= DR_IMG_Y;
	public:
	Device_reset()
	{

	};
	
	void Default() 
	{
		oled.OLED_Write_To_Bufer(x[0]+0,y,1,8,R);
		oled.OLED_Write_To_Bufer(x[0]+8,y,1,8,E);
		oled.OLED_Write_To_Bufer(x[0]+16,y,1,8,S);
		oled.OLED_Write_To_Bufer(x[0]+24,y,1,8,E);
		oled.OLED_Write_To_Bufer(x[0]+32,y,1,8,T);
		oled.OLED_Write_To_Bufer(x[0]+48,y,1,8,D);
		oled.OLED_Write_To_Bufer(x[0]+56,y,1,8,E);
		oled.OLED_Write_To_Bufer(x[0]+64,y,1,8,V);
		oled.OLED_Write_To_Bufer(x[0]+72,y,1,8,I);
		oled.OLED_Write_To_Bufer(x[0]+80,y,1,8,C);
		oled.OLED_Write_To_Bufer(x[0]+88,y,1,8,E);
		oled.OLED_Write_To_Bufer(x[0]+96,y,1,8,what);
		
		oled.OLED_Write_To_Bufer(x[2]+0,y+2,1,8,Y);
		oled.OLED_Write_To_Bufer(x[2]+8,y+2,1,8,E);
		oled.OLED_Write_To_Bufer(x[2]+16,y+2,1,8,S);
		
		oled.OLED_Write_To_Bufer(x[1]+0,y+2,1,8,N);
		oled.OLED_Write_To_Bufer(x[1]+8,y+2,1,8,O);	
		};
	
	void refresh() 
	{
		Default();
		//actions();
	};
	
	void close()
	{
		Reset_Status=false;
		Settings_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		newdevice=true;
		Reset_Status=false;
		asm("JMP 0");
		//oled.OLED_Bufer_Clear();
	};
	
	void previous()
	{
		close();
	};
	
	void choise()
	{

	};
	
	void back()
	{
		
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
	{

	};
	
};



#define Add_Owner_MENU_POINER_COUNT 10
#define Add_Owner_MENU_SIMVOLS_COUNT 10
#define Add_Owner_MENU_IMG_X_0 5
#define Add_Owner_MENU_IMG_X_1 16
#define Add_Owner_MENU_IMG_X_2 27
#define Add_Owner_MENU_IMG_X_3 38
#define Add_Owner_MENU_IMG_X_4 49
#define Add_Owner_MENU_IMG_X_5 60
#define Add_Owner_MENU_IMG_X_6 71
#define Add_Owner_MENU_IMG_X_7 82
#define Add_Owner_MENU_IMG_X_8 93
#define Add_Owner_MENU_IMG_X_9 104
#define Add_Owner_MENU_IMG_X_10 115
#define Add_Owner_MENU_IMG_Y 3



class Add_Owner
{
	protected:
	int pointer=0;
	int symbol_pointer=0;
	int x[11]={Add_Owner_MENU_IMG_X_0,Add_Owner_MENU_IMG_X_1,Add_Owner_MENU_IMG_X_2,Add_Owner_MENU_IMG_X_3,Add_Owner_MENU_IMG_X_4,Add_Owner_MENU_IMG_X_5,Add_Owner_MENU_IMG_X_6,Add_Owner_MENU_IMG_X_7,Add_Owner_MENU_IMG_X_8,Add_Owner_MENU_IMG_X_9,Add_Owner_MENU_IMG_X_10};
	int y=PASSWORD_MENU_IMG_Y;
	public:
	Add_Owner()
	{

	};
	
	void Default()
	{
		oled.OLED_Write_To_Bufer(x[0],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[1],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[2],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[3],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[4],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[5],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[6],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[7],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[8],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[9],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[10],y+1,1,8,line);
		oled.OLED_Write_To_Bufer(x[11],y+1,1,8,line);
	};
	
	void refresh()
	{
		//oled.OLED_Bufer_Clear();
		Default();
		actions();
	};
	
	void close()
	{
		pointer=0;
		symbol_pointer=0;
		User_Add_Status=false;
		Settings_Menu_Status=true;
		oled.OLED_Bufer_Clear();
	};
	
	void next()
	{
		symbol_pointer++;
		if(symbol_pointer>Add_Owner_MENU_SIMVOLS_COUNT) symbol_pointer=0;
		actions();
	};
	
	void previous()
	{
		symbol_pointer--;
		if(symbol_pointer<0) symbol_pointer=Add_Owner_MENU_SIMVOLS_COUNT;
		actions();
	};
	
	void choise()
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
		if(pointer>Add_Owner_MENU_POINER_COUNT) {
			
			User_Add_Status=false;
			Settings_Menu_Status=true;
			close();
		}
		else
		{
			symbol_pointer=0;
			actions();
		}
		
		
	};
	
	void back()
	{
		oled.OLED_Clear_Bufer_part(x[pointer],y,1,8);
		oled.OLED_Clear_Bufer_part(x[pointer],y+2,1,8);
		oled.OLED_Clear_Bufer_part(x[pointer],y-1,1,8);
		pointer--;
		if(pointer<0)
		{
			User_Add_Status=false;
			Settings_Menu_Status=true;
			close();
			pointer=0;
		}
		else actions();
	};
	
	void animate()
	{
		
		
	};
	
	void actions()
	{
		if(User_Add_Status){
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


Info_menu inf_menu;
Settings_Menu sett_menu;
Password_Menu passw_menu;
Main_Menu menu;
User_Info us_inf;
Device_info dev_inf;
Bright_set brgtns;
Device_reset Dreset;
Add_Owner adown;




bool btn0=false;
bool btn1=false;
bool btn2=false;
bool btn3=false;
bool btn03=false;
bool btn12=false;

ISR(PCINT0_vect)
{
	//getup();
    //cli();
	//PORTD=0b10000000;
	if(!(PINA&0b00000100)&!btn2 )
	{
		
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,three);
		btn2=true;
	}
	
	if(!(PINA&0b00001000)&!btn3 )
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,zero);
		btn3=true;
	}
	if(!(PINA&0b00010000)&!btn0 )
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,two);
		btn0=true;
	}
	if(!(PINA&0b00100000)&!btn1 )
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,one);
		btn1=true;
	}
	//_delay_ms(100);
	//sei();
//PORTD=0b00000000;
}


void check()
{
	_delay_ms(1000);
	cli();
	if(btn0 & !btn1 & !btn2 & btn3) btn03=true;
	if(!btn0 & btn1 & btn2 & !btn3) btn12=true;
	
	if(btn0 & !btn1 & !btn2 & !btn3 & !btn12 & !btn03)
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,zero);
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
		us_inf.close();
		}
		else if (Device_Info_Status)
		{
		dev_inf.close();
		}
		else if (User_Add_Status)
		{
		adown.previous();
		}
		else if (Reset_Status)
		{
			Dreset.previous();
		}
		else if (Brightness_Status)
		{
			brgtns.previous();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}
dreamreset=true;
		if(newdevice)
		{
			newdevice=!newdevice;
			Main_Menu_Status=true;
		}
	}
	else if(!btn0 & btn1 & !btn2 & !btn3 & !btn12 & !btn03)
	{
//		oled.OLED_Clear_Bufer_part(0,0,1,8);
//		oled.OLED_Write_To_Bufer(0,0,1,8,one);
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
			us_inf.close();
		}
		else if (Device_Info_Status)
		{
			dev_inf.close();
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
			locktimer=true;
		}
		dreamreset=true;
				if(newdevice)
				{
					newdevice=!newdevice;
					Main_Menu_Status=true;
				}
	}
	else if(!btn0 & !btn1 & btn2 & !btn3 & !btn12 & !btn03)
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,two);
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
			us_inf.close();
		}
		else if (Device_Info_Status)
		{
			dev_inf.close();
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
			locktimer=true;
		}
dreamreset=true;
		if(newdevice)
		{
			newdevice=!newdevice;
			Main_Menu_Status=true;
		}
	}
	else if(!btn0 & !btn1 & !btn2 & btn3 & !btn12 & !btn03)
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
		//oled.OLED_Write_To_Bufer(0,0,1,8,three);
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
			us_inf.close();
		}
		else if (Device_Info_Status)
		{
			dev_inf.close();
		}
		else if (User_Add_Status)
		{
			adown.next();
		}
		else if (Reset_Status)
		{
			Dreset.next();
		}
		else if (Brightness_Status)
		{
			brgtns.next();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}
dreamreset=true;
		if(newdevice)
		{
			newdevice=!newdevice;
			Main_Menu_Status=true;
		}
	}
	else if(!btn0  & !btn3 & btn12 & !btn03)
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,four);
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
		us_inf.close();
	}
	else if (Device_Info_Status)
	{
		dev_inf.close();
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
			locktimer=true;
		}
		dreamreset=true;
				if(newdevice)
				{
					newdevice=!newdevice;
					Main_Menu_Status=true;
				}
	}
	else if(!btn1 & !btn2 & !btn12 & btn03)
	{
	//	oled.OLED_Clear_Bufer_part(0,0,1,8);
	//	oled.OLED_Write_To_Bufer(0,0,1,8,five);
		
		
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
			us_inf.close();
		}
		else if (Device_Info_Status)
		{
			dev_inf.close();
		}
		else if (User_Add_Status)
		{
			adown.choise();
		}
		else if (Reset_Status)
		{
			//	.refresh();
		}
		else if (Brightness_Status)
		{
			brgtns.choise();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}
	dreamreset=true;
			if(newdevice)
			{
				newdevice=!newdevice;
				Main_Menu_Status=true;
			}	
	}

	//_delay_ms(100);
	
			btn0=false;
			btn1=false;
			btn2=false;
			btn3=false;
			btn03=false;
			btn12=false;
		

		sei();	
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
//	printlvltoOLEDbufer();
}

void refreshlvl()
{
	int kf=0;
	if((PINB>>0)&(0b00000001==1)) kf++;
	if((PINB>>1)&(0b00000001==1)) kf++;
	if((PINB>>2)&(0b00000001==1)) kf++;
	if((PINB>>3)&(0b00000001==1)) kf++;
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

		int j=0;
		int i=0;

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

void USART_Init()
{
	UBRR0L = 19;
	UBRR0H = 19 >> 8;
	UCSR0B |=(1<<RXEN0)|(1<<RXCIE0)|(1<<TXEN0);
	UCSR0C = (0<<USBS0) | (1<<UCSZ00)| (1<<UCSZ01)| (0<<UCSZ02);
	_delay_ms(100);
	send_Uart_str("AT");
	send_Uart((char)13);
	_delay_ms(100);
	send_Uart_str("ATE1");
	send_Uart((char)13);
	_delay_ms(100);
	send_Uart_str("ATV1");
	send_Uart((char)13);
	_delay_ms(100);
	
}

uint8_t data_in[100];
bool read=false;
int count=0;

ISR (USART0_RX_vect)
{
	while(!(UCSR0A&(1<<RXC0))) {};
	UCSR0B |=(0<<RXEN0)|(0<<RXCIE0);
	data_in[count] = UDR0;
	count++;
	/*asciitoimg((j++)*8,1,1,8,data_in[count-1]);*/
	UCSR0B |=(1<<RXEN0)|(1<<RXCIE0);
}




void readfirst()
{
	send_Uart_str("AT+CMGF=1");
	send_Uart((char)13);
	_delay_ms(1000);
	send_Uart_str("AT+CMGR=1,1");
	send_Uart((char)13);

}

void deleteall()
{
	
	send_Uart_str("AT+CMGDA=\"DEL ALL\"");
	send_Uart((char)13);
	
	_delay_ms(1000);
	send_Uart_str("AT+CMGF=1");
	send_Uart((char)13);
	_delay_ms(1000);
	
}

bool isnum(uint8_t sign)
{
	if(sign==0x30||sign==0x31||sign==0x32||sign==0x33||sign==0x34||sign==0x35||sign==0x36||sign==0x37||sign==0x38||sign==0x39) return true; else return false;

}


bool corect_sender=false;
bool unlock_comand=false;
bool readinginprocess=false;
bool test=false;

int z=0;
int k=0;
 ISR (TIMER1_COMPA_vect)
 {
	 if(locktimer)
	 if(z<100) z++;
	 else{

		 if(test){
			 oled.OLED_Clear_Bufer_part(8,0,1,8);
		//	 oled.OLED_Write_To_Bufer(8,0,1,8,zero);
			 PORTD=0b00000000;
			 locktimer=false;
		 }
		else
		{
			oled.OLED_Clear_Bufer_part(8,0,1,8);
		//	oled.OLED_Write_To_Bufer(8,0,1,8,one);
			PORTD=0b10000000;
		}
		
				 test=!test;
				 z=0;
	 }
	 else {z=100;}
 
	 if(!dream)
	 {
	 if(k<50) 
	 {
		k++;
		oled.OLED_Clear_Bufer_part(16,0,1,8);
		//oled.OLED_Write_To_Bufer(16,0,1,8,zero);
	 }
	 else{
	   	 oled.OLED_Clear_Bufer_part(16,0,1,8);
	//	 oled.OLED_Write_To_Bufer(16,0,1,8,two);
		  dream=true;
		 }
	 }

	 
	 if(dreamreset)
	 {
		 k=0;
		 dreamreset=false;
		 dream=false;
	 }

 }

 
 void sleepc(void)
 {
	 cli();		
	 set_sleep_mode(SLEEP_MODE_PWR_DOWN);    
	 sei();	
	 sleep_mode();
	 cli();
 }

 void oledwritenum(int num,int x,int y)
 {
	 if(num==0)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,zero);
	 }
	 else if(num==1)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,one);
	 }
	 else if(num==2)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,two);
	 }
	 else if(num==3)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,three);
	 }
	 else if(num==4)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,four);
	 }
	 else if(num==5)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,five);
	 }
	 else if(num==6)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,six);
	 }
	 else if(num==7)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,seven);
	 }
	 else if(num==8)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,eight);
	 }
	 else if(num==9)
	 {
		 oled.OLED_Clear_Bufer_part(x,y,1,8);
		 oled.OLED_Write_To_Bufer(x,y,1,8,nine);
	 }
	 
	 
 }
 
 
 void send_SMS(char *text,char *number)
 {
	 send_Uart_str("AT+CMGF=1");
	 send_Uart((char)13);
	 _delay_ms(250);
	 send_Uart_str("AT+CMGS=\"");
	 send_Uart_str(number);
	 send_Uart_str("\"");
	 send_Uart((char)13);
	 _delay_ms(250);
	 send_Uart_str(text);
	 send_Uart((char)26);
	 _delay_ms(250);
 }
 
 
 void SMStranslator(int j)
 {

	 if (count>j) {
		 if(count==j)
		 {
			 j=0;
			 count=0;
			 readinginprocess=false;
		 }
		 if(!readinginprocess)
		 {
			 if(count-j>3)
			 {
				 if(data_in[j]=='C'&data_in[j+1]=='M'&data_in[j+2]=='T'&data_in[j+3]=='I')
				 {
					 readinginprocess=true;
					 oled.OLED_Write_To_Bufer((i++)*8,1,1,8,C);
					 readfirst();
					 deleteall();

				 }
			 }
		 }
		 else
		 {
			 if(count>6)
			 {
				 if(data_in[j]=='0'&data_in[j+1]=='7'&data_in[j+2]=='5'&data_in[j+3]=='5'&data_in[j+4]=='7'&data_in[j+5]=='2'&data_in[j+6]=='5')
				 {
					 oled.OLED_Write_To_Bufer((i++)*8,1,1,8,N);
					 corect_sender=true;
					 j+=6;
				 }
			 }
			 
			 if(corect_sender)
			 {
				 if(j>5)
				 {
					 if(data_in[j]=='U'&data_in[j+1]=='N'&data_in[j+2]=='L'&data_in[j+3]=='O'*data_in[j+4]=='C'&data_in[j+5]=='K')
					 {
						 oled.OLED_Write_To_Bufer((i++)*8,1,1,8,U);
						 unlock_comand=true;
						 j+=5;
					 }
				 }
				 
			 }
			 if(unlock_comand)
			 {
				 if(j>4)
				 {
					 if(isnum(data_in[j])&isnum(data_in[j+1])&isnum(data_in[j+2])&isnum(data_in[j+3])&isnum(data_in[j+4]))
					 {
						 
						 if(data_in[j]==password[0]&data_in[j+1]==password[1]&data_in[j+2]==password[2]&data_in[j+3]==password[3]&data_in[j+4]==password[4]){
							 oled.OLED_Write_To_Bufer((i++)*8,1,1,8,U);
							 locked=false;
							 PORTD=0b10000000;
							 readinginprocess=false;
							 j+=4;
						 }
					 }
					 
				 }
				 
			 }
		 }
		 j++;
	 }
	 
 }

 

int main(void){

		sei();
		oled.OLED_Write_To_Bufer(48,2,4,16,SL);
		oled.OLED_Write_To_Bufer(24,6,1,8,L);
		oled.OLED_Write_To_Bufer(32,6,1,8,O);
		oled.OLED_Write_To_Bufer(40,6,1,8,A);
		oled.OLED_Write_To_Bufer(48,6,1,8,D);
		oled.OLED_Write_To_Bufer(56,6,1,8,I);
		oled.OLED_Write_To_Bufer(64,6,1,8,N);
		oled.OLED_Write_To_Bufer(72,6,1,8,G);
		oled.OLED_Write_To_Bufer(80,6,1,8,dot);
		oled.OLED_Write_To_Bufer(88,6,1,8,dot);
		oled.OLED_Write_To_Bufer(96,6,1,8,dot);
		oled.OLED_Write_Bufer();
		oled.OLED_Bufer_Clear();
	
		DDRD = 0b10000000;
		
		PCICR|=0b00000001;
		PCMSK0=0b00111100;
		
		TCCR1A = 0;                     
		TCCR1B = (1<<WGM12)|(5<<CS10);  
		OCR1A = 0b11111111;     
		TIMSK1 |= (1<<OCIE1A);         
		TIFR1 = (1<<OCF1A);            
		_delay_ms(30000);
		//_delay_ms(1000);
		USART_Init();
		_delay_ms(250);
		//deleteall();
		//_delay_ms(250);
		//send_Uart_str("AT");
		//send_Uart((char)13);
		//_delay_ms(250);

	while(1)
	{
		/*
		oledwritenum(password[0],8,1);
		oledwritenum(password[1],16,1);
		oledwritenum(password[2],24,1);
		oledwritenum(password[3],32,1);
		oledwritenum(password[4],40,1);
		oledwritenum(passwin[0],56,1);
		oledwritenum(passwin[1],64,1);
		oledwritenum(passwin[2],72,1);
		oledwritenum(passwin[3],80,1);
		oledwritenum(passwin[4],88,1);*/
		/*
			if(dream)
			{
				cli();
				set_sleep_mode(SLEEP_MODE_PWR_DOWN);
				sei();
				sleep_mode();
				cli();
			}*/
		sei();
		if ((count>0)&(!(UCSR0A &(1<<RXC0)))) {
			//oled.OLED_Clear_Bufer_part((j)*8,1,1,8);
			//asciitoimg((j)*8,1,1,8,data_in[j]);
			if(count-j>3)
			{
				if((data_in[j]=='C') & (data_in[j+1]=='M') & (data_in[j+2]=='T') & (data_in[j+3]=='I'))
				{
					readinginprocess=true;
					//oled.OLED_Write_To_Bufer((i++)*8,1,1,8,C);
					//readfirst();
					count=1;
					j=-1;
				//	deleteall();
				//	send_SMS("Device status changed",owner_number);
				//PORTD=0b10000000;
				locked=!locked;
				}
			}
			j++;
			count--;
		}
	if(count==0){
	j=0;
		}
		
		
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
			us_inf.refresh();
		}
		else if (Device_Info_Status)
		{
			dev_inf.refresh();
		}
		else if (User_Add_Status)
		{
		    adown.refresh();
		}
		else if (Reset_Status)
		{
			Dreset.refresh();
		}
		else if (Brightness_Status)
		{
			brgtns.refresh();
		}
		else if (Waiting_Status)
		{
			//	.refresh();
		}
		else if (newdevice)
		{
			int x=8;
			int q=28;
			oled.OLED_Write_To_Bufer(x+0,3,1,8,Y);
			oled.OLED_Write_To_Bufer(x+8,3,1,8,O);
			oled.OLED_Write_To_Bufer(x+16,3,1,8,U);
			oled.OLED_Write_To_Bufer(x+24,3,1,8,R);
			oled.OLED_Write_To_Bufer(x+40,3,1,8,I);
			oled.OLED_Write_To_Bufer(x+48,3,1,8,N);
			oled.OLED_Write_To_Bufer(x+56,3,1,8,I);
			oled.OLED_Write_To_Bufer(x+64,3,1,8,T);
			oled.OLED_Write_To_Bufer(x+80,3,1,8,C);
			oled.OLED_Write_To_Bufer(x+88,3,1,8,O);
			oled.OLED_Write_To_Bufer(x+96,3,1,8,D);
			oled.OLED_Write_To_Bufer(x+104,3,1,8,E);
			
			oled.OLED_Write_To_Bufer(q+0,4,1,8,two);
			oled.OLED_Write_To_Bufer(q+16,4,1,8,nine);
			oled.OLED_Write_To_Bufer(q+32,4,1,8,six);
			oled.OLED_Write_To_Bufer(q+48,4,1,8,zero);
			oled.OLED_Write_To_Bufer(q+64,4,1,8,eight);
			
		}

		
		batary.refresh();
		oled.OLED_Write_To_Bufer(80,0,2,8,Net3);
		oled.OLED_Write_Bufer();
	//	PORTD=0b10000000;
	//	PORTD=0b00000000;
	}
}

