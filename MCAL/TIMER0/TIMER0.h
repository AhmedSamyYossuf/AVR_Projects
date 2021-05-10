/*
 * TIMER.h
 *
 *  Created on: Sep 2, 2019
 *      Author: Ahmed
 */

#ifndef DRIVERS_MAIN_REPO_NASR5_REPO_SRC_MCAL_TIMER_TIMER_H_
#define DRIVERS_MAIN_REPO_NASR5_REPO_SRC_MCAL_TIMER_TIMER_H_

void TIM0_Initialize(void);

void TIM0_CompIntEnable(void);
void TIM0_CompIntDisable(void);

void TIM0_OverFlowIntEnable(void);
void TIM0_OverFlowIntDisable(void);

void TIM0_SetCompValue(uint8 Value);
void TIM0_SetTimerValue(uint8 Value);

void TIM0_OverFlowCallBack(void (*Copy_ptr) (void));
void TIM0_CompareCallBack(void (*Copy_ptr) (void));

#endif /* DRIVERS_MAIN_REPO_NASR5_REPO_SRC_MCAL_TIMER_TIMER_H_ */
