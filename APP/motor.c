/*
 * motor.c
 *
 *  Created on: Sep 22, 2019
 *      Author: ahmed
 */

#include "../LIB/std_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/UART/UART.h"

void test_bluetooth()
{
	DIO_SetPinDirection(PORTD , Pin3 , DIO_Output);
	DIO_SetPinDirection(PORTC , Pin2 , DIO_Output);
	DIO_SetPinDirection(PORTC , Pin7 , DIO_Output);
	DIO_SetPinDirection(PORTC , Pin2 , DIO_Output);
	DIO_SetPinDirection(PORTC , Pin3 , DIO_Output);//A1
	DIO_SetPinDirection(PORTC , Pin4 , DIO_Output);//A2
	DIO_SetPinDirection(PORTC , Pin5 , DIO_Output);//A3
	DIO_SetPinDirection(PORTC , Pin6 , DIO_Output);//A4
	UART_Initialize();
	while(1)
	{
		uint8 Result = UART_GetChar();
		if (Result == '2' || Result == 'D')
		{

			DIO_SetPinValue(PORTC , Pin3 , STD_HIGH);
			DIO_SetPinValue(PORTC , Pin4 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin5 , STD_HIGH);
			DIO_SetPinValue(PORTC , Pin6 , STD_LOW);

		}
		else if (Result == '3' || Result == 'U')
		{
			DIO_SetPinValue(PORTC , Pin3 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin4 , STD_HIGH);
			DIO_SetPinValue(PORTC , Pin5 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin6 , STD_HIGH);
		}
		else if (Result == '4' || Result == 'R')
		{
			DIO_SetPinValue(PORTC , Pin3 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin4 , STD_HIGH);
			DIO_SetPinValue(PORTC , Pin5 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin6 , STD_LOW);
		}
		else if (Result == '5' || Result == 'L')
		{
			DIO_SetPinValue(PORTC , Pin3 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin4 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin5 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin6 , STD_HIGH);
		}
		else if (Result == '6' || Result == 'S')
		{
			DIO_SetPinValue(PORTC , Pin3 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin4 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin5 , STD_LOW);
			DIO_SetPinValue(PORTC , Pin6 , STD_LOW);
		}
	}
}

void test_bluetooth2()
{
	DIO_SetPortDirection(PORTC,DIO_Output);
	UART_Initialize();
	while(1)
			{
				uint8 Result = UART_GetChar();
				if (Result == 'h' || Result == 'H')
				{
					DIO_SetPortValue(PORTC,0xFF);
				}
				else if (Result == 'l' || Result == 'L')
				{
					DIO_SetPortValue(PORTC,0x00);
				}
			}
}
