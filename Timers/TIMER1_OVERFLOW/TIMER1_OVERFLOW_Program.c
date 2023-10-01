/*
 * main.c
 *
 *      Author: youssef
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "TIMER1_OVERFLOW_Private.h"
// global variable to count the number of overflows
u8 overflow;
u8 flag = 0;
void __vector_10(void)__attribute__((signal));

void __vector_10(void){
	overflow++;
	if(overflow == 16){
		flag = 1;
		TCNT1L = 49152;
		overflow = 0;
	}
}

int main(void){
	TCCR1B |= 0b00000010; //set prescalar
	TIMSK |= 0b00000100; //enable global intterupt
	TCNT1L = 49152;

	while(1){
		if(flag == 1){
			//toggle led
			flag = 0;
		}
	}
	return 0;
}

