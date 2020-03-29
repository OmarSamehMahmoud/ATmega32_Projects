/*
 * EEPROM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include "std_types.h"
#include "BIT_MATH.h"
#include "TWI.h"
#include "EEPROM.h"

void EEPROM_init (void)
{
	TWI_Init();
}

void EEPROM_Writedata (u8 u8Address, u8 u8Data)
{
	TWI_StartCond();
	TWI_Write(0b10100000);
	TWI_Write( u8Address );
	TWI_Write( u8Data );
	TWI_StopCond();
}

u8 EEPROM_ReadData(u8 u8Address)
{
	u8 x;
	TWI_StartCond();
	TWI_Write(0b10100000);
	TWI_Write( u8Address );
	TWI_StartCond();
	TWI_Write(0b10100001);
	x= TWI_ReadWithNack();
	TWI_StopCond();
	return x;
}
