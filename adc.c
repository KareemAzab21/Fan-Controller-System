/*
 * adc.c
 *
 *  Created on: May 25, 2022
 *      Author: lenovo
 */

#include "adc.h"
#include "common_macros.h"
#include "avr/io.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX =0;
	ADMUX |=(Config_Ptr->ref_volt<<6);
	ADCSRA =(1<<ADEN);
	ADCSRA |=Config_Ptr->prescaler;
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | channel_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
