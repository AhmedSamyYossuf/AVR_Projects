/*
 * EEPROM.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */

#ifndef SRC_HAL_EEPROM_EEPROM_H_
#define SRC_HAL_EEPROM_EEPROM_H_

void EEPROM_Initialize(void);

uint8 EEPROM_WriteByte(uint8 BlockNum, uint8 ByteAddress, uint8 Data);

uint8 EEPROM_ReadByte(uint8 BlockNum, uint8 ByteAddress, uint8 *Data);

#endif /* SRC_HAL_EEPROM_EEPROM_H_ */
