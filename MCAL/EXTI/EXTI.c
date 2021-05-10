/*
 * EXTI.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */
#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"

#include "EXTI_reg.h"
#include "EXTI_types.h"
#include "EXTI.h"
#include "EXTI_config.h"

/* Define pointer to function */
void (*CallbackPtr) (void) = NULL;



void EXTI_Initialization(void)
{
/**************** Clearing all source modes ********************/
/***************************************************************/
	/* Clear ISC bits for External Interrupt 0 in register MCUCR */
	/* Clear bit ISC00 */
	CLEAR_BIT(MCUCR_Reg, 0);
	/* Clear bit ISC01 */
	CLEAR_BIT(MCUCR_Reg, 1);

	/* Clear ISC bits for External Interrupt 1 in register MCUCR */
	/* Clear bit ISC10 */
	CLEAR_BIT(MCUCR_Reg, 2);
	/* Clear bit ISC11 */
	CLEAR_BIT(MCUCR_Reg, 3);

	/* Clear ISC bits for External Interrupt 2 in register MCUCSR */
	/* Clear bit ISC2 */
	CLEAR_BIT(MCUCSR_Reg, 6);

/***************************************************************/

/************* Initializing Interrupt source mode **************/
/***************************************************************/
	/**** Setting EXTI INT0 Mode ****/
	#if (EXTI0_MODE == EXTI_LOW_LEVEL)
		MCUCR_Reg = MCUCR_Reg | EXTI_LOW_LEVEL;

	#elif (EXTI0_MODE == EXTI_IOC)
		MCUCR_Reg = MCUCR_Reg | EXTI_IOC;

	#elif (EXTI0_MODE == EXTI_FALLING)
		MCUCR_Reg = MCUCR_Reg | EXTI_FALLING;

	#elif (EXTI0_MODE == EXTI_RISING)
		MCUCR_Reg = MCUCR_Reg | EXTI_RISING;
	#endif

	/**** Setting EXTI INT1 Mode ****/
	#if (EXTI1_MODE == EXTI_LOW_LEVEL)
		MCUCR_Reg = MCUCR_Reg | (EXTI_LOW_LEVEL << 2);

	#elif (EXTI1_MODE == EXTI_IOC)
		MCUCR_Reg = MCUCR_Reg | (EXTI_IOC << 2);

	#elif (EXTI1_MODE == EXTI_FALLING)
		MCUCR_Reg = MCUCR_Reg | (EXTI_FALLING << 2);

	#elif (EXTI1_MODE == EXTI_RISING)
		MCUCR_Reg = MCUCR_Reg | (EXTI_RISING << 2);
	#endif

	/**** Setting EXTI INT2 Mode ****/
	#if (EXTI2_MODE == EXTI_INT2_FALLING)
		MCUCSR_Reg = MCUCSR_Reg | (EXTI_INT2_FALLING << 6);

	#elif (EXTI2_MODE == EXTI_INT2_RISING)
		MCUCR_Reg = MCUCR_Reg | (EXTI_INT2_RISING << 6);
	#endif
/***************************************************************/

/*********** Initializing External Interrupts State ************/
/***************************************************************/
	/* Initialize the state of EXTI_INT0 */
	#if EXTI_INT0_INIT_STATE == EXTI_ENABLE_STATE
		SET_BIT(GICR_Reg,6);
	#else
		CLEAR_BIT(GICR_Reg,6);
	#endif
	/* Initialize the state of EXTI_INT1 */
	#if EXTI_INT1_INIT_STATE == EXTI_ENABLE_STATE
		SET_BIT(GICR_Reg,7);
	#else
		CLEAR_BIT(GICR_Reg,7);
	#endif
	/* Initialize the state of EXTI_INT2 */
	#if EXTI_INT2_INIT_STATE == EXTI_ENABLE_STATE
		SET_BIT(GICR_Reg,5);
	#else
		CLEAR_BIT(GICR_Reg,5);
	#endif
/***************************************************************/

/**************** Clear Interrupt Flags ************************/
/***************************************************************/
	/* clear the interrupt flag for INT0 */
	SET_BIT(GIFR_Reg,6);
	/* clear the interrupt flag for INT1 */
	SET_BIT(GIFR_Reg,7);
	/* clear the interrupt flag for INT2 */
	SET_BIT(GIFR_Reg,5);

}


/* Function to enable EXTI 0 ISR */
void EXTI_EnableInt0(void)
{
	SET_BIT(GICR_Reg,6);
}

/* Function to disable EXTI 0 ISR */
void EXTI_DisableInt0(void)
{
	CLEAR_BIT(GICR_Reg,6);
}

void EXTI_SetCallback( void (*CopyFuncPtr) (void) )
{
	CallbackPtr = CopyFuncPtr;
}

void __vector_1(void) __attribute__((signal, used));
/* Definition of ISR of INT0 */
void __vector_1(void)
{
	if(CallbackPtr != NULL)
	{
		CallbackPtr();
	}
	/* Pass address of function in APP */
}

