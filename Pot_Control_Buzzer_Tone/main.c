/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include <avr/interrupt.h>

#include "ADC.h"

#include "LCD_Interface.h"


int main(void)
{
	DIO_SetPortDirection(PORTD,HIGH);
	DIO_SetPinDirection(PORTC,PIN0,HIGH);
	DIO_SetPinDirection(PORTC,PIN1,HIGH);
	DIO_SetPinDirection(PORTC,PIN2,HIGH);
	DIO_SetPortDirection(PORTA,LOW);
	DIO_SetPinDirection(PORTB,PIN3,HIGH);
	TCCR0=0b01101001;
	TIMSK=0b00000010;
	ADC_Init();
	LCD_vidInit();


	while(1)
	{
		u8 val = ADC_Read(0);

		u8 ADCe = (val * 9)/250;

		LCD_vidWriteCharctr(48+ADCe);

		LCD_vidSendCommand(0x01);

		if(ADCe==0)
		{
			OCR0=64;//duty cycle
		}
		else if(ADCe==1)
		{
			OCR0=128;
		}
		else if(ADCe==2)
		{
			OCR0=255;
		}
	}

}
