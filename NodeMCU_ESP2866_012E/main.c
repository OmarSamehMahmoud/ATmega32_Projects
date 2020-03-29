/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "USART.h"
#include "LCD_interface.h"
#include "DIO_int.h"

volatile u8 Sensor_Readings_Tx[3];

int main(void)
{


	DIO_SetPortDirection(PORTC,HIGH);
	DIO_SetPinDirection(PORTA,PIN0,HIGH);
	DIO_SetPinDirection(PORTA,PIN1,HIGH);
	DIO_SetPinDirection(PORTA,PIN2,HIGH);

	DIO_SetPinDirection(PORTD,PIN0,INPUT);  //  D0: Rx ( input )
	DIO_SetPinDirection(PORTD,PIN1,OUTPUT); //  D1: Tx ( output )

	DIO_SetPinDirection(PORTB,PIN0,OUTPUT); // PORTA | Pin 0 : Act as Output
	DIO_SetPinDirection(PORTB,PIN1,OUTPUT); // PORTA | Pin 1 : Act as Output

	USART_Init(); // Init of USART Function call




	while(1)
	{

		USART_SendReadings(Sensor_Readings_Tx);

	}
}
