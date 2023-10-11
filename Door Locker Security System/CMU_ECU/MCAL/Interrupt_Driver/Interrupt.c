/*
 * Interrupt.c
 *
 *  Created on: May 17, 2023
 *      Author: Lenovo
 */
#include"Interrupt.h"

void INT0_Init()
{
	CLEAR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1); //make interrupt 0 request interrupt at falling edge
	SET_BIT(GICR,6);  //enable MIE (INT0)
	SET_BIT(SREG,7); //enable GIE
}

void INT1_Init()
{
	SET_BIT(MCUCR,3);
	CLEAR_BIT(MCUCR,2); //make interrupt 1 request interrupt at falling edge
	SET_BIT(GICR,7);  //enable MIE (INT1)
	SET_BIT(SREG,7); //enable GIE
}
void INT2_Init()
{
	SET_BIT(MCUCSR,6);
	SET_BIT(GICR,5);  //enable MIE (INT2)
	SET_BIT(SREG,7); //enable GIE
}

