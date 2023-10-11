/*
 * DIO_Types.h
 *
 *  Created on: May 5, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DRIVER_DIO_TYPES_H_
#define MCAL_DIO_DRIVER_DIO_TYPES_H_
typedef enum{
	LOW,
	HIGH
}DIO_VAL;

typedef enum{
	INPUT,
	OUTPUT
}DIO_DIRECTION;

typedef enum{
	PORTA_reg,
	PORTB_reg,
	PORTC_reg,
	PORTD_reg
}PORT_TYPE;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PIN_NUM;







#endif /* MCAL_DIO_DRIVER_DIO_TYPES_H_ */
