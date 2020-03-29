/*
 * TWI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef TWI_H_
#define TWI_H_

#include <avr/io.h>
#include "std_types.h"
#include "BIT_MATH.h"
#include<util/delay.h>

void TWI_Init (void);
void TWI_StartCond (void);
void TWI_StopCond (void);
void TWI_Write (u8 u8Data);
u8  TWI_Read (void);
u8  TWI_ReadWithNack (void);
u8 TWI_GetStatus (void);


#endif /* TWI_H_ */
