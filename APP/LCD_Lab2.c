/*
 * LCD_Lab2.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"


void LCD_Lab2(void)
{
	/* Initialization */
	/* Set direction of LCD pins to be output */
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);

	/* Start initialization sequence for LCD */
	LCD_Initialize();

	LCD_WriteString("Ali", 1, 4);

}

