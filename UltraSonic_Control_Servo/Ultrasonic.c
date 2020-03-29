#include"Ultrasonic.h"

u32 count; //For UltraSonic 1
u32 count1; //For UltraSonic 2
volatile u16 Timer0Overflow = 0;

u16 Distance; // range 0:400 cm  ( distance=(34300*TIMER)/2 = 17150*TIMER ) --> UltraSonic1
u16 Distance1; // range 0:400 cm  ( distance=(34300*TIMER)/2 = 17150*TIMER ) --> UltraSonic1

void Ultrasonic_init(void) {
// Timer0 Init :
	SET_BIT(SREG, PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8

	SET_BIT(TIMSK, PIN0);  //Timer0 Overflow Interrupt Enable  (PIE) page 80

	CLR_BIT(TCCR0, PIN3); // To choose Normal Mode  ( Over Flow Mode )  ( Page 78 )
	CLR_BIT(TCCR0, PIN6);

	SET_BIT(TCCR0, PIN0); // To choose Prescaller = 1 : No Prescaling
	CLR_BIT(TCCR0, PIN1);
	CLR_BIT(TCCR0, PIN2);

	TCNT0 = 0;         // Clear timer0 counter

}

void Check_All_UltraSonic(void) {
	DIO_SetPinValue(PORTA, PIN0, HIGH); // C0: HIGH ( Connected with Trigger pin on Ultrasonic1 )
	_delay_us(10);                    // at least 10us pulse on trigger
	DIO_SetPinValue(PORTA, PIN0, LOW); // C0 : LOW
	while (DIO_GetPinValue(PORTA, PIN1) != 1)
		;
	TCNT0 = 0;
	Timer0Overflow = 0;
	while (DIO_GetPinValue(PORTA, PIN1) == 1)
		;
	count = TCNT0 + (255 * Timer0Overflow);
	Distance = count / 466.4723032;
	if(Distance>6&&Distance<=16)
	{
		TCCR0 = 0b01101001;
		OCR0=40;
	}

	Gotoxy(1, 0);
	lcd_writenumber(Distance);
	LCD_vidSendCommand(0x01);
}

ISR(TIMER0_OVF_vect) {
	Timer0Overflow++;
}
