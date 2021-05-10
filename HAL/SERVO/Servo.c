/*
 * Servo.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/GIE/GIE.h"
#include "../../MCAL/TIMER2/TIMER2.h"

uint8 Ton_Steps = 255;
uint8 Toff_Steps = 255;

#define MAX_ANGLE	180
#define MIN_ANGLE	0

#define STEPS_FOR_MIN_ANGLE		63
#define STEPS_FOR_MAX_ANGLE		250
#define	STEPS_FOR_ONE_PERIOD	250	// 2  milli second period


void TIME2_CTC_ISR(void)
{
	static uint8 Periods_Counter = 0;
	if (Periods_Counter == 0)
	{
		TIM2_SetCompValue(Toff_Steps);
		DIO_SetPinValue(PORTD, Pin7, STD_LOW);
		Periods_Counter++;
	}
	else if(Periods_Counter == 11)
	{
		TIM2_SetCompValue(Ton_Steps);
		DIO_SetPinValue(PORTD, Pin7, STD_HIGH);
		Periods_Counter = 0;
	}
	else
	{
		Periods_Counter++;
	}

}

void SERVO_Initialize(void)
{
	/* Initialization */
	TIM2_CompareCallBack(TIME2_CTC_ISR);
	TIM2_CompIntEnable();
	TIM2_Initialize();
	GIE_Enable();
}

void SERVO_setAngle(uint8 angle)
{


	Ton_Steps = ((angle - MIN_ANGLE)  *  (STEPS_FOR_MAX_ANGLE - STEPS_FOR_MIN_ANGLE) \
				/*--------------------------------------------------------------------*/
				/ (MAX_ANGLE - MIN_ANGLE) ) \

						+ STEPS_FOR_MIN_ANGLE ;

	/* steps needed for one off period (low voltage) */
	Toff_Steps = STEPS_FOR_ONE_PERIOD - (Ton_Steps / 10);

}




