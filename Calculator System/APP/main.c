/*
 * main.c
 *
 *  Created on: May 28, 2023
 *      Author: Lenovo
 */
#include"../HAL/Keypad.h"
#include"../HAL/LCD.h"
uint8 x,y,z;
char op;
int main()
{
	uint8 number1[3],number2[3];
	sint64 result;
	int num1,num2;
	uint8 key;
	uint8 j,i;
	LCD_Init();
	Display_string_row_col(0, 1, "Welcome To");
	Display_string_row_col(1, 1, "Calculator");
	_delay_ms(1000);
	LCD_CLEAR();
	LCD_SendCommand(DISPLAY_ON_CURSOR_BLINK);
	while(1)
	{

		for(x=0;x<4;x++)
		{
		key=get_key_pressed();
		_delay_ms(250);
		if(key>=0 && key<=9)
		{
			LCD_integer_To_String(key);
			number1[x]=key;
		}
		else
		{
			if(key == 13)
			{
				LCD_CLEAR();
				break;
			}
			if(x==1)
			{
				num1=(int)(number1[0]);
			}
			else if(x==2)
			{
				num1=(int)((number1[0])*10+(number1[1]));
			}
			else if(x==3)
			{
				num1=(int)((number1[0])*10+(number1[1]));
				num1=num1*10+(number1[2]);
			}
			else if(x==4)
			{
				num1=(int)((number1[0])*10+(number1[1]));
				num1=num1*10+(int)(number1[2]);
				num1=num1*10+(int)(number1[3]);
			}
			break;
		}

		}
		switch(key)
		{
		case '+':
			LCD_SendCharacter(key);
			op='+';
			break;
		case '-':
			LCD_SendCharacter(key);
			op='-';
			break;
		case '*':
			LCD_SendCharacter(key);
			op='*';
			break;
		case '/':
			LCD_SendCharacter(key);
			op='/';
			break;
		case 13:
			LCD_CLEAR();
			break;
		}
		for(y=0;y<3;y++)
		{
		key=get_key_pressed();
		_delay_ms(250);
		if(key>=0 && key<=9)
		{
			LCD_integer_To_String(key);
			number2[y]=key;
		}
		else
		{
			if(key == 13)
			{
				LCD_CLEAR();
				break;
			}
			if(y==1)
			{
				num2=(int)(number2[0]);
			}
			else if(y==2)
			{
				num2=(int)((number2[0])*10+(number2[1]));
			}
			else if(y==3)
			{
				num2=(int)((number2[0])*10+(number2[1]));
				num2=num2*10+(int)(number2[2]);
			}
			else if(y==4)
			{
				num2=(int)((number2[0])*10+(number2[1]));
				num2=num2*10+(number2[2]);
				num2=num2*10+(number2[3]);
			}
			break;
		}

		}
			switch(op)
			{
			case '+':
				result=(sint64)(num1+num2);
				break;
			case '-':
				result=(sint64)(num1-num2);
				break;
			case '*':
				result=(sint64)(num1*num2);
				break;
			case '/':
				result=(sint64)(num1/num2);
				break;
			}

		switch(key)
		{
		case '=':
			GOTO_ROW_COL(1, 0);
			LCD_SendCharacter(key);
			LCD_integer_To_String(result);
			break;
		case 13:
			LCD_CLEAR();
			break;
		}

	}
	return 0;
}

