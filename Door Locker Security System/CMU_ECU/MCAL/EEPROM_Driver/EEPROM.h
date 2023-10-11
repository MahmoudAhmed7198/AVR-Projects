/*
 * EEPROM.h
 *
 *  Created on: May 26, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_EEPROM_DRIVER_EEPROM_H_
#define MCAL_EEPROM_DRIVER_EEPROM_H_
#include"../DIO_Driver/DIO.h"
#define ERROR 0
#define SUCCESS 1
void EEPROM_init(void);
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);


#endif /* MCAL_EEPROM_DRIVER_EEPROM_H_ */
