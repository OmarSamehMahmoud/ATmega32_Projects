/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */


#include "ADC.h"
#include "LCD_Interface.h"

int main(void)
{
	DIO_SetPortDirection(PORTD,HIGH);
	DIO_SetPinDirection(PORTC,PIN0,HIGH);
	DIO_SetPinDirection(PORTC,PIN1,HIGH);
	DIO_SetPinDirection(PORTC,PIN2,HIGH);
	DIO_SetPortDirection(PORTA,LOW);

	ADC_Init();
	LCD_vidInit();


	while(1)
	{
		u8 val = ADC_Read(0);

		u8 ADCe = (val * 9)/250;

		//LCD_vidWriteCharctr(48+ADCe);

		lcd_writenumber(ADCe);

		LCD_vidSendCommand(0x01);
	}

}
