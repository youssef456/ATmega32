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

void sinosoidal_wave(u8* Copy_u8_Name){
	u8 namelenght = 0;

	while (*Copy_u8_Name){
		namelenght++;
		Copy_u8_Name++;
	}
	Copy_u8_Name -= namelenght;
	u8 start_Xpos = 0;
	u8 start_Ypos = 1;

	while (1){
		LCD_Void_Clear_Display();
		if(start_Xpos >= 0 && start_Xpos < 16){
			for (u8 i = 0; i < namelenght; i++){
				u8 xpos = start_Xpos + i;
				u8 ypos = start_Ypos;
				if(xpos >= 0 && xpos < 16 && ypos >= 0 && ypos < 2){
					LCD_Void_Write_String(Copy_u8_Name + i, xpos, ypos);
				}
			}
		}
		start_Xpos++;

		if(start_Xpos >= 16){
			start_Xpos = 0;
		}
		if(start_Ypos == 1){
			start_Ypos = 0;
		}
		else {
			start_Ypos = 1;
		}
		_delay_ms(2000);

	}
}

int main(void){
	LCD_VOID_Init_8Bit();
	//LCD_Void_Write_Cmd(0b10000010);

	//LCD_Void_Write_Data('B');

	//LCD_Void_Write_String("Hi",0,1);

	//moving string
	//while(1){
	//	while(pos < 16){
	//		LCD_Void_Write_String(" jimba",pos,0);
	//		pos ++;
	//		_delay_ms(2000);
	//	}
	//	pos = 0;
	//}

	//write number
	//LCD_Void_Write_Number(10);

	//write in arabic
	//LCD_Void_Write_Cmd(0b01000000);
	//u8 arr[8] = {0,0,0,1,1,31,0,4};
	//for(u8 i = 0 ; i < 8; i++){
	//	LCD_Void_Write_Data(arr[i]);
	//}
	//LCD_Void_Write_Cmd(0b10000000);
	//LCD_Void_Write_Data(0);

	//sinosidal wave
	sinosoidal_wave((u8*)"youssef");

	return 0;
}

