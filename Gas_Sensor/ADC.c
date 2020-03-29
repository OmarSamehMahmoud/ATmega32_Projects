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

extern void ADC_Init(void) {
	// Enable ADC On AVR
	SET_BIT(ADCSRA_Reg, 7);

	// Select Conversion Speed
	SET_BIT(ADCSRA_Reg, 0);
	SET_BIT(ADCSRA_Reg, 1);
	SET_BIT(ADCSRA_Reg, 2);

	// ADC Data Rgith Adjustment
	SET_BIT(ADMUX_Reg, 5);
}

u8 ADC_Read(u8 channel) {

	// Select Voltage Reference
	// Select ADC Channel
	ADMUX_Reg = 0x40 | (channel & 0b00000111);

	// Start ADC Conversion
	SET_BIT(ADCSRA_Reg, 6);

	//Wait for the conversion
	while (!(ADCSRA_Reg & (1 << 4)))
		;

	SET_BIT(ADCSRA_Reg, 4);

	return ADC;

}

void Gas_Sensor(void) {

	u8 Detect[13] =
			{ 'S', 'M', 'O', 'K', 'E', ' ', 'D', 'e', 't', 'e', 'c', 't' };
	u8 Ppm[5]=
			{'P','P','M',':'};
	float PPM;

	PPM = (ADC_Read(0) * 4.88);

	PPM = (PPM / 10.00);

	Gotoxy(1, 0);

	LCD_String(Ppm);

	Gotoxy(1,5);

	lcd_writenumber(PPM);

	if (PPM >= 100) {
		DIO_SetPinValue(PORTB, PIN0, HIGH);

		LCD_String_xy(2,0,Detect);

	} else {
		DIO_SetPinValue(PORTB, PIN0, LOW);
	}
}
