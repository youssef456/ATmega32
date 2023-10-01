/*
 * ADC_Program.c
 *
 *      Author: youssef
 */
#include "ADC_Private.h"
#include "BIT_CALC.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"

void ADC_Void_Init(void){
	//Adc enable
	Set_Bit(ADCSRA,7);
	//prescalar128
	Set_Bit(ADCSRA,0);
	Set_Bit(ADCSRA,1);
	Set_Bit(ADCSRA,2);
	//set ref voltage avcc
	Clear_Bit(ADMUX,7);
	Set_Bit(ADCSRA,6);
	//left adjustment
	Set_Bit(ADMUX,6);

}

u16 ADC_U8_Read_channel(u8 channel){
	u16 result;
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	//start converion
	Set_Bit(ADCSRA,6);

	while(Get_Bit(ADCSRA,4)  != 1);
	Set_Bit(ADCSRA,4);
	result = ADCL >> 6;
	result |= ((u16)ADCH << (2));

	return result;
}
