/*
 * main.c
 *
 *      Author: youssef
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "TIMER_0_CM_Config.h"
#include "TIMER_0_CM_Interface.h"
#include "TIMER_0_CM_Private.h"
#include "ADC_Interface.h"


int main(){
	ADC_Void_Init();
	DIO_U8_Set_Pin_Direction(GROUP_A,PIN0,INPUT);
	DIO_U8_Set_Pin_Direction(GROUP_B,PIN3,OUTPUT);

	//TIMER0_U8_OCR0=200;
	TIMER0_U8_TCCR0 = 0B01111010; //Fast pwm module
								  //PRESCALAR = CLR/8
								  //SET OCR ON COMPUTE
								  //CLEAR ON TOP

	while(1){
		TIMER0_U8_OCR0 = ADC_U8_Read_channel(channel_0) / 4;
	}
	return 0;
}

