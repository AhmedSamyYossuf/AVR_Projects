/*
 * TIMER_reg.h
 *
 *  Created on: Sep 2, 2019
 *      Author: Ahmed
 */


#ifndef DRIVERS_MAIN_REPO_NASR5_REPO_SRC_MCAL_TIMER_TIMER_REG_H_
#define DRIVERS_MAIN_REPO_NASR5_REPO_SRC_MCAL_TIMER_TIMER_REG_H_

#define OCR0_reg       *((volatile uint8*)0x5C)
#define TIFR_reg       *((volatile uint8*)0x58)
#define TCCR0_reg      *((volatile uint8*)0x53)
#define TCNT0_reg      *((volatile uint8*)0x52)
#define TIMSK_reg      *((volatile uint8*)0x59)


#endif /* DRIVERS_MAIN_REPO_NASR5_REPO_SRC_MCAL_TIMER_TIMER_REG_H_ */
