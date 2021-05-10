/*
 * SPI_APP.c
 *
 *  Created on: Sep 25, 2019
 *      Author: ahmed
 */
#include <avr/delay.h>
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/LCD/LCD.h"

void spi_master()
{

	DIO_SetPinDirection(PORTD , Pin3 , DIO_Output);
	SPI_Initialize();
	while(1)
	{
		SPI_SendString("Ahmed Samy");

		/*if (result == 'h')
		{
			DIO_SetPinValue(PORTD , Pin3 , STD_HIGH);
		}*/
	}
}

void spi_slave()
{
	DIO_SetPortDirection(PORTA , DIO_Output);
	DIO_SetPinDirection(PORTB,Pin1,DIO_Output);
	DIO_SetPinDirection(PORTB,Pin2,DIO_Output);
	DIO_SetPinDirection(PORTB,Pin3,DIO_Output);
	LCD_Initialize();
	SPI_Initialize();
	DIO_SetPinDirection(PORTD , Pin3 , DIO_Output);
	DIO_SetPinValue(PORTD , Pin3 , STD_LOW);
	//SPI_SetSlaveData('h');
	while(1)
	{

		uint8 result = SPI_DataReceived();
		LCD_WriteData(result);
		DIO_SetPinValue(PORTD , Pin3 , STD_HIGH);

		/*if(result == 'a')
		{
			DIO_SetPinValue(PORTD , Pin3 , STD_HIGH);
			LCD_WriteData(result);
		}
		else
		{
			DIO_SetPinValue(PORTD , Pin3 , STD_HIGH);
			_delay_ms(100);
			DIO_SetPinValue(PORTD , Pin3 , STD_LOW);
			_delay_ms(100);
		}*/

	}
}

