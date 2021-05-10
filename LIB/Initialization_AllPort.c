/*
 * Initialization_AllPort.c
 *
 *  Created on: Aug 18, 2019
 *      Author: ahmed
 */
#include "../MCAL/DIO/DIO.h"
#include "std_types.h"
void Initialization_AllPort(void){
	DIO_SetPortDirection(PORTA , DIO_Output );
	DIO_SetPortDirection(PORTB , DIO_Output );
	DIO_SetPortDirection(PORTC , DIO_Output );
	DIO_SetPortDirection(PORTD , DIO_Output );

	DIO_SetPortValue(PORTA , STD_LOW );
	DIO_SetPortValue(PORTB , STD_LOW );
	DIO_SetPortValue(PORTC , STD_LOW );
	DIO_SetPortValue(PORTD , STD_LOW );
}
