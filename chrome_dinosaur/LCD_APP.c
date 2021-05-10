/*
 * LCD_APP.c
 *
 *  Created on: Aug 25, 2019
 *      Author: ahmed
 */
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCD_LCD/LCD.h"
#include <avr/delay.h>


void jump()
{
	BCDSevenSegment_Initialization();
	DIO_SetPortDirection(PORTA , DIO_Output);
	DIO_SetPortDirection(PORTB , DIO_Output);
	LCD_Initialize();
	uint8 row = 1 ;
	uint8 count = 0 ;
	uint8 chance = 3 ;
	//uint8 Col_boy = 0 ;
	uint8 Col_tree = 15 ;
	STD_levelType CurrentState = STD_LOW;
	STD_levelType PreviousState = STD_LOW;


	while(1)
	{
		BCDSevenSegment_WriteNumber(chance , 0);
		boy_tree();
		LCD_WriteCmd(0x01);
		boy();
		while(1)
		{
			CurrentState = DIO_GetPinValue(PORTD, Pin2);
			if (count == 0)
			{
				count++;
			}
			else
			{
				LCD_DisplayCustomChr(7 ,row ,Col_tree);
				Col_tree--;
				if (Col_tree == 0 && CurrentState == 0)
				{
					chance--;
					BCDSevenSegment_WriteNumber(chance , 0);
					if (chance < 1  )
					{
						LCD_WriteCmd(0x01);
						while(DIO_GetPinValue(PORTB , Pin4) == 0)
						{

							LCD_WriteString("game over press b2 to play again", 0 , 0);
						}
						chance = 3 ;
						BCDSevenSegment_WriteNumber(chance , 0);
						LCD_WriteCmd(0x01);
					}
					else
					{
						while(DIO_GetPinValue(PORTB , Pin4) == 0)
						{
							LCD_WriteCmd(0x01);
							LCD_WriteString("press b2 to ", 0 , 2);
							LCD_WriteString("Continue " , 1 , 3);
							_delay_ms(50);
							LCD_DisplayCustomChr(6 ,row ,(Col_tree + 1));
							LCD_DisplayCustomChr(1, 1 , 0 );
							_delay_ms(50);
						}
					LCD_WriteCmd(0x01);
					}
				}
			}
			if (STD_HIGH == CurrentState   && STD_LOW == PreviousState)
			{
				//560 ms

				LCD_DisplayCustomChr(7,1,0);
				LCD_DisplayCustomChr(1, 0 , 0 );
				LCD_DisplayCustomChr(2 ,row ,Col_tree);
				_delay_ms(140);
				LCD_DisplayCustomChr(3 ,row ,Col_tree);
				_delay_ms(140);
				LCD_DisplayCustomChr(4 ,row ,Col_tree);
				_delay_ms(140);
				LCD_DisplayCustomChr(5 ,row ,Col_tree);
				_delay_ms(140);
				LCD_DisplayCustomChr(6 ,row ,Col_tree);
				_delay_ms(140);
				LCD_DisplayCustomChr(7,0,0);
			}

			else
			{
				LCD_DisplayCustomChr(2 ,row ,Col_tree);
				boy();
				LCD_DisplayCustomChr(3 ,row ,Col_tree);
				boy();
				LCD_DisplayCustomChr(4 ,row ,Col_tree);
				boy();
				LCD_DisplayCustomChr(5 ,row ,Col_tree);
				boy();
				LCD_DisplayCustomChr(6 ,row ,Col_tree);
				boy();
				if (STD_LOW == CurrentState && STD_HIGH == PreviousState )
				{
					PreviousState = STD_LOW;
				}
			}
			PreviousState = CurrentState ;
			if (Col_tree == 0 )
			{
				LCD_DisplayCustomChr(7 ,row ,Col_tree);
				Col_tree = 16 ;
			}

		}
	}
}






























	// to move the tree
	/*
	while(1)
		{
			LCD_WriteCmd(0x01);
			//tree
			tree();
			LCD_DisplayCustomChr(0 ,row ,Col_tree);
			//boy
			boy();
			LCD_DisplayCustomChr(0 , 1 , 0 );
			_delay_ms(100);
			LCD_WriteCmd(0x01);
			//boy
			LCD_DisplayCustomChr(1 , 1 , 0 );
			//tree
			tree();
			LCD_DisplayCustomChr(1 ,row ,Col_tree);
			_delay_ms(100);
			while(1)
			{
				if (count == 0)
				{
					count++;
				}
				else
				{
					Col_tree--;
				}
				LCD_WriteCmd(0x01);
				//tree
				LCD_DisplayCustomChr(2 ,row ,Col_tree);
				//boy
				boy();
				LCD_DisplayCustomChr(2 , 1 , 0 );
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				//boy
				LCD_DisplayCustomChr(2, 1 , 0 );
				//tree
				tree();
				LCD_DisplayCustomChr(3 ,row ,Col_tree);
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				//tree
				LCD_DisplayCustomChr(4 ,row ,Col_tree);
				//boy
				boy();
				LCD_DisplayCustomChr(1 , 1 , 0 );
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				//boy
				LCD_DisplayCustomChr(2, 1 , 0 );
				//tree
				tree();
				LCD_DisplayCustomChr(5 ,row ,Col_tree);
				if(Col_tree != 0 )
				{
					LCD_DisplayCustomChr(0 ,row ,(Col_tree-1));
				}
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				//tree
				LCD_DisplayCustomChr(6 ,row ,Col_tree);
				if(Col_tree != 0 )
				{
					LCD_DisplayCustomChr(1 ,row ,(Col_tree-1));
				}
				//boy
				boy();
				LCD_DisplayCustomChr(1 , 1 , 0 );
				_delay_ms(100);
				if (Col_tree == 0 )
				{
					Col_tree = 16 ;
				}
			}
		}
*/
	// boy
/*
	while (1)
	{
		LCD_WriteCmd(0x01);
		//LCD_DisplayCustomChr(0 , 1 , 0 );
		while (1)
		{
			_delay_ms(200);
			LCD_WriteCmd(0x01);
			//LCD_DisplayCustomChr(1 , 1 , 0 );
			_delay_ms(200);
			LCD_WriteCmd(0x01);
			//LCD_DisplayCustomChr(2, 1 , 0 );
			CurrentState = DIO_GetPinValue(PORTD, Pin2);
			if (CurrentState == STD_HIGH)
			{
				LCD_WriteCmd(0x01);
				LCD_DisplayCustomChr(3, 0 , 0 );
				_delay_ms(150);
			}
			CurrentState = STD_LOW ;
		}
	}
*/

