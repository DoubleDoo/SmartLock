#include "TWI.h"


	TWI::TWI(){}

	void TWI::twi_Init(void)
	{
		TWBR=(((CPU_F)/(SCL_F)-16)/2);
		TWSR=0;
	}

	void TWI::twi_SendAdress(void)
	{
		TWDR=(Dev_Adr<<1)|0;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}

	void TWI::twi_Start(void)
	{
		TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}

	void TWI::twi_Stop(void)
	{
		TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	}

	void TWI::twi_SendByte(int Inf)
	{
		TWDR=Inf;
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(!(TWCR & (1<<TWINT))){};
	}
	
