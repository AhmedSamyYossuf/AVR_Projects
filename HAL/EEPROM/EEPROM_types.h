/*
 * EEPROM_types.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */

#ifndef SRC_HAL_EEPROM_EEPROM_TYPES_H_
#define SRC_HAL_EEPROM_EEPROM_TYPES_H_

typedef enum
{
    StartCondition,
    SendSlaveAddress,
	ReStartCondition,
    SendByteAddress,
    SendData,
	NACK,
    StopCondition,
    OperationFinished

}EEPROM_Write_State_T;



#endif /* SRC_HAL_EEPROM_EEPROM_TYPES_H_ */
