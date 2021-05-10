/*
 * TWI_reg.h
 *
 *  Created on: Sep 20, 2019
 *      Author: ahmed
 */

#ifndef SRC_MCAL_TWI_TWI_REG_H_
#define SRC_MCAL_TWI_TWI_REG_H_


#define  TWBR_Reg           *((volatile uint8*) 0x20)
#define  TWCR_Reg           *((volatile uint8*) 0x56)
#define  TWSR_Reg         	*((volatile uint8*) 0x21)
#define  TWDR_Reg         	*((volatile uint8*) 0x23)
#define  TWAR_Reg         	*((volatile uint8*) 0x22)

#endif /* SRC_MCAL_TWI_TWI_REG_H_ */
