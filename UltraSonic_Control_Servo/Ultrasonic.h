#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/interrupt.h>  // interrupt first to neglect understanding PORTA as a register

#include "DIO_int.h"
#include <util/delay.h>

#include "LCD_interface.h"
void Ultrasonic_init(void);
void Check_All_UltraSonic(void);

#endif /* ULTRASONIC_H_ */
