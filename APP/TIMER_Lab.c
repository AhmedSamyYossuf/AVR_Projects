/*
 * TIMER_Lab.c
 *
 *  Created on: Sep 6, 2019
 *      Author: Amr
 */

#include "../LIB/std_types.h"
#include "../LIB/Bit_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/TIMER0/TIMER0.h"


volatile uint8 counter = 0;

void TIMER_OV_ISR(void)
{
	/* Increment counter to keep track of
	 * number of timer overflows */
	counter++;
}

void TIMER_Lab(void)
{
	/* Initialization */
	DIO_SetPinDirection(PORTD, Pin3, DIO_Output);

	TIM0_Initialize();

	/* Select function to execute in case of Overflow interrupt */
	TIM0_OverFlowCallBack(TIMER_OV_ISR);

	/* Interrupt enable */
	TIM0_OverFlowIntEnable();
	GIE_Enable();

	while(1)
	{
		/* 61 overflows = 1 second, when prescaler = 1024 and system clock is 16 MHz */
		if(counter == 61)
		{
			/* Toggle led state */
			DIO_TogglePin(PORTD, Pin3);
			/* Reset counter */
			counter = 0;
		}
	}
}
