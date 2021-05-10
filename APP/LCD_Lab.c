/*
 * LCD_Lab.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Amr
 */

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"


void LCD_Lab(void)
{
	/* Initialization */
	/* Set direction of LCD pins to be output */
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);

	/* Start initialization sequence for LCD */
	LCD_Initialize();

	LCD_WriteData('H');
	LCD_WriteData('e');
	LCD_WriteData('l');
	LCD_WriteData('l');
	LCD_WriteData('o');

	LCD_WriteData(' ');

	LCD_WriteData('W');
	LCD_WriteData('o');
	LCD_WriteData('r');
	LCD_WriteData('l');
	LCD_WriteData('d');
}
