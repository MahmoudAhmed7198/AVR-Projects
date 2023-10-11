/*
 * I2C.h
 *
 *  Created on: May 26, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_I2C_DRIVER_I2C_H_
#define MCAL_I2C_DRIVER_I2C_H_
#include"../DIO_Driver/DIO.h"
#include<avr/io.h>
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave
//I2C functions prototype

void TWI_Init();
void TWI_start();
void TWI_stop();
void TWI_write(uint8);
uint8 TWI_readWithACK();
uint8 TWI_readWithNACK();
uint8 TWI_getStatus();



#endif /* MCAL_I2C_DRIVER_I2C_H_ */
