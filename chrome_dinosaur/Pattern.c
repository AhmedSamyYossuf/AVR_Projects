/*
 * Pattern.c
 *
 *  Created on: Aug 25, 2019
 *      Author: ahmed
 */
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCD_LCD/LCD.h"
#include <avr/delay.h>
#include "Pattern.h"

void boy_tree(void)
{
	LCD_StoreCustomChr(pattern1   , 0); //boy run
	LCD_StoreCustomChr(pattern2   , 1); //boy run
	LCD_StoreCustomChr(pattern6   , 2); //tree
	LCD_StoreCustomChr(pattern7   , 3); //tree
	LCD_StoreCustomChr(pattern8   , 4); //tree
	LCD_StoreCustomChr(pattern9   , 5); //tree
	LCD_StoreCustomChr(pattern10  , 6); //tree
	LCD_StoreCustomChr(pattern11  , 7); // clear one square
}


/*
void tree (void)
{
	LCD_StoreCustomChr(pattern4  , 0);
	LCD_StoreCustomChr(pattern5  , 1);
	LCD_StoreCustomChr(pattern6  , 2);
	LCD_StoreCustomChr(pattern7  , 3);
	LCD_StoreCustomChr(pattern8  , 4);
	LCD_StoreCustomChr(pattern9  , 5);
	LCD_StoreCustomChr(pattern10 , 6);
	LCD_StoreCustomChr(pattern11 , 7); // clear one square

}

*/


void boy (void)
{
/*
	LCD_StoreCustomChr(pattern0  , 0);
	LCD_StoreCustomChr(pattern1  , 1);
	LCD_StoreCustomChr(pattern2  , 2);
	LCD_StoreCustomChr(pattern3  , 3); //jump
	LCD_StoreCustomChr(pattern11 , 4); // clear one square
*/
	LCD_DisplayCustomChr(0 , 1 , 0 );
	_delay_ms(70);
	LCD_DisplayCustomChr(1 , 1 , 0 );
	_delay_ms(70);
	/*LCD_DisplayCustomChr(2, 1 , 0 );
	_delay_ms(50);
	*/
}


/*
void move_tree(void)
{
	// to move the tree
	while(1)
		{
			LCD_WriteCmd(0x01);
			LCD_DisplayCustomChr(0 ,row ,Col_tree);
			_delay_ms(100);
			LCD_WriteCmd(0x01);
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
				LCD_DisplayCustomChr(2 ,row ,Col_tree);
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				LCD_DisplayCustomChr(3 ,row ,Col_tree);
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				LCD_DisplayCustomChr(4 ,row ,Col_tree);
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				LCD_DisplayCustomChr(5 ,row ,Col_tree);
				if(Col_tree != 0 )
				{
					LCD_DisplayCustomChr(0 ,row ,(Col_tree-1));
				}
				_delay_ms(100);
				LCD_WriteCmd(0x01);
				LCD_DisplayCustomChr(6 ,row ,Col_tree);
				if(Col_tree != 0 )
				{
					LCD_DisplayCustomChr(1 ,row ,(Col_tree-1));
				}
				_delay_ms(100);
				if (Col_tree == 0 )
				{
					Col_tree = 16 ;
				}
			}
		}

}
*/

/*
void move_boy_jump(void)
{
	while (1)
	{
		LCD_WriteCmd(0x01);
		LCD_DisplayCustomChr(0 , 1 , 0 );
		while (1)
		{
			_delay_ms(200);
			LCD_WriteCmd(0x01);
			LCD_DisplayCustomChr(1 , 1 , 0 );
			_delay_ms(200);
			LCD_WriteCmd(0x01);
			LCD_DisplayCustomChr(2, 1 , 0 );
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
}
*/
