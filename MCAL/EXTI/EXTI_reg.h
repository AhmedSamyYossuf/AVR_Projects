/*
 * EXTI_reg.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_EXTI_EXTI_REG_H_
#define SRC_MCAL_EXTI_EXTI_REG_H_

/* Registers related to External Interrupt */
#define MCUCR_Reg	(*( (volatile uint8*) 0x55) )
#define MCUCSR_Reg	(*( (volatile uint8*) 0x54) )
#define GICR_Reg	(*( (volatile uint8*) 0x5B) )
#define GIFR_Reg	(*( (volatile uint8*) 0x5A) )

#endif /* SRC_MCAL_EXTI_EXTI_REG_H_ */
