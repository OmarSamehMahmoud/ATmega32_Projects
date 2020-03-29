/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "ADC.h"
#include <avr/io.h>
#include "LCD_interface.h"
#include "DIO_reg.h"
#include "DIO_int.h"

extern void ADC_Init(void)
{
	// Enable ADC On AVR
		SET_BIT(ADCSRA_Reg,7);

	// Select Conversion Speed
		SET_BIT(ADCSRA_Reg,0);
		SET_BIT(ADCSRA_Reg,1);
		SET_BIT(ADCSRA_Reg,2);


	// ADC Data Rgith Adjustment
		SET_BIT(ADMUX_Reg,5);
}

u8 ADC_Read (u8 channel)
{

	// Select Voltage Reference
	// Select ADC Channel
	ADMUX_Reg = 0x40 | (channel & 0b00000111) ;

	// Start ADC Conversion
	SET_BIT(ADCSRA_Reg,6);

	//Wait for the conversion
	while(!(ADCSRA_Reg & (1<<4)));



	SET_BIT(ADCSRA_Reg,4);

	return ADC;

}

void LM35(void)
{

	float celsius;

	celsius = (ADC_Read(0)*4.88);

	celsius = (celsius/10.00);

	Gotoxy(1,0);

	lcd_writenumber(celsius);

}

void Potinemeter(void)
{
	u8 val;
	u8 ADCw;

	val = (ADC_Read(1));

	ADCw = (val * 9)/250;

	Gotoxy(2,1);
	LCD_vidWriteCharctr(48+ADCw);

}

void LDR(void)
{
	u8 Name_Test_English[3]="on";
	u8 Namei_Test_English[4]="off";

	int vale;
	int ADCe;

	vale = (ADC_Read(2));
	ADCe = (vale * 5)/250;

	if (	ADCe > 3 )
		{
			LCD_String_xy(2,4,Name_Test_English);
			DIO_SetPinValue(PORTD,PIN5,LOW);
			_delay_ms(1000);
			LCD_vidSendCommand(0x01);

		}
	else
		{
			LCD_String_xy(2,4,Namei_Test_English);
			DIO_SetPinValue(PORTD,PIN5,HIGH);
			_delay_ms(1000);
			LCD_vidSendCommand(0x01);
		}
	LCD_vidSendCommand(0x01);
}
