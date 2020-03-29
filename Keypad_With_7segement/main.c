/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Keypad.h"

int main (void)

{
	DIO_SetPinDirection (PORTB,PIN0,HIGH);
	DIO_SetPinDirection (PORTB,PIN1,HIGH);
	DIO_SetPinDirection (PORTB,PIN2,HIGH);
	DIO_SetPinDirection (PORTB,PIN3,HIGH);
	DIO_SetPinDirection (PORTB,PIN4,HIGH);
	DIO_SetPinDirection (PORTB,PIN5,HIGH);
	DIO_SetPinDirection (PORTB,PIN6,HIGH);
	DIO_SetPinDirection (PORTB,PIN7,HIGH);

	extern u8 Keypressed;
	Key_Pressed_Init();
	while(1)
	{
		Key_Pressed_Config();
		if(Keypressed==1)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,LOW);
			DIO_SetPinValue (PORTB,PIN2,LOW);
			DIO_SetPinValue (PORTB,PIN3,LOW);
			DIO_SetPinValue (PORTB,PIN4,LOW);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,LOW);
		}
		else if(Keypressed==2)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,LOW);
			DIO_SetPinValue (PORTB,PIN3,HIGH);
			DIO_SetPinValue (PORTB,PIN4,HIGH);
			DIO_SetPinValue (PORTB,PIN5,LOW);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
		else if(Keypressed==3)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,LOW);
			DIO_SetPinValue (PORTB,PIN3,LOW);
			DIO_SetPinValue (PORTB,PIN4,HIGH);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
		else if(Keypressed==4)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,HIGH);
			DIO_SetPinValue (PORTB,PIN3,LOW);
			DIO_SetPinValue (PORTB,PIN4,LOW);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,LOW);
		}
		else if(Keypressed==5)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,HIGH);
			DIO_SetPinValue (PORTB,PIN3,LOW);
			DIO_SetPinValue (PORTB,PIN4,HIGH);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,LOW);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
		else if(Keypressed==6)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,HIGH);
			DIO_SetPinValue (PORTB,PIN3,HIGH);
			DIO_SetPinValue (PORTB,PIN4,HIGH);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,LOW);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
		else if(Keypressed==7)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,LOW);
			DIO_SetPinValue (PORTB,PIN2,LOW);
			DIO_SetPinValue (PORTB,PIN3,LOW);
			DIO_SetPinValue (PORTB,PIN4,LOW);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
		else if(Keypressed==8)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,HIGH);
			DIO_SetPinValue (PORTB,PIN3,HIGH);
			DIO_SetPinValue (PORTB,PIN4,HIGH);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
		else if(Keypressed==9)
		{
			DIO_SetPinValue (PORTB,PIN0,LOW);
			DIO_SetPinValue (PORTB,PIN1,HIGH);
			DIO_SetPinValue (PORTB,PIN2,HIGH);
			DIO_SetPinValue (PORTB,PIN3,LOW);
			DIO_SetPinValue (PORTB,PIN4,HIGH);
			DIO_SetPinValue (PORTB,PIN5,HIGH);
			DIO_SetPinValue (PORTB,PIN6,HIGH);
			DIO_SetPinValue (PORTB,PIN7,HIGH);
		}
	}
	return 0;

}

