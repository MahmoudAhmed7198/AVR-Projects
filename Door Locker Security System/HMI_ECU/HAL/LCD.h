/*
 * LCD.h
 *
 *  Created on: May 23, 2023
 *      Author: Lenovo
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_
#include"../MCAL/DIO_Driver/DIO.h"
#include<util/delay.h>
#include"stdlib.h"

#define LCD_BIT_MODE 4
#if(LCD_BIT_MODE == 4)
#define UPPER_PORT_PINS
#endif
//LCD PIN Configuration
#define RS PIN0
#define RW PIN1
#define E  PIN2

#define LCD_CTRL_DIR  DDRC
#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_PIN  PINC

#define LCD_DATA_DIR  DDRC
#define LCD_DATA_PORT PORTC
#define LCD_DATA_PIN  PINC
//LCD commands
#define CLEAR_DISPLAY           0x01
#define FOUR_BIT_DATA_MODE      0x02
#define DISPLAY_ON_CURSOR_OFF   0x0C
#define DISPLAY_ON_CURSOR_ON    0x0E
#define DISPLAY_ON_CURSOR_BLINK 0x0F
#define SET_CURSOR_LOCATION     0x80
#define SET_CURSOR_LOCAT2ndLINE 0xC0
#define LCD_8_BIT_TWO_LINE      0x38
#define LCD_4_BIT_TWO_LINE      0x28
#define SHIFT_DISPLAY_LEFT      0x07
#define SHIFT_TO_LEFT           0x18
#define SHIFT_CURSOR_LEFT       0x04

//LCD functions prototype
void LCD_Init();
void LCD_SendCommand(uint8);
void LCD_SendCharacter(uint8);
void LCD_DisplayString(uint8* str);
void GOTO_ROW_COL(uint8,uint8);
void Display_string_row_col(uint8,uint8,uint8*str);
void LCD_integer_To_String(int);
void LCD_CLEAR();



#endif /* HAL_LCD_H_ */
