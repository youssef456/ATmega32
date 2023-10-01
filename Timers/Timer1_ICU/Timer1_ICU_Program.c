/*
 * main.c
 *
 *      Author: youssef
 */
#include "TIMER1_ICU_Private.h"
#include "STD_TYPES.h"
#include "BIT_CALC.h"

u16 ON_TIME;
u16 OFF_TIME;
u8 Duty = 0;
u8 freq = 0;
void __vector_6(void)__attribute__((signal));
void __vector_6(void){
	static u8 flag = 0;

	if(flag==0){
		OFF_TIME = ICR1L;
		TCNT1H=0;
		TCCR1B=0b00000010;
		flag = 1;
	}
	else{
		ON_TIME = ICR1L;
		TCNT1L=0;
		TCCR1B=0b00000010;
		flag = 0;

	}
	Duty = (ON_TIME * 100) / OFF_TIME;
	freq = 1000000 / (ON_TIME + OFF_TIME);
}

int main(){
	LCD_VOID_Init_8Bit();

	//TIMER 1 ICU D6 ==> I/P
	//TIMER 0
	TCCR0 = 0b01101010;
	OCR0 = 128;
	//timer 1
	TCCR1A = 0b00000000;
	TCCR1B = 0b01000010;
	TIMSK = 0b00100000;
	SREG = 0b10000000;

	while(1){
		//u8 Duty = (ON_TIME * 100) / OFF_TIME;
		//u8 freq = 1000000 / (ON_TIME + OFF_TIME);
		LCD_Void_Write_Number(Duty,0,0);
		//LCD_Void_Write_Number(freq,1,1);


	}
}

