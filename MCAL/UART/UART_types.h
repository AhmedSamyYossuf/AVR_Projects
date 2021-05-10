/*
 * UART_types.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_UART_UART_TYPES_H_
#define SRC_MCAL_UART_UART_TYPES_H_

#define  UART_ASYNCHRONOUS        0b00000000      //0x00
#define  UART_SYNCHRONOUS         0b01000000      //0x40

#define  UART_PARITY_DISABLED     0b00000000      //0x00
#define  UART_PARITY_EVEN         0b00100000      //0x20
#define  UART_PARITY_ODD          0b00110000      //0x30
    
#define  UART_STOP_BIT_ONE        0b00000000      //0x00
#define  UART_STOP_BIT_TWO        0b00001000      //0x08
    
#define  UART_DATA_BITS_FIVE      0b00000000      //0x00
#define  UART_DATA_BITS_SIX       0b00000010      //0x02
#define  UART_DATA_BITS_SEVEN     0b00000100      //0x04
#define  UART_DATA_BITS_EIGHT     0b00000110      //0x06
#define  UART_DATA_BITS_NINE      0b11111111      //0xFF

#endif /* SRC_MCAL_UART_UART_TYPES_H_ */
