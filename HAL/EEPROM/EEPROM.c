/*
 * EEPROM.c
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/std_types.h"

#include "../../MCAL/TWI/TWI.h"
#include "../../MCAL/TWI/TWI_types.h"
#include "EEPROM_types.h"
#include "EEPROM_config.h"
#include "EEPROM.h"

/*
void EEPROM_Initialize(void)
{
	/* Initialize I2C prephiral
	TWI_Intialize();
}

uint8 EEPROM_WriteByte(uint8 BlockNum, uint8 ByteAddress, uint8 Data)
{
	uint8 Result = 0;
    uint8 SlaveAddress = 0xA0 | (BlockNum << 1);
    CLEAR_BIT(SlaveAddress, 0);

    EEPROM_Write_State_T WriteState = StartCondition;
    do
        {
            switch(WriteState)
            {
                case StartCondition:
                    TWI_GenerateStartCondition();
                    WriteState = SendSlaveAddress;
                    break;

                case SendSlaveAddress:
                    if( TWI_GetStatus() == Master_Start_Condition)
                    {
                        TWI_ClearStartCondition();
                        TWI_SendData(SlaveAddress);
                        TWI_ClearInterruptFlag();
                        WriteState = SendByteAddress;
                    }
                    break;

                case SendByteAddress:
                    if( TWI_GetStatus() == MasterTx_SlaveAddrWritebitTx_AckRx)
                    {
                        TWI_SendData(ByteAddress);
                        TWI_ClearInterruptFlag();
                        WriteState = SendData;
                    }
                    break;

                case SendData:
                    if( TWI_GetStatus() == MasterTx_DataTx_AckRx)
                    {
                        TWI_SendData(Data);
                        TWI_ClearInterruptFlag();
                        WriteState = StopCondition;
                    }
                    break;

                case StopCondition:
                    if( TWI_GetStatus() == MasterTx_DataTx_AckRx)
                    {
                        TWI_GenerateStopCondition();
                        TWI_ClearInterruptFlag();
                        WriteState = OperationFinished;
                        Result = 1;
                    }
                    break;
            }
        }while(WriteState != OperationFinished);


        return Result;
}

uint8 EEPROM_ReadByte(uint8 BlockNum, uint8 ByteAddress, uint8 *Data)
{

	TWI_AckEnable();
	uint8 Result = 0;
	uint8 SlaveAddress = 0xA0 | (BlockNum << 1);
	SET_BIT(SlaveAddress, 0);

	EEPROM_Write_State_T WriteState = StartCondition;
	while(WriteState != OperationFinished)
	{
		 switch(WriteState)
		{
			case StartCondition:
				TWI_GenerateStartCondition();
				WriteState = SendSlaveAddress;
				break;

			case SendSlaveAddress:
				if( TWI_GetStatus() == Master_Start_Condition)
				{
					TWI_ClearStartCondition();
					TWI_SendData(SlaveAddress);
					TWI_ClearInterruptFlag();
					WriteState = ReStartCondition;
				}
				break;

			case ReStartCondition:
				if( TWI_GetStatus() == MasterRx_SlaveAddrReadbitTx_AckRx)
				{
					TWI_GenerateStartCondition();
					WriteState = SendByteAddress;

				}
				break;
			case SendByteAddress:
				if( TWI_GetStatus() == Master_RepeatedStart_Condition)
				{
					TWI_ClearStartCondition();
					TWI_SendData(ByteAddress);
					TWI_ClearInterruptFlag();
					WriteState = SendData;
				}
				break;

			case SendData:
				if( TWI_GetStatus() == MasterTx_SlaveAddrWritebitTx_AckRx || TWI_GetStatus() == MasterRx_SlaveAddrReadbitTx_AckRx)
				{
					TWI_ReadData(Data);
					TWI_ClearInterruptFlag();
					WriteState = NACK;
				}
				break;

			case NACK:
				if( TWI_GetStatus() == MasterTx_DataTx_NotAckRx)
				{
					TWI_AckDisable();
					TWI_ClearInterruptFlag();
					WriteState = StopCondition;
				}
				break;

			case StopCondition:
				if( TWI_GetStatus() == MasterTx_DataTx_AckRx)
				{
					TWI_GenerateStopCondition();
					TWI_ClearInterruptFlag();
					WriteState = OperationFinished;
					Result = 1;
				}
				break;
		}
	}



}


*/

