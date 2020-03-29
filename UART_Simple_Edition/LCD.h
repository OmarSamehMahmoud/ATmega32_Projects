/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef LCD_H_
#define LCD_H_

extern void lcd_init(void);
extern void lcd_writecommand(u8 command);
extern void lcd_writedata(u8 data);

#endif /* LCD_H_ */
