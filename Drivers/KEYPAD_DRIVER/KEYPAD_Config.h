/*
 * KEYPAD_Config.h
 *
 *      Author: youssef
 */
#include "DIO_Interface.h"


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KPD_U8_Active_Col 0
#define KPD_U8_Active_Row 1
#define KPD_U8_PullUp 0
#define KPD_U8_PullDown 1
#define KPD_U8_Col_Number 3
#define KPD_U8_Row_Number 4

#define KPD_U8_Activation_Type KPD_U8_Active_Col //choose active column or active row
#define KPD_U8_ConnectionType  KPD_U8_PullUp // choose pullup connection or pulldown
#define KPD_U8_Col_Port Group_A
#define KPD_U8_Row_Port Group_B
#define KPD_U8_Col_0 PIN0
#define KPD_U8_Col_1 PIN1
#define KPD_U8_Col_2 PIN2
#define KPD_U8_Col_3 PIN3

#define KPD_U8_Row_0 PIN0
#define KPD_U8_Row_1 PIN1
#define KPD_U8_Row_2 PIN2
#define KPD_U8_Row_3 PIN3


#endif /* KEYPAD_CONFIG_H_ */
