/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include "USART.h"
#include "DIO_int.h"


int main(void)
{
	char x;

	DIO_SetPinDirection(PORTD,PIN0,INPUT);  //  D0: Rx ( input )
	DIO_SetPinDirection(PORTD,PIN1,OUTPUT); //  D1: Tx ( output )

	USART_Init();

	while(1)
	{
		x=USART_ReceiveData();
		USART_SendData(x);

	}
}
