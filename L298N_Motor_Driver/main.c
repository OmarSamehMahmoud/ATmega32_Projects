/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reg.h"
#include "DIO_int.h"


int main(void)
{

	DIO_SetPortDirection(PORTB,HIGH);

	while(1)

	{
		DIO_SetPinDirection(PORTB,PIN0,HIGH);
		DIO_SetPinDirection(PORTB,PIN1,LOW);

		DIO_SetPinDirection(PORTB,PIN2,LOW);
		DIO_SetPinDirection(PORTB,PIN3,HIGH);
	}

}
