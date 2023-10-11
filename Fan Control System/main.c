/*
 * main.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Lenovo
 */
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
typedef unsigned char uint8;
typedef unsigned short uint16;
uint8 seg[2],i;
void INT0_speed1_Init()
{
	DDRD &=~(1<<PD2);//make pin PD2 input
	PORTD |=(1<<PD2);//internal pull up resistor
	MCUCR |=(1<<ISC01);//make interrupt INT0 sense at falling edge
	GICR |=(1<<INT0);//enable MIE
	SREG |=(1<<7);//enable GIE
}
void INT1_speed2_Init()
{
	DDRD &=~(1<<PD3);//make pin PD3 input pin
	PORTD |=(1<<PD3);//internal pull up resistor
	MCUCR |=(1<<ISC11);//make interrupt INT1 sense at falling edge
	GICR |=(1<<INT1);//enable MIE
	SREG |=(1<<7);//enable GIE
}
void INT2_speed3_Init()
{
	DDRB &=~(1<<PB2);//make pin PB2 input pin
	PORTB |=(1<<PB2);//internal pull up resistor
	MCUCSR |=(1<<ISC2);//sense of INT2
	GICR |=(1<<INT2);//enable MIE
	SREG |=(1<<7);//enable GIE
}
void start_stop()
{
	DDRB &=~(1<<PB0);//make pin PB0 input pin
	PORTB |=(1<<PB0);//internal pull up resistor

}
void timer_setting()
{
	DDRB &=~(1<<PB1);//make pin PB1 input pin
	PORTB |=(1<<PB1);//internal pull up resistor
}
void seven_seg_Init()
{
	DDRC |=0x0F;//make lower 4 pins of portc output pins
	DDRA |=(1<<PA0)|(1<<PA1);//enable pins direction for seven segments is ouput
	//PORTA |=(1<<PA0)|(1<<PA1);//enable pins at initialization time
	//PORTC &=0xF0;//make all seven segments 0 at beginning
}
void Timer0_PWM_Init(uint8 duty_cycle)
{
	TCCR0 |=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);//make timer0 PWM mode non inverting 8 prescaler
	TCNT0=0;
	OCR0=duty_cycle;
	DDRB |=(1<<PB3);
}
void motor_rotate()
{
	DDRA |=(1<<PA2)|(1<<PA3);
	PORTA &=~(1<<PA2);
	PORTA |=(1<<PA3);
}

void Timer1_CTC_Init()
{

}
ISR(INT0_vect)
{
	seg[0]=1;
	motor_rotate();
	Timer0_PWM_Init(64);
	PORTA |=(1<<PA0);
	PORTA &=~(1<<PA1);
	PORTC=(PORTC & 0xF0)|(seg[0] & 0x0F);
}
ISR(INT1_vect)
{
	seg[0]=2;
	motor_rotate();
	Timer0_PWM_Init(128);
	PORTA |=(1<<PA0);
	PORTA &=~(1<<PA1);
	PORTC=(PORTC & 0xF0)|(seg[0] & 0x0F);
}
ISR(INT2_vect)
{
	seg[0]=3;
	motor_rotate();
	Timer0_PWM_Init(255);
	PORTA |=(1<<PA0);
	PORTA &=~(1<<PA1);
	PORTC=(PORTC & 0xF0)|(seg[0] & 0x0F);
}

int main()
{
	INT0_speed1_Init();
	INT1_speed2_Init();
	INT2_speed3_Init();
	start_stop();
	timer_setting();
	seven_seg_Init();
	while(1)
	{



	}


	return 0;
}

