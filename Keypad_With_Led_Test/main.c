/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#include "Keypad.h"

int main (void)

{

	Key_Pressed_Init();
	while(1)
	{
		Key_Pressed_Config();
	}
	return 0;

}

