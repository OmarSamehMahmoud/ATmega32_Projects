/*
 * main.c
 *
 *  Created on: ??�/??�/????
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

