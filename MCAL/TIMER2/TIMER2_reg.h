/*
 * TIMER2_reg.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TIMER2_TIMER2_REG_H_
#define SRC_MCAL_TIMER2_TIMER2_REG_H_

#define OCR2_reg       *((volatile uint8*)0x43)
#define TCNT2_reg      *((volatile uint8*)0x44)
#define TCCR2_reg      *((volatile uint8*)0x45)
#define TIFR_reg       *((volatile uint8*)0x58)
#define TIMSK_reg      *((volatile uint8*)0x59)

#endif /* SRC_MCAL_TIMER2_TIMER2_REG_H_ */
