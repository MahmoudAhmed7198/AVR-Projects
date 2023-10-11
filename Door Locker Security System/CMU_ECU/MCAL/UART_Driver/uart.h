/*
 * uart.h
 *
 *  Created on: May 25, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_UART_DRIVER_UART_H_
#define MCAL_UART_DRIVER_UART_H_
#include"../DIO_Driver/DIO.h"
#include<avr/io.h>
#define BAUD_RATE 9600

void uart_Init();
void uart_sendByte(uint8);
uint8 uart_recieveByte();
void uart_sendString(uint8* str);
void uart_recieveString(uint8* str);


#endif /* MCAL_UART_DRIVER_UART_H_ */
