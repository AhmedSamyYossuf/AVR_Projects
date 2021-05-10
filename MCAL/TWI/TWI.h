/*
 * TWI.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TWI_TWI_H_
#define SRC_MCAL_TWI_TWI_H_

/* Initialize driver functionality */
void TWI_Initialize(void);

/* Enable TWI interrupt */
void TWI_InterruptEnable(void);

/* Disable TWI interrupt */
void TWI_InterruptDisable(void);

/* Enable Acknowledgment */
void TWI_AckEnable(void);

/* Disable Acknowledgment */
void TWI_AckDisable(void);

/* Generate a start condition */
void TWI_GenerateStartCondition(void);

/* Clear start condition */
void TWI_ClearStartCondition(void);

/* Generate a stop condition */
void TWI_GenerateStopCondition(void);

/* Send one byte of data */
void TWI_SendData(uint8 Data);

/* Read one byte of data */
void TWI_ReadData(uint8 Data);

/* Get the current bus status */
uint8 TWI_GetStatus(void);

/* Clear the interrupt flag */
void TWI_ClearInterruptFlag(void);

/* Send a message */
uint8 TWI_SendMsg(uint8 SlaveAddress, uint8 TxMsg[], uint8 TxMsgSize);

/* Start reading operation */
void TWI_StartReading(uint8 SlaveAddress, uint8 SizeCpy);

/* Get last received message */
uint8 TWI_GetLastRxMsg(uint8 RxMsg[], uint8* RxMsgSize);

#endif /* SRC_MCAL_TWI_TWI_H_ */
