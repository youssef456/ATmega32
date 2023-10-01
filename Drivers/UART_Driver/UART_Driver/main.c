/*
 * main.c
 *
 *      Author: youssef
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "UART_Private.h"
#include "UART_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include <avr/delay.h>

u8 state0=0;
u8 state1=0;
u8 state2=0;


int main(){
	LCD_VOID_Init_8Bit();
	LCD_Void_Write_String("test",0,1);

	u8 str[] = "1-Yellow \n2-Red\n 3-Green\n";
	u8 Recevied_Data;
	UART_void_INIT();
	DIO_U8_SetPinDirection(Group_D,PIN0,INPUT);
	DIO_U8_SetPinDirection(Group_D,PIN1,OUTPUT);

	DIO_U8_SetPinDirection(Group_A,PIN0,OUTPUT);
	DIO_U8_SetPinDirection(Group_A,PIN1,OUTPUT);
	DIO_U8_SetPinDirection(Group_A,PIN2,OUTPUT);
	UART_Send_String(str);

	while(1){
		Recevied_Data = UART_U8_Receive_Char();
		switch(Recevied_Data){
		case '1':
			DIO_U8_SetPinValue(Group_A,PIN0,Toggle_Bit(state0,PIN3));
			break;
		case '2':
			DIO_U8_SetPinValue(Group_A,PIN1,Toggle_Bit(state1,PIN4));
			break;
		case '3':
			DIO_U8_SetPinValue(Group_A,PIN2,Toggle_Bit(state2,PIN5));
			break;


		}
	}
	return 0;



}

