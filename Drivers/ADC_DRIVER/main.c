/*
 * main.c
 *
 *      Author: youssef
 */

#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"


#include "BIT_CALC.h"
#include "STD_TYPES.h"

#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include <util/delay.h>

int main(){
	//a0 input
	DIO_U8_Set_Pin_Direction(GROUP_A,PIN0,INPUT);
	ADC_Void_Init();
	LCD_Void_Init_8Bits();
	u16 digital;
	f32 analog;
	while(1){
		LCD_ClearDisplay();
		digital = ADC_U8_Read_channel(channel_0);
		LCD_Void_Write_Number(digital,0,0);
		analog = (digital * 5) / 1024;
		LCD_Void_Write_Number(analog,0,0);

	}
	return 0;
}
