/*
 * LCD_Config.h
 *
 *      Author: youssef
 */
#include "DIO_Interface.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_U8_CTRL_PORT Group_C

#define LCD_U8_RS_PIN PIN0
#define LCD_U8_RW_PIN PIN1
#define LCD_U8_ENABLE_PIN PIN2

#define LCD_U8_DATA_PORT Group_D

#define LCD_U8_DATA_PIN_0 PIN0
#define LCD_U8_DATA_PIN_1 PIN1
#define LCD_U8_DATA_PIN_2 PIN2
#define LCD_U8_DATA_PIN_3 PIN3
#define LCD_U8_DATA_PIN_4 PIN4
#define LCD_U8_DATA_PIN_5 PIN5
#define LCD_U8_DATA_PIN_6 PIN6
#define LCD_U8_DATA_PIN_7 PIN7

//number of bits
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

// init values for LCD , instructions in datasheet
#define LCD_INSTRUCTION_SET 0b00111000
#define LCD_ON_OFF_DISPLAY 0b00001100
#define LCD_CLR_DISPLAY 0b00000001
#define LCD_ENTRY_MODE_SET 0b00000110
#endif /* LCD_CONFIG_H_ */
