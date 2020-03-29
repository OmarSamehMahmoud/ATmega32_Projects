
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


/* Connect 7Segment pin a to D0     */
/* Connect 7Segment pin b to D1     */
/* Connect 7Segment pin c to D2     */
/* Connect 7Segment pin d to D3     */
/* Connect 7Segment pin e to D4     */
/* Connect 7Segment pin f to D5     */
/* Connect 7Segment pin g to D6     */
/* Connect 7Segment dot pin a to D7 */

/* Following This Table we creat array To convert Decimal to 7Segment */
/***********************************************/
/* Decimal | Dot | g | f | e | d | c | b | a | */
/*    0    |  0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    1    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 0 | */
/*    2    |  0  | 1 | 0 | 1 | 1 | 0 | 1 | 1 | */
/*    3    |  0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 | */
/*    4    |  0  | 1 | 1 | 0 | 0 | 1 | 1 | 0 | */
/*    5    |  0  | 1 | 1 | 0 | 1 | 1 | 0 | 1 | */
/*    6    |  0  | 1 | 1 | 1 | 1 | 1 | 0 | 1 | */
/*    7    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | */
/*    8    |  0  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    9    |  0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 | */
/***********************************************/

int Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };

ISR(INT0_vect)
{
	PORTA =  0b01111111;
	_delay_ms(1000);
}

int main(void)
{
	int LoopCounter;

	/* Set D1 as input and rest of pins as Output Pins */
	DDRA   = 0b11111101;

	DDRD   = 0b00000000;

	SET_BIT(GICR,PIN6); /* Peripheral Interrupt Enable ( PIE ) of INT0     */

	SET_BIT(MCUCR,PIN0);
	SET_BIT(MCUCR,PIN1); /* ExternaL Interrupt 0 happen on : Rising Edge                 */

	SET_BIT(SREG,PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8


	while(1)
	{
		/* Check if D1 is High, Turn LED on */
		for(LoopCounter=0; LoopCounter<9;LoopCounter++)
		{
			PORTA = Arr_DecToSeg[LoopCounter];
			_delay_ms(1000);
		}
	}
}

