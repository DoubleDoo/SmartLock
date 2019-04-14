

#define OLED_WIDTH			128
#define OLED_HEIGHT			8//*8
#define CPU_F				20000000UL
#define SCL_F				1250000UL
#define Skip_Flag			0xff
#define Dev_Adr				0b00111100

#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>


class TWI
{
	public:
	TWI(){}

	void twi_Init(void)
	{
		TWBR=(((CPU_F)/(SCL_F)-16)/2);
		TWSR=0;
	}

	void twi_SendAdress(void) 
	{
		TWDR=(Dev_Adr<<1)|0;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}

	void twi_Start(void)
	{
		TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}

	void twi_Stop(void)
	{
		TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	}

	void twi_SendByte(int Inf)
	{
		TWDR=Inf;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}
	
};

class OLED
{
private:
uint8_t  oled_bufer[OLED_HEIGHT][OLED_WIDTH];
TWI wire;
bool nw=false;
public:
OLED(TWI _wire)
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

	OLED_Command(0xA7);
	OLED_Command(0xD5);
	OLED_Command(0x80);
	OLED_Command(0x8D);
	OLED_Command(0x14);
	OLED_Command(0xAF);
	for(int i=0;i<OLED_HEIGHT;i++)
	{
		for(int j=0;j<OLED_WIDTH;j++)
		{
			oled_bufer[i][j]=0b00000000;		
		}
	}
	oled_bufer[0][0]=0b11111111;
	OLED_Write_Bufer();
}
	

void OLED_Command(int command)
{
	TWDR=0x80;								
	TWCR=(1<<TWINT)|(1<<TWEN);				
	while(!(TWCR & (1<<TWINT))){};

	TWDR=command;							
	TWCR=(1<<TWINT)|(1<<TWEN);				
	while(!(TWCR & (1<<TWINT))){};
}


void OLED_Data(int data)
{
	TWDR=data;							
	TWCR=(1<<TWINT)|(1<<TWEN);				
	while(!(TWCR & (1<<TWINT))){};
}


void OLED_Write_Bufer()
{
	
	OLED_Command(0x20);
	OLED_Command(0x00);
	OLED_Command(0x21);
	OLED_Command(0);
	OLED_Command(127);
	OLED_Command(0x22);
	OLED_Command(0);
	OLED_Command(7);
	//OLED_Command(0xB1);
	//OLED_Command(0x00);
	//OLED_Command(0x1F);
	TWDR=0x40;
	TWCR=(1<<TWINT)|(1<<TWEN);
  //  if(nw){OLED_Data(0b11111111);nw=false;}
	for(int i=0;i<OLED_HEIGHT;i++)
	{
		for(int j=0;j<OLED_WIDTH;j++)
		{
			OLED_Data(oled_bufer[i][j]);
			
		}
	}
}


void OLED_Write_To_Bufer(int x,int y,int wdth,int height,uint8_t* img)
{
	for(int i=0;i<wdth;i++)
	{
		for(int j=0;j<height;j++)
		{
			oled_bufer[x+i][y+j]|=img[(height)*i+j];
		}
	}
}

void OLED_Write_To_Bufer(int x,int y,uint8_t img)
{

			oled_bufer[x][y]|=img;

}

void writenumber(int i){
	switch(i)
	{
		case 0:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01111110);
		OLED_Data(0b01000010);
		OLED_Data(0b01000010);
		OLED_Data(0b01111110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 1:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b00001000);
		OLED_Data(0b01000110);
		OLED_Data(0b01111110);
		OLED_Data(0b01000000);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 2:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01110010);
		OLED_Data(0b01010010);
		OLED_Data(0b01001010);
		OLED_Data(0b01001110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 3:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01001010);
		OLED_Data(0b01001010);
		OLED_Data(0b01001010);
		OLED_Data(0b01111110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 4:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b00011100);
		OLED_Data(0b00010000);
		OLED_Data(0b00010000);
		OLED_Data(0b01111110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 5:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01000110);
		OLED_Data(0b01001010);
		OLED_Data(0b01001010);
		OLED_Data(0b01110010);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 6:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01111110);
		OLED_Data(0b01001010);
		OLED_Data(0b01001010);
		OLED_Data(0b01111010);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 7:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b00000010);
		OLED_Data(0b01110010);
		OLED_Data(0b00001010);
		OLED_Data(0b00000110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 8:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01111110);
		OLED_Data(0b01001010);
		OLED_Data(0b01001010);
		OLED_Data(0b01111110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
		case 9:
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		OLED_Data(0b01011110);
		OLED_Data(0b01010010);
		OLED_Data(0b01010010);
		OLED_Data(0b01111110);
		OLED_Data(0b00000000);
		OLED_Data(0b00000000);
		break;
	}
}

void Numtooled(int i){
	int j=i;
	int count=0;
	while(j%10!=0)
	{
		j=j/10;
		count++;
	}
	j=i;
	int step=0;
	for(int k=0;k<count;k++)
	{
		step=pow(10,count-k);
		writenumber(j/step);
		j=j%step;
	}
}

};

TWI wire;
OLED oled(wire);
int num = 1;

ISR(PCINT0_vect)
{
    cli();
	if (num == 1)
	num = 0;
	else
    num = 1;
	sei();

}



int main(void){
		//TWI wire;
		//OLED oled(wire);
		//oled.OLED_Write_Bufer();
		//_delay_ms(1000);
		
		
		//Interupts
		DDRA = 0x00;
		PORTA=0x00;
		PCMSK0=0b00111100;
		PCICR|=0b00000001;
		sei();
		//
		DDRD|=0b10000000;
		
while(1)
{
	if(num==1)
	{
		PORTD&=0b01111111;
	}
	else
	{
		PORTD|=0b10000000;
	}
	/*
		if(PINA==0b00000000) {
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			oled.OLED_Data(0b10000000);
			for(int j=0; j<1016; j++)oled.OLED_Data(0b00000000);
		}
		if(PINA==0b00000100)
		{
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			oled.OLED_Data(0b00100000);
			for(int j=0; j<1016; j++)oled.OLED_Data(0b00000000);
		}
		if(PINA==0b00001000)
		{
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			oled.OLED_Data(0b00001000);
			for(int j=0; j<1016; j++)oled.OLED_Data(0b00000000);
		}
		if(PINA==0b00010000)
		{
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			oled.OLED_Data(0b00000010);
			for(int j=0; j<1016; j++)oled.OLED_Data(0b00000000);
		}
		if(PINA==0b00100000)
		{
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			oled.OLED_Data(0b11111111);
			for(int j=0; j<1016; j++)oled.OLED_Data(0b00000000);
		}
		*/
}


	}

