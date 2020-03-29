/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>




ISR(INT0_vect)
{
	int i;
	for(i=7;i>=0;i--)
	{
		PORTA=(1<<i);
		_delay_ms(100);
	}

}



int main(void)
{
	DDRA=0b11111111;

	PORTA=0b00000001;

	DDRD=0b00000000;

	SET_BIT(GICR,PIN6); /* Peripheral Interrupt Enable ( PIE ) of INT0     */

	SET_BIT(MCUCR,PIN0);
	SET_BIT(MCUCR,PIN1); /* ExternaL Interrupt 0 happen on : Rising Edge                 */

	SET_BIT(SREG,PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8

	int i;
	while(1)
	{
			for(i=0;i<8;i++)
			{
				PORTA=(1<<i);
				_delay_ms(100);
			}
	}
}
