/*
 * TIMER2_config.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TIMER2_TIMER2_CONFIG_H_
#define SRC_MCAL_TIMER2_TIMER2_CONFIG_H_

/*
 SIGNAL_MODE CHOICES:-

 Normal_Mode
 PWM_PhaseCorrect
 CTC
 Fast_PWM

 */
#define SIGNAL_MODE                     CTC

/****************************************************/

/*
 COMPARE_OUTPUT_MODE CHOICES:-

 OC2_DISCONNECTED
 OC2_TOGGLE_ON_COMPARE_MATCH
 OC2_CLEAR_ON_COMPARE_MATCH
 OC2_SET_ON_COMPARE_MATCH

 */
#define COMPARE_OUTPUT_MODE            OC2_DISCONNECTED

/****************************************************/

/*
 CLOCK_TYPES_Prescalers CHOICES :-

 No_Clock_Stop
 ClkIo
 Clk_8
 Clk_32
 Clk_64
 Clk_128
 Clk_256
 Clk_1024

 */
#define CLOCK_Prescaler                  Clk_128

#endif /* SRC_MCAL_TIMER2_TIMER2_CONFIG_H_ */
