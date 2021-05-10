#include "../LIB/std_types.h"
#include "../LIB/Bit_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include <stdlib.h>
#include <string.h>
#include <avr/delay.h>

volatile uint8 x=0;
volatile uint8 y=0;
volatile uint8 z=0;
volatile uint8 w=0;


uint8 counter1=0;
uint8 pass[4];

uint8 array[4];

uint8 passcheck[4]={1,1,1,1};

uint8 Indicator=0;

//uint8 savedpass[4][10]={"1234"};
uint8 Col=8;
void Door_Unlock(void)
{
	DIO_SetPortDirection(PORTA, DIO_Output);
	DIO_SetPortDirection(PORTB, DIO_Output);
	DIO_SetPortDirection(PORTD, DIO_Output);

	DIO_SetPinDirection(PORTD, Pin2, DIO_Input);
	DIO_SetPinDirection(PORTB, Pin0, DIO_Input);
	DIO_SetPinDirection(PORTB, Pin4, DIO_Input);
	DIO_SetPinDirection(PORTC, Pin2, DIO_Output);

	LCD_Initialize();




	/* Logic */

	STD_levelType CurrentState1 = STD_LOW;
	STD_levelType CurrentState2 = STD_LOW;
	STD_levelType CurrentState3 = STD_LOW;
	while(1)
	{

		CurrentState1 = DIO_GetPinValue(PORTD, Pin2);
		CurrentState2 = DIO_GetPinValue(PORTB, Pin0);
		CurrentState3 = DIO_GetPinValue(PORTB, Pin4);
		LCD_WriteString("PASSWORD:",0,0);

		/*INCREMNTING AND DECREMNTING THE FIRST NUMBER IN ARRAY[0]*/
		if(CurrentState1==STD_HIGH &&(Indicator==0))
		{
			if((x>=0)&&(x<=9)&&(Col==9))
			{
				x++;
				itoa(x,array,10);
				LCD_WriteString(array,0,Col);
                _delay_ms(500);
                pass[0]=x;
	        }
			else if((y>=0)&&(y<=9)&&(Col==10))
			{
				y++;
				itoa(y,array,10);
	            LCD_WriteString(array,0,Col);
	            _delay_ms(500);
	            pass[1]=y;

            }
			else if((z>=0)&&(z<=9)&&(Col==11))
			{
				z++;
				itoa(z,array,10);
				LCD_WriteString(array,0,Col);
			    _delay_ms(500);
			    pass[2]=z;
			}
			else if((w>=0)&&(w<=9)&&(Col==12))
			{
				w++;
	            itoa(w,array,10);
				LCD_WriteString(array,0,Col);
				_delay_ms(500);
			    pass[3]=w;
            }
	    }
		else if((CurrentState2==STD_HIGH))
		{
			if((x>0)&&(Col==9))
			{
				x--;
				itoa(x,array,10);
				LCD_WriteString(array,0,Col);
				_delay_ms(500);
				pass[0]=x;
	         }
			 else if((y>0)&&(Col==10))
			 {
	         	y--;
	          	itoa(y,array,10);
	         	LCD_WriteString(array,0,Col);
	        	_delay_ms(500);
	        	pass[1]=y;
		     }
			 else if((z>0)&&(Col==11))
			 {
				z--;
				itoa(z,array,10);
				LCD_WriteString(array,0,Col);
				_delay_ms(500);
				pass[2]=z;
			 }
			 else if((w>0)&&(Col==12))
			 {
				w--;
				itoa(w,array,10);
				LCD_WriteString(array,0,Col);
				_delay_ms(500);
		      	pass[3]=w;
			 }
		}
/***************************/
/***********MOVING THE CURSOR TO THE NEXT NUMBER POSITION****/
		else if((CurrentState3==STD_HIGH))
		{
			Col++;
			if((Col>=8)&&(Col<=12))
			{
				LCD_GoToPos(0,Col);
				_delay_ms(500);
            }
			if(Col>12)
			{
				Col=8;
				Indicator=1;
				LCD_WriteString("checking",1,0);
			}

		}
	/*****************************/

		else if((CurrentState1==STD_HIGH)&&(Indicator==1))
		{
			DIO_SetPinValue(PORTA,Pin3,STD_HIGH);
		}
	}
}
