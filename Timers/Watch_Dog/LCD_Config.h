/*
 * DIO_Config.h
 *
 *      Author: youssef
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#define LCD_U8_CTRL_PORT Group_A
#define LCD_U8_RS_PIN PIN0
#define LCD_U8_RW_PIN PIN1
#define LCD_U8_ENABLE_PIN PIN2

#define LCD_U8_DATA_PORT Group_C
#define LCD_U8_DATA_PIN0 PIN0
#define LCD_U8_DATA_PIN1 PIN1
#define LCD_U8_DATA_PIN2 PIN2
#define LCD_U8_DATA_PIN3 PIN3
#define LCD_U8_DATA_PIN4 PIN4
#define LCD_U8_DATA_PIN5 PIN5
#define LCD_U8_DATA_PIN6 PIN6
#define LCD_U8_DATA_PIN7 PIN7

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#define Init_Function_set 0b00111000
#define Init_Display_OnOff 0b00001100
#define Init_Display_Clear 0b00000001
#define Init_Entry_Data_Set 0b00000110

#endif /* LCD_CONFIG_H_ */
