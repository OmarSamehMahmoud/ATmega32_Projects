/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "DIO_int.h"

ISR(INT0_vect)
{
	int i;
	for(i=0;i<5;i++)
	{
	DIO_SetPinValue(PORTA,PIN0,HIGH);
	_delay_ms(100);
	DIO_SetPinValue(PORTA,PIN0,LOW);
	_delay_ms(100);
	}

}

ISR(INT1_vect)
{
	int y;
		for(y=0;y<5;y++)
		{
		DIO_SetPinValue(PORTA,PIN1,HIGH);
		_delay_ms(100);
		DIO_SetPinValue(PORTA,PIN1,LOW);
		_delay_ms(100);
		}
}

int main(void)
{
	DIO_SetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_SetPinDirection(PORTA,PIN1,OUTPUT);

	DIO_SetPinDirection(PORTD,PIN2,INPUT);  /* D2: Input (INT0 : EXternal Interrupt 0)  */
	DIO_SetPinDirection(PORTD,PIN3,INPUT);  /* D3: Input (INT1 : EXternal Interrupt 1)  */

	SET_BIT(GICR,PIN6); /* Peripheral Interrupt Enable ( PIE ) of INT0     */
	SET_BIT(GICR,PIN7); /* Peripheral Interrupt Enable ( PIE ) of INT1     */

	SET_BIT(MCUCR,PIN0);
	SET_BIT(MCUCR,PIN1); /* ExternaL Interrupt 0 happen on : Rising Edge                  */

	SET_BIT(MCUCR,PIN2);
	SET_BIT(MCUCR,PIN3); /* ExternaL Interrupt 0 happen on : Rising Edge                  */

	SET_BIT(SREG,PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8

	while(1)
	{
		DIO_SetPinValue(PORTA,PIN0,LOW);
		DIO_SetPinValue(PORTA,PIN1,LOW);
	}
}
