/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */
#include<avr/io.h>
#include "uart.h"
#include "types.h"
#include "utilss.h"
#include "LCD.h"


int main(void)
{
	char x;
	uart_int();
		DDRA=0b11111111;
		DDRC=0xff;
		DDRB=0xff;
		lcd_init();
		lcd_writecommand(0b10000000);

while(1)
{
	x=uart_rx_data();
			uart_tx_data(x);
			switch(x)
			{
			case 'o':
				PORTB=0b11111111;
				break;
			case 'f':
				PORTB=0b00000000;
				break;
			}
}
}
void uart_int(void)
{
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	UBRRL=6;
}
void uart_tx_data(char data)
{
	while((UCSRA&(1<<UDRE))==0);
	UDR=data;
}
char uart_rx_data(void)
{
	char x;
	while((UCSRA&(1<<RXC))==0);
	x=UDR;
	return x;
}
