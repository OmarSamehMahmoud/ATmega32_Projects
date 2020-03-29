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
	DIO_SetPortDirection(PORTB,HIGH);
	DIO_SetPortDirection(PORTC,HIGH);
	DIO_SetPortDirection(PORTA,LOW);

	ADC_Init();



	while(1)
	{
		int val = ADC_Read(0);

		int ADC = (val * 5)/250;

		if ( ADC > 3 )
		{

			DIO_SetPinValue(PORTB,PIN0,LOW);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN2,HIGH);
			DIO_SetPinValue(PORTB,PIN3,HIGH);
			DIO_SetPinValue(PORTB,PIN4,HIGH);
			DIO_SetPinValue(PORTB,PIN5,HIGH);
			DIO_SetPinValue(PORTB,PIN6,HIGH);
			DIO_SetPinValue(PORTB,PIN7,HIGH);

			DIO_SetPinValue(PORTC,PIN0,LOW);
			DIO_SetPinValue(PORTC,PIN1,HIGH);
			DIO_SetPinValue(PORTC,PIN2,HIGH);
			DIO_SetPinValue(PORTC,PIN3,HIGH);
			DIO_SetPinValue(PORTC,PIN4,LOW);
			DIO_SetPinValue(PORTC,PIN5,LOW);
			DIO_SetPinValue(PORTC,PIN6,LOW);
			DIO_SetPinValue(PORTC,PIN7,HIGH);

			DIO_SetPinValue(PORTD,PIN0,LOW);
			DIO_SetPinValue(PORTD,PIN1,HIGH);
			DIO_SetPinValue(PORTD,PIN2,HIGH);
			DIO_SetPinValue(PORTD,PIN3,HIGH);
			DIO_SetPinValue(PORTD,PIN4,LOW);
			DIO_SetPinValue(PORTD,PIN5,LOW);
			DIO_SetPinValue(PORTD,PIN6,LOW);
			DIO_SetPinValue(PORTD,PIN7,HIGH);


		}
		else
		{


			DIO_SetPinValue(PORTB,PIN0,LOW);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN2,HIGH);
			DIO_SetPinValue(PORTB,PIN3,HIGH);
			DIO_SetPinValue(PORTB,PIN4,HIGH);
			DIO_SetPinValue(PORTB,PIN5,HIGH);
			DIO_SetPinValue(PORTB,PIN6,HIGH);
			DIO_SetPinValue(PORTB,PIN7,HIGH);

			DIO_SetPinValue(PORTC,PIN0,LOW);
			DIO_SetPinValue(PORTC,PIN1,HIGH);
			DIO_SetPinValue(PORTC,PIN2,LOW);
			DIO_SetPinValue(PORTC,PIN3,HIGH);
			DIO_SetPinValue(PORTC,PIN4,LOW);
			DIO_SetPinValue(PORTC,PIN5,HIGH);
			DIO_SetPinValue(PORTC,PIN6,LOW);
			DIO_SetPinValue(PORTC,PIN7,LOW);

			DIO_SetPinValue(PORTD,PIN0,LOW);
			DIO_SetPinValue(PORTD,PIN1,LOW);
			DIO_SetPinValue(PORTD,PIN2,LOW);
			DIO_SetPinValue(PORTD,PIN3,LOW);
			DIO_SetPinValue(PORTD,PIN4,LOW);
			DIO_SetPinValue(PORTD,PIN5,LOW);
			DIO_SetPinValue(PORTD,PIN6,LOW);
			DIO_SetPinValue(PORTD,PIN7,LOW);
		}


	}

}
