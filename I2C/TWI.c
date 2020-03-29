/*
 * TWI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include <avr/io.h>
#include "std_types.h"
#include "BIT_MATH.h"
#include "TWI.h"


void TWI_Init (void)
{
	TWBR= 0x02;		// For SCLK Division ( Eq of SCLK Freq.)
	TWSR= 0x00;		// the 2 LSB
	TWAR= 0b10101010;
	TWCR= (1<<TWEN) | (1<<TWEA);
	// TWI Enable
	//Enable Ack because we need it if our Mc is slave to send Ack that this address belongs to it

}

void TWI_StartCond (void)
{
	TWCR= (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// TWINT: down the flag to ensure that it's not raised
	// TWEN	: Take Control Over the bus

	while(!GETBIT(TWCR, TWINT));
}

void TWI_StopCond (void)
{
	TWCR= (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void TWI_Write (u8 u8Data)
{
	TWDR= u8Data;
	TWCR= (1<<TWINT) | (1<<TWEN);
	while(!GETBIT(TWCR, TWINT));
}

u8  TWI_Read (void)
{
	TWCR= (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	while(!GETBIT(TWCR, TWINT));
	return TWDR;
}

u8  TWI_ReadWithNack (void)
{
	TWCR= (1<<TWINT) | (1<<TWEN);
	while(!GETBIT(TWCR, TWINT));
	return TWDR;
}

u8 TWI_GetStatus (void)
{
	u8 status;
	status= (TWSR & 0xF8);
	return status;
}
