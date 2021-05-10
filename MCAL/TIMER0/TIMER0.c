/*
 * TIMER.c
 *
 *  Created on: Sep 4, 2019
 *      Author: Ahmed
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"


#include "TIMER0_reg.h"
#include "TIMER0.h"

#include "TIMER0_config.h"
#include "TIMER0_types.h"

static void(*CallIntComp)(void)=NULL;
static void(*CallIntOver)(void)=NULL;

/* Initialization of the timer */
void TIM0_Initialize(void)
{
    /** Clear TCNT0 register Initial Counting **/
    TCNT0_reg &= Clear_reg ;
    TCCR0_reg &= Clear_reg;
    /*******************************************/

    /*** Selecting Waveform Generation Mode ***/
	#if (SIGNAL_MODE == Normal_Mode)
		TCCR0_reg |= Normal_Mode;
	#elif(SIGNAL_MODE == PWM_PhaseCorrect )
		TCCR0_reg |= PWM_PhaseCorrect;
	#elif(SIGNAL_MODE == CTC )
		TCCR0_reg |= CTC;

	#elif(SIGNAL_MODE == Fast_PWM   )
		TCCR0_reg |= Fast_PWM  ;
	#endif
    /******************************************/

	/***** Selecting clock prescaler *****/
	#if(CLOCK_Prescaler == No_Clock_Stop)
		TCCR0_reg |= No_Clock_Stop;
	#elif (CLOCK_Prescaler == ClkIo)
		TCCR0_reg |= ClkIo;
	#elif (CLOCK_Prescaler == Clk_8 )
		TCCR0_reg |= Clk_8 ;
	#elif (CLOCK_Prescaler == Clk_64 )
		TCCR0_reg |= Clk_64 ;
	#elif (CLOCK_Prescaler == Clk_256 )
		TCCR0_reg |= Clk_256 ;
	#elif (CLOCK_Prescaler == Clk_1024 )
		TCCR0_reg |= Clk_1024 ;
	#elif (CLOCK_Prescaler == Ext_clk_FallingEdge )
		TCCR0_reg |= Ext_clk_FallingEdge ;
	#elif (CLOCK_Prescaler == Ext_clk_RisingEdge)
		TCCR0_reg |= Ext_clk_RisingEdge;
	#endif
	/**************************************/

    /**** Setting Compare Output Mode ****/
	#if(COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
		TCCR0_reg |= OC0_DISCONNECTED;
	#elif(COMPARE_OUTPUT_MODE == OC0_TOGGLE_ON_COMPARE_MATCH)
		TCCR0_reg |= OC0_TOGGLE_ON_COMPARE_MATCH;
	#elif(COMPARE_OUTPUT_MODE == OC0_CLEAR_ON_COMPARE_MATCH)
		TCCR0_reg |= OC0_CLEAR_ON_COMPARE_MATCH;
	#elif(COMPARE_OUTPUT_MODE == OC0_SET_ON_COMPARE_MATCH)
		TCCR0_reg |= OC0_SET_ON_COMPARE_MATCH;
	#endif
	/**************************************/

    /*** Clearing interrupt flags ***/
    SET_BIT(TIFR_reg, 0);
    SET_BIT(TIFR_reg, 1);

}


void TIM0_CompIntEnable(void)
{
	SET_BIT(TIMSK_reg,1);
}
void TIM0_CompIntDisable(void)
{
    CLEAR_BIT(TIMSK_reg,1);
}


void TIM0_OverFlowIntEnable(void)
{
    SET_BIT(TIMSK_reg,0);
}
void TIM0_OverFlowIntDisable(void)
{
    CLEAR_BIT(TIMSK_reg,0);
}

void TIM0_SetCompValue(uint8 Value)
{

	if(Value<=255)
	{
    	OCR0_reg=Value;
    }
    else
    {
        OCR0_reg=0xFF;
    }
}

void TIM0_SetTimerValue(uint8 Value)
{
    if(Value<=255)
    {
        TCNT0_reg=Value;
    }
    else
    {
        TCNT0_reg=0xFF;
    }
}

void TIM0_OverFlowCallBack(void (*Copy_ptr) (void)){

    CallIntOver = Copy_ptr;
}

void TIM0_CompareCallBack(void (*Copy_ptr) (void)){

    CallIntComp = Copy_ptr;
}

/*Compare Interrupt*/
void __vector_10(void) __attribute__((signal,used));

void __vector_10(void){

    CallIntComp();
}

/*OverFlow Interrupt*/
void __vector_11(void) __attribute__((signal,used));

void __vector_11(void){

    CallIntOver();
}
