/*
 * SPI_types.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_SPI_SPI_TYPES_H_
#define SRC_MCAL_SPI_SPI_TYPES_H_

/*------------------- SPI Control Register –SPCR ------------------------------------*/

#define SPI_LSB_FIRST				0b00100000 // bit 5
#define SPI_MSB_FIRST				0b00000000 // bit 5

#define SPI_MASTER					0b00010000 // bit 4
#define SPI_SLAVE					0b00000000 // bit 4

#define SPI_CLK_POL_RISING			0b00000000 // bit 3
#define SPI_CLK_POL_FALLING			0b00001000 // bit 3

#define SPI_CLK_PHASE_SETUP_FIRST	0b00000100 // bit 2
#define SPI_CLK_PHASE_SAMPLE_FIRST	0b00000000 // bit 2

#define SPI_CLK_PRESCALER_4			0b00000000 // bit 1 & 0
#define SPI_CLK_PRESCALER_16		0b00000001 // bit 1 & 0
#define SPI_CLK_PRESCALER_64		0b00000010 // bit 1 & 0
#define SPI_CLK_PRESCALER_128		0b00000011 // bit 1 & 0

/*------------------------------------------------------------------------------------*/

/*------------------ SPI Status Register –SPSR --------------------------------------*/

#define SPI_CLK_NORMAL_SPEED  		0b00000000 // bit 0
#define SPI_CLK_DOUBLE_SPEED  		0b00000001 // bit 0

/*------------------------------------------------------------------------------------*/


#endif /* SRC_MCAL_SPI_SPI_TYPES_H_ */
