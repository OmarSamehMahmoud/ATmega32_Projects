/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */


#include "ADC.h"


int main(void)
{
	DIO_SetPortDirection(PORTD,HIGH);



	ADC_Init();


	while(1)
	{
			int val = ADC_Read(0);

			int ADC = (val * 5)/250;


	}

}
