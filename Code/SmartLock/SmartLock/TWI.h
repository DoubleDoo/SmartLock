#ifndef TWI_H_
#define TWI_H_
#include "Defines.h"
class TWI
{
public:
	TWI();
	void twi_Init(void);
	void twi_SendAdress(void);
	void twi_SendByte(int Inf);
	void twi_Start(void);
	void twi_Stop(void);
};

#endif 