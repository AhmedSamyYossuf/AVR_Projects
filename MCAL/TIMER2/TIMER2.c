/*
 * TIMER2.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Amr
 */

#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"


#include "TIMER2_reg.h"
#include "TIMER2.h"

#include "TIMER2_config.h"
#include "TIMER2_types.h"

static void(*CallIntComp)(void)=NULL;
static void(*CallIntOver)(void)=NULL;

/* Initialization of the timer */
void TIM2_Initialize(void){

    /** Clear TCNT0 register Initial Counting **/
    TCNT2_reg &= Clear_reg ;
    TCCR2_reg &= Clear_reg;
    /*******************************************/

    /*** Selecting Waveform Generation Mode ***/
	#if (SIGNAL_MODE == Normal_Mode)
		TCCR2_reg |= Normal_Mode;
	#elif(SIGNAL_MODE == PWM_PhaseCorrect )
		TCCR2_reg |= PWM_PhaseCorrect;
	#elif(SIGNAL_MODE == CTC )
		TCCR2_reg |= CTC;
	#elif(SIGNAL_MODE == Fast_PWM   )
		TCCR2_reg |= Fast_PWM  ;
	#endif
    /******************************************/

	/***** Selecting clock prescaler *****/
	#if(CLOCK_Prescaler == No_Clock_Stop)
		TCCR2_reg |= No_Clock_Stop;
	#elif (CLOCK_Prescaler == ClkIo)
		TCCR2_reg |= ClkIo;
	#elif (CLOCK_Prescaler == Clk_8 )
		TCCR2_reg |= Clk_8 ;
	#elif (CLOCK_Prescaler == Clk_32 )
		TCCR2_reg |= Clk_32 ;
	#elif (CLOCK_Prescaler == Clk_64 )
		TCCR2_reg |= Clk_64 ;
	#elif (CLOCK_Prescaler == Clk_128 )
		TCCR2_reg |= Clk_128 ;
	#elif (CLOCK_Prescaler == Clk_256 )
		TCCR2_reg |= Clk_256 ;
	#elif (CLOCK_Prescaler == Clk_1024)
		TCCR2_reg |= Clk_1024;
	#endif
	/**************************************/

    /**** Setting Compare Output Mode ****/
	#if(COMPARE_OUTPUT_MODE == OC2_DISCONNECTED)
		TCCR2_reg |= OC2_DISCONNECTED;
	#elif(COMPARE_OUTPUT_MODE == OC2_TOGGLE_ON_COMPARE_MATCH)
		TCCR2_reg |= OC0_TOGGLE_ON_COMPARE_MATCH;
	#elif(COMPARE_OUTPUT_MODE == OC2_CLEAR_ON_COMPARE_MATCH)
		TCCR2_reg |= OC0_CLEAR_ON_COMPARE_MATCH;
	#elif(COMPARE_OUTPUT_MODE == OC2_SET_ON_COMPARE_MATCH)
		TCCR2_reg |= OC0_SET_ON_COMPARE_MATCH;
	#endif
	/**************************************/

    /*** Clearing interrupt flags ***/
    SET_BIT(TIFR_reg, 6);
    SET_BIT(TIFR_reg, 7);

}


void TIM2_CompIntEnable(void){
	SET_BIT(TIMSK_reg,7);
}
void TIM2_CompIntDisable(void){
    CLEAR_BIT(TIMSK_reg,7);
}


void TIM2_OverFlowIntEnable(void){
    SET_BIT(TIMSK_reg,6);
}
void TIM2_OverFlowIntDisable(void){
    CLEAR_BIT(TIMSK_reg,6);
}

void TIM2_SetCompValue(uint8 Value){
    if(Value<=255)
    {
    	OCR2_reg=Value;
    }
    else
    {
        OCR2_reg=0xFF;
    }
}

void TIM2_SetTimerValue(uint8 Value)
{
    if(Value<=255)
    {
        TCNT2_reg=Value;
    }
    else
    {
        TCNT2_reg=0xFF;
    }
}

void TIM2_OverFlowCallBack(void (*Copy_ptr) (void)){

    CallIntOver = Copy_ptr;

}
void TIM2_CompareCallBack(void (*Copy_ptr) (void)){

    CallIntComp = Copy_ptr;

}

/*Compare Interrupt*/
void __vector_4(void) __attribute__((signal,used));

void __vector_4(void){

    CallIntComp();
}

/*OverFlow Interrupt*/
void __vector_5(void) __attribute__((signal,used));

void __vector_5(void){

    CallIntOver();
}
