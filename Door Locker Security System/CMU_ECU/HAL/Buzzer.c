/*
 * Buzzer.c
 *
 *  Created on: May 26, 2023
 *      Author: Lenovo
 */
#include"Buzzer.h"
void buzzer_Init()
{
	set_pin_direction(PORTD_reg, PIN7, OUTPUT);
}
void buzzer_ON()
{
	set_pin_value(PORTD_reg, PIN7, HIGH);
}
void buzzer_OFF()
{
	set_pin_value(PORTD_reg, PIN7, LOW);
}
