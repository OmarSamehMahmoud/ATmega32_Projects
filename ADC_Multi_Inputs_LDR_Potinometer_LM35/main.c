/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "ADC.h"
#include "DIO_reg.h"
#include "DIO_int.h"


int main(void)
{

	DIO_SetPinDirection(PORTB,PIN0,HIGH);
	DIO_SetPinDirection(PORTA,PIN0,LOW);
	DIO_SetPinDirection(PORTA,PIN1,LOW);

	DIO_SetPortDirection(PORTD,HIGH);
	DIO_SetPinDirection(PORTC,PIN0,HIGH);
	DIO_SetPinDirection(PORTC,PIN1,HIGH);
	DIO_SetPinDirection(PORTC,PIN2,HIGH);

	LCD_vidInit();
	ADC_Init();
	while(1)

	{
		LM35();
		_delay_ms(100);
		Potinemeter();
		_delay_ms(100);
		LDR();
		_delay_ms(100);

	}

}
