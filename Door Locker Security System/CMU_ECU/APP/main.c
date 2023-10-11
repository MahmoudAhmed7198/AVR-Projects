/*
 * main.c
 *
 *  Created on: May 26, 2023
 *      Author: Lenovo
 */
#include"../HAL/LED.h"
#include"../HAL/MOTOR.h"
#include"../HAL/Buzzer.h"
#include"../MCAL/EEPROM_Driver/EEPROM.h"
#include"../MCAL/I2C_Driver/I2C.h"
#include"../MCAL/UART_Driver/uart.h"
#include<string.h>
#include<avr/io.h>
#define SET_PASS '#'
#define OPENED_DOOR '+'
int main()
{
	uart_Init();
	TWI_Init();
	EEPROM_init();
	LED_Init();
	buzzer_Init();
	motor_Init();
	uint8 default_pass[10];
	uint8 entered_pass[10];
	uint8 new_pass[10];

	uint8 correct_message[20]="correct pass!#";
	uint8 incorrect_message[20]="Incorrect pass!";
	while(1)
	{
		uint8 choice;
		choice=uart_recieveByte();
		switch(choice)
		{
			case SET_PASS:
				do{
			uart_recieveString(default_pass);//receive default pass
			uart_recieveString(entered_pass);//receive entered pass
			if(strcmp(default_pass,entered_pass)==0)//if they are equal save default pass in EEPROM
			{
				uint8 i;
				for(i=0;i<5;i++)
				{
					EEPROM_writeByte(0x0311+i, default_pass[i]);
					_delay_ms(10);
				}
				default_pass[i]='\0';
			   uart_sendByte('1');
			   break;
			}
			else
				uart_sendByte('0');
				}while(1);//repeat while two passwords not equal
		}
	}

	return 0;
}






