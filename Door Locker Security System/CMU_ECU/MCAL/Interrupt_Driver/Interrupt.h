/*
 * Interrupt.h
 *
 *  Created on: May 17, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_INTERRUPT_DRIVER_INTERRUPT_H_
#define MCAL_INTERRUPT_DRIVER_INTERRUPT_H_
#include"../DIO_Driver/DIO.h"

#include<avr/interrupt.h>
void INT0_Init();
void INT1_Init();
void INT2_Init();


#endif /* MCAL_INTERRUPT_DRIVER_INTERRUPT_H_ */
