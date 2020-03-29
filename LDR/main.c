/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */


#include "ADC.h"
#include "DIO_int.h"

int main(void)
{
	DIO_SetPortDirection(PORTD,HIGH);
	DIO_SetPinDirection(PORTC,PIN0,HIGH);
	DIO_SetPortDirection(PORTA,LOW);

	ADC_Init();



	while(1)
	{
		int val = ADC_Read(0);

		int ADC = (val * 5)/250;

		if ( ADC > 3 )
		{
			DIO_SetPinValue(PORTC,PIN0,LOW);
		}
		else
		{
			DIO_SetPinValue(PORTC,PIN0,HIGH);
		}


	}

}
