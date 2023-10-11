/*
 * uart.c
 *
 *  Created on: May 25, 2023
 *      Author: Lenovo
 */
#include"uart.h"
#define UBRR_value (((F_CPU/(16*BAUD_RATE)))-1) //16 in case normal mode and 8 in case double speed
void uart_Init()
{
	//we use normal mode not double speed mode
	UCSRB|=(1<<TXEN)|(1<<RXEN);//enable for TX and RX
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);//uart select=1 cauze we use UCSRC and use 8-bit mode
	UBRRH=UBRR_value>>8;
	UBRRL=UBRR_value;
}
void uart_sendByte(uint8 data)
{
	while(BIT_IS_CLEAR(UCSRA,UDRE));//polling until UDRE=1 which means UDR ready to send data
	UDR=data;
}
uint8 uart_recieveByte()
{
	while(BIT_IS_CLEAR(UCSRA,RXC));
	return UDR;
}
void uart_sendString(uint8* str)
{
	uint8 i=0;
	while(str[i]!='\0')
	{
		uart_sendByte(str[i]);
		i++;
	}
}
void uart_recieveString(uint8* str)
{
	uint8 i=0;
	str[i]=uart_recieveByte();
	while(str[i]!='#')
	{
		i++;
		str[i]=uart_recieveByte();
	}
	str[i]='\0';

}
