
#include "TWI.h"

int main (void)
{

	TWI_Init();

	while(1)
	{

		TWI_StartCond();
		TWI_Write(0b10101010);	//LSB=0 means: Write
		TWI_Write(0x55);
		TWI_Write(0x30);
		TWI_StopCond();
		_delay_ms(1000);

	/*	if (TWI_GetStatus() == 0x60)
		{
			TWI_Read();
		}*/
	}

	return 0;
}
