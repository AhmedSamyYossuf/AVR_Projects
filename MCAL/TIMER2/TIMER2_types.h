/*
 * TIMER2_types.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TIMER2_TIMER2_TYPES_H_
#define SRC_MCAL_TIMER2_TIMER2_TYPES_H_

/*Clearing*/
#define Clear_reg                  	0b00000000

/*Modes For Signal */
#define Normal_Mode                	0b00000000
#define PWM_PhaseCorrect           	0b01000000
#define CTC                        	0b00001000
#define Fast_PWM                   	0b01001000
/************************************************/
/* Compare Output Mode */
#define OC2_DISCONNECTED		   	0b00000000
#define OC2_TOGGLE_ON_COMPARE_MATCH	0b00010000
#define OC2_CLEAR_ON_COMPARE_MATCH	0b00100000
#define OC2_SET_ON_COMPARE_MATCH	0b00110000
 /************************************************/
/*Prescaler Modes*/
#define No_Clock_Stop              	0
#define ClkIo                      	1
#define Clk_8                      	2
#define Clk_32                     	3
#define Clk_64                    	4
#define Clk_128                   	5
#define Clk_256        				6
#define Clk_1024         			7
/**********************************************/

#endif /* SRC_MCAL_TIMER2_TIMER2_TYPES_H_ */
