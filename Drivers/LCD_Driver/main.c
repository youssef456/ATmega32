/*
 * main.c
 *
 *      Author: youssef
 */
#include "STD_Types.h"
#include "bit_calc.h"
#include "util/delay.h"
#include "DIO_Interface.h"

#include "LCD_Interface.h"
u8 pos = 0;

int main(void){
	LCD_VOID_Init_8Bit();
	//LCD_Void_Write_Cmd(0b10000010);

	//LCD_Void_Write_Data('B');

	//LCD_Void_Write_String("Hi",0,1);

	//while(1){
	//	while(pos < 16){
	//		LCD_Void_Write_String(" jimba",pos,0);
	//		pos ++;
	//		_delay_ms(2000);
	//	}
	//	pos = 0;
	//}

	//LCD_Void_Write_Number(10);
	LCD_Void_Write_Cmd(0b01000000);
	u8 arr[8] = {0,0,0,1,1,31,0,4};
	for(u8 i = 0 ; i < 8; i++){
		LCD_Void_Write_Data(arr[i]);
	}
	LCD_Void_Write_Cmd(0b10000000);
	LCD_Void_Write_Data(0);

	return 0;
}

