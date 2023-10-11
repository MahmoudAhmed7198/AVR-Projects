/*
 * Keypad.h
 *
 *  Created on: May 23, 2023
 *      Author: Lenovo
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_
#include"../MCAL/DIO_Driver/DIO.h"
#include"LCD.h"
#define N_COL 4
#define N_ROW 4
//keypad DIO Configurations
#define Keypad_DDR DDRA
#define Keypad_PORT PORTA
#define Keypad_PIN PINA
//Keypad function prototype
uint8 get_key_pressed();





#endif /* HAL_KEYPAD_H_ */
