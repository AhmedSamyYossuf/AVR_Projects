/*
 * GIE.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */


#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"


#include "GIE_reg.h"
#include "GIE_types.h"
#include "GIE.h"
#include "GIE_config.h"


/* Function to enable global interrupt */
void GIE_Enable(void)
{
	SET_BIT(SREG_Reg,GIE_ENABLE_BIT);
}

/* Function to disable global interrupt */
void GIE_Disable(void)
{
	CLEAR_BIT(SREG_Reg,GIE_ENABLE_BIT);
}
