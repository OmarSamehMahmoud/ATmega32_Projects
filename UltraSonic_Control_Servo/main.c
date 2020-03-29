#include "Ultrasonic.h"

int main(void) {
	DIO_SetPinDirection(PORTA, PIN0, OUTPUT);  // C0: Ultrasonic1 Trigger
	DIO_SetPinDirection(PORTA, PIN1, INPUT);  // B0: Ultrasonic1 Echo

	DIO_SetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_SetPinDirection(PORTC, PIN1, OUTPUT);
	DIO_SetPinDirection(PORTC, PIN2, OUTPUT);

	DIO_SetPortDirection(PORTD, HIGH);

	DIO_SetPinDirection(PORTB, PIN3, OUTPUT);

	Ultrasonic_init();
	LCD_vidInit();

	while (1) {

		Check_All_UltraSonic();

	}

	return 0;
}
