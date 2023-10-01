/*
 * LCD_Program.c
 *
 *      Author: youssef
 */


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Config.h"

#include "LCD_Interface.h"
#include <avr/delay.h>

void LCD_Void_Init_8Bits (void){
	DIO_U8_Set_Port_Direction(LCD_U8_DATA_Port, maximum_port_direction);
	DIO_U8_Set_Pin_Direction(LCD_U8_CTRL_Port, LCD_U8_RS_PIN, OUTPUT);
	DIO_U8_Set_Pin_Direction(LCD_U8_CTRL_Port, LCD_U8_RW_PIN, OUTPUT);
	DIO_U8_Set_Pin_Direction(LCD_U8_CTRL_Port, LCD_U8_ENABLE_PIN, OUTPUT);
	_delay_ms(50);
	LCD_Void_Write_Cmd(Init_Function_set);  //FUNCTION set  see starting from page 12 in lcd datasheet
	_delay_ms(50);
	LCD_Void_Write_Cmd(Init_Display_OnOff);  //display on/off
	_delay_ms(50);
	LCD_Void_Write_Cmd(Init_Display_Clear);  //display clear
	_delay_ms(2);
	LCD_Void_Write_Cmd(Init_Entry_Data_Set);  //Entry Mode set
}


void LCD_Void_Write_Cmd(u8 Copy_u8_Cmd){
	DIO_U8_Set_Pin_Value(LCD_U8_CTRL_Port, LCD_U8_RS_PIN, LOW);
	LCD_Void_Write(Copy_u8_Cmd);
}

void LCD_Void_Write_Data(u8 Copy_u8_Data){
	DIO_U8_Set_Pin_Value(LCD_U8_CTRL_Port, LCD_U8_RS_PIN, HIGH);
	LCD_Void_Write(Copy_u8_Data);
}

void LCD_Void_Write(u8 Copy_U8_Value){
	DIO_U8_Set_Pin_Value(LCD_U8_CTRL_Port, LCD_U8_RW_PIN, LOW);
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_0 ,Get_Bit(Copy_U8_Value,BIT0));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_1 ,Get_Bit(Copy_U8_Value,BIT1));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_2 ,Get_Bit(Copy_U8_Value,BIT2));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_3 ,Get_Bit(Copy_U8_Value,BIT3));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_4 ,Get_Bit(Copy_U8_Value,BIT4));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_5 ,Get_Bit(Copy_U8_Value,BIT5));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_6 ,Get_Bit(Copy_U8_Value,BIT6));
	DIO_U8_Set_Pin_Value(LCD_U8_DATA_Port, LCD_U8_DATA_PIN_7 ,Get_Bit(Copy_U8_Value,BIT7));

	DIO_U8_Set_Pin_Value(LCD_U8_CTRL_Port, LCD_U8_ENABLE_PIN, HIGH);
	_delay_ms(1);
	DIO_U8_Set_Pin_Value(LCD_U8_CTRL_Port, LCD_U8_ENABLE_PIN, LOW);

}


void LCD_Void_Write_String(u8* Copy_PU8_DATA, u8 Copy_U8_X_Postion, u8 Copy_U8_Y_Postion) {
    u8 Local_U8_DDRAM_Address;
    u8 counter = 0;
    if (Copy_U8_X_Postion > 15 || Copy_U8_Y_Postion > 1) {
        LCD_Void_Write_String((u8*)"Invalid entry", 0, 0);
        return;
    }
    Local_U8_DDRAM_Address = Copy_U8_X_Postion + (Copy_U8_Y_Postion * 64);
    Local_U8_DDRAM_Address |= DDRAM_ADDRESS;
    LCD_Void_Write_Cmd(Local_U8_DDRAM_Address);

    while (*Copy_PU8_DATA != '\0') {
        LCD_Void_Write_Data(*Copy_PU8_DATA);
        Copy_PU8_DATA++;
        counter++;
        if (counter == 16) {
            if (Copy_U8_Y_Postion == 0) {
                Local_U8_DDRAM_Address = Second_Line_Start;
            } else {
            	Local_U8_DDRAM_Address = Copy_U8_X_Postion;
            }
            Local_U8_DDRAM_Address |= DDRAM_ADDRESS;
            LCD_Void_Write_Cmd(Local_U8_DDRAM_Address);
        }
    }
}



void LCD_Void_Write_Number(u32 Copy_U32_Number, u8 Copy_U8_X_Postion, u8 Copy_U8_Y_Postion){
    u8 Copy_U8_Reminder;
    u8 Copy_U8_arr[20];
    u8 i=0;
    u8 Local_U8_DDRAM_Address;
    u8 counter = 0; // Initialize counter variable to 0

    if (Copy_U8_X_Postion > 15 || Copy_U8_Y_Postion > 1) {
        LCD_Void_Write_String((u8*)"Invalid entry", 0, 0);
        return;
    }

    Local_U8_DDRAM_Address = Copy_U8_X_Postion + (Copy_U8_Y_Postion * 64);
    Local_U8_DDRAM_Address |= DDRAM_ADDRESS;
    LCD_Void_Write_Cmd(Local_U8_DDRAM_Address);

    if (Copy_U32_Number == 0) {
        Copy_U8_arr[i] = '0';
        i++;
        counter++;
    } else {
        while(Copy_U32_Number != 0){
            Copy_U8_Reminder = Copy_U32_Number % 10;
            Copy_U8_arr[i] = Copy_U8_Reminder +'0';
            i++;
            Copy_U32_Number = Copy_U32_Number / 10;
            counter++;
        }
    }
    Copy_U8_arr[i] = '\0';

    // Reverse the order of the digits in the array

    for (u8 j = 0; j < i/2; j++) {
        u8 temp = Copy_U8_arr[j];
        Copy_U8_arr[j] = Copy_U8_arr[i-1-j];
        Copy_U8_arr[i-1-j] = temp;
    }


    // Print the array elements and check for line break
    for(u8 j = 0; Copy_U8_arr[j] != '\0'; j++){
        LCD_Void_Write_Data(Copy_U8_arr[j]);
        counter++;
        if (counter == 16) {
            if (Copy_U8_Y_Postion == 0) {
                Local_U8_DDRAM_Address = Second_Line_Start;
            } else {
            	Local_U8_DDRAM_Address = Copy_U8_X_Postion + (Copy_U8_Y_Postion * 64);
            }
            Local_U8_DDRAM_Address |= DDRAM_ADDRESS;
            LCD_Void_Write_Cmd(Local_U8_DDRAM_Address);
        }
    }
}

void LCD_ClearDisplay(){
	LCD_Void_Write_Cmd(Init_Display_Clear);  //display clear
	_delay_ms(2);
}

u8 Calculate_String_Length(u8* Copy_PU8_DATA){
	u8 i=0;
	while(*Copy_PU8_DATA != '\0'){
		i++;
		Copy_PU8_DATA++;

	}
	return i;
}


void reverse(u8 arr[], u8 lenght){
	u8 start=0;
	u8 end = lenght -1;

	while(start< end){

		u8 temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end++;

	}
}







