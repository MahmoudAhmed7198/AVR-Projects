/*
 * MOTOR.c
 *
 *  Created on: May 19, 2023
 *      Author: Lenovo
 */
#include"MOTOR.h"

void motor_Init()
{
	set_pin_direction(PORTB_reg, PIN0, OUTPUT);
	set_pin_direction(PORTB_reg, PIN1, OUTPUT);
	set_pin_direction(PORTB_reg, PIN3, OUTPUT);//OC0 pin
	set_pin_value(PORTB_reg, PIN0, LOW);//by default fan turned off
	set_pin_value(PORTB_reg, PIN1, LOW);

}
void open_door()
{
	Timer0_PWM_Init(128);//move 2.5Volt
	set_pin_value(PORTB_reg, PIN0, HIGH);
	set_pin_value(PORTB_reg, PIN1, LOW);
}
void close_door()
{
	Timer0_PWM_Init(128);//move 2.5Volt
	set_pin_value(PORTB_reg, PIN0, LOW);
	set_pin_value(PORTB_reg, PIN1, HIGH);
}
void stop()
{
	Timer0_PWM_Init(0);//move 0Volt
	set_pin_value(PORTB_reg, PIN0, LOW);
	set_pin_value(PORTB_reg, PIN1, LOW);
}
