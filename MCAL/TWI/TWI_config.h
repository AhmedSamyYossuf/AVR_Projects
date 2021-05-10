/*
 * TWI_config.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TWI_TWI_CONFIG_H_
#define SRC_MCAL_TWI_TWI_CONFIG_H_

/*
 * TWBR_VAL = ( ( (Fosc / SCLfreq) - 16 ) / (2 * Prescaler_value) )
 *
 * In case of:
 * Fosc = 16MHz, SCLfreq = 400KHz, and Prescaler_value = 1  --> TWBR_VAL = 12
 *
 * */

#define TWI_BITRATE_TWBR_VAL			12
/*
 * TWI_PRESCALER options:
 *
 * TWI_PRESCALER_1
 * TWI_PRESCALER_4
 * TWI_PRESCALER_16
 * TWI_PRESCALER_64
 *
 * */
#define TWI_PRESCALER_SELECT			TWI_PRESCALER_1

/* Select address in range [1-120] since (1111xxx) are reserved */
#define TWI_NODE_ADDRESS				0x55

/*
 * TWI_GENERAL_BROADCAST options:
 *
 * GB_ENABLE
 * GB_DISABLE
 *
 * */
#define TWI_GENERAL_BROADCAST_SELECT	GB_ENABLE

#define TWI_TX_BUFFER_SIZE_Byte			32
#define TWI_RX_BUFFER_SIZE_Byte			32


#endif /* SRC_MCAL_TWI_TWI_CONFIG_H_ */
