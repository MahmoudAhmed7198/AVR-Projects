/*
 * I2C.c
 *
 *  Created on: May 26, 2023
 *      Author: Lenovo
 */
#include"I2C.h"
void TWI_Init()
{
	TWBR=0x02;
	TWSR=0x00;
	TWAR=0b000000100;
	TWCR|=(1<<TWEN);
}
void TWI_start()
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}
void TWI_stop()
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void TWI_write(uint8 data)
{
	   TWDR=data;
	    /*
		 * Clear the TWINT flag before sending the data TWINT=1
		 * Enable TWI Module TWEN=1
		 */
	    TWCR=(1<<TWINT)|(1<<TWEN);
	    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
	    while(BIT_IS_CLEAR(TWCR,TWINT));
}
uint8 TWI_readWithACK()
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
uint8 TWI_readWithNACK()
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR=(1<<TWINT)|(1<<TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
uint8 TWI_getStatus()
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status=TWSR&0xF8;
    return status;
}
