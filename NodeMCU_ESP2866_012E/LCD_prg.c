/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/

#include "STD_TYPES.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_interface.h"

/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{

	/* Set RS to LOW */
	DIO_SetPinValue(PORTA, 0, LOW);

	/* Set R/W to LOW */
	DIO_SetPinValue(PORTA, 1, LOW);

	/* Set E to HIGH  */
	DIO_SetPinValue(PORTA, 2, HIGH);

	/* Load Command on Data bus */
	DIO_SetPortValue(PORTC, u8CmdCpy);

	/* Set E to LOW */
	DIO_SetPinValue(PORTA, 2, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_SetPinValue(PORTA, 2, HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{
	/* Set RS to HIG */
	DIO_SetPinValue(PORTA, 0, HIGH);

	/* Set R/W to LOW */
	DIO_SetPinValue(PORTA, 1, LOW);

	/* Set E to HIGH */
	DIO_SetPinValue(PORTA, 2, HIGH);

	/* Load Command on Data bus */
	DIO_SetPortValue(PORTC, u8DataCpy);

	/* Set E to LOW */
	DIO_SetPinValue(PORTA, 2, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_SetPinValue(PORTA, 2, HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{

//	/* Local loop index */

	u8 iteration=0;
//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

//		/* Increment local loop index */
//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}
	_delay_ms(1000); //for Controlling Speed of writing
}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_vidSendCommand(X+127);
		    break;
		    case 2:
		    	LCD_vidSendCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}



/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (u8 Y,u8 X,u8* ExtraChar,u8* Index)
{


    u8 iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidSendCommand(64);
	for(iteration1=0 ; iteration1<Index ; iteration1++)
	{
		LCD_vidWriteCharctr(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand(128);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr(iteration2);

		_delay_ms(5);
	}
}
/***************************************************************************************/
/* Description! Interface to write Number LCD screen                                   */
/* Input      ! X : Number                                                             */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteNumber (u32 x)
{
	u32 y=x;
	u8 counter=0;
	u8 sumbol[]={'0','1','2','3','4','5','6','7','8','9'};
	while(y!=0)
	{
		counter++;
		y=y/10;
	}
	u8 arr[counter];
	for(u8 i=0;i<counter;i++)
	{
		arr[i]=x%10;
		x=x/10;
	}
	for(s8 j=counter-1;j>=0;j--)
	{
		LCD_vidWriteCharctr(sumbol[arr[j]]);
	}
}
