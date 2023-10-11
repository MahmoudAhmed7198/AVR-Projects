/*
 * LCD.c
 *
 *  Created on: May 23, 2023
 *      Author: Lenovo
 */

#include"LCD.h"

void LCD_Init()
{
	set_pin_direction(PORTC_reg, RS, OUTPUT);
	set_pin_direction(PORTC_reg,RW,OUTPUT); //make control pins output
	set_pin_direction(PORTC_reg,E,OUTPUT);

	#if(LCD_BIT_MODE == 4)
	#ifdef UPPER_PORT_PINS
	LCD_DATA_DIR|=0xF0; //make upper port pins output
	#else
	LCD_DATA_DIR|=0x0F; //make lower port pins output
	#endif
	LCD_SendCommand(FOUR_BIT_DATA_MODE);
	LCD_SendCommand(LCD_4_BIT_TWO_LINE);
	#elif(LCD_BIT_MODE==8)
	LCD_DATA_DIR|=0xFF;
	LCD_SendCommand(LCD_8_BIT_TWO_LINE);
	#endif
	LCD_SendCommand(DISPLAY_ON_CURSOR_ON);
	LCD_SendCommand(CLEAR_DISPLAY);
}
void LCD_SendCommand(uint8 command)
{
	set_pin_value(PORTC_reg, RS, LOW);
	set_pin_value(PORTC_reg, RW, LOW);
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, HIGH);
	_delay_ms(1);

	#if(LCD_BIT_MODE == 4)
	#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT=(LCD_DATA_PORT & 0x0F)|(command & 0xF0);
	#else
	LCD_DATA_PORT=(LCD_DATA_PORT & 0xF0)|((command & 0xF0)>>4);
	#endif

	_delay_ms(1);
	set_pin_value(PORTC_reg, E, LOW);
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, HIGH);
	_delay_ms(1);

	#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT=(LCD_DATA_PORT & 0x0F)|((command & 0x0F)<<4);
	#else
	LCD_DATA_PORT=(LCD_DATA_PORT & 0xF0)|(command & 0x0F);
	#endif
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, LOW);
	_delay_ms(1);

	#elif(LCD_BIT_MODE == 8)
	LCD_DATA_PORT=command;
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, LOW);
	_delay_ms(1);
	#endif
}
void LCD_SendCharacter(uint8 data)
{
	set_pin_value(PORTC_reg, RS, HIGH);
	set_pin_value(PORTC_reg, RW, LOW);
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, HIGH);
	_delay_ms(1);

	#if(LCD_BIT_MODE == 4)
	#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT=(LCD_DATA_PORT & 0x0F)|(data & 0xF0);
	#else
	LCD_DATA_PORT=(LCD_DATA_PORT & 0xF0)|((data & 0xF0)>>4);
	#endif

	_delay_ms(1);
	set_pin_value(PORTC_reg, E, LOW);
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, HIGH);
	_delay_ms(1);

	#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT=(LCD_DATA_PORT & 0x0F)|((data & 0x0F)<<4);
	#else
	LCD_DATA_PORT=(LCD_DATA_PORT & 0xF0)|(data & 0x0F);
	#endif
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, LOW);
	_delay_ms(1);

	#elif(LCD_BIT_MODE == 8)
	LCD_DATA_PORT=data;
	_delay_ms(1);
	set_pin_value(PORTC_reg, E, LOW);
	_delay_ms(1);
	#endif

}
void LCD_DisplayString(uint8* str)
{
	uint8 i=0;
	while(str[i]!='\0')
	{
		LCD_SendCharacter(str[i]);
		i++;
	}

}
void GOTO_ROW_COL(uint8 row ,uint8 col)
{
	uint8 address;
	switch(row)
	{
	case 0:
		address=col;
		break;
	case 1:
		address=col+0x40;
		break;
	}
	LCD_SendCommand(address | SET_CURSOR_LOCATION);
}

void Display_string_row_col(uint8 row,uint8 col,uint8*str)
{
	GOTO_ROW_COL(row,col);
	LCD_DisplayString(str);
}
void LCD_integer_To_String(int data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD_DisplayString(buff);
}
void LCD_CLEAR()
{
	LCD_SendCommand(CLEAR_DISPLAY);
}

