/*
 * SPI_reg.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_SPI_SPI_REG_H_
#define SRC_MCAL_SPI_SPI_REG_H_

#define  SPCR_Reg           (*((volatile uint8*) 0x2D))
#define  SPSR_Reg           (*((volatile uint8*) 0x2E))
#define  SPDR_Reg         	(*((volatile uint8*) 0x2F))

#endif /* SRC_MCAL_SPI_SPI_REG_H_ */
