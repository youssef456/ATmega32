#include "STD_Types.h"
#include "bit_calc.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "avr/delay.h"
#include "KEYPAD_Config.h"
#include "stdio.h"

#define DEBOUNCE_THRESHOLD 5

void pressed_Switch(u8 *Copy_Sw_Value) {
    static u8 displayFlag = 0;  // Static flag to keep track of the display state
    u8 sw_index = 0;
    u8 row_index, col_index;
    u8 isPressed = 0;
    u8 currentnumber = 0;

    for (u8 i = 0; i < KPD_U8_Size; i++) {
        if (Copy_Sw_Value[i] == LOW) {
            sw_index = i;
            isPressed = 1;
            currentnumber = i + 1;
            break;
        }
    }

    if (isPressed == 1) {
        row_index = sw_index / KPD_U8_Row_Number;
        col_index = sw_index % KPD_U8_Col_Number;

        if (displayFlag == 0) {
            LCD_Void_Clear_Display();
            displayFlag = 1;
        }

        LCD_Void_Write_String((u8*) "Sw ", 0, 0);
        LCD_Void_Write_Number(currentnumber, 5, 0);


        //LCD_Void_Write_Number(row_index, 3, 0);
        //LCD_Void_Write_String((u8*) ",", 4, 0);
        //LCD_Void_Write_Number(col_index, 5, 0);
    } else {
        if (displayFlag == 1) {
    		  displayFlag = 0;
        }
        LCD_Void_Write_String((u8*) "switch np", 0, 0);
    }
}

int main() {
    LCD_Void_Init_8Bit();
    KPD_Void_Init();

    u8 sw_data_arr[KPD_U8_Size];  // Adjusted array size for 16 switches

    while(1){
        KPD_Void_Get_KPD_Status(sw_data_arr);
        pressed_Switch(sw_data_arr);
        //_delay_ms(100);
    }

    return 0;
}
