/*
 * SevenSeg_Lab.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Amr
 */
#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"
#include <util/delay.h>

void SevenSeg_POV(void)
{
	/** Initialization **/
	BCDSevenSegment_Initialization();

	uint8 SevenSegOne, SevenSegTwo;
	uint8 i;

	uint8 Value = 57;

	while(1)
	{
		if (Value < 100){

			for(i=0;i<50;i++)
			{
				/* 53 / 10 = 5 */
				SevenSegOne = Value / 10;
				/* 53 % 10 = 3*/
				SevenSegTwo = Value % 10;

				/* Disable seven segment 1 */
				BCDSevenSegment_Disable1();
				/* Disable seven segment 2 */
				BCDSevenSegment_Disable2();

				BCDSevenSegment_WriteNumber(SevenSegOne);

				/* Enable seven segment 1 */
				BCDSevenSegment_Enable1();

				/* 10 mSec delay */
				_delay_ms(10);

				/* Disable seven segment 1 */
				BCDSevenSegment_Disable1();

				BCDSevenSegment_WriteNumber(SevenSegTwo);

				/* Enable seven segment 2 */
				BCDSevenSegment_Enable2();

				/* 10 mSec delay */
				_delay_ms(10);
			}
		}
	}

}
