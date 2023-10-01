/*
 * DIO_Program.c
 *
 *      Author: youssef
 */

#include "STD_Types.h"
#include "bit_calc.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"

#include "util/delay.h"

void LCD_Void_Write_Cmd(u8 Copy_U8_Cmd){
	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,LOW);
	LCD_Void_Write(Copy_U8_Cmd);
}

void LCD_Void_Write_Data(u8 Copy_U8_Data){
	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,HIGH);
	LCD_Void_Write(Copy_U8_Data);
}
void LCD_Void_Write_String(u8 *Copy_PU8_Data,u8 Copy_U8_XPos,u8 Copy_U8_YPOS){
	u8 LOCAL_U8_DDRAM_ADDRESS;
	LOCAL_U8_DDRAM_ADDRESS = Copy_U8_XPos + (Copy_U8_YPOS * 64);
	LOCAL_U8_DDRAM_ADDRESS |= 0b10000000;
	LCD_Void_Write_Cmd(LOCAL_U8_DDRAM_ADDRESS);

	while(*Copy_PU8_Data != '\0'){
		LCD_Void_Write_Data(*Copy_PU8_Data);
		Copy_PU8_Data ++;
	}
}
void LCD_Void_Write_Number(u32 Copy_U32_Num){
	u8 rem;
	u8 i = 0;
	u8 str[20];
	while(Copy_U32_Num != 0){
		rem = Copy_U32_Num % 10;
		str[i]= rem + '0';
		i++;
		Copy_U32_Num = Copy_U32_Num/10;
	}
	str[i] = '\0';
	reverse(str,i);
	LCD_Void_Write_String(str,0,0);
}
void LCD_Void_Clear_Display(){
	LCD_Void_Write_Cmd(Init_Display_Clear);  //display clear
	_delay_ms(2);
}

void reverse(u8 *ptr,u8 lenght){
	u8 start = 0;
	u8 end = lenght - 1;
	while(start < end){
		swap(&ptr[start],&ptr[end]);
		start ++;
		end --;
	}
}
void swap(u8 *a,u8 *b){
	u8 z = *a;
	*a = *b;
	*b = z;
}

void LCD_Void_Write(u8 Copy_U8_Value){
	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RW_PIN,LOW);
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN0,Get_Bit(Copy_U8_Value,BIT0));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN1,Get_Bit(Copy_U8_Value,BIT1));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN2,Get_Bit(Copy_U8_Value,BIT2));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN3,Get_Bit(Copy_U8_Value,BIT3));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN4,Get_Bit(Copy_U8_Value,BIT4));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN5,Get_Bit(Copy_U8_Value,BIT5));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN6,Get_Bit(Copy_U8_Value,BIT6));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT,LCD_U8_DATA_PIN7,Get_Bit(Copy_U8_Value,BIT7));

	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT,LCD_U8_ENABLE_PIN,HIGH);
	_delay_us(1);
	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT,LCD_U8_ENABLE_PIN,LOW);

}

void LCD_VOID_Init_8Bit(){
	DIO_U8_SetPortDirection(LCD_U8_DATA_PORT,Max_Port_Value);
	DIO_U8_SetPinDirection(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,OUTPUT);
	DIO_U8_SetPinDirection(LCD_U8_CTRL_PORT,LCD_U8_RW_PIN,OUTPUT);
	DIO_U8_SetPinDirection(LCD_U8_CTRL_PORT,LCD_U8_ENABLE_PIN,OUTPUT);

	_delay_ms(50);

	LCD_Void_Write_Cmd(Init_Function_set);
	_delay_us(50);

	LCD_Void_Write_Cmd(Init_Display_OnOff);
	_delay_us(50);

	LCD_Void_Write_Cmd(Init_Display_Clear);
	_delay_us(2);

	LCD_Void_Write_Cmd(Init_Entry_Data_Set);


}
