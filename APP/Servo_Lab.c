/*
 * Servo_Lab.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#include "../LIB/std_types.h"
#include "../LIB/Bit_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/TIMER2/TIMER2.h"

#define T_ON		10	//NO. of overflows
#define T_TOTAL		200

volatile uint8 OV_Counter = 0;

void TIMER2_OV_ISR(void)
{
	/* Counter to keep track */
	OV_Counter++;
	/* Reset value inside timer to count 100 usec again */
	TIM2_SetTimerValue(230);
}


void Servo_Lab(void)
{
	/*Initialization*/
	DIO_SetPinDirection(PORTD, Pin7, DIO_Output);


	TIM2_OverFlowCallBack(TIMER2_OV_ISR);

	/* Initial value in timer to satisfy 100  usec overflow */
	TIM2_SetTimerValue(230);

	TIM2_Initialize();
	TIM2_OverFlowIntEnable();
	GIE_Enable();

	/* Set pin initially to high */
	DIO_SetPinValue(PORTD, Pin7, STD_HIGH);

	while(1){

		if(OV_Counter == T_ON)
		{
			/* Set pin to low */
			DIO_SetPinValue(PORTD, Pin7, STD_LOW);
		}
		else if (OV_Counter == T_TOTAL)
		{
			DIO_SetPinValue(PORTD, Pin7, STD_HIGH);
			/* Reset counter to start a new cycle */
			OV_Counter = 0;
		}
	}



}
