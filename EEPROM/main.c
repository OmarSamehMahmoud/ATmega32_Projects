#include <avr/io.h>
#include "std_types.h"
#include "BIT_MATH.h"
#include "TWI.h"
#include "EEPROM.h"
#include<util/delay.h>

int main (void)
{
	DDRD=0xff;

	u8 x;

	EEPROM_init();
	// Write to EEPROM (Address= 0x0F)

	EEPROM_Writedata(0x55, 0xCC);

	_delay_ms(10);

	//Read from EEPROM (Address= 0x0F)

	x= EEPROM_ReadData(0x55);

	while(1)
	{
		PORTD = x;
	}
	return 0;
}
