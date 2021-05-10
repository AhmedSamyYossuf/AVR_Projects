/*
 * UART_reg.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_UART_UART_REG_H_
#define SRC_MCAL_UART_UART_REG_H_

#define  UDR_Reg           *((volatile uint8*) 0x2C)
#define  UCSRA_Reg         *((volatile uint8*) 0x2B)
#define  UCSRB_Reg         *((volatile uint8*) 0x2A)
#define  UCSRC_Reg         *((volatile uint8*) 0x40)
#define  UBRRL_Reg         *((volatile uint8*) 0x29)
#define  UBRRH_Reg         *((volatile uint8*) 0x40)

#endif /* SRC_MCAL_UART_UART_REG_H_ */
