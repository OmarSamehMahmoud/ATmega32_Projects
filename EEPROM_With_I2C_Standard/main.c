/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include <avr/io.h>
#include "std_types.h"
#include "BIT_MATH.h"
#include "TWI.h"
#include<util/delay.h>

int main (void)
{
	DDRD=0xff;
	TWI_Init();
	// Write to EEPROM (Address= 0x0F)
	u8 x;

	TWI_StartCond();
	TWI_Write(0b10100000);	//LSB=0 means: Write
	TWI_Write(0xFF);	//address
	TWI_Write(0X0F);	//data
	TWI_StopCond();

	_delay_ms(10);

	//Read from EEPROM (Address= 0x0F)

	TWI_StartCond();
	TWI_Write(0b10100000);	//LSB=0 means: Write
	TWI_Write(0xFF);	//address
	TWI_StartCond();
	TWI_Write(0b10100001);	//LSB=1 means: Read
	x = TWI_Read();
	TWI_StopCond();

	while(1)
	{
		PORTD = x;
	}
	return 0;
}
