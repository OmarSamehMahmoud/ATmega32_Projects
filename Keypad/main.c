/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Keypad.h"

int main (void)

{
	extern u8 Keypressed;
	Key_Pressed_Init();

	while(1)
	{
		Key_Pressed_Config();

	}
	return 0;

}

