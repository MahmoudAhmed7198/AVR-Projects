/*
 * main.c
 *
 *  Created on: May 26, 2023
 *      Author: Lenovo
 */
#include"../HAL/Keypad.h"
#include"../HAL/LCD.h"
#include"../MCAL/DIO_Driver/DIO.h"
#include"../MCAL/UART_Driver/uart.h"
#include"../MCAL/Interrupt_Driver/Interrupt.h"
#include"string.h"
#define SET_PASS '#'
#define OPENED_DOOR '+'

uint8 set_pass_flag=0;

void main()
{
	LCD_Init();
	uart_Init();
	uint8 default_pass[10];// char pass[10]="0000"== pass[0]='0'...pass[3]='0',pass[4]='#'
	uint8 entered_pass[10];
	uint8 new_pass[10];
	uint8 message[20];

	/*Display_string_row_col(0, 0, "1-lock/unlock");
	Display_string_row_col(1, 0, "2-change pass");
	uart_sendString(default_pass);*/
	while(1)
	{
		if(!set_pass_flag)
		{

		 uart_sendByte(SET_PASS);
		 uint8 key,result;
		 do{
			Display_string_row_col(0, 0, "Enter password");//default password
			GOTO_ROW_COL(1, 0);
			LCD_SendCommand(DISPLAY_ON_CURSOR_BLINK);
			uint8 i;
			for(i=0;i<5;i++)
			{
				key=get_key_pressed();
				if(key>=0 && key<=9)
				{
					default_pass[i]=key+'0';
					LCD_SendCharacter('*');
				}
				else
				{
					default_pass[i]='#';
					i++;
					default_pass[i]='\0';
					uart_sendString(default_pass);
					LCD_CLEAR();
				}
				_delay_ms(500);
			}
			Display_string_row_col(0,0,"ReEnter password");
			GOTO_ROW_COL(1, 0);
			LCD_SendCommand(DISPLAY_ON_CURSOR_BLINK);
			uint8 j;
			for(j=0;j<5;j++)
			{
			key=get_key_pressed();
			if(key>=0 && key<=9)
			{
				entered_pass[j]=key+'0';
				LCD_SendCharacter('*');
			}
			else
			{
				entered_pass[j]='#';
				j++;
				entered_pass[j]='0';
				uart_sendString(entered_pass);
				LCD_CLEAR();
			}
			_delay_ms(500);
			}

		}while(result!='1');
		 set_pass_flag=1;
		 LCD_DisplayString("Correct!");
		 _delay_ms(1000);
		 LCD_CLEAR();

		}

	}


}

