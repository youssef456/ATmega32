/*
 * main.c
 *
 *      Author: youssef
 */


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include <util\delay.h>
#include "LCD_Interface.h"


// We need to switch a buzzer On & OFF by 2n2222 With delay 1 sec.

int main(){
	LCD_VOID_Init_8Bit();

	DIO_U8_SetPinDirection(Group_C,PIN0,OUTPUT);

	while(1){
		DIO_U8_SetPinValue(Group_C,PIN0,HIGH);
		LCD_Void_Write_String((u8*)"clockwise" ,0 ,0);
		_delay_ms(100);
		DIO_U8_SetPinValue(Group_C,PIN0,LOW);
		LCD_Void_Write_String((u8*)"anti clockwise" ,0 ,0);
		_delay_ms(100);

	}
}






/*
// LAB 1 Write a C code to control a DC motor in one direction using a tactile switch. The switch
// shall act as a breaking the system, the motor shall rotate as long as the switch is not pressed.

int main() {
    DIO_U8_Set_Pin_Direction(GROUP_A, PIN1, OUTPUT);
    DIO_U8_Set_Pin_Direction(GROUP_A, PIN0, INPUT);
    DIO_U8_Set_Pin_Value(GROUP_A,PIN0,HIGH);

    while (1) {
        if (DIO_U8_Get_Pin_Value(GROUP_A, PIN0) == LOW) {
            DIO_U8_Set_Pin_Value(GROUP_A, PIN1, LOW);

        } else {
            DIO_U8_Set_Pin_Value(GROUP_A, PIN1,HIGH);

        }
    }

    return 0;
}

*/





// LAB 2
/*

int main(){
	DIO_U8_Set_Pin_Direction(GROUP_A,PIN0,OUTPUT);
	DIO_U8_Set_Pin_Direction(GROUP_A,PIN1,OUTPUT);

	while(1){
		DIO_U8_Set_Pin_Value(GROUP_A,PIN0,HIGH);
		DIO_U8_Set_Pin_Value(GROUP_A,PIN1,LOW);
		_delay_ms(2000);
		DIO_U8_Set_Pin_Value(GROUP_A,PIN0,LOW);
		DIO_U8_Set_Pin_Value(GROUP_A,PIN1,HIGH);
		_delay_ms(2000);


	}

}

*/
// lab 4
/*
int main() {
    DIO_U8_Set_Pin_Direction(GROUP_A, PIN0, OUTPUT);
    DIO_U8_Set_Pin_Direction(GROUP_A, PIN1, OUTPUT);

    while (1) {
        DIO_U8_Set_Pin_Value(GROUP_A, PIN0, LOW);
        DIO_U8_Set_Pin_Value(GROUP_A, PIN1, HIGH);
        _delay_ms(500);

        DIO_U8_Set_Pin_Value(GROUP_A, PIN0, HIGH);
        DIO_U8_Set_Pin_Value(GROUP_A, PIN1, LOW);
        _delay_ms(500);
    }

    return 0;
}

*/




