/*
 * MAIN.C
 *
 *      Author: youssef
 */


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include <avr\delay.h>

int main(){
	char arr[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
	LCD_Void_Init_8Bits();

	DIO_U8_Set_Port_Direction(GROUP_C,maximum_port_direction);

	DIO_U8_Set_Pin_Direction(GROUP_D,PIN0,OUTPUT);

	while(1){
		for(u8 i=5;i>0;i--){
			LCD_Void_Write_String((u8*)"DOOR IS OPENING IN:",0,0);
			DIO_U8_Set_Port_Value(GROUP_C,arr[i]);
			DIO_U8_Set_Pin_Value(GROUP_D,PIN0,HIGH);
			_delay_ms(50);
			DIO_U8_Set_Pin_Value(GROUP_D,PIN0,LOW);
			_delay_ms(50);
		}
		LCD_ClearDisplay();

		DIO_U8_Set_Port_Value(GROUP_C,arr[0]);
		LCD_Void_Write_String((u8*)"DOOR IS OPENED",0,0);
		_delay_ms(500);
		LCD_ClearDisplay();

		for(u8 i=5;i>0;i--){
			LCD_Void_Write_String((u8*)"DOOR IS CLOSING IN:",0,0);
			DIO_U8_Set_Port_Value(GROUP_C,arr[i]);
			DIO_U8_Set_Pin_Value(GROUP_D,PIN0,HIGH);
			_delay_ms(50);
			DIO_U8_Set_Pin_Value(GROUP_D,PIN0,LOW);
			_delay_ms(50);
			LCD_ClearDisplay();
		}
		DIO_U8_Set_Port_Value(GROUP_C,arr[0]);
		LCD_Void_Write_String((u8*)"DOOR IS CLOSED",0,0);
		_delay_ms(500);
		LCD_ClearDisplay();



	}


}
