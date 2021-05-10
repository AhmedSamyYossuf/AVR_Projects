/*
 * fingerPrint.h
 *
 *  Created on: Jan 24, 2021
 *      Author: ahmed
 */

#ifndef SRC_HAL_FINGERPRINT_FINGERPRINT_H_
#define SRC_HAL_FINGERPRINT_FINGERPRINT_H_

#include 	"../../LIB/std_types.h"
#include 	"../../LIB/Bit_Math.h"
#include 	"../../MCAL/UART/UART.h"
#include	"../LCD/LCD.h"
#include	<util/delay.h>



/* Confirmation code's definition (ZFM-20 series provide 23 instructions) : */
#define FingerPrint_OK 					0x00
#define FingerPrint_PACKETRECIEVEERR 	0x01
#define FingerPrint_NOFINGER			0x02
#define FingerPrint_IMAGEFAIL 			0x03
#define FingerPrint_IMAGEMESS 			0x06
#define FingerPrint_FEATUREFAIL 		0x07
#define FingerPrint_NOMATCH 			0x08
#define FingerPrint_NOTFOUND 			0x09
#define FingerPrint_ENROLLMISMATCH 		0x0A
#define FingerPrint_BADLOCATION 		0x0B
#define FingerPrint_DBRANGEFAIL 		0x0C
#define FingerPrint_UPLOADFEATUREFAIL 	0x0D
#define FingerPrint_PACKETRESPONSEFAIL 	0x0E
#define FingerPrint_UPLOADFAIL 			0x0F
#define FingerPrint_DELETEFAIL 			0x10
#define FingerPrint_DBCLEARFAIL 		0x11
#define FingerPrint_PASSFAIL 			0x13
#define FingerPrint_INVALIDIMAGE 		0x15
#define FingerPrint_FLASHERR 			0x18
#define FingerPrint_INVALIDREG 			0x1A
#define FingerPrint_ADDRCODE 			0x20
#define FingerPrint_PASSVERIFY 			0x21

#define FingerPrint_STARTCODE 			0xEF01

#define FingerPrint_COMMANDPACKET 		0x1
#define FingerPrint_DATAPACKET 			0x2
#define FingerPrint_ACKPACKET 			0x7
#define FingerPrint_ENDDATAPACKET 		0x8

#define FingerPrint_TIMEOUT	 			0xFF
#define FingerPrint_BADPACKET 			0xFE

#define FingerPrint_GETIMAGE 			0x01
#define FingerPrint_IMAGE2TZ 			0x02
#define FingerPrint_REGMODEL 			0x05
#define FingerPrint_STORE 				0x06
#define FingerPrint_DELETE 				0x0C
#define FingerPrint_EMPTY 				0x0D
#define FingerPrint_VERIFYPASSWORD 		0x13
#define FingerPrint_HISPEEDSEARCH 		0x1B
#define FingerPrint_TEMPLATECOUNT 		0x1D


#define DEFAULTTIMEOUT 					5000  // milliseconds




void Communicate_link(void);
void Read_valid_template_number(void);
uint8 collect_finger_image(void);
void generate_character_file(uint8 Buffer_num);
void generate_template(void);
void store_template(uint8 PageID);
uint8 search_of_two_finger_templates(void);

void Upload_image(void);
void Download_the_image(void);
void upload_character_or_template(void);
void download_character_or_template(void);
void read_template_from_Flash_library(void);
void delete_template(void);
void empty_finger_library(void);
void search_finger_library(void);
/*
typedef enum{
	False,
	True
}boolean;

void 	writePacket(uint32_t addr, uint8_t packettype, uint16_t len, uint8_t *packet);
void    begin(uint16_t baud);
uint8 	getImage(void);
uint8 	image2Tz(uint8_t slot = 1);
uint8 	createModel(void);
uint8 	emptyDatabase(void);
uint8	storeModel(uint16_t id);
uint8	deleteModel(uint16_t id);
uint8	fingerFastSearch(void);
uint8	getTemplateCount(void);
uint8	getReply(uint8_t packet[], uint16_t timeout=DEFAULTTIMEOUT);

*/
















/*
void read_finger_1(void);
void read_finger_2(void);
void make_template(void);
void check_finger(void);
void store(uint32 ID);
void empty(void);
*/

#endif /* SRC_HAL_FINGERPRINT_FINGERPRINT_H_ */
