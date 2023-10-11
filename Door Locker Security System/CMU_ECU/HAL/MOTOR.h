/*
 * MOTOR.h
 *
 *  Created on: May 19, 2023
 *      Author: Lenovo
 */

#ifndef HAL_MOTOR_H_
#define HAL_MOTOR_H_
#include"../MCAL/DIO_Driver/DIO.h"
#include"../MCAL/Timer_Driver/Timer.h"
void motor_Init();
void open_door();//anti-clock wise
void close_door();//clock wise
void stop();

#endif /* HAL_MOTOR_H_ */
