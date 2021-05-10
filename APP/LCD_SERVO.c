/*
 * LCD_SERVO.c
 *
 *  Created on: Sep 8, 2019
 *      Author: ahmed
 */


#include <avr/delay.h>
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/SERVO/SERVO.h"

void LCD_SERVO ()
{
	/*       	 Initialization	 	       */
	DIO_SetPortDirection(PORTA, DIO_Output);
	DIO_SetPortDirection(PORTB, DIO_Output);
	DIO_SetPortDirection(PORTD, DIO_Output);

	DIO_SetPinDirection(PORTD, Pin2, DIO_Input);
	DIO_SetPinDirection(PORTB, Pin0, DIO_Input);
	DIO_SetPinDirection(PORTB, Pin4, DIO_Input);

	LCD_Initialize();
	SERVO_Initialize();

	STD_levelType CurrentState_butt0  = STD_LOW;
	STD_levelType CurrentState_butt1  = STD_LOW;
	STD_levelType CurrentState_butt2  = STD_LOW;
	STD_levelType PreviousState_butt0 = STD_LOW;
	STD_levelType PreviousState_butt1 = STD_LOW;
	STD_levelType PreviousState_butt2 = STD_LOW;
	SERVO_setAngle(0);
	uint8 number = 0  ,ROW = 1 , COL = 0 , status = 0;
	uint8 pin[3] , check[3];
	//LCD_WriteData('1');

	CurrentState_butt0 = DIO_GetPinValue(PORTB, Pin0);
	CurrentState_butt1 = DIO_GetPinValue(PORTB, Pin1);
	CurrentState_butt2 = DIO_GetPinValue(PORTD, Pin2);

	while(1)
	{
		if (status == 0)
		{
			LCD_WriteString("write your new" , 0 , 0 );
			LCD_WriteString("pin code" , 1 , 0 );
			_delay_ms(3500);
			LCD_WriteCmd(0x01);
			while(1)
			{
				LCD_WriteString("new pin code is :" , 0 , 0 );
				CurrentState_butt2 = DIO_GetPinValue(PORTD, Pin2);
				CurrentState_butt1 = DIO_GetPinValue(PORTB, Pin4);
				CurrentState_butt0 = DIO_GetPinValue(PORTB, Pin0);
				if(STD_HIGH == CurrentState_butt2 && STD_LOW == PreviousState_butt2)
				{
					if (number < 9 )
					{
						number++;
					}
					else if (number == 9 )
					{
						number = 0 ;
					}
				}
				else if (STD_HIGH == CurrentState_butt1 && STD_LOW == PreviousState_butt1)
				{
					if (number > 0 )
					{
						number--;
					}
					else if (number == 0 )
					{
						number = 9 ;
					}
				}
				else if (STD_HIGH == CurrentState_butt0 && STD_LOW == PreviousState_butt0)
				{
					pin[COL] = number ;
					COL++;
					number = 0 ;
					if (COL > 2)
					{
						status++;
						LCD_WriteCmd(0x01);
						break;
					}
				}

				switch (number)
				{
					case 0 : LCD_WriteString("0" , ROW , COL );  break;
					case 1 : LCD_WriteString("1" , ROW , COL );  break;
					case 2 : LCD_WriteString("2" , ROW , COL );  break;
					case 3 : LCD_WriteString("3" , ROW , COL );  break;
					case 4 : LCD_WriteString("4" , ROW , COL );  break;
					case 5 : LCD_WriteString("5" , ROW , COL );  break;
					case 6 : LCD_WriteString("6" , ROW , COL );  break;
					case 7 : LCD_WriteString("7" , ROW , COL );  break;
					case 8 : LCD_WriteString("8" , ROW , COL );  break;
					case 9 : LCD_WriteString("9" , ROW , COL );  break;
				}
				PreviousState_butt0 = CurrentState_butt0 ;
				PreviousState_butt1 = CurrentState_butt1 ;
				PreviousState_butt2 = CurrentState_butt2 ;
			}


		}
		else if (status == 1)
		{
			COL = 0 ;
			LCD_WriteString("please enter your" , 0 , 0 );
			LCD_WriteString("pin code" , 1 , 0 );
			_delay_ms(3500);
			LCD_WriteCmd(0x01);
			while(1)
			{
				LCD_WriteString("pin code is :" , 0 , 0 );
				CurrentState_butt2 = DIO_GetPinValue(PORTD, Pin2);
				CurrentState_butt1 = DIO_GetPinValue(PORTB, Pin4);
				CurrentState_butt0 = DIO_GetPinValue(PORTB, Pin0);
				if(STD_HIGH == CurrentState_butt2 && STD_LOW == PreviousState_butt2)
				{
					if (number < 9 )
					{
						number++;
					}
					else if (number == 9 )
					{
						number = 0 ;
					}
				}
				else if (STD_HIGH == CurrentState_butt1 && STD_LOW == PreviousState_butt1)
				{
					if (number > 0 )
					{
						number--;
					}
					else if (number == 0 )
					{
						number = 9 ;
					}
				}
				else if (STD_HIGH == CurrentState_butt0 && STD_LOW == PreviousState_butt0)
				{
					check[COL] = number ;
					COL++;
					number = 0 ;
					if (COL > 2)
					{
						status++;
						LCD_WriteCmd(0x01);
						break;
					}
				}

				switch (number)
				{
					case 0 : LCD_WriteString("0" , ROW , COL );  break;
					case 1 : LCD_WriteString("1" , ROW , COL );  break;
					case 2 : LCD_WriteString("2" , ROW , COL );  break;
					case 3 : LCD_WriteString("3" , ROW , COL );  break;
					case 4 : LCD_WriteString("4" , ROW , COL );  break;
					case 5 : LCD_WriteString("5" , ROW , COL );  break;
					case 6 : LCD_WriteString("6" , ROW , COL );  break;
					case 7 : LCD_WriteString("7" , ROW , COL );  break;
					case 8 : LCD_WriteString("8" , ROW , COL );  break;
					case 9 : LCD_WriteString("9" , ROW , COL );  break;
				}
				PreviousState_butt0 = CurrentState_butt0 ;
				PreviousState_butt1 = CurrentState_butt1 ;
				PreviousState_butt2 = CurrentState_butt2 ;
			}
		}
		else if (status == 2)
		{
			for (int i = 0 ; i < 3 ; i++)
			{
				if(pin[i] == check[i])
				{
					if (i == 2)
					{
						LCD_WriteString("pin code correct" , 0 , 0 );
						for (int x = 0 ; x <=180 ; x++)
						{
						SERVO_setAngle(x);
						_delay_ms(10);
						}
						status++;
					}
				}
				else
				{
					LCD_WriteString("pin code wrong" , 0 , 0 );
					SERVO_setAngle(0);
					break;
					status++;
				}
			}

		}
	}

}
