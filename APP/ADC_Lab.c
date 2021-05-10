/*
 * ADC_Lab.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Amr
 */

/* App to read analog data from Temp_sensor/Potentiometer
 * , convert analog signal to digital
 * then output the reading on LCD */

#include "../LIB/std_types.h"
#include "../LIB/Bit_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/ADC/ADC_reg.h"

#include "../HAL/LCD/LCD.h"

#include <stdlib.h>
#include <util/delay.h>

/* Flag (variable) to indicate that the ADC conversion operation
 * has finished.
 * The variable is declared as 'volatile' to instruct the compiler
 * to not optimize it */
volatile uint8 ADC_Complete = 0;

void ADC_ConvCompleteISR(void)
{
	/* Raise a flag to indicate that the ADC
	 * conversion has finished */
	ADC_Complete = 1;
}

void ADC_Lab(void)
{
	uint16 DigitalValue=0;
	uint8 string_array[8];
	uint8 degreepattern[8]=  {0x1C, 0x14, 0x1C, 0x03, 0x04, 0x04, 0x04, 0x03};

    /** Initialization **/
    /* set direction of temperature sensor pin */
	DIO_SetPinDirection(PORTA,Pin1,DIO_Input);
    /* set direction of LCD pins */
	DIO_SetPinDirection(PORTA,Pin0,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin2,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin3,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin4,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin5,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin6,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin7,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);


	ADC_SetCallBack(ADC_ConvCompleteISR);
	ADC_Initialize();
	LCD_Initialize();
	ADC_EnableInt();
	GIE_Enable();

	LCD_StoreCustomChr(degreepattern,0);

    /* Start analog to digital conversion for input on channel 1 */
	ADC_StartConversion(ADC_Channel_1);

	while(1){

		if(ADC_Complete==1)
		{
			/** ADC conversion was finished **/
			/* Lower the ADC_Complete flag */
			ADC_Complete=0;

			/* Get the digital value resulted from the ADC operation */
			DigitalValue=ADC_GetResult();
			/* Convert the digital value back to temperature (milli voltage / 10) */
			uint8 temp = ((DigitalValue*500)/1024);

			/* Convert decimal number to be string */
			itoa(temp,string_array,10);

			LCD_WriteString(string_array,0,5);
			LCD_DisplayCustomChr(0,0,8);
		}
	}

}


