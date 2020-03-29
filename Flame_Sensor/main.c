
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_int.h"


int main()
{
	DIO_SetPinDirection(PORTD,PIN2,INPUT);  /* D2: Input (INT0 : EXternal Interrupt 0) Flame Sensor      */
	DIO_SetPinDirection(PORTC,PIN0,OUTPUT); //  Buzzer for flame

	DIO_SetPinValue(PORTC,PIN0,LOW);  // Buzzer Off

    while(1)
    {

    	if(DIO_GetPinValue(PORTD,PIN2)==1)
    	{
    		DIO_SetPinValue(PORTC,PIN0,HIGH);  // Buzzer ON
    	}
    	else
    	{
    		DIO_SetPinValue(PORTC,PIN0,LOW);  // Buzzer OFF
    	}
    }

	return 0;
}
