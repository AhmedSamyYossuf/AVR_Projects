/*
 * EXTI_Lab.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Amr
 */

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/GIE/GIE.h"
#include <util/delay.h>

void EXTI_ISR(void);

void EXTI_Lab(void)
{
	/* Initialization */
	/* Button 2 pin */
	DIO_SetPinDirection(PORTD,Pin2,DIO_Input);
	/* Buzzer pin */
	DIO_SetPinDirection(PORTA,Pin3,DIO_Output);
	/* Led2 pin */
	DIO_SetPinDirection(PORTD,Pin3,DIO_Output);

	EXTI_Initialization();
	EXTI_SetCallback(EXTI_ISR);

	/* Enable PIE for INT0 */
	EXTI_EnableInt0();
	/* Enable global interrupt */
	GIE_Enable();



	while(1)
	{
		/* Toggle led */
		DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
		_delay_ms(500);
		DIO_SetPinValue(PORTD,Pin3,STD_LOW);
		_delay_ms(500);
	}
}

void EXTI_ISR(void)
{
	/* Turn on buzzer */
	DIO_SetPinValue(PORTA,Pin3,STD_HIGH);
	/* delay */
	_delay_ms(500);
	/* Turn off buzzer */
	DIO_SetPinValue(PORTA,Pin3,STD_LOW);
}
