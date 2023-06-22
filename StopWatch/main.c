/*
 * main.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Lenovo
 */
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

typedef unsigned char uint8;
uint8 seg[4],flag,i;

void INT0_Reset_Init()
{
	DDRD &=~(1<<PD2);//make pin PD2 is input pin for button
	PORTD |=(1<<PD2);//make pin PD2 internal pull up resistor
	MCUCR |=(1<<ISC01);
	MCUCR &=~(1<<ISC00); //make INT0 sense at falling edge
	GICR |=(1<<INT0); //enable MIE
	SREG |=(1<<7);//enable GIE
}
void INT1_Pause_Init()
{
	DDRD &=~(1<<PD3);//make pin PD3 input pin for button
	PORTD |=(1<<PD3);//internal pull up resistor
	MCUCR |=(1<<ISC11);
	MCUCR &=~(1<<ISC10);//make INT1 sense at falling edge
	GICR |=(1<<INT1);//enable MIE
	SREG |=(1<<7);//enable GIE
}
void INT2_Resume_Init()
{
	DDRB &=~(1<<PB2);//make pin PB2 input pin for button
	PORTB |=(1<<PB2);//make this pin internal pull up resistor
	MCUCSR |=(1<<ISC2);
	GICR |=(1<<INT2);//enable MIE
	SREG |=(1<<7);//enable GIE
}
void Timer1_CTC_Init()
{
	TCCR1A |=(1<<FOC1A);//set FOC that is set in non PWM mode
	TCCR1B |=(1<<WGM12)|(1<<CS12)|(1<<CS10);//make timer1 in CTC mode with 1024 prescaler
	TCNT1=0;//counter starts from 0
	OCR1A=1000;//because num of overflows for 1 second=1overflow
	TIMSK |=(1<<OCIE1A);//enable MIE
	SREG |=(1<<7);//enable GIE
}
void stop_watch()
{
	seg[0]++;
	if(seg[0]>9)
	{
		seg[1]++;
		seg[0]=0;
		if(seg[1]==6)
		{
			seg[2]++;
			seg[1]=0;
		}
	}
	if(seg[2]>9)
	{
		seg[3]++;
		seg[2]=0;
		if(seg[3]==6)
		{
			for(i=0;i<4;i++)
			{
				seg[i]=0;
			}
		}
	}

}
ISR(TIMER1_COMPA_vect)
{
	flag=1;
}
ISR(INT0_vect)
{
	PORTC &=0xF0;
	for(i=0;i<4;i++)
	{
		seg[i]=0;
	}
}
ISR(INT1_vect)
{
	TIMSK &=~(1<<OCIE1A);
}
ISR(INT2_vect)
{
	TIMSK |=(1<<OCIE1A);
}

int main()
{
	DDRC |=0x0F; //make PORTC output port 4pins for 7segment and 4pins for enable of 7seg
	DDRA |=0x0F;//make Lower 4 pins output (enable pins)
	PORTA |=0x0F;//enable all enables
	PORTC &=0xF0;//make all 7 seg leds to zero at beginning
	INT0_Reset_Init();
	INT1_Pause_Init();
	INT2_Resume_Init();
	Timer1_CTC_Init();
	flag=0;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			PORTA=(PORTA & 0xF0)|(1<<i);
			PORTC=(PORTC & 0xF0)|(seg[i] & 0x0F);
			_delay_ms(1);
		}
		if(flag==1)
		{
			stop_watch();
			flag=0;
		}

	}


	return 0;
}

