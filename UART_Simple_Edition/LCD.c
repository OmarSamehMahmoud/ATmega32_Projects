/*
 * lcdfunction.c
 *
 *  Created on: Aug 11, 2017
 *      Author: galal
 */
#include <stdio.h>
#include "avr/io.h"
#define F_cpu 16000000
#include "avr/delay.h"
#include "types.h"
#include "utilss.h"
extern void lcd_init(void)
{
	_delay_ms(50);
		lcd_writecommand(0b00111000);
		_delay_ms(1);
		lcd_writecommand(0b00001111);
		_delay_ms(1);
		lcd_writecommand(0b00000001);
		_delay_ms(2);


}
extern void lcd_writecommand(u8 command)
{
	clr_bit(PORTA,0); // rs=0 rs->a0
	clr_bit(PORTA ,1); // rw=0 rw->a1
	PORTC=command;
	set_bit(PORTA,2);
	_delay_ms(2);
	clr_bit(PORTA,2);


}

extern void lcd_writedata(u8 data)
{
	set_bit(PORTA,0); // rs=1 rs->a0
	clr_bit(PORTA,1); // rw=0 rw->a1
	PORTC=data;
	set_bit(PORTA,2);
	_delay_ms(2);
	clr_bit(PORTA,2);


}

