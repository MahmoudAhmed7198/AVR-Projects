/*
 * HW_Registers.h
 *
 *  Created on: May 5, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DRIVER_HW_REGISTERS_H_
#define MCAL_DIO_DRIVER_HW_REGISTERS_H_
#include"../../LIB/Std_Types.h"
//ATmega16 I/O registers
#define DDRA (*(volatile uint8*)0x3A)
#define PORTA (*(volatile uint8*)0x3B)
#define PINA (*(volatile uint8*)0x39)

#define DDRB (*(volatile uint8*)0x37)
#define PORTB (*(volatile uint8*)0x38)
#define PINB (*(volatile uint8*)0x36)

#define DDRC (*(volatile uint8*)0x34)
#define PORTC (*(volatile uint8*)0x35)
#define PINC (*(volatile uint8*)0x33)

#define DDRD (*(volatile uint8*)0x31)
#define PORTD (*(volatile uint8*)0x32)
#define PIND (*(volatile uint8*)0x30)

#endif /* MCAL_DIO_DRIVER_HW_REGISTERS_H_ */
