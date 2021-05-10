/*
 * TIMER2.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TIMER2_TIMER2_H_
#define SRC_MCAL_TIMER2_TIMER2_H_

void TIM2_Initialize(void);

void TIM2_CompIntEnable(void);
void TIM2_CompIntDisable(void);

void TIM2_OverFlowIntEnable(void);
void TIM2_OverFlowIntDisable(void);

void TIM2_SetCompValue(uint8 Value);
void TIM2_SetTimerValue(uint8 Value);

void TIM2_OverFlowCallBack(void (*Copy_ptr) (void));
void TIM2_CompareCallBack(void (*Copy_ptr) (void));

#endif /* SRC_MCAL_TIMER2_TIMER2_H_ */
