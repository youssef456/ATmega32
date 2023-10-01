/*
 * main.c
 *
 *      Author: youssef
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "TIMER_0_Private.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

u8 flag=0;
u16 state0=0;
u16 state1=0;
u16 state2=0;

u16 led_flag=0;



void __vector_11(void)__attribute__((signal));

void __vector_11(void){
	static u16 counter=0;

	counter++;

	if(counter == 3907){
		led_flag++;
		counter=0;
		TIMER0_U8_TCNT0=192;
		flag=1;
	}

}



int main(){

	DIO_U8_Set_Pin_Direction(GROUP_C,PIN0,OUTPUT);
	DIO_U8_Set_Pin_Direction(GROUP_C,PIN1,OUTPUT);
	DIO_U8_Set_Pin_Direction(GROUP_C,PIN2,OUTPUT);

	TIMER0_U8_TCNT0=192;
	Set_Bit(TIMER0_U8_TIMSK,0);  // INTERUPT ENABLE
	Set_Bit(TIMER0_U8_SREG,7);  // Global Intterupt Enable
	TIMER0_U8_TCCR0= 0b00000010; //Normal Mode prescalar = clk/8


	while(1){
		if(flag){
			if(led_flag % 1 ==0){
				DIO_U8_Set_Pin_Value(GROUP_C,PIN0,Toggle_Bit(state0,PIN0));
			}
			if(led_flag%2 ==0){
				DIO_U8_Set_Pin_Value(GROUP_C,PIN1,Toggle_Bit(state1,PIN0));
			}
			if(led_flag%3 ==0){
				DIO_U8_Set_Pin_Value(GROUP_C,PIN2,Toggle_Bit(state2,PIN0));
			}
		flag=0;
		}
	}
	return 0;
}

