/*
 * main.c
 *
 *      Author: yousef
 */
#include "Watch_Dog_Private.h"
#include "Watch_Dog_Interface.h"

#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"

#include "util/delay.h"

int main(){
	//co ==> o/p
	DIO_U8_SetPinDirection(Group_A,PIN0,OUTPUT);

	//co ==> high
	DIO_U8_SetPinValue(Group_A,PIN0,HIGH);

	//delay 1000
	_delay_ms(1000);
	//co ==> low
	DIO_U8_SetPinValue(Group_A,PIN0,LOW);

	WDTCR = 0b00001111;
	//WDTCR |= 0b00011000;
	//Clear_Bit(WDTCR,3);
	while(1){

	}
}

