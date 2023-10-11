/*
 * Timer.h
 *
 *  Created on: May 18, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_H_
#define MCAL_TIMER_DRIVER_TIMER_H_
#include"../Interrupt_Driver/Interrupt.h"
/*
 * Timer normal mode configurations
 */
void Timer0_normalMode_Init();
void Timer1_normalMode_Init();
void Timer2_normalMode_Init();
/*
 * Timer CTC mode configurations
 */
void Timer0_CTCMode_Init();
void Timer1_CTCMode_Init();
void Timer2_CTCMode_Init();
/*
 * Time PWM mode configurations
 */
void Timer0_PWM_Init(uint8 duty_cycle);



#endif /* MCAL_TIMER_DRIVER_TIMER_H_ */
