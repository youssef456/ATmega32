/*
 * main.c
 *
 *      Author: youssef
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include <avr/delay.h>



u8 ledState = 0;
u8 arr[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
u8 currentNumber=0;


void Turn_onLed(void) {
    ledState = !ledState;
    if (ledState==1){
    	DIO_U8_Set_Pin_Value(GROUP_D, PIN0, HIGH);
    }
    else{
    	DIO_U8_Set_Pin_Value(GROUP_D, PIN0, LOW);
    }

}

void Turn_onLCD(void){
    ledState = !ledState;
    if (ledState==1){
        LCD_ClearDisplay();
    	LCD_Void_Write_String((u8*)"Pressed",0,0);
    }
    else{
        LCD_ClearDisplay();
    	LCD_Void_Write_String((u8*)"NOT Pressed",0,0);
    }
}

void Turn_on7SEG(void) {
    currentNumber++;
    if (currentNumber >= 10) {
        currentNumber = 0;
    }

    DIO_U8_Set_Port_Value(GROUP_C, arr[currentNumber]);
}


int main(){

	EXTI_Void_Global_Enable_Disable(EXTI_U8_Global_Enable);

	// led PORTD PIN0 INT0
	DIO_U8_Set_Pin_Direction(EXTI_U8_INT0_PORT,EXTI_U8_INT0_PIN,INPUT);
	DIO_U8_Set_Pin_Value(EXTI_U8_INT0_PORT,EXTI_U8_INT0_PIN,HIGH);
	DIO_U8_Set_Pin_Direction(GROUP_D,PIN0,OUTPUT);

	EXTI_U8_Set_Level(EXTI_U8_INT0,EXTI_U8_Falling_Edge);
	EXTI_Void_Set_Call_Back(EXTI_U8_INT0, Turn_onLed);
	EXTI_Void_Ein_Dis(EXTI_U8_INT0 ,EXTI_U8_Global_Enable);

	// LCD PORTB PORTC INT1
	LCD_Void_Init_8Bits();
	DIO_U8_Set_Pin_Direction(EXTI_U8_INT1_PORT,EXTI_U8_INT1_PIN,INPUT);
	DIO_U8_Set_Pin_Value(EXTI_U8_INT1_PORT,EXTI_U8_INT1_PIN,HIGH);

	EXTI_U8_Set_Level(EXTI_U8_INT1,EXTI_U8_Falling_Edge);
	EXTI_Void_Set_Call_Back(EXTI_U8_INT1, Turn_onLCD);
	EXTI_Void_Ein_Dis(EXTI_U8_INT1 ,EXTI_U8_Global_Enable);

	// 7SEGEMENT PORTA
	DIO_U8_Set_Pin_Direction(EXTI_U8_INT2_PORT,EXTI_U8_INT2_PIN,INPUT);
	DIO_U8_Set_Pin_Value(EXTI_U8_INT2_PORT,EXTI_U8_INT2_PIN,HIGH);
	DIO_U8_Set_Port_Direction(GROUP_B,maximum_port_direction);

	EXTI_U8_Set_Level(EXTI_U8_INT2,EXTI_U8_Falling_Edge);
	EXTI_Void_Set_Call_Back(EXTI_U8_INT2, Turn_on7SEG);
	EXTI_Void_Ein_Dis(EXTI_U8_INT2 ,EXTI_U8_Global_Enable);


	while(1){

	}

}


// use RC CIRCUIT TO STOP DEBOUNCING

