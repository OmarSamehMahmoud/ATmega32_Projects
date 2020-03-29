#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<avr/interrupt.h>
#include<util/delay.h>
#include"DIO_int.h"


ISR(INT0_vect)  /* Flame Sensor  */
{
		DIO_SetPinValue(PORTC,PIN0,HIGH);  // BUZZER ON
		_delay_ms(100);
		DIO_SetPinValue(PORTC,PIN0,LOW);  // BUZZER OFF
}

int main()
{
	DIO_SetPinDirection(PORTD,PIN2,INPUT);  /* D2: Input (INT0 : EXternal Interrupt 0) Flame Sensor      */

    SET_BIT(GICR,PIN6); /* Prephral Interrupt Enable ( PIE ) of INT0 ( Flame Sensor )     */
	SET_BIT(MCUCR,PIN0); /* bit0 = 1 & bit1 = 1 means:         (page: 64)                 */
	SET_BIT(MCUCR,PIN1); /* ExternaL Interrupt 0 happen on : Rising Edge                  */

	SET_BIT(SREG,PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8


	DIO_SetPinDirection(PORTC,PIN0,OUTPUT); // BUZZER OUTPUT


    while(1)
    {
    	DIO_SetPinValue(PORTC,PIN0,LOW);  // BUZZER OFF
    }

	return 0;
}
