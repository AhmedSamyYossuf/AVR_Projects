/*
 * EXTI.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_EXTI_EXTI_H_
#define SRC_MCAL_EXTI_EXTI_H_

/* Function to initialize external interrupt */
void EXTI_Initialization(void);

/* Function to enable EXTI 0 ISR */
void EXTI_EnableInt0(void);

/* Function to disable EXTI 0 ISR */
void EXTI_DisableInt0(void);

/* Call Back Function  */
void EXTI_SetCallback( void (*CopyFuncPtr) (void) );

#endif /* SRC_MCAL_EXTI_EXTI_H_ */
