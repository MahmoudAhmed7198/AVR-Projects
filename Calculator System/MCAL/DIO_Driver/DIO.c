/*
 * DIO.c
 *
 *  Created on: May 5, 2023
 *      Author: Lenovo
 */
#include"DIO.h"

void set_port_direction(PORT_TYPE ptype,DIO_DIRECTION dir)
{
	if(dir == INPUT)
	{
		switch(ptype)
		{
		case PORTA_reg:
			DDRA=0x00;
			break;
		case PORTB_reg:
			DDRB=0x00;
			break;
		case PORTC_reg:
			DDRC=0x00;
			break;
		case PORTD_reg:
			DDRD=0x00;
			break;
		}

	}
	else if(dir == OUTPUT)
	{
		switch(ptype)
		{
		case PORTA_reg:
			DDRA=0xFF;
			break;
		case PORTB_reg:
			DDRB=0xFF;
			break;
		case PORTC_reg:
			DDRC=0xFF;
			break;
		case PORTD_reg:
			DDRD=0xFF;
			break;
		}
	}
}
void set_pin_direction(PORT_TYPE ptype,PIN_NUM p_num,DIO_DIRECTION dir)
{
	if(dir == INPUT)
	{
		switch(ptype)
		{
		case PORTA_reg:
			CLEAR_BIT(DDRA,p_num);
			break;
		case PORTB_reg:
			CLEAR_BIT(DDRB,p_num);
			break;
		case PORTC_reg:
			CLEAR_BIT(DDRC,p_num);
			break;
		case PORTD_reg:
			CLEAR_BIT(DDRD,p_num);
			break;
		}
	}
	else if(dir == OUTPUT)
	{
		switch(ptype)
		{
		case PORTA_reg:
			SET_BIT(DDRA,p_num);
			break;
		case PORTB_reg:
			SET_BIT(DDRB,p_num);
			break;
		case PORTC_reg:
			SET_BIT(DDRC,p_num);
			break;
		case PORTD_reg:
			SET_BIT(DDRD,p_num);
			break;
		}

	}

}
void set_port_value(PORT_TYPE ptype,uint8 value)
{
	switch(ptype)
	{
	case PORTA_reg:
		PORTA=value;
		break;
	case PORTB_reg:
		PORTB=value;
		break;
	case PORTC_reg:
		PORTC=value;
		break;
	case PORTD_reg:
		PORTD=value;
		break;
	}
}
void set_pin_value(PORT_TYPE ptype,PIN_NUM p_num,DIO_VAL val)
{
	if(val == HIGH)
	{
		switch(ptype)
		{
		case PORTA_reg:
			SET_BIT(PORTA,p_num);
			break;
		case PORTB_reg:
			SET_BIT(PORTB,p_num);
			break;
		case PORTC_reg:
			SET_BIT(PORTC,p_num);
			break;
		case PORTD_reg:
			SET_BIT(PORTD,p_num);
			break;
		}

	}
	else if(val == LOW)
	{
		switch(ptype)
		{
		case PORTA_reg:
			CLEAR_BIT(PORTA,p_num);
			break;
		case PORTB_reg:
			CLEAR_BIT(PORTB,p_num);
			break;
		case PORTC_reg:
			CLEAR_BIT(PORTC,p_num);
			break;
		case PORTD_reg:
			CLEAR_BIT(PORTD,p_num);
			break;
		}
	}

}
DIO_VAL get_pin_value(PORT_TYPE ptype,PIN_NUM p_num)
{
	DIO_VAL x;
	switch(ptype)
	{
	case PORTA_reg:
			x=GET_BIT(PINA,p_num);
			break;
	case PORTB_reg:
			x=GET_BIT(PINB,p_num);
			break;
	case PORTC_reg:
			x=GET_BIT(PINC,p_num);
			break;
	case PORTD_reg:
			x=GET_BIT(PIND,p_num);
			break;
	}
	return x;


}
