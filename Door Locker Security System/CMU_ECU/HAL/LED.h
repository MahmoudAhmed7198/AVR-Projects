/*
 * LED.h
 *
 *  Created on: May 17, 2023
 *      Author: Lenovo
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_
#include"../MCAL/DIO_Driver/DIO.h"
#include"../MCAL/Timer_Driver/Timer.h"
void LED_Init();
void greenLed_ON();
void greenLed_OFF();
void redLed_ON();
void redLed_OFF();
//void flash_led();

#endif /* HAL_LED_H_ */
