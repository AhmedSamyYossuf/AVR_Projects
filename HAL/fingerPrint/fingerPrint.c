/*
 * fingerPrint.c
 *
 *  Created on: Jan 24, 2021
 *      Author: ahmed
 */

#include <avr/io.h>
#include "fingerPrint.h"
//#include "../LCD/LCD.h"





void Communicate_link(void){

/***************** Communicate link *********************/

/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0004 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x04);
/**** Send Instruction code 0x17 *****/
	UART_SendChar(0x17);
/**** Send Control code 0x00 *****/
	UART_SendChar(0x00);
/**** Send Checksum 0x001C *****/
	UART_SendChar(0x00);
	UART_SendChar(0x1C);

/** Receive Acknowledge package format ****/
	uint8 k = 1 , s ;
	for(uint8 i = 0 ; i< 12 ; i++){
		k = UART_GetChar() ;
		if(i == 11 ){
			itoa(k,s,16);
			LCD_WriteString(s,0,1);
			LCD_WriteString("ahmed samy",1,1);
		}

	}
}

void Read_valid_template_number(void){

/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0003 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x03);
/**** Send Instruction code 0x1D *****/
	UART_SendChar(0x1D);
/**** Send Checksum 0x0021 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x21);

/** Receive Acknowledge package format ****/
	uint8 k , s[2] ;
	for(uint8 i = 0 ; i< 14 ; i++){
		k = UART_GetChar() ;

		if( i == 13 ){
			itoa(k,s,16);
			LCD_WriteString(s,0,3);
			LCD_WriteString("samy",1,6);
		}
	}
}

uint8 collect_finger_image(void){
/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0003 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x03);
/**** Send Instruction code 0x01 *****/
	UART_SendChar(0x01);
/**** Send Checksum 0x0005 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x05);

/** Receive Acknowledge package format ****/
	uint8 k , result ;
	for(uint8 i = 0 ; i< 12 ; i++){
		k = UART_GetChar() ;
		if( i == 9 ){
			result = k;
		}
	}
	return result ;
}

void generate_character_file(uint8 Buffer_num){
	_delay_ms(1000);
	uint8 checksum ;
	if(Buffer_num == 1){
		checksum = 0x0008 ;
	}
	else {
		checksum = 0x0009 ;
	}
/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0004 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x04);
/**** Send Instruction code 0x02 *****/
	UART_SendChar(0x02);
/**** Send Buffer number (0x01 or 0x02) *****/
	UART_SendChar(Buffer_num);
/**** Send Checksum 0x0008 for Buffer = 1  0x0009 for Buffer = 2*****/
	UART_SendChar(0x00);
	UART_SendChar(checksum);

/** Receive Acknowledge package format ****/
	uint8 k , s[2] ;
	for(uint8 i = 0 ; i< 12 ; i++){
		k = UART_GetChar() ;
		/*
		if( i == 9 ){
			itoa(k,s,16);
			LCD_WriteString(s,0,3);
			if(k == 0x00){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("generate character file complete",0,0);
			}
			else if(k == 0x01){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("error when receiving package;",0,0);
			}
			else if(k == 0x06){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("fail due to disorderly image",0,0);
			}
			else if(k == 0x07){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("fail due to lackness image",0,0);
			}
			else if(k == 0x15){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("fail due to valid primary image",0,0);
			}
		}
		*/
	}
}

void generate_template(void){
/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0003 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x03);
/**** Send Instruction code 0x05 *****/
	UART_SendChar(0x05);
/**** Send Checksum 0x0009*****/
	UART_SendChar(0x00);
	UART_SendChar(0x09);

/** Receive Acknowledge package format ****/
	uint8 k , s[2] ;
	for(uint8 i = 0 ; i< 12 ; i++){
		k = UART_GetChar() ;
		/*
		if( i == 9 ){
			itoa(k,s,16);
			LCD_WriteString(s,0,3);
			if(k == 0x00){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("generate character file complete",0,0);
			}
			else if(k == 0x01){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("error when receiving package;",0,0);
			}
		}
		*/
	}
}

void store_template(uint8 PageID){
	uint8 checksum = 14 + PageID ;
/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0003 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x06);
/**** Send Instruction code 0x06 *****/
	UART_SendChar(0x06);
/**** Send buffer Number 0x01 *****/
	UART_SendChar(0x01);
/**** Send Location Number 0x0000 *****/
	UART_SendChar(0x00);
	UART_SendChar(PageID);
/**** Send Checksum 0x0009*****/
	UART_SendChar(0x00);
	UART_SendChar(checksum);

/** Receive Acknowledge package format ****/
	uint8 k , s[2] ;
	for(uint8 i = 0 ; i< 12 ; i++){
		k = UART_GetChar() ;
		/*
		if( i == 9 ){
			itoa(k,s,16);
			LCD_WriteString(s,0,3);
			if(k == 0x00){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("generate character file complete",0,0);
			}
			else if(k == 0x01){
				LCD_WriteString("                                ",0,0);
				LCD_WriteString("error when receiving package;",0,0);
			}
		}
		*/
	}
}

uint8 search_of_two_finger_templates(void){
/****Send Header 0xEF01 (Start) ****/
	UART_SendChar(0xEF);
	UART_SendChar(0x01);
/**** Send Address 0xFFFFFFFF *****/
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
	UART_SendChar(0xFF);
/**** Send Package identifier 0x01 *****/
	UART_SendChar(0x01);
/**** Send Package length 0x0008 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x08);
/**** Send Instruction code 0x04 *****/
	UART_SendChar(0x04);
/**** Send buffer Number 0x01 *****/
	UART_SendChar(0x01);
/**** Send StartPage 0x0000 *****/
	UART_SendChar(0x00);
	UART_SendChar(0x00);
/**** Send Page Number 0x000A *****/
	UART_SendChar(0x00);
	UART_SendChar(0x0A);
/**** Send Checksum 0x0009*****/
	UART_SendChar(0x00);
	UART_SendChar(0x18);

/** Receive Acknowledge package format ****/
	uint8 k ,result ;
	for(uint8 i = 0 ; i< 16 ; i++){
		k = UART_GetChar() ;
		if( i == 9 ){
			result =k ;
		}
	}
	return result ;
}

/*
void read_finger_1(){          //for char_buffer1

	int i=0;
	char k=1,ch=1;

	UART_SendChar(239);
	UART_SendChar(1);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(3);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(5);

	for(i=0;i<10;i++){

		k=UART_GetChar();

		if(i==9){
			ch=k;
			k=UART_GetChar();
			k=UART_GetChar();
			if(ch==0x00){
				PORTC|=(1<<0);
				k=1;
				UART_SendChar(239);
				UART_SendChar(1);
				UART_SendChar(255);
				UART_SendChar(255);
				UART_SendChar(255);
				UART_SendChar(255);
				UART_SendChar(1);
				UART_SendChar(0);
				UART_SendChar(4);
				UART_SendChar(2);
				UART_SendChar(1);
				UART_SendChar(0);
				UART_SendChar(8);

				i=0;
				for(i=0;i<10;i++){
					k=UART_GetChar();

					if(i==9){
						ch=k;
						k=UART_GetChar();
						k=UART_GetChar();

						if(ch==0x00){
							PORTC|=(1<<1);
						}
					}
				}
			}
		}
	}
}

void read_finger_2(){          //for char_buffer2

	int i=0;
	char k=1,ch=1;

	UART_SendChar(239);
	UART_SendChar(1);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(3);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(5);
	for(i=0;i<10;i++){
		k=UART_GetChar();

		if(i==9){
			  ch=k;
			  k=UART_GetChar();
			  k=UART_GetChar();

			  if(ch==0x00){
					PORTC|=(1<<2);
					k=1;

					UART_SendChar(239);
					UART_SendChar(1);
					UART_SendChar(255);
					UART_SendChar(255);
					UART_SendChar(255);
					UART_SendChar(255);
					UART_SendChar(1);
					UART_SendChar(0);
					UART_SendChar(4);
					UART_SendChar(2);
					UART_SendChar(2);
					UART_SendChar(0);
					UART_SendChar(9);
					i=0;
					for(i=0;i<10;i++){
						k=UART_GetChar();
						if(i==9){
							ch=k;
							k=UART_GetChar();
							k=UART_GetChar();
							if(ch==0x00){
								  PORTC|=(1<<3);
							}
						}
					}
			  }
		}
	}
}

void make_template(){
      int i=0;
      char k=1,ch=1;
      k=1;
      UART_SendChar(239);
      UART_SendChar(1);
      UART_SendChar(255);
      UART_SendChar(255);
      UART_SendChar(255);
      UART_SendChar(255);
      UART_SendChar(1);
      UART_SendChar(0);
      UART_SendChar(3);
      UART_SendChar(5);
      UART_SendChar(0);
      UART_SendChar(9);
      for(i=0;i<10;i++){
            k=UART_GetChar();
            if(i==9){
                  ch=k;
                  k=UART_GetChar();
                  k=UART_GetChar();
                  if(ch==0x00){
                	 PORTC|=(1<<4);
                  }
            }
      }
}

void check_finger(){
	int i=0;
	char k=1,ch=1;

	UART_SendChar(239);
	UART_SendChar(1);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(8);
	UART_SendChar(4);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(0);
	UART_SendChar(0);
	UART_SendChar(10);
	UART_SendChar(0);
	UART_SendChar(24);

	for(i=0;i<10;i++){

		k=UART_GetChar();

		if(i==9){
		  ch=k;
		  k=UART_GetChar();
		  k=UART_GetChar();
		  k=UART_GetChar();
		  k=UART_GetChar();
		  k=UART_GetChar();
		  k=UART_GetChar();
		  LCD_Clear();

		  if(ch==0x00){
			  PORTC|=(1<<5);
			  LCD_WriteString("FINGER FOUND",0,0);
		  }
		  else{
			  LCD_WriteString("FINGER NOT FOUND",0,0);
		  }
		}
	}
}

void store(uint32 ID){

	int i=0,sum=14+ID;
	char k=1,ch=1;

	UART_SendChar(239);
	UART_SendChar(1);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(6);
	UART_SendChar(6);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(ID);
	UART_SendChar(0);//C
	UART_SendChar(sum);//C

	for(i=0;i<10;i++){
	  k=UART_GetChar();
	  if(i==9){
		ch=k;
		k=UART_GetChar();
		k=UART_GetChar();
		if(ch==0x00){
			PORTC|=(1<<6);
		}
	  }
	}
}

void empty(){

	int i=0;
	char k=1,ch=1;

	UART_SendChar(239);
	UART_SendChar(1);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(255);
	UART_SendChar(1);
	UART_SendChar(0);
	UART_SendChar(3);
	UART_SendChar(13);
	UART_SendChar(0);
	UART_SendChar(17);

	for(i=0;i<10;i++){
	  k=UART_GetChar();
	  if(i==9){
		ch=k;
		k=UART_GetChar();
		k=UART_GetChar();
		if(ch==0x00){
			PORTC|=(1<<7);
		}
	  }
	}
}

*/
