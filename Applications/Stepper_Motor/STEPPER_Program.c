/*
 * STEPPER_Program.c
 *
 *      Author: youssef
 */

#include "STD_Types.h"
#include "bit_calc.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

#include "STEPPER_Interface.h"

#include "util/delay.h"

void stepper_motor_init(void){
	DIO_U8_SetPinDirection(Group_A,PIN0,OUTPUT);
	DIO_U8_SetPinDirection(Group_A,PIN1,OUTPUT);
	DIO_U8_SetPinDirection(Group_A,PIN2,OUTPUT);
	DIO_U8_SetPinDirection(Group_A,PIN3,OUTPUT);

}

void stepper_Rotate_CCW_Full_Step(void){
	DIO_U8_SetPinValue(Group_A,PIN0,HIGH);
	DIO_U8_SetPinValue(Group_A,PIN1,LOW);
	DIO_U8_SetPinValue(Group_A,PIN2,LOW);
	DIO_U8_SetPinValue(Group_A,PIN3,LOW);
	_delay_ms(10);
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);
	DIO_U8_SetPinValue(Group_A,PIN1,HIGH);
	DIO_U8_SetPinValue(Group_A,PIN2,LOW);
	DIO_U8_SetPinValue(Group_A,PIN3,LOW);
	_delay_ms(10);
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);
	DIO_U8_SetPinValue(Group_A,PIN1,LOW);
	DIO_U8_SetPinValue(Group_A,PIN2,HIGH);
	DIO_U8_SetPinValue(Group_A,PIN3,LOW);
	_delay_ms(10);
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);
	DIO_U8_SetPinValue(Group_A,PIN1,LOW);
	DIO_U8_SetPinValue(Group_A,PIN2,LOW);
	DIO_U8_SetPinValue(Group_A,PIN3,HIGH);
	_delay_ms(10);

}
void stepper_Rotate_CW_Full_Step(void){
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);
	DIO_U8_SetPinValue(Group_A,PIN1,LOW);
	DIO_U8_SetPinValue(Group_A,PIN2,LOW);
	DIO_U8_SetPinValue(Group_A,PIN3,HIGH);
	_delay_ms(10);
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);
	DIO_U8_SetPinValue(Group_A,PIN1,LOW);
	DIO_U8_SetPinValue(Group_A,PIN2,HIGH);
	DIO_U8_SetPinValue(Group_A,PIN3,LOW);
	_delay_ms(10);
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);
	DIO_U8_SetPinValue(Group_A,PIN1,HIGH);
	DIO_U8_SetPinValue(Group_A,PIN2,LOW);
	DIO_U8_SetPinValue(Group_A,PIN3,LOW);
	_delay_ms(10);
	DIO_U8_SetPinValue(Group_A,PIN0,HIGH);
	DIO_U8_SetPinValue(Group_A,PIN1,LOW);
	DIO_U8_SetPinValue(Group_A,PIN2,LOW);
	DIO_U8_SetPinValue(Group_A,PIN3,LOW);
	_delay_ms(10);

}
void stepper_Rotate_Angle(u32 angle,u8 direction){
	u32 steps = (angle * 2048) / (360);
	steps /= 4;
	for(u32 i = 0;i < steps ;i++){
		if(direction == CW){
			stepper_Rotate_CW_Full_Step();
		}else{
			stepper_Rotate_CCW_Full_Step();
		}
	}
}
