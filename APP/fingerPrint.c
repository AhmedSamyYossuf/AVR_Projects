/*
 * fingerPrint.c
 *
 *  Created on: Jan 24, 2021
 *      Author: ahmed
 */




//#include <avr/io.h>
#include "../LIB/std_types.h"
#include "../LIB/Bit_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/ADC/ADC_reg.h"

#include "../HAL/LCD/LCD.h"

#include <stdlib.h>
#include <util/delay.h>


void finger_APP(){

      DIO_SetPortDirection(PORTA,DIO_Output);
      DIO_SetPortDirection(PORTB,DIO_Output);

      UART_Initialize();
      LCD_Initialize();

      _delay_ms(1000);  //plenty of delay for modules initialization
      uint8 result_collect_finger , result_search;
      do{
    	  LCD_WriteString("Pleas put finger",0,0);
    	  _delay_ms(1000);
    	  result_collect_finger = collect_finger_image();
      }while(result_collect_finger != 0);
      generate_character_file(1);
      do{
    	  LCD_WriteString("                  ",0,0);
    	  LCD_WriteString("Pleas put finger 2",0,0);
    	  _delay_ms(1000);
    	  result_collect_finger = collect_finger_image();
      }while(result_collect_finger != 0);
      generate_character_file(2);

      generate_template();
      store_template(0);
      while(1){
          do{
        	  LCD_WriteString("Pleas put finger to enroll   ",0,0);
        	  _delay_ms(1000);
        	  result_collect_finger = collect_finger_image();
          }while(result_collect_finger != 0);
          generate_character_file(1);
    	  result_search = search_of_two_finger_templates();
    	  if(result_search == 0){
    		  LCD_WriteString("found the matching finer     ",0,0);
    		  _delay_ms(3000);
    	  }
    	  else if(result_search == 1){
    		  LCD_WriteString("error when receiving package ",0,0);
    		  _delay_ms(3000);
    	  }
    	  else if(result_search == 9){
    		  LCD_WriteString("No matching in the library   ",0,0);
    		  _delay_ms(3000);
    	  }
      }
}
