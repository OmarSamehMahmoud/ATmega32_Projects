/*

* Keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Omar Sameh
 */

#include "Keypad.h"

u8 Keypressed;
void Key_Pressed_Init(void)
{
	DIO_SetPinDirection (PORTC,PIN0,HIGH);
	DIO_SetPinDirection (PORTC,PIN1,HIGH);
	DIO_SetPinDirection (PORTC,PIN2,HIGH);
	DIO_SetPinDirection (PORTC,PIN3,HIGH);
	DIO_SetPinDirection (PORTC,PIN4,LOW);
	DIO_SetPinDirection (PORTC,PIN5,LOW);
	DIO_SetPinDirection (PORTC,PIN6,LOW);
	DIO_SetPinDirection (PORTC,PIN7,LOW);
	DIO_SetPinValue(PORTC,PIN4,HIGH);
	DIO_SetPinValue(PORTC,PIN5,HIGH);
	DIO_SetPinValue(PORTC,PIN6,HIGH);
	DIO_SetPinValue(PORTC,PIN7,HIGH);
	DIO_SetPinValue(PORTB,PIN0,LOW);
}

u8 Key_Pressed_Config(void)
{
	DIO_SetPinValue(PORTC,PIN0,LOW);
	DIO_SetPinValue(PORTC,PIN1,HIGH);
	DIO_SetPinValue(PORTC,PIN2,HIGH);
	DIO_SetPinValue(PORTC,PIN3,HIGH);
	if(DIO_GetPinValue(PORTC,PIN4)==LOW)
		{
			Keypressed=7;
		}
	if(DIO_GetPinValue(PORTC,PIN5)==LOW)
		{
			Keypressed=4;
		}
	if(DIO_GetPinValue(PORTC,PIN6)==LOW)
		{
			Keypressed=1;
		}
	if(DIO_GetPinValue(PORTC,PIN7)==LOW)
		{
			Keypressed='O';
		}
	DIO_SetPinValue(PORTC,PIN0,HIGH);
	DIO_SetPinValue(PORTC,PIN1,LOW);
	DIO_SetPinValue(PORTC,PIN2,HIGH);
	DIO_SetPinValue(PORTC,PIN3,HIGH);
	if(DIO_GetPinValue(PORTC,PIN4)==LOW)
		{
			Keypressed=8;
		}
	if(DIO_GetPinValue(PORTC,PIN5)==LOW)
		{
			Keypressed=5;
		}
	if(DIO_GetPinValue(PORTC,PIN6)==LOW)
		{
			Keypressed=2;
		}
	if(DIO_GetPinValue(PORTC,PIN7)==LOW)
		{
			Keypressed=0;
		}
	DIO_SetPinValue(PORTC,PIN0,HIGH);
	DIO_SetPinValue(PORTC,PIN1,HIGH);
	DIO_SetPinValue(PORTC,PIN2,LOW);
	DIO_SetPinValue(PORTC,PIN3,HIGH);
	if(DIO_GetPinValue(PORTC,PIN4)==LOW)
		{
			Keypressed=9;
		}
	if(DIO_GetPinValue(PORTC,PIN5)==LOW)
		{
			Keypressed=6;
		}
	if(DIO_GetPinValue(PORTC,PIN6)==LOW)
		{
			Keypressed=3;
		}
	if(DIO_GetPinValue(PORTC,PIN7)==LOW)
		{
			Keypressed='=';
		}
	DIO_SetPinValue(PORTC,PIN0,HIGH);
	DIO_SetPinValue(PORTC,PIN1,HIGH);
	DIO_SetPinValue(PORTC,PIN2,HIGH);
	DIO_SetPinValue(PORTC,PIN3,LOW);
	if(DIO_GetPinValue(PORTC,PIN4)==LOW)
		{
			Keypressed='/';
		}
	if(DIO_GetPinValue(PORTC,PIN5)==LOW)
		{
			Keypressed='*';
		}
	if(DIO_GetPinValue(PORTC,PIN6)==LOW)
		{
			Keypressed='-';
		}
	if(DIO_GetPinValue(PORTC,PIN7)==LOW)
		{
			Keypressed='-';
		}
}
