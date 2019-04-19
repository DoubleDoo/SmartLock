#include "OLED.h"

	OLED::OLED(TWI _wire)
	{
		wire=_wire;
		wire.twi_Init();
		wire.twi_Start();
		wire.twi_SendAdress();
		OLED_Command(0xA8);
		OLED_Command(0x3F);

		OLED_Command(0xD3);
		OLED_Command(0x00);

		OLED_Command(0x40);
		OLED_Command(0xA1);

		OLED_Command(0xC8);
		OLED_Command(0xDA);
		OLED_Command(0x12);

		OLED_Command(0x81);
		OLED_Command(0xFF);
		OLED_Command(0xA4);

		OLED_Command(0xA6);
		OLED_Command(0xD5);
		OLED_Command(0x80);
		OLED_Command(0x8D);
		OLED_Command(0x14);
		OLED_Command(0xAF);

		OLED_Command(0x20);
		OLED_Command(0x00);
		OLED_Command(0x21);
		OLED_Command(0);
		OLED_Command(127);
		OLED_Command(0x22);
		OLED_Command(0);
		OLED_Command(7);
		TWDR=0x40;
		TWCR=(1<<TWINT)|(1<<TWEN);
		OLED_Bufer_Clear();
		OLED_Data(0b00000000);
		OLED_Write_Bufer();
	}
	

	void OLED::OLED_Command(int command)
	{
		TWDR=0x80;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};

		TWDR=command;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}


	void OLED::OLED_Data(int data)
	{
		TWDR=data;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}


	void OLED::OLED_Write_Bufer()
	{
		for(int i=0;i<(OLED_HEIGHT/8)*OLED_WIDTH;i++)
		{
			OLED_Data(oled_bufer[i]);
		}
	}

	void OLED::OLED_Bufer_Clear()
	{
		for(int i=0;i<(OLED_HEIGHT/8)*OLED_WIDTH;i++)
		{
			oled_bufer[i]=0b00000000;
		}
	}


	void OLED::OLED_Clear_Bufer_part(int x,int y,int width,int height)
	{
		for(int j=0;j<height;j++)
		{
			
			for(int i=0;i<width;i++)
			{
				for(int k=0;k<8;k++)
				{
					oled_bufer[(x+i*8+k)+(y+j/8)*OLED_WIDTH]=0b00000000;
				}
			}
		}
	}

	void OLED::OLED_Write_To_Bufer(int x,int y,int width,int height,uint8_t* img)
	{
		for(int j=0;j<height;j++)
		{
			
			for(int i=0;i<width;i++)
			{
				for(int k=0;k<8;k++)
				{
					oled_bufer[(x+i*8+k)+(y+j/8)*OLED_WIDTH]|=((img[j*width+i]<<k)&0b10000000)>>(7-j%8);
				}
			}
		}
	}

