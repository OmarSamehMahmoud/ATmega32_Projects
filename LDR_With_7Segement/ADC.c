/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC.h"

extern void ADC_Init(void)
{
	// Enable ADC On AVR
		SET_BIT(ADCSRA_Reg,7);

	// Select Conversion Speed
		SET_BIT(ADCSRA_Reg,0);
		SET_BIT(ADCSRA_Reg,1);
		SET_BIT(ADCSRA_Reg,2);

	// Select Voltage Reference
		SET_BIT(ADMUX_Reg,6);


	// ADC Data Rgith Adjustment
		SET_BIT(ADMUX_Reg,5);
}

extern char ADC_Read (char channel)
{
	char value;

	// Select ADC Channel
	ADMUX_Reg |= (channel & 0b00000111);

	// Start ADC Conversion
	SET_BIT(ADCSRA_Reg,6);

	//Wait for the conversion
	while(!(ADCSRA_Reg & (1<<4)));

	value=ADCH_Reg;

	//ADCSRA_Reg|=0x10;

	return value;

	SET_BIT(ADCSRA_Reg,4);
}


