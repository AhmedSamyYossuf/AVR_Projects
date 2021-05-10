/*
 * UART.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_UART_UART_H_
#define SRC_MCAL_UART_UART_H_

typedef enum
{
    UART_Receive_Complete_Int,
    UART_Data_Register_Empty_Int,
    UART_Transmit_Complete_Int
} UART_Interrupt_Select_T ;

/* Initialize driver functionality */
void UART_Initialize(void);

/* Read data in UDR register, in case of receiving */
uint8 UART_GetChar(void);

/* Write data in UDR register, in case of transmitting */
void UART_SendChar(uint8 Data);

/* Send a Message */
void UART_SendMsg(uint8 TxMsg[], uint8 TxMsgSize);

/* Read a Message */
void UART_ReadMsg(uint8 RxMsg[], uint8* RxMsgSize);

/* Functions to define interrupt functionality */
void UART_InterruptEnable(UART_Interrupt_Select_T Interrupt_Source);

void UART_InterruptDisable(UART_Interrupt_Select_T Interrupt_Source);

#endif /* SRC_MCAL_UART_UART_H_ */
