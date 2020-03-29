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



int main(void)
{
	u8 RXData;

	DIO_SetPortDirection(PORTC,HIGH);
	DIO_SetPinDirection(PORTA,PIN0,HIGH);
	DIO_SetPinDirection(PORTA,PIN1,HIGH);
	DIO_SetPinDirection(PORTA,PIN2,HIGH);

	DIO_SetPinDirection(PORTD,PIN0,INPUT);  //  D0: Rx ( input )
	DIO_SetPinDirection(PORTD,PIN1,OUTPUT); //  D1: Tx ( output )

	DIO_SetPinDirection(PORTB,PIN0,OUTPUT); // PORTA | Pin 0 : Act as Output
	DIO_SetPinDirection(PORTB,PIN1,OUTPUT); // PORTA | Pin 1 : Act as Output

	USART_Init(); // Init of USART Function call
	LCD_vidInit();

	while(1)
	{

	USART_SendData('O');

	/*RXData=USART_ReceiveData();//Call of function of Receveied and put value from it in char x
	DIO_SetPinValue(PORTB,PIN0,HIGH);
		switch(RXData)
		{
		case 'i':
			DIO_SetPinValue(PORTB,PIN0,HIGH);
			LCD_vidWriteCharctr('Y');
			break;
		case 'o':
			DIO_SetPinValue(PORTB,PIN0,LOW);
			LCD_vidWriteCharctr('N');
			break;
		}*/

	}
}
