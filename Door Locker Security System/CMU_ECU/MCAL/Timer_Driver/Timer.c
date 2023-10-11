/*
 * Timer.c
 *
 *  Created on: May 18, 2023
 *      Author: Lenovo
 */

#include"Timer.h"
void Timer0_normalMode_Init()
{
	SET_BIT(TCCR0,7);//FOC0 setting in non PWM mode
	SET_BIT(TCCR0,2);//1024 prescaler,, timer overflow every 256ms for 1 second need 4overflow
	SET_BIT(TCCR0,0);

	TCNT0=0; //start count from 0 to max value for this timer register which 255
	SET_BIT(TIMSK,0);//set MIE for normal mode timer0
	SET_BIT(SREG,7);
}
void Timer1_normalMode_Init()
{
	SET_BIT(TCCR1A,3); //FOC1A in case non PWM mode
	SET_BIT(TCCR1A,2);//FOC1B
	SET_BIT(TCCR1B,2); //make 1024 prescaler
	SET_BIT(TCCR1B,0);
	TCNT1=0;
	SET_BIT(TIMSK,2);//enable MIE for Timer1
	SET_BIT(SREG,7);//enable GIE

}
void Timer0_CTCMode_Init()
{
	SET_BIT(TCCR0,7);//FOC0 set in this mode(its set in non PWM mode)
	SET_BIT(TCCR0,3);//set WGM01 CTC mode
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,0); //1024 prescaler
	TCNT0=0;
	OCR0=250;
	SET_BIT(TIMSK,1);//enable MIE
	SET_BIT(SREG,7);
}
void Timer1_CTCMode_Init()
{
	SET_BIT(TCCR1A,3);//FOC1A
	SET_BIT(TCCR1A,2);//FOC1B

	SET_BIT(TCCR1B,3);//set WGM 12 (CTC mode)
	SET_BIT(TCCR1B,2); //1024 prescaler
	SET_BIT(TCCR1B,0);

	TCNT1=0;
	OCR1A=60000; //compare match occurs at 60000
	SET_BIT(TIMSK,4);

}
void Timer0_PWM_Init(uint8 duty_cycle)
{
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3); //make timer works in PWM mode
	SET_BIT(TCCR0,5);//set COM01 to works in OC0
	SET_BIT(TCCR0,1);//8 prescaler
	TCNT0=0;
	OCR0=duty_cycle;

}

