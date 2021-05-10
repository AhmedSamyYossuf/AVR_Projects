/*
 * ADC.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Amr
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"


#include "ADC_reg.h"
#include "ADC_types.h"
#include "ADC_config.h"
#include "ADC.h"

static void(*ADC_CallBack)(void) = NULL;

extern void ADC_Initialize(void)
{
/**************** Selecting voltage reference ******************/
/***************************************************************/
    ADMUX_Reg = ADMUX_Reg & ADC_VOLTAGE_REF_clr_msk;
    ADMUX_Reg = ADMUX_Reg | ADC_VOLTAGE_REF_SELECTOR_msk;
/***************************************************************/

/******************** Selecting ADC Mode ***********************/
/***************************************************************/
    #if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER

        SET_BIT(ADCSRA_Reg,5);
        /* Select auto trigger source */
        SFIOR_Reg &= ADC_AUTO_TRIG_SRC_clr_msk;
        SFIOR_Reg |= ADC_AUTO_TRIG_SRCE_SELECTOR;

    #elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION

        CLEAR_BIT(ADCSRA_Reg,5);

    #endif
/***************************************************************/

/******************* Selecting Adjustment **********************/
/***************************************************************/
    #if ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED
        CLEAR_BIT(ADMUX_Reg, 5);
    #elif ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTED
        SET_BIT(ADMUX_Reg, 5);
    #endif
/***************************************************************/

/***************** Clearing Interrupt Flag *********************/
/***************************************************************/
    SET_BIT(ADCSRA_Reg,4);
/***************************************************************/

/********************** Enabling ADC ***************************/
/***************************************************************/
    SET_BIT(ADCSRA_Reg,7);
/***************************************************************/
}

void ADC_StartConversion(ADC_ChannelType Channel_Number)
{
    /* Select ADC channel using MUX in ADMUX */
    ADMUX_Reg &= ADC_CHANNEL_SELECTOR_clr_msk;
    ADMUX_Reg |= Channel_Number;

    /* Start conversion using ADSC in ADCSRA */
    SET_BIT(ADCSRA_Reg,6);
}

uint16 ADC_GetResult(void)
{
    /* Get the value of ADCL and ADCH registers
     * at once by reading the 16 bits starting
     * from the low address of ADCL */
    return ADCLH_Reg;
}

void ADC_SetCallBack(void (*Copy_ptr) (void))
{
    ADC_CallBack = Copy_ptr;
}

void ADC_EnableInt(void)
{
    SET_BIT(ADCSRA_Reg, 3);
}

void ADC_DisableInt(void)
{
    CLEAR_BIT(ADCSRA_Reg, 3);
}


void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
    ADC_CallBack();
}
