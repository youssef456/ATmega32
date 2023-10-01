/*
 * main.c
 *
 *      Author: youssef
 */
#include "ICU_TIMER1_EXTI_0_Private.h"
#include "STD_TYPES.h"
#include "BIT_CALC.h"

u16 ON_TIME;
u16 OFF_TIME;

void __vector_1(void)__attribute__((signal));
void __vector_1(void){
	static u8 flag = 0;
	OFF_TIME = TCNT1L;
	TCNT1L = 0;
	MCUCR = 0B00000010;//FALLING
	ON_TIME = TCNT1L;
	TCNT1L = 0;
	MCUCR = 0b00000011;//RISING
	flag = 0;
	//Duty = (ON_TIME * 100) / OFF_TIME;
	//freq = 1000000 / (ON_TIME + OFF_TIME);
}

int main(){
	TCCR0 = 0b01101010;//fast pwm
	OCR0 = 128;//clear OCR0 on compare, set on top
	//prescalar=clr/128

	//EXTI0
	MCUCR = 0b00000011;//rising edge
	GICR = 0b01000000;// enable EXTI0
	//Timer1
	TCCR1A = 0b00000000;//normal mode
	TCCR1B = 0b00000001;//prescalar/8

	SREG = 0b10000000;
}

