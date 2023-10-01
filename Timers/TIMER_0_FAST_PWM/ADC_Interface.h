/*
 * ADC_Interface.h
 *
 *      Author: youssef
 */
#include "STD_TYPES.h"

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define channel_0 0
#define channel_1 1
#define channel_2 2
#define channel_3 3
#define channel_4 4
#define channel_5 5
#define channel_6 6
#define channel_7 7

u16 ADC_U8_Read_channel(u8 channel);
void ADC_Void_Init(void);

#endif /* ADC_INTERFACE_H_ */
