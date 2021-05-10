
#include "../MCAL/DIO/DIO_types.h"
#include "../LIB/std_types.h"
#include "avr/delay.h"

void ass1(void){
	Initialization_AllPort();
	BCDSevenSegment_Initialization();
	int x=0 ;
	STD_levelType CurrentState_butt0  = STD_LOW;
	STD_levelType CurrentState_butt1  = STD_LOW;
	STD_levelType CurrentState_butt2  = STD_LOW;
	STD_levelType PreviousState_butt0 = STD_LOW;
	STD_levelType PreviousState_butt1 = STD_LOW;
	STD_levelType PreviousState_butt2 = STD_LOW;


	while(1)
		{
			CurrentState_butt0=DIO_GetPinValue(PORTB, Pin0);
			CurrentState_butt1=DIO_GetPinValue(PORTB, Pin4);
			CurrentState_butt2=DIO_GetPinValue(PORTD, Pin2);

			 //if press on button 0
			if(STD_HIGH == CurrentState_butt0 )
			{
				_delay_ms(100);
				CurrentState_butt0 = STD_LOW;
				while(1){
					CurrentState_butt0=DIO_GetPinValue(PORTB, Pin0);
					CurrentState_butt1=DIO_GetPinValue(PORTB, Pin4);
					CurrentState_butt2=DIO_GetPinValue(PORTD, Pin2);

					if(STD_HIGH == CurrentState_butt0 && STD_LOW == PreviousState_butt0){
						while(DIO_GetPinValue(PORTB, Pin0)){
							if (x<99){
								x++;
							}else {
								x= 0 ;
							}
							BCDSevenSegment_WriteNumber(x , .5);
						}
					}
					else if(STD_HIGH == CurrentState_butt1 && STD_LOW == PreviousState_butt1){
						if (x<99){
							x++;
						}else {
							x= 0 ;
						}
						while(DIO_GetPinValue(PORTB, Pin4)){
							BCDSevenSegment_WriteNumber( x , .15);
						}
					}
					else if(STD_HIGH == CurrentState_butt2 && STD_LOW == PreviousState_butt2)
					{
						if (x>0){
							x--;
						}else {
							x= 99 ;
						}
						while(DIO_GetPinValue(PORTD, Pin2)){
							BCDSevenSegment_WriteNumber( x , .15);
						}
					}else{
						while(DIO_GetPinValue(PORTD, Pin2) == 0 && DIO_GetPinValue(PORTB, Pin0)==0 &&DIO_GetPinValue(PORTB, Pin4)==0 ){

							BCDSevenSegment_WriteNumber( x , 0);

						}
					}
					PreviousState_butt0 = CurrentState_butt0 ;
					PreviousState_butt1 = CurrentState_butt1 ;
					PreviousState_butt2 = CurrentState_butt2 ;
				}
			}
			 //if press on button 1
			else if(STD_HIGH == CurrentState_butt1)
			{

				while(1){
					for(x = 60 ; x >= 0 ; x--){
						BCDSevenSegment_WriteNumber( x , .2);
						DIO_SetPinValue(PORTD , Pin3 , STD_HIGH);
						DIO_SetPinValue(PORTC , Pin7 , STD_LOW);
						DIO_SetPinValue(PORTC , Pin2 , STD_LOW);
					}
					for(x = 5 ; x >= 0 ; x--){
						BCDSevenSegment_WriteNumber( x , .2);
						DIO_SetPinValue(PORTD , Pin3 , STD_LOW);
						DIO_SetPinValue(PORTC , Pin7 , STD_HIGH);
						DIO_SetPinValue(PORTC , Pin2 , STD_LOW);
					}
					for(x = 30 ; x >= 0 ; x--){
						BCDSevenSegment_WriteNumber( x , .2);
						DIO_SetPinValue(PORTD , Pin3 , STD_LOW);
						DIO_SetPinValue(PORTC , Pin7 , STD_LOW);
						DIO_SetPinValue(PORTC , Pin2 , STD_HIGH);
					}
				}

			}

		}
}

