/*
 * LCD_Program.c
 *
 *      Author: youssef
 */



#include "STD_Types.h"
#include "bit_calc.h"
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"1




void LCD_Void_Move_Name(u8 *Copy_PU8_String) {
    u8 nameLen = 0;
    while (*Copy_PU8_String) {
        nameLen++;
        Copy_PU8_String++;
    }
    Copy_PU8_String -= nameLen;

    s8 startPos = 0;
    s8 direction = 1; // 1 for left to right and -1 for right to left

    while (1) {
        LCD_Void_Clear_Display();

        if (startPos >= 0 && startPos < 16) {
            for (u8 i = 0; i < nameLen; i++) {
                s8 xPos = startPos + i;
                if (xPos >= 0 && xPos < 16) {
                    LCD_Void_Write_String(Copy_PU8_String + i, xPos, 0);
                }
            }
        }

        _delay_ms(250);
        startPos += direction;

        if (startPos >= 16 - nameLen +1) {
            direction = -1;
            startPos = 16 - nameLen - 1;
        } else if (startPos < 0) {
            direction = 1;
            startPos = 0;
        }
    }
}



void reverse(u8 arr[], u8 i){
	u8 start = 0;;
	u8 end = i-1;

	while (start < end){

		u8 temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;

	}
}

void LCD_Void_Write_Number(u32 Copy_U32_Num, u8 Copy_U8_Xpos,u8 Copy_U8_Ypos){
	u8 rem;
	u8 arr[20];
	u8 i = 0;
	while(Copy_U32_Num){
	rem = Copy_U32_Num % 10;
	arr[i]= rem + '0';
	i++;
	Copy_U32_Num /= 10;

	}
	arr[i] = '\0';
	reverse(arr,i);
	LCD_Void_Write_String(arr, Copy_U8_Xpos, Copy_U8_Ypos);

}

void LCD_Void_Write_String(u8 *Copy_PU8_String , u8 Copy_U8_Xpos ,u8 Copy_U8_Ypos){

	if(Copy_U8_Xpos <= 16 && Copy_U8_Ypos <= 1){
		u8 local_U8_DDRAM_Address = Copy_U8_Xpos +(Copy_U8_Ypos * 64);
		local_U8_DDRAM_Address |= 0b10000000;
		LCD_Void_Write_Cmd(local_U8_DDRAM_Address);
	}

	u8 charWritten = 0;
	while(*Copy_PU8_String){

		if((Copy_U8_Xpos + charWritten) > 15){ // wrapping the text in the x axis
			Copy_U8_Xpos = 0;
			Copy_U8_Ypos = (Copy_U8_Ypos + 1) % 2; //toggling line 0 or 1 depends on this eq*/

			if(Copy_U8_Xpos <= 16 && Copy_U8_Ypos <= 1){
					u8 local_U8_DDRAM_Address = Copy_U8_Xpos +(Copy_U8_Ypos * 64);
					local_U8_DDRAM_Address |= 0b10000000;
					LCD_Void_Write_Cmd(local_U8_DDRAM_Address);
				}

		}

		LCD_Void_Write_Data(*Copy_PU8_String);
		Copy_PU8_String++;
		charWritten++;

	}
}


void LCD_Void_Write(u8 Copy_U8_Value){

	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT, LCD_U8_RW_PIN, LOW);

	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_0, get_Bit(Copy_U8_Value,BIT0));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_1, get_Bit(Copy_U8_Value,BIT1));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_2, get_Bit(Copy_U8_Value,BIT2));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_3, get_Bit(Copy_U8_Value,BIT3));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_4, get_Bit(Copy_U8_Value,BIT4));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_5, get_Bit(Copy_U8_Value,BIT5));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_6, get_Bit(Copy_U8_Value,BIT6));
	DIO_U8_SetPinValue(LCD_U8_DATA_PORT, LCD_U8_DATA_PIN_7, get_Bit(Copy_U8_Value,BIT7));

	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT, LCD_U8_ENABLE_PIN, HIGH);
	_delay_ms(1);
	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT, LCD_U8_ENABLE_PIN, LOW);


}

void LCD_Void_Write_Data(u8 Copy_U8_Data){

	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT, LCD_U8_RS_PIN, HIGH);
	LCD_Void_Write(Copy_U8_Data);
}

void LCD_Void_Write_Cmd(u8 Copy_U8_Cmd){

	DIO_U8_SetPinValue(LCD_U8_CTRL_PORT, LCD_U8_RS_PIN, LOW);
	LCD_Void_Write(Copy_U8_Cmd);



}
void LCD_Void_Clear_Display(){

	LCD_Void_Write_Cmd(LCD_CLR_DISPLAY);
}

void LCD_Void_Init_8Bit(){

	//Initialize data port as output
	DIO_U8_SetPortDirection(LCD_U8_DATA_PORT, Max_Port_Value);
	// RS PIN
	DIO_U8_SetPinDirection(LCD_U8_CTRL_PORT, LCD_U8_RS_PIN, OUTPUT);
	//RW PIN
	DIO_U8_SetPinDirection(LCD_U8_CTRL_PORT, LCD_U8_RW_PIN, OUTPUT);
	//Enable pin
	DIO_U8_SetPinDirection(LCD_U8_CTRL_PORT, LCD_U8_ENABLE_PIN, OUTPUT);

	_delay_ms(40);

	//perform function set
	// default 0011NFXX x --> don't care
	// F --> for font 0 = 5*7 for 1 = 5*10
	// N --> for number of lines 0 = 1 line , 1 = 2 lines.
	LCD_Void_Write_Cmd(LCD_INSTRUCTION_SET);

	_delay_us(50);
	// display ON/OFF function set//

	// default 00001DCB D--> for display 1 = on , 0 = off
	//C for cursor 1 = on , 0 = off //
	// B for cursor blinking 0 = no blinking , 1 = blinking in case of C = 1
	LCD_Void_Write_Cmd(LCD_ON_OFF_DISPLAY);
	_delay_us(50);

	// clear display function set//
	LCD_Void_Write_Cmd(LCD_CLR_DISPLAY);
	_delay_ms(2);

	//data entry set
	// default 000001I/D SH  i/d -> 1 = increase i/d -> 0 = decrease
	// SH shifting left if sh = 1 and if i/d = 1 and right if i/d = 0.

	LCD_Void_Write_Cmd(LCD_ENTRY_MODE_SET);

	// END OF INITIALIZATION


}
