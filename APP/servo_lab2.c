/*
 * servo_lab2.c
 *
 *  Created on: Sep 7, 2019
 *      Author: ahmed
 */
#include <avr/delay.h>
#include "../HAL/SERVO/SERVO.h"

void servo22()
{
	SERVO_Initialize();
	int x = 0 , status = 0;
	while(1)
	{
		if ((x >= 0) && (x < 180) && (status == 0))
		{
			SERVO_setAngle(x);
			x++;
			_delay_ms(30);
			if (x == 180)
			{
				status = 1 ;
			}
		}
		else if ((x <= 180) && (x > 0) && (status == 1) )
		{
			SERVO_setAngle(x);
			x--;
			_delay_ms(30);
			if (x == 0)
			{
				status = 0;
			}

		}
	}

}
