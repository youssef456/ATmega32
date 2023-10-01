/*
 * main.c
 *
 *      Author: youssef
 */


#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "TIMER_0_CM_Private.h"

u8 flag=0;
u16 state0=0;

u16 led_flag=0;



void __vector_10(void)__attribute__((signal));

void __vector_10(void){

		flag=1;
}





int main(){

	DIO_U8_Set_Pin_Direction(GROUP_C,PIN0,OUTPUT);
	TIMER0_U8_OCR0 = 500;

	Set_Bit(TIMER0_U8_TIMSK,1);  // INTERUPT ENABLE TIMER0 COMPARE MATCH
	Set_Bit(TIMER0_U8_SREG,7);  // Global Intterupt Enable
	TIMER0_U8_TCCR0= 0b00001010; //COMPARE MATCH Mode -- prescalar = clk/8  (CTC)  -- OC0 DISCONNECTED


	while(1){
		if(flag){
			DIO_U8_Set_Pin_Value(GROUP_C,PIN0,Toggle_Bit(state0,PIN0));
			flag=0;
		}
	}
	return 0;
}

