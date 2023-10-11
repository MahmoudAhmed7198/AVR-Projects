/*
 * Keypad.c
 *
 *  Created on: May 23, 2023
 *      Author: Lenovo
 */

#include"Keypad.h"

#if(N_COL == 3)
static uint8 keypad_4X3_config(uint8 button_number);
#elif(N_COL == 4)
static uint8 Keypad_4x4_config(uint8 button_number);
#endif

uint8 get_key_pressed()
{
	uint8 row,col;

	while(1)
	{
		for(col=0;col<N_COL;col++)
		{
			Keypad_DDR=(0b00010000<<col);//make col0 output and rest of cols and rows are input
			Keypad_PORT=(~(0b00010000<<col));//put 0 on col0 and make all pins internal pull up resistance
			for(row=0;row<N_ROW;row++)
			{
				if(BIT_IS_CLEAR(Keypad_PIN,row))
				{
					#if(N_COL == 3)
					return keypad_4X3_config((row*N_COL)+col+1);
					#elif(N_COL == 4)
					return Keypad_4x4_config((row*N_COL)+col+1);
					#endif
				}
			}
		}
	}
}
static uint8 keypad_4X3_config(uint8 button_number)
{
	switch(button_number)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 6;
		break;
	case 7:
		return 7;
		break;
	case 8:
		return 8;
		break;
	case 9:
		return 9;
		break;
	case 11:
		return 0;
		break;
	default:
		return button_number;
	}
}

static uint8 Keypad_4x4_config(uint8 button_number)
{

	switch(button_number)
	{
	case 1: return 7;
			break;
	case 2: return 8;
			break;
	case 3: return 9;
			break;
	case 4: return '/';
			break;
	case 5: return 4;
			break;
	case 6: return 5;
			break;
	case 7: return 6;
			break;
	case 8: return '*'; /* ASCII Code of '*' */
			break;
	case 9: return 1;
			break;
	case 10: return 2;
			break;
	case 11: return 3;
			break;
	case 12: return '-'; /* ASCII Code of '-' */
			break;
	case 13: return 13;  /* ASCII of Enter */
			break;
	case 14: return 0;
			break;
	case 15:return '=';
			break;
	case 16: return '+'; /* ASCII Code of '+' */
			break;
	default: return button_number;
	}

}

