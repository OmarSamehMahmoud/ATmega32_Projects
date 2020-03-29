/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef ADC_H_
#define ADC_H_

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#include <util/delay.h>

extern void ADC_Init (void); // ADC Initialization And Enable
u8 ADC_Read (u8 channel); // Read From The ADC Channel



#endif /* ADC_H_ */
