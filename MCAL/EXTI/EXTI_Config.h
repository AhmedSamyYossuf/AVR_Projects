/*
 * EXTI_config.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_EXTI_EXTI_CONFIG_H_
#define SRC_MCAL_EXTI_EXTI_CONFIG_H_

/* Configure the External interrupt 0 mode
 * Range:
 *
 * EXTI_LOW_LEVEL
 * EXTI_IOC
 * EXTI_FALLING
 * EXTI_RISING
 *
 * */

#define EXTI0_MODE	EXTI_LOW_LEVEL

/* Configure the external interrupt 1 mode
 * Range:
 *
 * EXTI_LOW_LEVEL
 * EXTI_IOC
 * EXTI_FALLING
 * EXTI_RISING
 *
 * */

#define EXTI1_MODE	EXTI_FALLING

/* Configure the external interrupt 2 mode
 * Range:
 *
 * EXTI_INT2_FALLING
 * EXTI_INT2_RISING
 *
 * */
#define EXTI2_MODE	EXTI_INT2_FALLING

/* Configure the external interrupt initial state
 * Range:
 *
 * EXTI_DISABLE_STATE
 * EXTI_ENABLE_STATE
 *
 * */

#define EXTI_INT0_INIT_STATE	EXTI_DISABLE_STATE
#define EXTI_INT1_INIT_STATE	EXTI_DISABLE_STATE
#define EXTI_INT2_INIT_STATE	EXTI_DISABLE_STATE

#endif /* SRC_MCAL_EXTI_EXTI_CONFIG_H_ */
