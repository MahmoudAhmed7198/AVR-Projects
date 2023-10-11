/*
 * LED.c
 *
 *  Created on: May 17, 2023
 *      Author: Lenovo
 */
#include"LED.h"

void LED_Init()
{
	set_pin_direction(PORTC_reg, PIN6, OUTPUT);//red led
	set_pin_direction(PORTC_reg, PIN7, OUTPUT);//green led
}

void greenLed_ON()
{
	set_pin_value(PORTC_reg, PIN7, HIGH);
}
void greenLed_OFF()
{
	set_pin_value(PORTC_reg, PIN7, LOW);
}
void redLed_ON()
{
	set_pin_value(PORTC_reg, PIN6, HIGH);
}
void redLed_OFF()
{
	set_pin_value(PORTC_reg, PIN6, LOW);
}


/*void flash_led()
{
	LED1_ON();
	_delay_ms(1000);
	LED1_OFF();
	_delay_ms(1000);
}*/
