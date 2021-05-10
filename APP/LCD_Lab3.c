/*
 * LCD_Lab3.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */
#include "../LIB/std_types.h"

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"


void LCD_Lab3(void)
{
	/* Initialization */
	/* Set direction of LCD pins to be output */
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);

	/* Start initialization sequence for LCD */
	LCD_Initialize();

	/* pattern for 7arf el alif */
	uint8 pattern[8] = {0x0E, 0x08, 0x1E, 0x00, 0x04, 0x04, 0x04, 0x04};
	LCD_StoreCustomChr(pattern, 0);
	LCD_DisplayCustomChr(0,0,5);

}

