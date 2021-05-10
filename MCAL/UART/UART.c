/*
 * UART.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Amr
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"

#include "UART_Reg.h"
#include "UART_types.h"
#include "UART_config.h"
#include "UART.h"

static uint8 Rx_Buffer[UART_RX_BUFFER_SIZE]={0};
static uint8 Tx_Buffer[UART_TX_BUFFER_SIZE]={0};
static volatile uint8 Rx_Msg_Length = 0;
static volatile uint8 Tx_Msg_Index = 0;
static volatile uint8 Tx_Msg_Length = 0;

void UART_Initialize(void)
{
	/* Variable to hold the configurations that will be written to UCSRC register */
	uint8 UCSRC_Contents = 0;

    /*** Selecting UART Mode ***/
    #if (UART_MODE_SELECT == UART_ASYNCHRONOUS)
	UCSRC_Contents |= UART_ASYNCHRONOUS;
    #elif(UART_MODE_SELECT == UART_SYNCHRONOUS )
	UCSRC_Contents |= UART_SYNCHRONOUS;
    #endif
    /******************************************/

    /** Selecting Number of Data Bits in UART Frame **/
    #if(UART_DATA_BITS_SELECT == UART_DATA_BITS_FIVE)
	UCSRC_Contents |= UART_DATA_BITS_FIVE;
    #elif (UART_DATA_BITS_SELECT == UART_DATA_BITS_SIX)
	UCSRC_Contents |= UART_DATA_BITS_SIX;
    #elif (UART_DATA_BITS_SELECT == UART_DATA_BITS_SEVEN)
	UCSRC_Contents |= UART_DATA_BITS_SEVEN ;
    #elif (UART_DATA_BITS_SELECT == UART_DATA_BITS_EIGHT)
	UCSRC_Contents |= UART_DATA_BITS_EIGHT ;
    #elif (UART_DATA_BITS_SELECT == UART_DATA_BITS_NINE)
        SET_BIT(UCSRC_Contents, 1); // setting UCSZ0 bit
        SET_BIT(UCSRC_Contents, 2); // setting UCSZ1 bit
        SET_BIT(UCSRB_Reg, 2); // setting UCSZ2 bit
    #endif
    /*************************************************/

    /******* Selecting Parity Check *******/
    #if(UART_PARITY_SELECT == UART_PARITY_DISABLED)
        UCSRC_Contents |= UART_PARITY_DISABLED;
    #elif(UART_PARITY_SELECT == UART_PARITY_EVEN)
        UCSRC_Contents |= UART_PARITY_EVEN;
    #elif(UART_PARITY_SELECT == UART_PARITY_ODD)
        UCSRC_Contents |= UART_PARITY_ODD;
    #endif
    /**************************************/

    /** Selecting Number of Stop Bits in UART Frame **/
    #if(UART_STOP_BIT_SELECT == UART_STOP_BIT_ONE)
        UCSRC_Contents |= UART_STOP_BIT_ONE;
    #elif(UART_STOP_BIT_SELECT == UART_STOP_BIT_TWO)
        UCSRC_Contents |= UART_STOP_BIT_TWO;
    #endif
    /*************************************************/

	/** Setting URSEL bit to Select writing in UCSRC register **/
    SET_BIT(UCSRC_Contents, 7);
    /***********************************************************/

    UCSRC_Reg = UCSRC_Contents;

    /** Selecting Transmission Baud Rate **/
    UBRRH_Reg = 0;
    UBRRL_Reg = UART_BAUD_RATE_UBRR_VAL;
    /**************************************/

    /*** Enabling UART Transmitter ***/
    SET_BIT(UCSRB_Reg,3);
    /*** Enabling UART Receiver ***/
    SET_BIT(UCSRB_Reg,4);

}

void UART_SendChar(uint8 Data)
{
    /* Waiting, in an empty loop, until the "UDR_Empty" flag is raised (polling) */
    while (GET_BIT(UCSRA_Reg,5) == 0);
    /* Writing the data to be transmitted into UDR */
    UDR_Reg = Data;

}

uint8 UART_GetChar(void)
{
    uint8 Result = 0;

    /* Waiting, in an empty loop, until the "Rx Complete" flag is raised (polling) */
    while (GET_BIT(UCSRA_Reg,7) == 0);
    /* Reading the contents of UDR */
    Result = UDR_Reg;
    /* Clear "Rx Complete" flag, by writing one to it */
    SET_BIT(UCSRA_Reg,7);
    
    return Result;
}

void UART_InterruptEnable(UART_Interrupt_Select_T Interrupt_Source)
{
    switch(Interrupt_Source)
    {
        case UART_Receive_Complete_Int:
            SET_BIT(UCSRB_Reg,7);
            break;
        case UART_Transmit_Complete_Int:
            SET_BIT(UCSRB_Reg,6);
            break;
        case UART_Data_Register_Empty_Int:
            SET_BIT(UCSRB_Reg,5);
            break;
    }
}

void UART_InterruptDisable(UART_Interrupt_Select_T Interrupt_Source)
{
    switch(Interrupt_Source)
    {
        case UART_Receive_Complete_Int:
            CLEAR_BIT(UCSRB_Reg,7);
            break;
        case UART_Transmit_Complete_Int:
            CLEAR_BIT(UCSRB_Reg,6);
            break;
        case UART_Data_Register_Empty_Int:
            CLEAR_BIT(UCSRB_Reg,5);
            break;
    }
}


void UART_SendMsg(uint8 TxMsg[], uint8 TxMsgSize)
{
    uint8 Index;
    /* Copy size of message into local variable */
    Tx_Msg_Length = TxMsgSize;
    
    for(Index=0; Index<TxMsgSize; Index++)
    {
        /* Copy user message into local Tx buffer */
        Tx_Buffer[Index]= TxMsg[Index];
    }
    /* Enable "UDR_Empty" interrupt source */
    UART_InterruptEnable(UART_Data_Register_Empty_Int);
}

void UART_ReadMsg(uint8 RxMsg[], uint8* RxMsgSize)
{
    uint8 Index;
    /* Provide the length of the received message */
    *RxMsgSize = Rx_Msg_Length;

    for(Index=0; Index<Rx_Msg_Length; Index++)
    {
        /* Copy message from local Rx buffer back to user */
        RxMsg[Index]= Rx_Buffer[Index];
    }

    Rx_Msg_Length = 0;
}

/* Rx Complete Interrupt Handler */
void __vector_13 (void) __attribute__((signal, used));
void __vector_13 (void)
{
    /* As long as local buffer has size keep copying received messages into it */
    if(Rx_Msg_Length < UART_RX_BUFFER_SIZE)
    {
        Rx_Buffer[Rx_Msg_Length] = UDR_Reg;
        Rx_Msg_Length++;
    }
    else
    {
        /* Ignore messages */
    }
}

/* Data Register Empty Interrupt Handler */
void __vector_14 (void) __attribute__((signal, used));
void __vector_14 (void)
{
    /* As long as size of message is not reached keep sending */
    if(Tx_Msg_Index < Tx_Msg_Length)
    {
        UDR_Reg = Tx_Buffer[Tx_Msg_Index];
        Tx_Msg_Index++;
    }
    else
    {
        /* If the whole message has been transmitted reset the counters and disable the interrupt */
        Tx_Msg_Index = 0;
        Tx_Msg_Length = 0;
        UART_InterruptDisable(UART_Data_Register_Empty_Int);
    }
}

/* Tx Complete Interrupt Handler */
void __vector_15 (void) __attribute__((signal, used));
void __vector_15 (void)
{

}
