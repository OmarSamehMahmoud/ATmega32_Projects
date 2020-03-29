/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_init (void);
void EEPROM_Writedata (u8 u8Address, u8 u8Data);
u8 EEPROM_ReadData(u8 u8Address);


#endif /* EEPROM_H_ */
