/*
 * SPI.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_SPI_SPI_H_
#define SRC_MCAL_SPI_SPI_H_

void SPI_Initialize(void);

void SPI_SendData(uint8 Data);
void SPI_SendString( uint8* Str);

/*{
	uint8 result;
	DIO_SetPinValue(portID,PinID,STD_LOW);
	SPDR_Reg = Data;
	while(transmission complete);
	result = SPDR_Reg;
	DIO_SetPinValue(portID,PinID,STD_HIGH);
	return result;
}*/

uint8 SPI_DataReceived(void);

void SPI_SetSlaveData(uint8 Data);

#endif /* SRC_MCAL_SPI_SPI_H_ */
