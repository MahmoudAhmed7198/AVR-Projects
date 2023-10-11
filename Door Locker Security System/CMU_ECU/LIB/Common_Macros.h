/*
 * Common_Macros.h
 *
 *  Created on: May 5, 2023
 *      Author: Lenovo
 */

#ifndef LIB_COMMON_MACROS_H_
#define LIB_COMMON_MACROS_H_

#define SET_BIT(reg,bit_n) reg|=(1<<bit_n)
#define CLEAR_BIT(reg,bit_n) reg&=~(1<<bit_n)
#define TOGGLE_BIT(reg,bit_n) reg^=(1<<bit_n)
#define GET_BIT(reg,bit_n)  (((reg>>bit_n))&(0x01))
#define ROR(reg,bit_n) reg=(reg>>bit_n)|(reg<<sizeof(reg)*8 - bit_n)
#define ROL(reg_bit_n) reg=(reg<<bit_n)|(reg>>sizeof(reg)*8 - bit_n)
#define BIT_IS_SET(reg,bit_n) (reg&(1<<bit_n))
#define BIT_IS_CLEAR(reg,bit_n) (!(reg&(1<<bit_n)))



#endif /* LIB_COMMON_MACROS_H_ */
