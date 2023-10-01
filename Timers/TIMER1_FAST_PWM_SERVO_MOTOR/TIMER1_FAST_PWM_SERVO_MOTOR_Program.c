/*
 * main.c
 *
 *      Author: youssef
 */

#include "TIMER1_FAST_PWM_SERVO_MOTOR_Private.h"
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

int main(){ //prescalar=clr/64
	//Direction
	DIO_U8_Set_Pin_Direction(GROUP_A,PIN0,INPUT);
	DIO_U8_Set_Pin_Direction(GROUP_D,PIN5,OUTPUT);

	ADC_Void_Init();
	//timer1 mode14 fastpwm
	TCCRIA = 0b10100010; //clear on compare, set on top
	TCCRIB = 0b00011011; //non inverted
	ICRIL = 2500;
	//OCRIAL = 250;

	while(1){
		OCRIAL = ADC_U8_Read_channel(channel_0) / 4;
	}
	return 0;
}
