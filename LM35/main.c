
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdio.h>
#include "ADC.h"
#include "LCD_interface.h"
#include "DIO_int.h"

int main()
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
		//u8 Temperature[10];
		float celsius;

		celsius = (ADC_Read(0)*4.88);
		celsius = (celsius/10.00);
		Gotoxy(1,0);
		lcd_writenumber(celsius);
		_delay_ms(1000);
		LCD_vidSendCommand(0x01);

	}
	return 0;
}

