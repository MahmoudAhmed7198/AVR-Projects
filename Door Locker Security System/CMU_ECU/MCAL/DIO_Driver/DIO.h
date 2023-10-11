/*
 * DIO.h
 *
 *  Created on: May 5, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DRIVER_DIO_H_
#define MCAL_DIO_DRIVER_DIO_H_
#include<util/delay.h>
#include"../../LIB/Common_Macros.h"
#include"../../LIB/Std_Types.h"
#include"HW_Registers.h" //include registers and std_types
#include"DIO_Types.h"

void set_port_direction(PORT_TYPE,DIO_DIRECTION);
void set_pin_direction(PORT_TYPE,PIN_NUM,DIO_DIRECTION);
void set_port_value(PORT_TYPE,uint8);
void set_pin_value(PORT_TYPE,PIN_NUM,DIO_VAL);
DIO_VAL get_pin_value(PORT_TYPE,PIN_NUM);

#endif /* MCAL_DIO_DRIVER_DIO_H_ */
