/*
 * ADC.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_ADC_ADC_H_
#define SRC_MCAL_ADC_ADC_H_

typedef enum
{
    ADC_Channel_0,
    ADC_Channel_1,
    ADC_Channel_2,
    ADC_Channel_3,
    ADC_Channel_4,
    ADC_Channel_5,
    ADC_Channel_6,
    ADC_Channel_7

}ADC_ChannelType;

void ADC_Initialize(void);

void ADC_StartConversion(ADC_ChannelType Channel_Number);

uint16 ADC_GetResult(void);

void ADC_SetCallBack(void (*Copy_ptr) (void));

void ADC_EnableInt(void);

void ADC_DisableInt(void);

#endif /* SRC_MCAL_ADC_ADC_H_ */
